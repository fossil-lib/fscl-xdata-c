/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_H
#define TRILOBITE_XDATA_H

#ifdef __cplusplus
extern "C"
{
#endif

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

const char * const TRILOBITE_XDATA_STD = "Redlichiids";

#ifdef __cplusplus
}
#endif

#endif
