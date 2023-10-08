/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloSet* trilo_xdata_set_create(enum DataType set_type) {
    TriloSet* set = (TriloSet*)malloc(sizeof(TriloSet));
    if (set == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    set->head = NULL;
    set->set_type = set_type;
    return set;
} // end of func

void trilo_xdata_set_destroy(TriloSet* set) {
    TriloSetNode* current = set->head;
    TriloSetNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    } // end while
    free(set);
} // end of func

bool trilo_xdata_set_is_empty(const TriloSet* set) {
    return set->head == NULL;
} // end of func

void trilo_xdata_set_insert(TriloSet* set, TriloTofu data) {
    // Ensure the data type matches the set type
    if (data.type != set->set_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    if (!trilo_xdata_set_contains(set, data)) {
        TriloSetNode* new_node = (TriloSetNode*)malloc(sizeof(TriloSetNode));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        } // end if
        new_node->data = data;
        new_node->next = set->head;
        set->head = new_node;
    } // end if
} // end of func

void trilo_xdata_set_remove(TriloSet* set, TriloTofu data) {
    TriloSetNode* current = set->head;
    TriloSetNode* prev = NULL;

    while (current != NULL) {
        if (memcmp(&current->data, &data, sizeof(TriloTofu)) == 0) {
            if (prev == NULL) {
                set->head = current->next;
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

bool trilo_xdata_set_contains(const TriloSet* set, TriloTofu data) {
    TriloSetNode* current = set->head;
    while (current != NULL) {
        if (memcmp(&current->data, &data, sizeof(TriloTofu)) == 0) {
            return true;
        } // end if
        current = current->next;
    } // end while
    return false;
} // end of func

void trilo_xdata_set_print(const TriloSet* set) {
    TriloSetNode* current = set->head;
    while (current != NULL) {
        switch (set->set_type) {
            case INTEGER_TYPE:
                printf("%d -> ", current->data.data.integer_type);
                break;
            case DOUBLE_TYPE:
                printf("%lf -> ", current->data.data.double_type);
                break;
            case STRING_TYPE:
                printf("%s -> ", current->data.data.string_type);
                break;
            case CHAR_TYPE:
                printf("%c -> ", current->data.data.char_type);
                break;
            case BOOLEAN_TYPE:
                printf("%s -> ", current->data.data.boolean_type ? "true" : "false");
                break;
            default:
                printf("Unknown type\n");
                break;
        } // end switch
        current = current->next;
    } // end while
    printf("NULL\n");
} // end of func

int trilo_xdata_set_size(const TriloSet* set) {
    return set->size;
} // end of func