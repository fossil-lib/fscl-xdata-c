/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_DQUEUE_H
#define TRILOBITE_XDATA_DQUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the double-ended queue
typedef struct TriloDQueueNode {
    TriloTofu data;
    struct TriloDQueueNode* prev;
    struct TriloDQueueNode* next;
} TriloDQueueNode;

// Double-ended queue structure
typedef struct TriloDQueue {
    TriloDQueueNode* front;
    TriloDQueueNode* rear;
    enum DataType list_type;  // Type of the deque
} TriloDQueue;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloDQueue instance with the specified list type.
 *
 * @param list_type The data type for the TriloDQueue (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloDQueue instance.
 */
TriloDQueue* trilo_xdata_dqueue_create(enum DataType list_type);

/**
 * @brief Destroys the TriloDQueue instance, freeing all associated memory.
 *
 * @param dqueue The TriloDQueue instance to be destroyed.
 */
void trilo_xdata_dqueue_destroy(TriloDQueue* dqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a TriloTofu data element into the TriloDQueue.
 *
 * @param dqueue The TriloDQueue where the data will be inserted.
 * @param data   The TriloTofu data element to be inserted.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_dqueue_insert(TriloDQueue* dqueue, TriloTofu data);

/**
 * @brief Removes a TriloTofu data element from the TriloDQueue.
 *
 * @param dqueue The TriloDQueue from which the data will be removed.
 * @param data   The TriloTofu data element to be removed.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_dqueue_remove(TriloDQueue* dqueue, TriloTofu data);

/**
 * @brief Searches for a TriloTofu data element in the TriloDQueue.
 *
 * @param dqueue The TriloDQueue to search within.
 * @param data   The TriloTofu data element to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_dqueue_search(const TriloDQueue* dqueue, TriloTofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloDQueue.
 *
 * @param dqueue The TriloDQueue for which the size will be determined.
 * @return The size of the TriloDQueue.
 */
size_t trilo_xdata_dqueue_size(const TriloDQueue* dqueue);

/**
 * @brief Getter function to retrieve a TriloTofu data element from the TriloDQueue.
 *
 * @param dqueue The TriloDQueue from which the data will be retrieved.
 * @param data   The TriloTofu data element to retrieve.
 * @return A pointer to the TriloTofu data element in the TriloDQueue (or NULL if not found).
 */
TriloTofu* trilo_xdata_dqueue_getter(TriloDQueue* dqueue, TriloTofu data);

/**
 * @brief Setter function to update a TriloTofu data element in the TriloDQueue.
 *
 * @param dqueue The TriloDQueue in which the data will be updated.
 * @param data   The TriloTofu data element to update.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_dqueue_setter(TriloDQueue* dqueue, TriloTofu data);

/**
 * @brief Checks if the TriloDQueue is not empty.
 *
 * @param dqueue The TriloDQueue to check.
 * @return true if the TriloDQueue is not empty, false otherwise.
 */
bool trilo_xdata_dqueue_not_empty(const TriloDQueue* dqueue);

/**
 * @brief Checks if the TriloDQueue is not a null pointer.
 *
 * @param dqueue The TriloDQueue to check.
 * @return true if the TriloDQueue is not a null pointer, false otherwise.
 */
bool trilo_xdata_dqueue_not_nullptr(const TriloDQueue* dqueue);

/**
 * @brief Checks if the TriloDQueue is empty.
 *
 * @param dqueue The TriloDQueue to check.
 * @return true if the TriloDQueue is empty, false otherwise.
 */
bool trilo_xdata_dqueue_is_empty(const TriloDQueue* dqueue);

/**
 * @brief Checks if the TriloDQueue is a null pointer.
 *
 * @param dqueue The TriloDQueue to check.
 * @return true if the TriloDQueue is a null pointer, false otherwise.
 */
bool trilo_xdata_dqueue_is_nullptr(const TriloDQueue* dqueue);

#ifdef __cplusplus
}
#endif

#endif
