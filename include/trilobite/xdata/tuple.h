/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_TUPLE_H
#define TRILOBITE_XDATA_TUPLE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Tuple structure
typedef struct TriloTuple {
    TriloTofu* elements;
    enum DataType* tuple_types; // Array of data types for each element
    size_t size;
} TriloTuple;

// Function to create a new TriloTuple with specified data types
TriloTuple* trilo_xdata_tuple_create(enum DataType* tuple_types, size_t size);

// Function to destroy the TriloTuple
void trilo_xdata_tuple_destroy(TriloTuple* tuple);

// Function to get a TriloTofu element from the tuple by index
TriloTofu trilo_xdata_tuple_get(const TriloTuple* tuple, size_t index);

// Function to set a TriloTofu element into the tuple at the specified index
void trilo_xdata_tuple_set(TriloTuple* tuple, size_t index, TriloTofu data);

// Function to check if the tuple is empty
bool trilo_xdata_tuple_is_empty(const TriloTuple* tuple);

// Function to get the size (number of elements) of the tuple
size_t trilo_xdata_tuple_size(const TriloTuple* tuple);

// Function to print the elements in the tuple
void trilo_xdata_tuple_print(const TriloTuple* tuple);

#ifdef __cplusplus
}
#endif

#endif
