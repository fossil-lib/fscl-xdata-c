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
#ifndef fscl_dlist_H
#define fscl_dlist_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

// Node structure for the doubly linked list
typedef struct cdlist_node {
    ctofu data;
    struct cdlist_node* prev;
    struct cdlist_node* next;
} cdlist_node;

// Doubly linked list structure
typedef struct cdlist {
    cdlist_node* head;
    cdlist_node* tail;
    ctofu_type list_type;  // Type of the linked list
} cdlist;

// =======================
// CREATE and DELETE
// =======================
cdlist* fscl_dlist_create(ctofu_type list_type);
void fscl_dlist_erase(cdlist* dlist);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_dlist_insert(cdlist* dlist, ctofu data);
ctofu_error fscl_dlist_remove(cdlist* dlist, ctofu* data);
ctofu_error fscl_dlist_search(const cdlist* dlist, ctofu data);
void fscl_dlist_reverse_forward(cdlist* dlist);
void fscl_dlist_reverse_backward(cdlist* dlist);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_dlist_size(const cdlist* dlist);
ctofu* fscl_dlist_getter(cdlist* dlist, ctofu data);
ctofu_error fscl_dlist_setter(cdlist* dlist, ctofu data);
bool fscl_dlist_not_empty(const cdlist* dlist);
bool fscl_dlist_not_cnullptr(const cdlist* dlist);
bool fscl_dlist_is_empty(const cdlist* dlist);
bool fscl_dlist_is_cnullptr(const cdlist* dlist);

#ifdef __cplusplus
}
#endif

#endif
