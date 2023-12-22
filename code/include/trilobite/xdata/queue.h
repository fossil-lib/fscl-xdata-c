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
#ifndef TSCL_QUEUE_H
#define TSCL_QUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the queue
typedef struct cqueue_node {
    ctofu data;
    struct cqueue_node* next;
} cqueue_node;

// Queue structure
typedef struct cqueue {
    cqueue_node* front;
    cqueue_node* rear;
    ctofu_type queue_type;  // Type of the queue
} cqueue;

// =======================
// CREATE and DELETE
// =======================
cqueue* tscl_queue_create(ctofu_type list_type);
void tscl_queue_erase(cqueue* queue);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error tscl_queue_insert(cqueue* queue, ctofu data);
ctofu_error tscl_queue_remove(cqueue* queue, ctofu* data);
ctofu_error tscl_queue_search(const cqueue* queue, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t tscl_queue_size(const cqueue* queue);
ctofu* tscl_queue_getter(cqueue* queue, ctofu data);
ctofu_error tscl_queue_setter(cqueue* queue, ctofu data);
bool tscl_queue_not_empty(const cqueue* queue);
bool tscl_queue_not_cnullptr(const cqueue* queue);
bool tscl_queue_is_empty(const cqueue* queue);
bool tscl_queue_is_cnullptr(const cqueue* queue);

#ifdef __cplusplus
}
#endif

#endif
