/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {INITIAL_CAPACITY = 10};

// Hash function to compute the index for a given key
static size_t hash(const char* key, size_t capacity) {
    size_t hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key++);
    } // end while
    return hash % capacity;
} // end of func

TriloDict* trilo_xdata_dict_create(enum DataType dict_type, size_t capacity) {
    TriloDict* dict = (TriloDict*)malloc(sizeof(TriloDict));
    if (dict == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    dict->dict_type = dict_type;
    dict->size = 0;
    dict->capacity = capacity;

    // Allocate memory for the hash table (array of pointers to nodes)
    dict->table = (TriloDictNode**)malloc(sizeof(TriloDictNode*) * capacity);
    if (dict->table == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(dict);
        exit(EXIT_FAILURE);
    } // end if

    // Initialize each bucket with NULL
    for (size_t i = 0; i < capacity; i++) {
        dict->table[i] = NULL;
    } // end for

    return dict;
} // end of func

void trilo_xdata_dict_destroy(TriloDict* dict) {
    if (dict == NULL) {
        return;
    } // end if

    // Free memory for each node in the hash table
    for (size_t i = 0; i < dict->capacity; i++) {
        TriloDictNode* current = dict->table[i];
        while (current != NULL) {
            TriloDictNode* temp = current;
            current = current->next;
            free(temp);
        } // end while
    } // end for

    free(dict->table);
    free(dict);
} // end of func

void trilo_xdata_dict_insert(TriloDict* dict, const char* key, TriloTofu value) {
    if (value.type != dict->dict_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    size_t index = hash(key, dict->capacity);

    // Check if the key already exists and update the value
    TriloDictNode* current = dict->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            return;
        } // end if
        current = current->next;
    } // end while

    // Key does not exist, create a new node
    TriloDictNode* newNode = (TriloDictNode*)malloc(sizeof(TriloDictNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    strncpy(newNode->key, key, sizeof(newNode->key));
    newNode->value = value;
    newNode->next = dict->table[index];
    dict->table[index] = newNode;
    dict->size++;

    // Check if the hash table needs to be resized
    if (dict->size > dict->capacity * 0.75) {
        // Resize the hash table and rehash all elements
        size_t new_capacity = dict->capacity * 2;
        TriloDictNode** new_table = (TriloDictNode**)malloc(sizeof(TriloDictNode*) * new_capacity);
        if (new_table == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        } // end if
        for (size_t i = 0; i < new_capacity; i++) {
            new_table[i] = NULL;
        } // end for

        for (size_t i = 0; i < dict->capacity; i++) {
            current = dict->table[i];
            while (current != NULL) {
                size_t new_index = hash(current->key, new_capacity);
                TriloDictNode* next = current->next;
                current->next = new_table[new_index];
                new_table[new_index] = current;
                current = next;
            } // end while
        } // end for

        free(dict->table);
        dict->table = new_table;
        dict->capacity = new_capacity;
    } // end if
} // end of func

TriloTofu trilo_xdata_dict_get(const TriloDict* dict, const char* key) {
    size_t index = hash(key, dict->capacity);

    TriloDictNode* current = dict->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        } // end if
        current = current->next;
    } // end while

    // Key not found, return a default value of the specified type
    TriloTofu defaultValue;
    defaultValue.type = dict->dict_type;
    switch (dict->dict_type) {
        case INTEGER_TYPE:
            defaultValue.data.integer_type = 0;
            break;
        case DOUBLE_TYPE:
            defaultValue.data.double_type = 0.0;
            break;
        case STRING_TYPE:
            defaultValue.data.string_type[0] = '\0';
            break;
        case CHAR_TYPE:
            defaultValue.data.char_type = '\0';
            break;
        case BOOLEAN_TYPE:
            defaultValue.data.boolean_type = false;
            break;
        default:
            fprintf(stderr, "Unknown data type!\n");
            exit(EXIT_FAILURE);
    } // end switch
    return defaultValue;
} // end of func

bool trilo_xdata_dict_contains(const TriloDict* dict, const char* key) {
    size_t index = hash(key, dict->capacity);

    TriloDictNode* current = dict->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return true;
        } // end if
        current = current->next;
    } // end while

    return false;
} // end of func

void trilo_xdata_dict_remove(TriloDict* dict, const char* key) {
    size_t index = hash(key, dict->capacity);

    TriloDictNode* current = dict->table[index];
    TriloDictNode* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                dict->table[index] = current->next;
            } else {
                prev->next = current->next;
            } // end if else
            free(current);
            dict->size--;
            return;
        } // end if
        prev = current;
        current = current->next;
    } // end while
} // end of func

size_t trilo_xdata_dict_size(const TriloDict* dict) {
    return dict->size;
} // end of func

void trilo_xdata_dict_print(const TriloDict* dict) {
    for (size_t i = 0; i < dict->capacity; i++) {
        TriloDictNode* current = dict->table[i];
        while (current != NULL) {
            printf("Key: %s (Type: %d) -> ", current->key, current->value.type);
            switch (current->value.type) {
                case INTEGER_TYPE:
                    printf("%d\n", current->value.data.integer_type);
                    break;
                case DOUBLE_TYPE:
                    printf("%lf\n", current->value.data.double_type);
                    break;
                case STRING_TYPE:
                    printf("%s\n", current->value.data.string_type);
                    break;
                case CHAR_TYPE:
                    printf("%c\n", current->value.data.char_type);
                    break;
                case BOOLEAN_TYPE:
                    printf("%s\n", current->value.data.boolean_type ? "true" : "false");
                    break;
                default:
                    printf("Unknown type\n");
                    break;
            } // end switch
            current = current->next;
        } // end while
    } // end for
} // end of func
