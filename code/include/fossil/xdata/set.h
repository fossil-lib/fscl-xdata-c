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
#ifndef fscl_set_H
#define fscl_set_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xdata/tofu.h"

// Node structure for the set
typedef struct cset_node {
    ctofu data;
    struct cset_node* next;
} cset_node;

// Set structure
typedef struct cset {
    cset_node* head;
    ctofu_type set_type;  // Type of the set
} cset;

// =======================
// CREATE and DELETE
// =======================
cset* fscl_set_create(ctofu_type list_type);
void fscl_set_erase(cset* set);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_set_insert(cset* set, ctofu data);
ctofu_error fscl_set_remove(cset* set, ctofu data);
ctofu_error fscl_set_search(const cset* set, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_set_size(const cset* set);
ctofu* fscl_set_getter(cset* set, ctofu data);
ctofu_error fscl_set_setter(cset* set, ctofu data);
bool fscl_set_not_empty(const cset* set);
bool fscl_set_not_cnullptr(const cset* set);
bool fscl_set_is_empty(const cset* set);
bool fscl_set_is_cnullptr(const cset* set);
bool fscl_set_contains(const cset* set, ctofu data);

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator fscl_set_iterator_start(cset* set);
ctofu_iterator fscl_set_iterator_end(void);
ctofu_iterator fscl_set_iterator_next(ctofu_iterator iterator);
bool fscl_set_iterator_has_next(ctofu_iterator iterator);

#ifdef __cplusplus
}
#endif

#endif
