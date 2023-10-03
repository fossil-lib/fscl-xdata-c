/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloMap* trilo_xdata_map_create(enum DataType map_type) {
    TriloMap* map = (TriloMap*)malloc(sizeof(TriloMap));
    if (map == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    map->head = NULL;
    map->map_type = map_type;
    return map;
} // end of func

void trilo_xdata_map_destroy(TriloMap* map) {
    TriloMapNode* current = map->head;
    TriloMapNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    } // end while
    free(map);
} // end of func

bool trilo_xdata_map_is_empty(const TriloMap* map) {
    return map->head == NULL;
} // end of func

void trilo_xdata_map_insert(TriloMap* map, const char* key, TriloTofu value) {
    // Ensure the data type matches the map type
    if (value.type != map->map_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloMapNode* new_node = (TriloMapNode*)malloc(sizeof(TriloMapNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    strncpy(new_node->key, key, sizeof(new_node->key));
    new_node->key[sizeof(new_node->key) - 1] = '\0'; // Ensure null-termination
    new_node->value = value;
    new_node->next = NULL;

    if (map->head == NULL) {
        map->head = new_node;
    } else {
        TriloMapNode* current = map->head;
        while (current->next != NULL) {
            current = current->next;
        } // end while
        current->next = new_node;
    } // end if else
} // end of func

void trilo_xdata_map_remove(TriloMap* map, const char* key) {
    TriloMapNode* current = map->head;
    TriloMapNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                map->head = current->next;
            } else {
                prev->next = current->next;
            } // end if else
            free(current);
            return;
        } // end if
        prev = current;
        current = current->next;
    } // end while
} // end of func

TriloTofu trilo_xdata_map_get(const TriloMap* map, const char* key) {
    TriloMapNode* current = map->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        } // end if
        current = current->next;
    } // end while

    // If key not found, return a default TriloTofu with the same type
    TriloTofu default_value;
    default_value.type = map->map_type;
    switch (map->map_type) {
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
            break;
    } // end switch
    return default_value;
} // end of func

bool trilo_xdata_map_contains_key(const TriloMap* map, const char* key) {
    TriloMapNode* current = map->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return true;
        } // end if
        current = current->next;
    } // end while
    return false;
} // end of func

void trilo_xdata_map_print(const TriloMap* map) {
    TriloMapNode* current = map->head;
    while (current != NULL) {
        printf("Key: %s, Value: ", current->key);
        switch (map->map_type) {
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
} // end of func
