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

#include "fossil/xtofu/core.h"

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
cstack* fscl_stack_create(ctofu_type list_type);
void fscl_stack_erase(cstack* stack);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_stack_insert(cstack* stack, ctofu data);
ctofu_error fscl_stack_remove(cstack* stack, ctofu* data);
ctofu_error fscl_stack_search(const cstack* stack, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_stack_size(const cstack* stack);
ctofu* fscl_stack_getter(cstack* stack, ctofu data);
ctofu_error fscl_stack_setter(cstack* stack, ctofu data);
bool fscl_stack_not_empty(const cstack* stack);
bool fscl_stack_not_cnullptr(const cstack* stack);
bool fscl_stack_is_empty(const cstack* stack);
bool fscl_stack_is_cnullptr(const cstack* stack);
ctofu fscl_stack_top(cstack* stack, ctofu default_value);

#ifdef __cplusplus
}
#endif

#endif
