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
#ifndef fscl_pqueue_H
#define fscl_pqueue_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

typedef struct cpqueue_node {
    ctofu data;
    int priority;
    struct cpqueue_node* next;
} cpqueue_node;

typedef struct cpqueue {
    cpqueue_node* front;
    ctofu_type queue_type;
} cpqueue;

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new priority queue with the specified data type.
 *
 * @param queue_type The type of data the priority queue will store.
 * @return           The created priority queue.
 */
cpqueue* fscl_pqueue_create(ctofu_type queue_type);

/**
 * Erase the contents of the priority queue and free allocated memory.
 *
 * @param pqueue The priority queue to erase.
 */
void fscl_pqueue_erase(cpqueue* pqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the priority queue with the specified priority.
 *
 * @param pqueue   The priority queue to insert data into.
 * @param data     The data to insert.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_pqueue_insert(cpqueue* pqueue, ctofu data, int priority);

/**
 * Remove data from the priority queue.
 *
 * @param pqueue   The priority queue to remove data from.
 * @param data     The data to remove.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_pqueue_remove(cpqueue* pqueue, ctofu* data, int* priority);

/**
 * Search for data in the priority queue.
 *
 * @param pqueue   The priority queue to search.
 * @param data     The data to search for.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_pqueue_search(const cpqueue* pqueue, ctofu data, int priority);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the priority queue.
 *
 * @param pqueue The priority queue for which to get the size.
 * @return       The size of the priority queue.
 */
size_t fscl_pqueue_size(const cpqueue* pqueue);

/**
 * Get the data from the priority queue matching the specified data and priority.
 *
 * @param pqueue   The priority queue from which to get the data.
 * @param data     The data to search for.
 * @param priority The priority of the data.
 * @return         A pointer to the matching data, or NULL if not found.
 */
ctofu* fscl_pqueue_getter(cpqueue* pqueue, ctofu data, int priority);

/**
 * Set data in the priority queue with the specified priority.
 *
 * @param pqueue   The priority queue in which to set the data.
 * @param data     The data to set.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_pqueue_setter(cpqueue* pqueue, ctofu data, int priority);

/**
 * Check if the priority queue is not empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not empty, false otherwise.
 */
bool fscl_pqueue_not_empty(const cpqueue* pqueue);

/**
 * Check if the priority queue is not a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not a null pointer, false otherwise.
 */
bool fscl_pqueue_not_cnullptr(const cpqueue* pqueue);

/**
 * Check if the priority queue is empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is empty, false otherwise.
 */
bool fscl_pqueue_is_empty(const cpqueue* pqueue);

/**
 * Check if the priority queue is a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is a null pointer, false otherwise.
 */
bool fscl_pqueue_is_cnullptr(const cpqueue* pqueue);

#ifdef __cplusplus
}
#endif

#endif
