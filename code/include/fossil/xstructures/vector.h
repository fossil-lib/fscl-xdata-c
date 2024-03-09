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

#include "fossil/xtofu.h"

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

/**
 * Create a new vector with the specified expected type.
 *
 * @param expected_type The expected type of elements in the vector.
 * @return              The created vector.
 */
cvector fscl_vector_create(ctofu_type expected_type);

/**
 * Erase the contents of the vector and free allocated memory.
 *
 * @param vector The vector to erase.
 */
void fscl_vector_erase(cvector* vector);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Add an element to the end of the vector.
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
void fscl_vector_push_back(cvector* vector, ctofu element);

/**
 * Search for a target element in the vector.
 *
 * @param vector The vector to search.
 * @param target The element to search for.
 * @return       The index of the target element, or -1 if not found.
 */
int fscl_vector_search(const cvector* vector, ctofu target);

/**
 * Reverse the order of elements in the vector.
 *
 * @param vector The vector to reverse.
 */
void fscl_vector_reverse(cvector* vector);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Check if the vector is a null pointer.
 *
 * @param vector The vector to check.
 * @return       True if the vector is a null pointer, false otherwise.
 */
bool fscl_vector_is_cnullptr(const cvector* vector);

/**
 * Check if the vector is not a null pointer.
 *
 * @param vector The vector to check.
 * @return       True if the vector is not a null pointer, false otherwise.
 */
bool fscl_vector_not_cnullptr(const cvector* vector);

/**
 * Check if the vector is empty.
 *
 * @param vector The vector to check.
 * @return       True if the vector is empty, false otherwise.
 */
bool fscl_vector_is_empty(const cvector* vector);

/**
 * Check if the vector is not empty.
 *
 * @param vector The vector to check.
 * @return       True if the vector is not empty, false otherwise.
 */
bool fscl_vector_not_empty(const cvector* vector);

/**
 * Set the element at the specified index in the vector.
 *
 * @param vector The vector in which to set the element.
 * @param index  The index at which to set the element.
 * @param element The element to set.
 */
void fscl_vector_setter(cvector* vector, size_t index, ctofu element);

/**
 * Get the element at the specified index in the vector.
 *
 * @param vector The vector from which to get the element.
 * @param index  The index from which to get the element.
 * @return       The element at the specified index.
 */
ctofu fscl_vector_getter(const cvector* vector, size_t index);

/**
 * Get the size of the vector.
 *
 * @param vector The vector for which to get the size.
 * @return       The size of the vector.
 */
size_t fscl_vector_size(const cvector* vector);

/**
 * Display the contents of the vector.
 *
 * @param vector The vector to peek into.
 */
void fscl_vector_peek(const cvector* vector);

#ifdef __cplusplus
}
#endif

#endif
