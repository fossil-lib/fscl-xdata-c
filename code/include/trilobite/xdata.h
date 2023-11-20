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
#ifndef TRILOBITE_XDATA_H
#define TRILOBITE_XDATA_H

#ifdef __cplusplus
extern "C"
{
#endif

// xdata/map.h: Header for Map Data Structure
// This header provides an implementation of a map data structure.
#include "xdata/map.h"

// xdata/queue.h: Header for Queue Data Structure
// This header provides an implementation of a queue data structure.
// Queues follow the First-In-First-Out (FIFO) principle and are useful for managing data in a sequential manner.
#include "xdata/queue.h"

// xdata/dqueue.h: Header for Double-ended Queue Data Structure
// This header includes the implementation of a double-ended queue data structure.
// Double-ended queues allow elements to be added or removed from both ends efficiently.
#include "xdata/dqueue.h"

// xdata/pqueue.h: Header for Priority Queue Data Structure
// This header contains the implementation of a priority queue data structure.
// Priority queues organize elements based on their priority and are often used in scheduling and optimization algorithms.
#include "xdata/pqueue.h"

// xdata/tree.h: Header for Tree Data Structure
// This header provides the implementation of various tree data structures, such as binary trees and AVL trees.
// Trees are hierarchical data structures commonly used for searching and organizing data.
#include "xdata/tree.h"

// xdata/set.h: Header for Set Data Structure
// This header provides an implementation of a set data structure, which stores unique elements.
// Sets are useful for tasks requiring unique element storage and set operations.
#include "xdata/set.h"

// xdata/tofu.h: Header for TriloTofu Data Structure
// This header defines a custom data structure named TriloTofu, which can hold data of different types (int, double, string, char, bool).
// It also provides functions for creating, manipulating, and converting TriloTofu instances.
#include "xdata/tofu.h"

// xdata/dlist.h: Header for Doubly Linked List Data Structure
// This header contains the implementation of a doubly linked list data structure.
// Doubly linked lists allow efficient insertion and deletion at both ends of the list.
#include "xdata/dlist.h"

// xdata/flist.h: Header for Fixed-Size List Data Structure
// This header provides an implementation of a fixed-size list data structure.
// Fixed-size lists have a predefined capacity and are useful when you need to limit the number of elements.
#include "xdata/flist.h"

// xdata/stack.h: Header for Stack Data Structure
// This header provides the implementation of a stack data structure.
// Stacks follow the Last-In-First-Out (LIFO) principle and are used for managing data with a strict order of insertion and removal.
#include "xdata/stack.h"

/**
 * @file xdata/vector.c
 * @brief Unit tests for the TriloVector functions.
 *
 * These tests use the Unity Test Framework. Include the corresponding header
 * file for the TriloVector functions, which is assumed to be "xdata/vector.h".
 */
#include "xdata/vector.h"

const char * const TRILOBITE_XDATA_STD = "Redlichiids";

#ifdef __cplusplus
}
#endif

#endif
