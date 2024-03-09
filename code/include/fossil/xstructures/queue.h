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
#ifndef fscl_queue_H
#define fscl_queue_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

// Node structure for the queue
typedef struct cqueue_node {
    ctofu data;
    struct cqueue_node* next;
} cqueue_node;

// Queue structure
typedef struct cqueue {
    cqueue_node* front;
    cqueue_node* rear;
    ctofu_type queue_type;  // Type of the queue
} cqueue;

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new queue with the specified data type.
 *
 * @param list_type The type of data the queue will store.
 * @return          The created queue.
 */
cqueue* fscl_queue_create(ctofu_type list_type);

/**
 * Erase the contents of the queue and free allocated memory.
 *
 * @param queue The queue to erase.
 */
void fscl_queue_erase(cqueue* queue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the queue.
 *
 * @param queue The queue to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_queue_insert(cqueue* queue, ctofu data);

/**
 * Remove data from the queue.
 *
 * @param queue The queue to remove data from.
 * @param data  The data to remove.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_queue_remove(cqueue* queue, ctofu* data);

/**
 * Search for data in the queue.
 *
 * @param queue The queue to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_queue_search(const cqueue* queue, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the queue.
 *
 * @param queue The queue for which to get the size.
 * @return      The size of the queue.
 */
size_t fscl_queue_size(const cqueue* queue);

/**
 * Get the data from the queue matching the specified data.
 *
 * @param queue The queue from which to get the data.
 * @param data  The data to search for.
 * @return      A pointer to the matching data, or NULL if not found.
 */
ctofu* fscl_queue_getter(cqueue* queue, ctofu data);

/**
 * Set data in the queue.
 *
 * @param queue The queue in which to set the data.
 * @param data  The data to set.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_queue_setter(cqueue* queue, ctofu data);

/**
 * Check if the queue is not empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not empty, false otherwise.
 */
bool fscl_queue_not_empty(const cqueue* queue);

/**
 * Check if the queue is not a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not a null pointer, false otherwise.
 */
bool fscl_queue_not_cnullptr(const cqueue* queue);

/**
 * Check if the queue is empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is empty, false otherwise.
 */
bool fscl_queue_is_empty(const cqueue* queue);

/**
 * Check if the queue is a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is a null pointer, false otherwise.
 */
bool fscl_queue_is_cnullptr(const cqueue* queue);

#ifdef __cplusplus
}
#endif

#endif
