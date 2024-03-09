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
#ifndef fscl_dqueue_H
#define fscl_dqueue_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

// Node structure for the double-ended queue
typedef struct cdqueue_node {
    ctofu data;
    struct cdqueue_node* prev;
    struct cdqueue_node* next;
} cdqueue_node;

// Double-ended queue structure
typedef struct cdqueue {
    cdqueue_node* front;
    cdqueue_node* rear;
    ctofu_type list_type;  // Type of the deque
} cdqueue;

// =======================
// CREATE and DELETE
// =======================
cdqueue* fscl_dqueue_create(ctofu_type list_type);
void fscl_dqueue_erase(cdqueue* dqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_dqueue_insert(cdqueue* dqueue, ctofu data);
ctofu_error fscl_dqueue_remove(cdqueue* dqueue, ctofu* data);
ctofu_error fscl_dqueue_search(const cdqueue* dqueue, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_dqueue_size(const cdqueue* dqueue);
ctofu* fscl_dqueue_getter(cdqueue* dqueue, ctofu data);
ctofu_error fscl_dqueue_setter(cdqueue* dqueue, ctofu data);
bool fscl_dqueue_not_empty(const cdqueue* dqueue);
bool fscl_dqueue_not_cnullptr(const cdqueue* dqueue);
bool fscl_dqueue_is_empty(const cdqueue* dqueue);
bool fscl_dqueue_is_cnullptr(const cdqueue* dqueue);

#ifdef __cplusplus
}
#endif

#endif
