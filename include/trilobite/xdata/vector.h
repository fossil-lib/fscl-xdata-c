/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_VECTOR_H
#define TRILOBITE_XDATA_VECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Define error constants for tuple operations
enum {
    TRILO_XDATA_VECTOR_TYPE_MISMATCH = -1,
    TRILO_XDATA_VECTOR_OUT_OF_RANGE  = -2
};

// Vector structure
typedef struct TriloVector {
    TriloTofu* data;
    enum DataType vector_type; // Type of the vector
    size_t size;
    size_t capacity;
} TriloVector;

// Function to create a new TriloVector with a specified data type
TriloVector* trilo_xdata_vector_create(enum DataType vector_type);

// Function to destroy the TriloVector
void trilo_xdata_vector_destroy(TriloVector* vector);

// Function to insert a TriloTofu data into the vector
void trilo_xdata_vector_insert(TriloVector* vector, TriloTofu data);

// Function to retrieve a TriloTofu data from the vector by index
TriloTofu trilo_xdata_vector_get(const TriloVector* vector, size_t index);

// Function to check if the vector is empty
bool trilo_xdata_vector_is_empty(const TriloVector* vector);

// Function to get the size (number of elements) of the vector
size_t trilo_xdata_vector_size(const TriloVector* vector);

// Function to get the capacity (maximum elements) of the vector
size_t trilo_xdata_vector_capacity(const TriloVector* vector);

// Function to print the elements in the vector
void trilo_xdata_vector_print(const TriloVector* vector);

#ifdef __cplusplus
}
#endif

#endif
