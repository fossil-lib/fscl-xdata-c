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

#include "xdata/tofu.h"

// Stack structure
typedef struct TriloStackNode {
    TriloTofu data; // Data stored in the stack node
    struct TriloStackNode* next; // Pointer to the next node
} TriloStackNode;

typedef struct TriloStack {
    enum DataType stack_type; // Type of the stack
    TriloStackNode* top; // Pointer to the top node of the stack
} TriloStack;

// Function to create a new TriloStack with a specified data type
TriloStack* trilo_xdata_stack_create(enum DataType stack_type);

// Function to destroy the TriloStack
void trilo_xdata_stack_destroy(TriloStack* stack);

// Function to push an element onto the stack
void trilo_xdata_stack_push(TriloStack* stack, TriloTofu data);

// Function to pop an element from the stack
TriloTofu trilo_xdata_stack_pop(TriloStack* stack);

// Function to peek at the top element of the stack without removing it
TriloTofu trilo_xdata_stack_peek(const TriloStack* stack);

// Function to check if the stack is empty
bool trilo_xdata_stack_is_empty(const TriloStack* stack);

// Function to get the number of elements in the stack
size_t trilo_xdata_stack_size(const TriloStack* stack);

#ifdef __cplusplus
}
#endif

#endif
