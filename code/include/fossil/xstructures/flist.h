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
#ifndef fscl_flist_H
#define fscl_flist_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

// Node structure for the linked list
typedef struct cflist_node {
    ctofu data;
    struct cflist_node* next;
} cflist_node;

// Linked list structure
typedef struct cflist {
    cflist_node* head;
    ctofu_type list_type;  // Type of the linked list
} cflist;

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new forward list with the specified data type.
 *
 * @param list_type The type of data the forward list will store.
 * @return          The created forward list.
 */
cflist* fscl_flist_create(ctofu_type list_type);

/**
 * Erase the contents of the forward list and free allocated memory.
 *
 * @param flist The forward list to erase.
 */
void fscl_flist_erase(cflist* flist);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the forward list.
 *
 * @param flist The forward list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_flist_insert(cflist* flist, ctofu data);

/**
 * Remove data from the forward list.
 *
 * @param flist The forward list to remove data from.
 * @param data  A pointer to store the removed data.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_flist_remove(cflist* flist, ctofu* data);

/**
 * Search for data in the forward list.
 *
 * @param flist The forward list to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_flist_search(const cflist* flist, ctofu data);

/**
 * Reverse the forward list in the forward direction.
 *
 * @param flist The forward list to reverse.
 */
void fscl_flist_reverse_forward(cflist* flist);

/**
 * Reverse the forward list in the backward direction.
 *
 * @param flist The forward list to reverse.
 */
void fscl_flist_reverse_backward(cflist* flist);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the forward list.
 *
 * @param flist The forward list for which to get the size.
 * @return      The size of the forward list.
 */
size_t fscl_flist_size(const cflist* flist);

/**
 * Get the data from the forward list matching the specified data.
 *
 * @param flist The forward list from which to get the data.
 * @param data  The data to search for.
 * @return      A pointer to the matching data.
 */
ctofu* fscl_flist_getter(cflist* flist, ctofu data);

/**
 * Set data in the forward list.
 *
 * @param flist The forward list in which to set the data.
 * @param data  The data to set.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_flist_setter(cflist* flist, ctofu data);

/**
 * Check if the forward list is not empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not empty, false otherwise.
 */
bool fscl_flist_not_empty(const cflist* flist);

/**
 * Check if the forward list is not a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not a null pointer, false otherwise.
 */
bool fscl_flist_not_cnullptr(const cflist* flist);

/**
 * Check if the forward list is empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is empty, false otherwise.
 */
bool fscl_flist_is_empty(const cflist* flist);

/**
 * Check if the forward list is a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is a null pointer, false otherwise.
 */
bool fscl_flist_is_cnullptr(const cflist* flist);

#ifdef __cplusplus
}
#endif

#endif
