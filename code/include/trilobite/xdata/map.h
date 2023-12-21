/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TSCL_MAP_H
#define TSCL_MAP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

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
cmap* map_create(ctofu_type list_type);
void map_erase(cmap* map);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error map_insert(cmap* map, ctofu key, ctofu value);
ctofu_error map_remove(cmap* map, ctofu key);
ctofu_error map_search(const cmap* map, ctofu key);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t map_size(const cmap* map);
ctofu_error map_getter(cmap* map, ctofu key, ctofu* value);
ctofu_error map_setter(cmap* map, ctofu key, ctofu value);
bool map_not_empty(const cmap* map);
bool map_not_cnullptr(const cmap* map);
bool map_is_empty(const cmap* map);
bool map_is_cnullptr(const cmap* map);
bool map_contains(const cmap* map, ctofu key);

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator map_iterator_start(cmap* map);
ctofu_iterator map_iterator_end(cmap* map);
ctofu_iterator map_iterator_next(ctofu_iterator iterator);
bool map_iterator_has_next(ctofu_iterator iterator);

#ifdef __cplusplus
}
#endif

#endif
