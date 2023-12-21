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
#ifndef TSCL_FLIST_H
#define TSCL_FLIST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the linked list
typedef struct cflist_node {
    ctofu data;
    struct cflist_node* next;
} cflist_node;

// Linked list structure
typedef struct cflist {
    cflist_node* head;
    ctofu_type list_type;  // Type of the linked list
} cflist;

// =======================
// CREATE and DELETE
// =======================
cflist* flist_create(ctofu_type list_type);
void flist_erase(cflist* flist);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error flist_insert(cflist* flist, ctofu data);
ctofu_error flist_remove(cflist* flist, ctofu* data);
ctofu_error flist_search(const cflist* flist, ctofu data);
void flist_reverse_forward(cflist* flist);
void flist_reverse_backward(cflist* flist);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t flist_size(const cflist* flist);
ctofu* flist_getter(cflist* flist, ctofu data);
ctofu_error flist_setter(cflist* flist, ctofu data);
bool flist_not_empty(const cflist* flist);
bool flist_not_cnullptr(const cflist* flist);
bool flist_is_empty(const cflist* flist);
bool flist_is_cnullptr(const cflist* flist);

#ifdef __cplusplus
}
#endif

#endif
