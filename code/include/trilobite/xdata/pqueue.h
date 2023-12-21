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
#ifndef TSCL_PQUEUE_H
#define TSCL_PQUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

typedef struct cpqueue_node {
    ctofu data;
    int priority;
    struct cpqueue_node* next;
} cpqueue_node;

typedef struct cpqueue {
    cpqueue_node* front;
    ctofu_type queue_type;
} cpqueue;

// =======================
// CREATE and DELETE
// =======================
cpqueue* tscl_pqueue_create(ctofu_type queue_type);
void tscl_pqueue_erase(cpqueue* pqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error tscl_pqueue_insert(cpqueue* pqueue, ctofu data, int priority);
ctofu_error tscl_pqueue_remove(cpqueue* pqueue, ctofu* data, int* priority);
ctofu_error tscl_pqueue_search(const cpqueue* pqueue, ctofu data, int priority);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t tscl_pqueue_size(const cpqueue* pqueue);
ctofu* tscl_pqueue_getter(cpqueue* pqueue, ctofu data, int priority);
ctofu_error tscl_pqueue_setter(cpqueue* pqueue, ctofu data, int priority);
bool tscl_pqueue_not_empty(const cpqueue* pqueue);
bool tscl_pqueue_not_cnullptr(const cpqueue* pqueue);
bool tscl_pqueue_is_empty(const cpqueue* pqueue);
bool tscl_pqueue_is_cnullptr(const cpqueue* pqueue);

#ifdef __cplusplus
}
#endif

#endif
