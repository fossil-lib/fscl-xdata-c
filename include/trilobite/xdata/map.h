/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_MAP_H
#define TRILOBITE_XDATA_MAP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Structure for the map
typedef struct TriloMapNode {
    char key[50];
    TriloTofu value;
    struct TriloMapNode* next;
} TriloMapNode;

// Map structure
typedef struct TriloMap {
    TriloMapNode* head;
    enum DataType map_type;  // Type of the map
} TriloMap;

// Function to create a new TriloMap
TriloMap* trilo_xdata_map_create(enum DataType map_type);

// Function to destroy the TriloMap
void trilo_xdata_map_destroy(TriloMap* map);

// Function to check if the map is empty
bool trilo_xdata_map_is_empty(const TriloMap* map);

// Function to insert a key-value pair into the map
void trilo_xdata_map_insert(TriloMap* map, const char* key, TriloTofu value);

// Function to remove a key-value pair from the map by key
void trilo_xdata_map_remove(TriloMap* map, const char* key);

// Function to retrieve a value from the map by key
TriloTofu trilo_xdata_map_get(const TriloMap* map, const char* key);

// Function to check if a key exists in the map
bool trilo_xdata_map_contains_key(const TriloMap* map, const char* key);

// Function to print the key-value pairs in the map
void trilo_xdata_map_print(const TriloMap* map);

#ifdef __cplusplus
}
#endif

#endif
