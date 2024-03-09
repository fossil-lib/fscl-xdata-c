/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef fscl_dlist_H
#define fscl_dlist_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

// Node structure for the doubly linked list
typedef struct cdlist_node {
    ctofu data;
    struct cdlist_node* prev;
    struct cdlist_node* next;
} cdlist_node;

// Doubly linked list structure
typedef struct cdlist {
    cdlist_node* head;
    cdlist_node* tail;
    ctofu_type list_type;  // Type of the linked list
} cdlist;

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new doubly linked list with the specified data type.
 *
 * @param list_type The type of data the doubly linked list will store.
 * @return          The created doubly linked list.
 */
cdlist* fscl_dlist_create(ctofu_type list_type);

/**
 * Erase the contents of the doubly linked list and free allocated memory.
 *
 * @param dlist The doubly linked list to erase.
 */
void fscl_dlist_erase(cdlist* dlist);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the doubly linked list.
 *
 * @param dlist The doubly linked list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_dlist_insert(cdlist* dlist, ctofu data);

/**
 * Remove data from the doubly linked list.
 *
 * @param dlist The doubly linked list to remove data from.
 * @param data  A pointer to store the removed data.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_dlist_remove(cdlist* dlist, ctofu* data);

/**
 * Search for data in the doubly linked list.
 *
 * @param dlist The doubly linked list to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_dlist_search(const cdlist* dlist, ctofu data);

/**
 * Reverse the doubly linked list in the forward direction.
 *
 * @param dlist The doubly linked list to reverse.
 */
void fscl_dlist_reverse_forward(cdlist* dlist);

/**
 * Reverse the doubly linked list in the backward direction.
 *
 * @param dlist The doubly linked list to reverse.
 */
void fscl_dlist_reverse_backward(cdlist* dlist);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the doubly linked list.
 *
 * @param dlist The doubly linked list for which to get the size.
 * @return      The size of the doubly linked list.
 */
size_t fscl_dlist_size(const cdlist* dlist);

/**
 * Get the data from the doubly linked list matching the specified data.
 *
 * @param dlist The doubly linked list from which to get the data.
 * @param data  The data to search for.
 * @return      A pointer to the matching data.
 */
ctofu* fscl_dlist_getter(cdlist* dlist, ctofu data);

/**
 * Set data in the doubly linked list.
 *
 * @param dlist The doubly linked list in which to set the data.
 * @param data  The data to set.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_dlist_setter(cdlist* dlist, ctofu data);

/**
 * Check if the doubly linked list is not empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not empty, false otherwise.
 */
bool fscl_dlist_not_empty(const cdlist* dlist);

/**
 * Check if the doubly linked list is not a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not a null pointer, false otherwise.
 */
bool fscl_dlist_not_cnullptr(const cdlist* dlist);

/**
 * Check if the doubly linked list is empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is empty, false otherwise.
 */
bool fscl_dlist_is_empty(const cdlist* dlist);

/**
 * Check if the doubly linked list is a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is a null pointer, false otherwise.
 */
bool fscl_dlist_is_cnullptr(const cdlist* dlist);

#ifdef __cplusplus
}
#endif

#endif
