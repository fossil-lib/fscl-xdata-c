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
#ifndef fscl_map_H
#define fscl_map_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xdata/tofu.h"

// Define a maximum number of key-value pairs that can be stored in the map
#define MAX_MAP_SIZE 100

// Define a structure to represent a cmap
typedef struct {
    ctofu keys[MAX_MAP_SIZE];
    ctofu values[MAX_MAP_SIZE];
    size_t size;
} cmap;

// =======================
// CREATE and DELETE
// =======================
cmap* fscl_map_create(ctofu_type list_type);
void fscl_map_erase(cmap* map);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_map_insert(cmap* map, ctofu key, ctofu value);
ctofu_error fscl_map_remove(cmap* map, ctofu key);
ctofu_error fscl_map_search(cmap* map, ctofu key);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_map_size(cmap* map);
ctofu_error fscl_map_getter(cmap* map, ctofu key, ctofu* value);
ctofu_error fscl_map_setter(cmap* map, ctofu key, ctofu value);
bool fscl_map_not_empty(cmap* map);
bool fscl_map_not_cnullptr(cmap* map);
bool fscl_map_is_empty(cmap* map);
bool fscl_map_is_cnullptr(cmap* map);
bool fscl_map_contains(cmap* map, ctofu key);

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator fscl_map_iterator_start(cmap* map);
ctofu_iterator fscl_map_iterator_end(cmap* map);
ctofu_iterator fscl_map_iterator_next(ctofu_iterator iterator);
bool fscl_map_iterator_has_next(ctofu_iterator iterator);

#ifdef __cplusplus
}
#endif

#endif
