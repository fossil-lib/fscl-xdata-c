/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_SET_H
#define TRILOBITE_XDATA_SET_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

enum {
    TRILO_XDATA_SET_TYPE_MISMATCH = -1,
    TRILO_XDATA_SET_OUT_OF_RANGE  = -2
};

// Node structure for the set
typedef struct TriloSetNode {
    TriloTofu data;
    struct TriloSetNode* next;
} TriloSetNode;

// Set structure
typedef struct TriloSet {
    TriloSetNode* head;
    enum DataType set_type;  // Type of the set
} TriloSet;

// Function to create a new TriloSet
TriloSet* trilo_xdata_set_create(enum DataType set_type);

// Function to destroy the TriloSet
void trilo_xdata_set_destroy(TriloSet* set);

// Function to check if the set is empty
bool trilo_xdata_set_is_empty(const TriloSet* set);

// Function to insert a TriloTofu data into the set
void trilo_xdata_set_insert(TriloSet* set, TriloTofu data);

// Function to remove a TriloTofu data from the set
void trilo_xdata_set_remove(TriloSet* set, TriloTofu data);

// Function to check if a TriloTofu data is in the set
bool trilo_xdata_set_contains(const TriloSet* set, TriloTofu data);

// Function to print the elements in the set
void trilo_xdata_set_print(const TriloSet* set);

#ifdef __cplusplus
}
#endif

#endif
