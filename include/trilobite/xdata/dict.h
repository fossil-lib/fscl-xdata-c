/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_DICT_H
#define TRILOBITE_XDATA_DICT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Define error constants for tuple operations
enum {
    TRILO_XDATA_DICT_TYPE_MISMATCH = -1,
    TRILO_XDATA_DICT_OUT_OF_RANGE  = -2
};

// Dictionary structure
typedef struct TriloDictNode {
    char key[50]; // Key as a string (max length 50)
    TriloTofu value; // Value associated with the key
    struct TriloDictNode* next; // Pointer to the next node
} TriloDictNode;

typedef struct TriloDict {
    TriloDictNode** table; // Array of pointers to nodes
    enum DataType dict_type; // Type of the dictionary values
    size_t size; // Number of elements in the dictionary
    size_t capacity; // Capacity of the hash table
} TriloDict;

// Function to create a new TriloDict with specified data type
TriloDict* trilo_xdata_dict_create(enum DataType dict_type, size_t capacity);

// Function to destroy the TriloDict
void trilo_xdata_dict_destroy(TriloDict* dict);

// Function to insert a key-value pair into the dictionary
void trilo_xdata_dict_insert(TriloDict* dict, const char* key, TriloTofu value);

// Function to retrieve a value by key from the dictionary
TriloTofu trilo_xdata_dict_get(const TriloDict* dict, const char* key);

// Function to check if a key exists in the dictionary
bool trilo_xdata_dict_contains(const TriloDict* dict, const char* key);

// Function to remove a key-value pair from the dictionary
void trilo_xdata_dict_remove(TriloDict* dict, const char* key);

// Function to get the number of elements in the dictionary
size_t trilo_xdata_dict_size(const TriloDict* dict);

// Function to print the key-value pairs in the dictionary
void trilo_xdata_dict_print(const TriloDict* dict);

#ifdef __cplusplus
}
#endif

#endif
