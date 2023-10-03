/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {INITIAL_SIZE = 100};

TriloHashNode* trilo_xdata_hash_node_create(const char* key, TriloTofu data) {
    TriloHashNode* node = (TriloHashNode*)malloc(sizeof(TriloHashNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    node->key = strdup(key); // Copy the key
    node->data = data;
    node->next = NULL;
    return node;
} // end of func

TriloHash* trilo_xdata_hash_create(enum DataType hash_type, int size) {
    TriloHash* hash = (TriloHash*)malloc(sizeof(TriloHash));
    if (hash == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    hash->size = size;
    hash->table = (TriloHashNode**)calloc(size, sizeof(TriloHashNode*));
    if (hash->table == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    hash->hash_type = hash_type;
    return hash;
} // end of func

void trilo_xdata_hash_destroy(TriloHash* hash) {
    for (int i = 0; i < hash->size; i++) {
        TriloHashNode* current = hash->table[i];
        while (current != NULL) {
            TriloHashNode* next = current->next;
            free(current->key);
            free(current);
            current = next;
        } // end while
    } // end for
    free(hash->table);
    free(hash);
} // end of func

unsigned int trilo_xdata_hash_function(const char* key, int size) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31) + key[i];
    } // end for
    return hash % size;
} // end of func

void trilo_xdata_hash_insert(TriloHash* hash, const char* key, TriloTofu data) {
    // Ensure the data type matches the hash table type
    if (data.type != hash->hash_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    unsigned int index = trilo_xdata_hash_function(key, hash->size);
    TriloHashNode* newNode = trilo_xdata_hash_node_create(key, data);

    if (hash->table[index] == NULL) {
        hash->table[index] = newNode;
    } else {
        // Collision handling: add the new node to the beginning of the linked list
        newNode->next = hash->table[index];
        hash->table[index] = newNode;
    } // end if else
} // end of func

void trilo_xdata_hash_remove(TriloHash* hash, const char* key) {
    unsigned int index = trilo_xdata_hash_function(key, hash->size);
    TriloHashNode* current = hash->table[index];
    TriloHashNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                // The node to remove is the first node in the list
                hash->table[index] = current->next;
            } else {
                prev->next = current->next;
            } // end if else
            free(current->key);
            free(current);
            return;
        } // end if
        prev = current;
        current = current->next;
    } // end while
} // end of func

TriloTofu trilo_xdata_hash_get(TriloHash* hash, const char* key) {
    unsigned int index = trilo_xdata_hash_function(key, hash->size);
    TriloHashNode* current = hash->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->data;
        } // end if
        current = current->next;
    } // end while

    // If the key is not found, return a default value of the same type
    TriloTofu default_value;
    default_value.type = hash->hash_type;

    switch (hash->hash_type) {
        case INTEGER_TYPE:
            default_value.data.integer_type = 0;
            break;
        case DOUBLE_TYPE:
            default_value.data.double_type = 0.0;
            break;
        case STRING_TYPE:
            strncpy(default_value.data.string_type, "", sizeof(default_value.data.string_type));
            break;
        case CHAR_TYPE:
            default_value.data.char_type = '\0';
            break;
        case BOOLEAN_TYPE:
            default_value.data.boolean_type = false;
            break;
        default:
            fprintf(stderr, "Unknown type\n");
            exit(EXIT_FAILURE);
    } // end switch

    return default_value;
} // end of func

bool trilo_xdata_hash_contains_key(TriloHash* hash, const char* key) {
    unsigned int index = trilo_xdata_hash_function(key, hash->size);
    TriloHashNode* current = hash->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return true;
        } // end if
        current = current->next;
    } // end while

    return false;
} // end of func

void trilo_xdata_hash_print(TriloHash* hash) {
    for (int i = 0; i < hash->size; i++) {
        printf("Bucket %d: ", i);
        TriloHashNode* current = hash->table[i];
        while (current != NULL) {
            switch (current->data.type) {
                case INTEGER_TYPE:
                    printf("(%s -> %d) -> ", current->key, current->data.data.integer_type);
                    break;
                case DOUBLE_TYPE:
                    printf("(%s -> %lf) -> ", current->key, current->data.data.double_type);
                    break;
                case STRING_TYPE:
                    printf("(%s -> %s) -> ", current->key, current->data.data.string_type);
                    break;
                case CHAR_TYPE:
                    printf("(%s -> %c) -> ", current->key, current->data.data.char_type);
                    break;
                case BOOLEAN_TYPE:
                    printf("(%s -> %s) -> ", current->key, current->data.data.boolean_type ? "true" : "false");
                    break;
                default:
                    printf("(%s -> Unknown type) -> ", current->key);
                    break;
            } // end switch
            current = current->next;
        } // end while
        printf("NULL\n");
    } // end for
} // end of func
