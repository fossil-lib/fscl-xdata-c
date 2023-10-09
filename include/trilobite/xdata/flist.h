/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_FLIST_H
#define TRILOBITE_XDATA_FLIST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the linked list
typedef struct TriloForwardListNode {
    TriloTofu data;
    struct TriloForwardListNode* next;
} TriloForwardListNode;

// Linked list structure
typedef struct TriloForwardList {
    TriloForwardListNode* head;
    enum DataType list_type;  // Type of the linked list
} TriloForwardList;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloForwardList instance with the specified list type.
 *
 * @param list_type The data type for the TriloForwardList (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloForwardList instance.
 */
TriloForwardList* trilo_xdata_flist_create(enum DataType list_type);

/**
 * @brief Destroys the TriloForwardList instance, freeing all associated memory.
 *
 * @param flist The TriloForwardList instance to be destroyed.
 */
void trilo_xdata_flist_destroy(TriloForwardList* flist);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a TriloTofu data element into the TriloForwardList.
 *
 * @param flist The TriloForwardList where the data will be inserted.
 * @param data  The TriloTofu data element to be inserted.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_flist_insert(TriloForwardList* flist, TriloTofu data);

/**
 * @brief Removes a TriloTofu data element from the TriloForwardList.
 *
 * @param flist The TriloForwardList from which the data will be removed.
 * @param data  The TriloTofu data element to be removed.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_flist_remove(TriloForwardList* flist, TriloTofu data);

/**
 * @brief Searches for a TriloTofu data element in the TriloForwardList.
 *
 * @param flist The TriloForwardList to search within.
 * @param data  The TriloTofu data element to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_flist_search(const TriloForwardList* flist, TriloTofu data);

/**
 * @brief Reverses the TriloForwardList in the forward direction.
 *
 * @param flist The TriloForwardList to be reversed.
 */
void trilo_xdata_flist_reverse_forward(TriloForwardList* flist);

/**
 * @brief Reverses the TriloForwardList in the backward direction.
 *
 * @param flist The TriloForwardList to be reversed.
 */
void trilo_xdata_flist_reverse_backward(TriloForwardList* flist);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloForwardList.
 *
 * @param flist The TriloForwardList for which the size will be determined.
 * @return The size of the TriloForwardList.
 */
size_t trilo_xdata_flist_size(const TriloForwardList* flist);

/**
 * @brief Getter function to retrieve a TriloTofu data element from the TriloForwardList.
 *
 * @param flist The TriloForwardList from which the data will be retrieved.
 * @param data  The TriloTofu data element to retrieve.
 * @return A pointer to the TriloTofu data element in the TriloForwardList (or NULL if not found).
 */
TriloTofu* trilo_xdata_flist_getter(TriloForwardList* flist, TriloTofu data);

/**
 * @brief Setter function to update a TriloTofu data element in the TriloForwardList.
 *
 * @param flist The TriloForwardList in which the data will be updated.
 * @param data  The TriloTofu data element to update.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_flist_setter(TriloForwardList* flist, TriloTofu data);

/**
 * @brief Checks if the TriloForwardList is not empty.
 *
 * @param flist The TriloForwardList to check.
 * @return true if the TriloForwardList is not empty, false otherwise.
 */
bool trilo_xdata_flist_not_empty(const TriloForwardList* flist);

/**
 * @brief Checks if the TriloForwardList is not a null pointer.
 *
 * @param flist The TriloForwardList to check.
 * @return true if the TriloForwardList is not a null pointer, false otherwise.
 */
bool trilo_xdata_flist_not_nullptr(const TriloForwardList* flist);

/**
 * @brief Checks if the TriloForwardList is empty.
 *
 * @param flist The TriloForwardList to check.
 * @return true if the TriloForwardList is empty, false otherwise.
 */
bool trilo_xdata_flist_is_empty(const TriloForwardList* flist);

/**
 * @brief Checks if the TriloForwardList is a null pointer.
 *
 * @param flist The TriloForwardList to check.
 * @return true if the TriloForwardList is a null pointer, false otherwise.
 */
bool trilo_xdata_flist_is_nullptr(const TriloForwardList* flist);

#ifdef __cplusplus
}
#endif

#endif
