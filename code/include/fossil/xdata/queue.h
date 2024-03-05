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
#ifndef fscl_queue_H
#define fscl_queue_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu/core.h"

// Node structure for the queue
typedef struct cqueue_node {
    ctofu data;
    struct cqueue_node* next;
} cqueue_node;

// Queue structure
typedef struct cqueue {
    cqueue_node* front;
    cqueue_node* rear;
    ctofu_type queue_type;  // Type of the queue
} cqueue;

// =======================
// CREATE and DELETE
// =======================
cqueue* fscl_queue_create(ctofu_type list_type);
void fscl_queue_erase(cqueue* queue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_queue_insert(cqueue* queue, ctofu data);
ctofu_error fscl_queue_remove(cqueue* queue, ctofu* data);
ctofu_error fscl_queue_search(const cqueue* queue, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_queue_size(const cqueue* queue);
ctofu* fscl_queue_getter(cqueue* queue, ctofu data);
ctofu_error fscl_queue_setter(cqueue* queue, ctofu data);
bool fscl_queue_not_empty(const cqueue* queue);
bool fscl_queue_not_cnullptr(const cqueue* queue);
bool fscl_queue_is_empty(const cqueue* queue);
bool fscl_queue_is_cnullptr(const cqueue* queue);

#ifdef __cplusplus
}
#endif

#endif
