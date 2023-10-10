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

#include "trilobite/xdata/tofu.h"

// Node structure for the doubly linked list
typedef struct TriloDoublyListNode {
    TriloTofu data;
    struct TriloDoublyListNode* prev;
    struct TriloDoublyListNode* next;
} TriloDoublyListNode;

// Doubly linked list structure
typedef struct TriloDoublyList {
    TriloDoublyListNode* head;
    TriloDoublyListNode* tail;
    enum DataType list_type;  // Type of the linked list
} TriloDoublyList;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloDoublyList instance with the specified list type.
 *
 * @param list_type The data type for the TriloDoublyList (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloDoublyList instance.
 */
TriloDoublyList* trilo_xdata_dlist_create(enum DataType list_type);

/**
 * @brief Destroys the TriloDoublyList instance, freeing all associated memory.
 *
 * @param dlist The TriloDoublyList instance to be destroyed.
 */
void trilo_xdata_dlist_destroy(TriloDoublyList* dlist);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a TriloTofu data element into the TriloDoublyList.
 *
 * @param dlist The TriloDoublyList where the data will be inserted.
 * @param data   The TriloTofu data element to be inserted.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_dlist_insert(TriloDoublyList* dlist, TriloTofu data);

/**
 * @brief Removes a TriloTofu data element from the TriloDoublyList.
 *
 * @param dlist The TriloDoublyList from which the data will be removed.
 * @param data   The TriloTofu data element to be removed.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_dlist_remove(TriloDoublyList* dlist, TriloTofu data);

/**
 * @brief Searches for a TriloTofu data element in the TriloDoublyList.
 *
 * @param dlist The TriloDoublyList to search within.
 * @param data   The TriloTofu data element to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_dlist_search(const TriloDoublyList* dlist, TriloTofu data);

/**
 * @brief Reverses the TriloDoublyList in the forward direction.
 *
 * @param dlist The TriloDoublyList to be reversed.
 */
void trilo_xdata_dlist_reverse_forward(TriloDoublyList* dlist);

/**
 * @brief Reverses the TriloDoublyList in the backward direction.
 *
 * @param dlist The TriloDoublyList to be reversed.
 */
void trilo_xdata_dlist_reverse_backward(TriloDoublyList* dlist);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloDoublyList.
 *
 * @param dlist The TriloDoublyList for which the size will be determined.
 * @return The size of the TriloDoublyList.
 */
size_t trilo_xdata_dlist_size(const TriloDoublyList* dlist);

/**
 * @brief Getter function to retrieve a TriloTofu data element from the TriloDoublyList.
 *
 * @param dlist The TriloDoublyList from which the data will be retrieved.
 * @param data   The TriloTofu data element to retrieve.
 * @return A pointer to the TriloTofu data element in the TriloDoublyList (or NULL if not found).
 */
TriloTofu* trilo_xdata_dlist_getter(TriloDoublyList* dlist, TriloTofu data);

/**
 * @brief Setter function to update a TriloTofu data element in the TriloDoublyList.
 *
 * @param dlist The TriloDoublyList in which the data will be updated.
 * @param data   The TriloTofu data element to update.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_dlist_setter(TriloDoublyList* dlist, TriloTofu data);

/**
 * @brief Checks if the TriloDoublyList is not empty.
 *
 * @param dlist The TriloDoublyList to check.
 * @return true if the TriloDoublyList is not empty, false otherwise.
 */
bool trilo_xdata_dlist_not_empty(const TriloDoublyList* dlist);

/**
 * @brief Checks if the TriloDoublyList is not a null pointer.
 *
 * @param dlist The TriloDoublyList to check.
 * @return true if the TriloDoublyList is not a null pointer, false otherwise.
 */
bool trilo_xdata_dlist_not_nullptr(const TriloDoublyList* dlist);

/**
 * @brief Checks if the TriloDoublyList is empty.
 *
 * @param dlist The TriloDoublyList to check.
 * @return true if the TriloDoublyList is empty, false otherwise.
 */
bool trilo_xdata_dlist_is_empty(const TriloDoublyList* dlist);

/**
 * @brief Checks if the TriloDoublyList is a null pointer.
 *
 * @param dlist The TriloDoublyList to check.
 * @return true if the TriloDoublyList is a null pointer, false otherwise.
 */
bool trilo_xdata_dlist_is_nullptr(const TriloDoublyList* dlist);

#ifdef __cplusplus
}
#endif

#endif
