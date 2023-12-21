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
#ifndef TSCL_SET_H
#define TSCL_SET_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the set
typedef struct cset_node {
    ctofu data;
    struct cset_node* next;
} cset_node;

// Set structure
typedef struct cset {
    cset_node* head;
    ctofu_type set_type;  // Type of the set
} cset;

// =======================
// CREATE and DELETE
// =======================
cset* tscl_set_create(ctofu_type list_type);
void tscl_set_erase(cset* set);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error tscl_set_insert(cset* set, ctofu data);
ctofu_error tscl_set_remove(cset* set, ctofu data);
ctofu_error tscl_set_search(const cset* set, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t tscl_set_size(const cset* set);
ctofu* tscl_set_getter(cset* set, ctofu data);
ctofu_error tscl_set_setter(cset* set, ctofu data);
bool tscl_set_not_empty(const cset* set);
bool tscl_set_not_cnullptr(const cset* set);
bool tscl_set_is_empty(const cset* set);
bool tscl_set_is_cnullptr(const cset* set);
bool tscl_set_contains(const cset* set, ctofu data);

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator tscl_set_iterator_start(cset* set);
ctofu_iterator tscl_set_iterator_end(void);
ctofu_iterator tscl_set_iterator_next(ctofu_iterator iterator);
bool tscl_set_iterator_has_next(ctofu_iterator iterator);

#ifdef __cplusplus
}
#endif

#endif
