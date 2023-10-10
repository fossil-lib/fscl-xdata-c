/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_STACK_H
#define TRILOBITE_XDATA_STACK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Stack structure
typedef struct TriloStackNode {
    TriloTofu data; // Data stored in the stack node
    struct TriloStackNode* next; // Pointer to the next node
} TriloStackNode;

typedef struct TriloStack {
    enum DataType stack_type; // Type of the stack
    TriloStackNode* top; // Pointer to the top node of the stack
} TriloStack;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloStack instance with the specified list type.
 *
 * @param list_type The data type for the TriloStack (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloStack instance.
 */
TriloStack* trilo_xdata_stack_create(enum DataType list_type);

/**
 * @brief Destroys the TriloStack instance, freeing all associated memory.
 *
 * @param stack The TriloStack instance to be destroyed.
 */
void trilo_xdata_stack_destroy(TriloStack* stack);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a TriloTofu data element into the TriloStack.
 *
 * @param stack The TriloStack where the data will be inserted.
 * @param data  The TriloTofu data element to be inserted.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_stack_insert(TriloStack* stack, TriloTofu data);

/**
 * @brief Removes a TriloTofu data element from the TriloStack.
 *
 * @param stack The TriloStack from which the data will be removed.
 * @param data  The TriloTofu data element to be removed.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_stack_remove(TriloStack* stack, TriloTofu data);

/**
 * @brief Searches for a TriloTofu data element in the TriloStack.
 *
 * @param stack The TriloStack to search within.
 * @param data  The TriloTofu data element to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_stack_search(const TriloStack* stack, TriloTofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloStack.
 *
 * @param stack The TriloStack for which the size will be determined.
 * @return The size of the TriloStack.
 */
size_t trilo_xdata_stack_size(const TriloStack* stack);

/**
 * @brief Getter function to retrieve a TriloTofu data element from the TriloStack.
 *
 * @param stack The TriloStack from which the data will be retrieved.
 * @param data  The TriloTofu data element to retrieve.
 * @return A pointer to the TriloTofu data element in the TriloStack (or NULL if not found).
 */
TriloTofu* trilo_xdata_stack_getter(TriloStack* stack, TriloTofu data);

/**
 * @brief Setter function to update a TriloTofu data element in the TriloStack.
 *
 * @param stack The TriloStack in which the data will be updated.
 * @param data  The TriloTofu data element to update.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_stack_setter(TriloStack* stack, TriloTofu data);

/**
 * @brief Checks if the TriloStack is not empty.
 *
 * @param stack The TriloStack to check.
 * @return true if the TriloStack is not empty, false otherwise.
 */
bool trilo_xdata_stack_not_empty(const TriloStack* stack);

/**
 * @brief Checks if the TriloStack is not a null pointer.
 *
 * @param stack The TriloStack to check.
 * @return true if the TriloStack is not a null pointer, false otherwise.
 */
bool trilo_xdata_stack_not_nullptr(const TriloStack* stack);

/**
 * @brief Checks if the TriloStack is empty.
 *
 * @param stack The TriloStack to check.
 * @return true if the TriloStack is empty, false otherwise.
 */
bool trilo_xdata_stack_is_empty(const TriloStack* stack);

/**
 * @brief Checks if the TriloStack is a null pointer.
 *
 * @param stack The TriloStack to check.
 * @return true if the TriloStack is a null pointer, false otherwise.
 */
bool trilo_xdata_stack_is_nullptr(const TriloStack* stack);

/**
 * @brief Gets the top element of the stack without removing it.
 *
 * This function returns a copy of the top element of the stack without removing it.
 *
 * @param stack The TriloStack instance to get the top element from.
 * @return A copy of the top element of the stack.
 */
TriloTofu trilo_xdata_stack_top(TriloStack* stack);

#ifdef __cplusplus
}
#endif

#endif
