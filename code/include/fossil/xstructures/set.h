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
#ifndef fscl_set_H
#define fscl_set_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

// Node structure for the set
typedef struct cset_node {
    ctofu data;
    struct cset_node* next;
} cset_node;

// Set structure
typedef struct cset {
    cset_node* head;
    ctofu_type set_type;  // Type of the set
} cset;

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new set with the specified data type.
 *
 * @param list_type The type of data the set will store.
 * @return          The created set.
 */
cset* fscl_set_create(ctofu_type list_type);

/**
 * Erase the contents of the set and free allocated memory.
 *
 * @param set The set to erase.
 */
void fscl_set_erase(cset* set);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the set.
 *
 * @param set  The set to insert data into.
 * @param data The data to insert.
 * @return     The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_set_insert(cset* set, ctofu data);

/**
 * Remove data from the set.
 *
 * @param set  The set to remove data from.
 * @param data The data to remove.
 * @return     The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_set_remove(cset* set, ctofu data);

/**
 * Search for data in the set.
 *
 * @param set  The set to search.
 * @param data The data to search for.
 * @return     The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_set_search(const cset* set, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the set.
 *
 * @param set The set for which to get the size.
 * @return    The size of the set.
 */
size_t fscl_set_size(const cset* set);

/**
 * Get the data from the set matching the specified data.
 *
 * @param set  The set from which to get the data.
 * @param data The data to search for.
 * @return     A pointer to the matching data, or NULL if not found.
 */
ctofu* fscl_set_getter(cset* set, ctofu data);

/**
 * Set data in the set.
 *
 * @param set  The set in which to set the data.
 * @param data The data to set.
 * @return     The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_set_setter(cset* set, ctofu data);

/**
 * Check if the set is not empty.
 *
 * @param set The set to check.
 * @return    True if the set is not empty, false otherwise.
 */
bool fscl_set_not_empty(const cset* set);

/**
 * Check if the set is not a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is not a null pointer, false otherwise.
 */
bool fscl_set_not_cnullptr(const cset* set);

/**
 * Check if the set is empty.
 *
 * @param set The set to check.
 * @return    True if the set is empty, false otherwise.
 */
bool fscl_set_is_empty(const cset* set);

/**
 * Check if the set is a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is a null pointer, false otherwise.
 */
bool fscl_set_is_cnullptr(const cset* set);

/**
 * Check if the set contains a specific element.
 *
 * @param set  The set to check.
 * @param data The data to search for.
 * @return     True if the set contains the element, false otherwise.
 */
bool fscl_set_contains(const cset* set, ctofu data);

// =======================
// ITERATOR FUNCTIONS
// =======================
/**
 * Get the iterator pointing to the start of the set.
 *
 * @param set The set for which to get the iterator.
 * @return    The iterator pointing to the start of the set.
 */
ctofu_iterator fscl_set_iterator_start(cset* set);

/**
 * Get the iterator pointing to the end of the set.
 *
 * @return The iterator pointing to the end of the set.
 */
ctofu_iterator fscl_set_iterator_end(void);

/**
 * Move the iterator to the next element in the set.
 *
 * @param iterator The current iterator position.
 * @return         The updated iterator position after moving to the next element.
 */
ctofu_iterator fscl_set_iterator_next(ctofu_iterator iterator);

/**
 * Check if there is a next element in the set.
 *
 * @param iterator The current iterator position.
 * @return         True if there is a next element, false otherwise.
 */
bool fscl_set_iterator_has_next(ctofu_iterator iterator);

#ifdef __cplusplus
}
#endif

#endif
