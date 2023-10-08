/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_FLIST_H
#define TRILOBITE_XDATA_FLIST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Define error constants for tuple operations
enum {
    TRILO_XDATA_FLIST_TYPE_MISMATCH = -1,
    TRILO_XDATA_FLIST_OUT_OF_RANGE  = -2
};

// Node structure for the linked list
typedef struct TriloForwardListNode {
    TriloTofu data;
    struct TriloForwardListNode* next;
} TriloForwardListNode;

// Linked list structure
typedef struct TriloForwardList {
    TriloForwardListNode* head;
    enum DataType list_type;  // Type of the linked list
} TriloForwardList;

// Function to create a new TriloForwardList
TriloForwardList* trilo_xdata_flist_create(enum DataType list_type);

// Function to destroy the TriloForwardList
void trilo_xdata_flist_destroy(TriloForwardList* list);

// Function to check if the list is empty
bool trilo_xdata_flist_is_empty(const TriloForwardList* list);

// Function to insert a TriloTofu data at the end of the list
void trilo_xdata_flist_insert(TriloForwardList* list, TriloTofu data);

// Function to remove the first occurrence of a TriloTofu data from the list
void trilo_xdata_flist_remove(TriloForwardList* list, TriloTofu data);

// Function to reverse the linked list in-place
void trilo_xdata_flist_reverse(TriloForwardList* list);

// Function to print the data in the linked list
void trilo_xdata_flist_print(const TriloForwardList* list);

// Function to get a TriloTofu data at a specified index in the forward list
TriloTofu* trilo_xdata_flist_get(const TriloForwardList* flist, int index);

#ifdef __cplusplus
}
#endif

#endif
