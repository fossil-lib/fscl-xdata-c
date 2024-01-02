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
#ifndef fscl_vector_H
#define fscl_vector_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xdata/tofu.h"

#define INITIAL_CAPACITY 10

typedef struct {
    ctofu* data;
    size_t size;
    size_t capacity;
    ctofu_type expected_type;
} cvector;

// =======================
// CREATE and DELETE
// =======================
cvector fscl_vector_create(ctofu_type expected_type);
void fscl_vector_erase(cvector* vector);

// =======================
// ALGORITHM FUNCTIONS
// =======================
void fscl_vector_push_back(cvector* vector, ctofu element);
int fscl_vector_search(const cvector* vector, ctofu target);
void fscl_vector_reverse(cvector* vector);

// =======================
// UTILITY FUNCTIONS
// =======================
bool fscl_vector_is_cnullptr(const cvector* vector);
bool fscl_vector_not_cnullptr(const cvector* vector);
bool fscl_vector_is_empty(const cvector* vector);
bool fscl_vector_not_empty(const cvector* vector);
void fscl_vector_setter(cvector* vector, size_t index, ctofu element);
ctofu fscl_vector_getter(const cvector* vector, size_t index);
size_t fscl_vector_size(const cvector* vector);
void fscl_vector_peek(const cvector* vector);

#ifdef __cplusplus
}
#endif

#endif
