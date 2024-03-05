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

#include "fossil/xtofu/core.h"

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
cpqueue* fscl_pqueue_create(ctofu_type queue_type);
void fscl_pqueue_erase(cpqueue* pqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_pqueue_insert(cpqueue* pqueue, ctofu data, int priority);
ctofu_error fscl_pqueue_remove(cpqueue* pqueue, ctofu* data, int* priority);
ctofu_error fscl_pqueue_search(const cpqueue* pqueue, ctofu data, int priority);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_pqueue_size(const cpqueue* pqueue);
ctofu* fscl_pqueue_getter(cpqueue* pqueue, ctofu data, int priority);
ctofu_error fscl_pqueue_setter(cpqueue* pqueue, ctofu data, int priority);
bool fscl_pqueue_not_empty(const cpqueue* pqueue);
bool fscl_pqueue_not_cnullptr(const cpqueue* pqueue);
bool fscl_pqueue_is_empty(const cpqueue* pqueue);
bool fscl_pqueue_is_cnullptr(const cpqueue* pqueue);

#ifdef __cplusplus
}
#endif

#endif
