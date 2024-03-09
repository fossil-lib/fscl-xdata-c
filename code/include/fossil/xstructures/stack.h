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
#ifndef fscl_stack_H
#define fscl_stack_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

// Stack structure
typedef struct cstack_node {
    ctofu data; // Data stored in the stack node
    struct cstack_node* next; // Pointer to the next node
} cstack_node;

typedef struct cstack {
    ctofu_type stack_type; // Type of the stack
    cstack_node* top; // Pointer to the top node of the stack
} cstack;

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new stack with the specified data type.
 *
 * @param list_type The type of data the stack will store.
 * @return          The created stack.
 */
cstack* fscl_stack_create(ctofu_type list_type);

/**
 * Erase the contents of the stack and free allocated memory.
 *
 * @param stack The stack to erase.
 */
void fscl_stack_erase(cstack* stack);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the stack.
 *
 * @param stack The stack to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_stack_insert(cstack* stack, ctofu data);

/**
 * Remove data from the stack.
 *
 * @param stack       The stack to remove data from.
 * @param[out] data   A pointer to store the removed data.
 * @return            The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_stack_remove(cstack* stack, ctofu* data);

/**
 * Search for data in the stack.
 *
 * @param stack The stack to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_stack_search(const cstack* stack, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the stack.
 *
 * @param stack The stack for which to get the size.
 * @return      The size of the stack.
 */
size_t fscl_stack_size(const cstack* stack);

/**
 * Get the data from the stack matching the specified data.
 *
 * @param stack The stack from which to get the data.
 * @param data  The data to search for.
 * @return      A pointer to the matching data, or NULL if not found.
 */
ctofu* fscl_stack_getter(cstack* stack, ctofu data);

/**
 * Set data in the stack.
 *
 * @param stack The stack in which to set the data.
 * @param data  The data to set.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_stack_setter(cstack* stack, ctofu data);

/**
 * Check if the stack is not empty.
 *
 * @param stack The stack to check.
 * @return      True if the stack is not empty, false otherwise.
 */
bool fscl_stack_not_empty(const cstack* stack);

/**
 * Check if the stack is not a null pointer.
 *
 * @param stack The stack to check.
 * @return      True if the stack is not a null pointer, false otherwise.
 */
bool fscl_stack_not_cnullptr(const cstack* stack);

/**
 * Check if the stack is empty.
 *
 * @param stack The stack to check.
 * @return      True if the stack is empty, false otherwise.
 */
bool fscl_stack_is_empty(const cstack* stack);

/**
 * Check if the stack is a null pointer.
 *
 * @param stack The stack to check.
 * @return      True if the stack is a null pointer, false otherwise.
 */
bool fscl_stack_is_cnullptr(const cstack* stack);

/**
 * Get the top element of the stack.
 *
 * @param stack         The stack to get the top element from.
 * @param default_value The default value to return if the stack is empty.
 * @return              The top element of the stack or the default value if the stack is empty.
 */
ctofu fscl_stack_top(cstack* stack, ctofu default_value);

#ifdef __cplusplus
}
#endif

#endif
