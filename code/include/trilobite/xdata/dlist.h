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
#ifndef TSCL_DLIST_H
#define TSCL_DLIST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the doubly linked list
typedef struct cdlist_node {
    ctofu data;
    struct cdlist_node* prev;
    struct cdlist_node* next;
} cdlist_node;

// Doubly linked list structure
typedef struct cdlist {
    cdlist_node* head;
    cdlist_node* tail;
    ctofu_type list_type;  // Type of the linked list
} cdlist;

// =======================
// CREATE and DELETE
// =======================
cdlist* tscl_dlist_create(ctofu_type list_type);
void tscl_dlist_erase(cdlist* dlist);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error tscl_dlist_insert(cdlist* dlist, ctofu data);
ctofu_error tscl_dlist_remove(cdlist* dlist, ctofu* data);
ctofu_error tscl_dlist_search(const cdlist* dlist, ctofu data);
void tscl_dlist_reverse_forward(cdlist* dlist);
void tscl_dlist_reverse_backward(cdlist* dlist);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t tscl_dlist_size(const cdlist* dlist);
ctofu* tscl_dlist_getter(cdlist* dlist, ctofu data);
ctofu_error tscl_dlist_setter(cdlist* dlist, ctofu data);
bool tscl_dlist_not_empty(const cdlist* dlist);
bool tscl_dlist_not_cnullptr(const cdlist* dlist);
bool tscl_dlist_is_empty(const cdlist* dlist);
bool tscl_dlist_is_cnullptr(const cdlist* dlist);

#ifdef __cplusplus
}
#endif

#endif
