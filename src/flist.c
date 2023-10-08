/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/flist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloForwardList* trilo_xdata_flist_create(enum DataType list_type) {
    TriloForwardList* list = (TriloForwardList*)malloc(sizeof(TriloForwardList));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->list_type = list_type;
    return list;
}

void trilo_xdata_flist_destroy(TriloForwardList* list) {
    TriloForwardListNode* current = list->head;
    TriloForwardListNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    } // end while
    free(list);
} // end of func

bool trilo_xdata_flist_is_empty(const TriloForwardList* list) {
    return list->head == NULL;
} // end of func

void trilo_xdata_flist_insert(TriloForwardList* list, TriloTofu data) {
    // Ensure the data type matches the list type
    if (data.type != list->list_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloForwardListNode* new_node = (TriloForwardListNode*)malloc(sizeof(TriloForwardListNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    } // end if

    TriloForwardListNode* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    } // end while
    current->next = new_node;
} // end of func

void trilo_xdata_flist_remove(TriloForwardList* list, TriloTofu data) {
    // Ensure the data type matches the list type
    if (data.type != list->list_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloForwardListNode* current = list->head;
    TriloForwardListNode* prev = NULL;

    while (current != NULL) {
        if (memcmp(&current->data, &data, sizeof(TriloTofu)) == 0) {
            if (prev == NULL) {
                list->head = current->next;
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

void trilo_xdata_flist_reverse(TriloForwardList* list) {
    TriloForwardListNode* prev = NULL;
    TriloForwardListNode* current = list->head;
    TriloForwardListNode* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } // end while

    list->head = prev;
} // end of func

void trilo_xdata_flist_print(const TriloForwardList* list) {
    TriloForwardListNode* current = list->head;
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

// Function to get a TriloTofu data at a specified index in the forward list
TriloTofu* trilo_xdata_flist_get(const TriloForwardList* flist, int index) {
    if (flist == NULL || index < 0) {
        return NULL;
    } // end if

    TriloForwardListNode* current = flist->head;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    } // end while

    if (current != NULL) {
        return &(current->data);
    } else {
        return NULL;
    } // end if else
} // end of func
