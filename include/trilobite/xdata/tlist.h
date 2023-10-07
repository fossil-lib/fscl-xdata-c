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

// Define error constants for tuple operations
enum {
    TRILO_XDATA_TLIST_TYPE_MISMATCH = -1,
    TRILO_XDATA_TLIST_OUT_OF_RANGE  = -2
};

// Node structure for the ternary linked list
typedef struct TriloTernaryListNode {
    TriloTofu data;
    struct TriloTernaryListNode* prev;
    struct TriloTernaryListNode* next;
    struct TriloTernaryListNode* middle;
} TriloTernaryListNode;

// Ternary linked list structure
typedef struct TriloTernaryList {
    TriloTernaryListNode* head;
    enum DataType list_type;  // Type of the list
} TriloTernaryList;

// Function to create a new TriloTernaryList
TriloTernaryList* trilo_xdata_tlist_create(enum DataType list_type);

// Function to destroy the TriloTernaryList
void trilo_xdata_tlist_destroy(TriloTernaryList* tlist);

// Function to insert a TriloTofu data into the ternary linked list
void trilo_xdata_tlist_insert(TriloTernaryList* tlist, TriloTofu data);

// Function to remove a TriloTofu data from the ternary linked list
void trilo_xdata_tlist_remove(TriloTernaryList* tlist, TriloTofu data);

// Function to search for a TriloTofu data in the ternary linked list
bool trilo_xdata_tlist_search(const TriloTernaryList* tlist, TriloTofu data);

// Function to print the elements in the ternary linked list
void trilo_xdata_tlist_print(const TriloTernaryList* tlist);

#ifdef __cplusplus
}
#endif

#endif
