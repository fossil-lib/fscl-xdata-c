/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_PQUEUE_H
#define TRILOBITE_XDATA_PQUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

typedef struct TriloPQueueNode {
    TriloTofu data;
    int priority;
    struct TriloPQueueNode* next;
} TriloPQueueNode;

typedef struct TriloPQueue {
    TriloPQueueNode* front;
    DataType queue_type;
} TriloPQueue;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloPQueue instance with the specified queue type.
 *
 * @param queue_type The data type for the TriloPQueue (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloPQueue instance.
 */
TriloPQueue* trilo_xdata_pqueue_create(enum DataType queue_type);

/**
 * @brief Destroys the TriloPQueue instance, freeing all associated memory.
 *
 * @param pqueue The TriloPQueue instance to be destroyed.
 */
void trilo_xdata_pqueue_destroy(TriloPQueue* pqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a TriloTofu data element with a given priority into the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue where the data will be inserted.
 * @param data     The TriloTofu data element to be inserted.
 * @param priority The priority of the data element.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_pqueue_insert(TriloPQueue* pqueue, TriloTofu data, int priority);

/**
 * @brief Removes a TriloTofu data element with a given priority from the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue from which the data will be removed.
 * @param data     The TriloTofu data element to be removed.
 * @param priority The priority of the data element to remove.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_pqueue_remove(TriloPQueue* pqueue, TriloTofu data, int priority);

/**
 * @brief Searches for a TriloTofu data element with a given priority in the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue to search within.
 * @param data     The TriloTofu data element to search for.
 * @param priority The priority of the data element to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_pqueue_search(const TriloPQueue* pqueue, TriloTofu data, int priority);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloPQueue.
 *
 * @param pqueue The TriloPQueue for which the size will be determined.
 * @return The size of the TriloPQueue.
 */
size_t trilo_xdata_pqueue_size(const TriloPQueue* pqueue);

/**
 * @brief Getter function to retrieve a TriloTofu data element with a given priority from the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue from which the data will be retrieved.
 * @param data     The TriloTofu data element to retrieve.
 * @param priority The priority of the data element to retrieve.
 * @return A pointer to the TriloTofu data element in the TriloPQueue (or NULL if not found).
 */
TriloTofu* trilo_xdata_pqueue_getter(TriloPQueue* pqueue, TriloTofu data, int priority);

/**
 * @brief Setter function to update a TriloTofu data element with a given priority in the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue in which the data will be updated.
 * @param data     The TriloTofu data element to update.
 * @param priority The priority of the data element to update.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_pqueue_setter(TriloPQueue* pqueue, TriloTofu data, int priority);

/**
 * @brief Checks if the TriloPQueue is not empty.
 *
 * @param pqueue The TriloPQueue to check.
 * @return true if the TriloPQueue is not empty, false otherwise.
 */
bool trilo_xdata_pqueue_not_empty(const TriloPQueue* pqueue);

/**
 * @brief Checks if the TriloPQueue is not a null pointer.
 *
 * @param pqueue The TriloPQueue to check.
 * @return true if the TriloPQueue is not a null pointer, false otherwise.
 */
bool trilo_xdata_pqueue_not_nullptr(const TriloPQueue* pqueue);

/**
 * @brief Checks if the TriloPQueue is empty.
 *
 * @param pqueue The TriloPQueue to check.
 * @return true if the TriloPQueue is empty, false otherwise.
 */
bool trilo_xdata_pqueue_is_empty(const TriloPQueue* pqueue);

/**
 * @brief Checks if the TriloPQueue is a null pointer.
 *
 * @param pqueue The TriloPQueue to check.
 * @return true if the TriloPQueue is a null pointer, false otherwise.
 */
bool trilo_xdata_pqueue_is_nullptr(const TriloPQueue* pqueue);

#ifdef __cplusplus
}
#endif

#endif
