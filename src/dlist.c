/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloDoublyList* trilo_xdata_dlist_create(enum DataType list_type) {
    TriloDoublyList* list = (TriloDoublyList*)malloc(sizeof(TriloDoublyList));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    list->head = NULL;
    list->tail = NULL;
    list->list_type = list_type;
    return list;
} // end of func

void trilo_xdata_dlist_destroy(TriloDoublyList* list) {
    TriloDoublyListNode* current = list->head;
    TriloDoublyListNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    } // end while
    free(list);
} // end of func

bool trilo_xdata_dlist_is_empty(const TriloDoublyList* list) {
    return list->head == NULL;
} // end of func

void trilo_xdata_dlist_insert(TriloDoublyList* list, TriloTofu data) {
    // Ensure the data type matches the list type
    if (data.type != list->list_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloDoublyListNode* new_node = (TriloDoublyListNode*)malloc(sizeof(TriloDoublyListNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    new_node->data = data;
    new_node->prev = list->tail;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    } // end if else
} // end of func

void trilo_xdata_dlist_remove(TriloDoublyList* list, TriloTofu data) {
    // Ensure the data type matches the list type
    if (data.type != list->list_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloDoublyListNode* current = list->head;

    while (current != NULL) {
        if (memcmp(&current->data, &data, sizeof(TriloTofu)) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            } // end if else
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            } // end if else
            free(current);
            return;
        } // end if
        current = current->next;
    } // end while
} // end of func

void trilo_xdata_dlist_reverse(TriloDoublyList* list) {
    TriloDoublyListNode* temp = NULL;
    TriloDoublyListNode* current = list->head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } // end while

    if (temp != NULL) {
        list->head = temp->prev;
    } // end if
} // end of func

void trilo_xdata_dlist_print_forward(const TriloDoublyList* list) {
    TriloDoublyListNode* current = list->head;
    while (current != NULL) {
        switch (list->list_type) {
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

void trilo_xdata_dlist_print_backward(const TriloDoublyList* list) {
    TriloDoublyListNode* current = list->tail;
    while (current != NULL) {
        switch (list->list_type) {
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
        current = current->prev;
    } // endwhile
    printf("NULL\n");
} // end of func
