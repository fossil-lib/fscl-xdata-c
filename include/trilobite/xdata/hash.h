/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_HASH_H
#define TRILOBITE_XDATA_HASH_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Define error constants for tuple operations
enum {
    TRILO_XDATA_HASH_TYPE_MISMATCH = -1,
    TRILO_XDATA_HASH_OUT_OF_RANGE  = -2
};

// Node structure for the hash table
typedef struct TriloHashNode {
    char* key;
    TriloTofu data;
    struct TriloHashNode* next;
} TriloHashNode;

// Hash table structure
typedef struct TriloHash {
    TriloHashNode** table;
    int size; // Number of buckets
    enum DataType hash_type; // Type of the hash table
} TriloHash;

// Function to create a new TriloHash
TriloHash* trilo_xdata_hash_create(enum DataType hash_type, int size);

// Function to destroy the TriloHash
void trilo_xdata_hash_destroy(TriloHash* hash);

// Function to compute the hash value for a given key
unsigned int trilo_xdata_hash_function(const char* key, int size);

// Function to insert a TriloTofu data into the hash table
void trilo_xdata_hash_insert(TriloHash* hash, const char* key, TriloTofu data);

// Function to remove a TriloTofu data from the hash table
void trilo_xdata_hash_remove(TriloHash* hash, const char* key);

// Function to get a TriloTofu data from the hash table by key
TriloTofu trilo_xdata_hash_get(TriloHash* hash, const char* key);

// Function to check if a key exists in the hash table
bool trilo_xdata_hash_contains_key(TriloHash* hash, const char* key);

// Function to print the elements in the hash table
void trilo_xdata_hash_print(TriloHash* hash);

#ifdef __cplusplus
}
#endif

#endif
