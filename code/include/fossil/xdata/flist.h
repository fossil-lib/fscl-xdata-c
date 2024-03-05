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
#ifndef fscl_flist_H
#define fscl_flist_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu/core.h"

// Node structure for the linked list
typedef struct cflist_node {
    ctofu data;
    struct cflist_node* next;
} cflist_node;

// Linked list structure
typedef struct cflist {
    cflist_node* head;
    ctofu_type list_type;  // Type of the linked list
} cflist;

// =======================
// CREATE and DELETE
// =======================
cflist* fscl_flist_create(ctofu_type list_type);
void fscl_flist_erase(cflist* flist);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_flist_insert(cflist* flist, ctofu data);
ctofu_error fscl_flist_remove(cflist* flist, ctofu* data);
ctofu_error fscl_flist_search(const cflist* flist, ctofu data);
void fscl_flist_reverse_forward(cflist* flist);
void fscl_flist_reverse_backward(cflist* flist);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_flist_size(const cflist* flist);
ctofu* fscl_flist_getter(cflist* flist, ctofu data);
ctofu_error fscl_flist_setter(cflist* flist, ctofu data);
bool fscl_flist_not_empty(const cflist* flist);
bool fscl_flist_not_cnullptr(const cflist* flist);
bool fscl_flist_is_empty(const cflist* flist);
bool fscl_flist_is_cnullptr(const cflist* flist);

#ifdef __cplusplus
}
#endif

#endif
