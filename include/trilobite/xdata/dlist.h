/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_DLIST_H
#define TRILOBITE_XDATA_DLIST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Node structure for the doubly linked list
typedef struct TriloDoublyListNode {
    TriloTofu data;
    struct TriloDoublyListNode* prev;
    struct TriloDoublyListNode* next;
} TriloDoublyListNode;

// Doubly linked list structure
typedef struct TriloDoublyList {
    TriloDoublyListNode* head;
    TriloDoublyListNode* tail;
    enum DataType list_type;  // Type of the linked list
} TriloDoublyList;

// Function to create a new TriloDoublyList
TriloDoublyList* trilo_xdata_dlist_create(enum DataType list_type);

// Function to destroy the TriloDoublyList
void trilo_xdata_dlist_destroy(TriloDoublyList* list);

// Function to check if the list is empty
bool trilo_xdata_dlist_is_empty(const TriloDoublyList* list);

// Function to insert a TriloTofu data at the end of the list
void trilo_xdata_dlist_insert(TriloDoublyList* list, TriloTofu data);

// Function to remove the first occurrence of a TriloTofu data from the list
void trilo_xdata_dlist_remove(TriloDoublyList* list, TriloTofu data);

// Function to reverse the linked list in-place
void trilo_xdata_dlist_reverse(TriloDoublyList* list);

// Function to print the data in the linked list forward
void trilo_xdata_dlist_print_forward(const TriloDoublyList* list);

// Function to print the data in the linked list backward
void trilo_xdata_dlist_print_backward(const TriloDoublyList* list);

#ifdef __cplusplus
}
#endif

#endif
