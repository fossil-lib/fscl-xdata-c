/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_QUEUE_H
#define TRILOBITE_XDATA_QUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the queue
typedef struct TriloQueueNode {
    TriloTofu data;
    struct TriloQueueNode* next;
} TriloQueueNode;

// Queue structure
typedef struct TriloQueue {
    TriloQueueNode* front;
    TriloQueueNode* rear;
    enum DataType queue_type;  // Type of the queue
} TriloQueue;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloQueue instance with the specified list type.
 *
 * @param list_type The data type for the TriloQueue (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloQueue instance.
 */
TriloQueue* trilo_xdata_queue_create(enum DataType list_type);

/**
 * @brief Destroys the TriloQueue instance, freeing all associated memory.
 *
 * @param queue The TriloQueue instance to be destroyed.
 */
void trilo_xdata_queue_destroy(TriloQueue* queue);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a TriloTofu data element into the TriloQueue.
 *
 * @param queue The TriloQueue where the data will be inserted.
 * @param data  The TriloTofu data element to be inserted.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_queue_insert(TriloQueue* queue, TriloTofu data);

/**
 * @brief Removes an element from the front of the TriloQueue.
 *
 * This function removes an element from the front of the TriloQueue if it's not empty.
 *
 * @param queue The TriloQueue from which the element will be removed.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_queue_remove(TriloQueue* queue);

/**
 * @brief Searches for a TriloTofu data element in the TriloQueue.
 *
 * @param queue The TriloQueue to search within.
 * @param data  The TriloTofu data element to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_queue_search(const TriloQueue* queue, TriloTofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloQueue.
 *
 * @param queue The TriloQueue for which the size will be determined.
 * @return The size of the TriloQueue.
 */
size_t trilo_xdata_queue_size(const TriloQueue* queue);

/**
 * @brief Getter function to retrieve a TriloTofu data element from the TriloQueue.
 *
 * @param queue The TriloQueue from which the data will be retrieved.
 * @param data  The TriloTofu data element to retrieve.
 * @return A pointer to the TriloTofu data element in the TriloQueue (or NULL if not found).
 */
TriloTofu* trilo_xdata_queue_getter(TriloQueue* queue, TriloTofu data);

/**
 * @brief Setter function to update a TriloTofu data element in the TriloQueue.
 *
 * @param queue The TriloQueue in which the data will be updated.
 * @param data  The TriloTofu data element to update.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_queue_setter(TriloQueue* queue, TriloTofu data);

/**
 * @brief Checks if the TriloQueue is not empty.
 *
 * @param queue The TriloQueue to check.
 * @return true if the TriloQueue is not empty, false otherwise.
 */
bool trilo_xdata_queue_not_empty(const TriloQueue* queue);

/**
 * @brief Checks if the TriloQueue is not a null pointer.
 *
 * @param queue The TriloQueue to check.
 * @return true if the TriloQueue is not a null pointer, false otherwise.
 */
bool trilo_xdata_queue_not_nullptr(const TriloQueue* queue);

/**
 * @brief Checks if the TriloQueue is empty.
 *
 * @param queue The TriloQueue to check.
 * @return true if the TriloQueue is empty, false otherwise.
 */
bool trilo_xdata_queue_is_empty(const TriloQueue* queue);

/**
 * @brief Checks if the TriloQueue is a null pointer.
 *
 * @param queue The TriloQueue to check.
 * @return true if the TriloQueue is a null pointer, false otherwise.
 */
bool trilo_xdata_queue_is_nullptr(const TriloQueue* queue);

#ifdef __cplusplus
}
#endif

#endif
