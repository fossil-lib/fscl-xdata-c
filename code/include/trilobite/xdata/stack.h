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
#ifndef TSCL_STACK_H
#define TSCL_STACK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Stack structure
typedef struct cstack_node {
    ctofu data; // Data stored in the stack node
    struct cstack_node* next; // Pointer to the next node
} cstack_node;

typedef struct cstack {
    ctofu_type stack_type; // Type of the stack
    cstack_node* top; // Pointer to the top node of the stack
} cstack;

// =======================
// CREATE and DELETE
// =======================
cstack* tscl_stack_create(ctofu_type list_type);
void tscl_stack_erase(cstack* stack);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error tscl_stack_insert(cstack* stack, ctofu data);
ctofu_error tscl_stack_remove(cstack* stack, ctofu* data);
ctofu_error tscl_stack_search(const cstack* stack, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t tscl_stack_size(const cstack* stack);
ctofu* tscl_stack_getter(cstack* stack, ctofu data);
ctofu_error tscl_stack_setter(cstack* stack, ctofu data);
bool tscl_stack_not_empty(const cstack* stack);
bool tscl_stack_not_cnullptr(const cstack* stack);
bool tscl_stack_is_empty(const cstack* stack);
bool tscl_stack_is_cnullptr(const cstack* stack);
ctofu tscl_stack_top(cstack* stack, ctofu default_value);

#ifdef __cplusplus
}
#endif

#endif
