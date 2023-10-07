/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_ARRAY_H
#define TRILOBITE_XDATA_ARRAY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Define error constants for tuple operations
enum {
    TRILO_XDATA_ARRAY_TYPE_MISMATCH = -1,
    TRILO_XDATA_ARRAY_OUT_OF_RANGE  = -2
};

// Structure for the array-based list
typedef struct TriloArray {
    TriloTofu* data;
    size_t capacity;
    size_t size;
    enum DataType list_type;  // Type of the list
} TriloArray;

// Function to create a new TriloArray
TriloArray* trilo_xdata_array_create(enum DataType list_type, size_t initial_capacity);

// Function to destroy the TriloArray
void trilo_xdata_array_destroy(TriloArray* list);

// Function to check if the list is empty
bool trilo_xdata_array_is_empty(const TriloArray* list);

// Function to insert a TriloTofu data at the end of the list
void trilo_xdata_array_insert(TriloArray* list, TriloTofu data);

// Function to remove the first occurrence of a TriloTofu data from the list
void trilo_xdata_array_remove(TriloArray* list, TriloTofu data);

// Function to print the data in the list
void trilo_xdata_array_print(const TriloArray* list);

#ifdef __cplusplus
}
#endif

#endif
