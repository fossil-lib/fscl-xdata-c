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

// xdata/array.h: Header for Array Data Structure
// This header provides the implementation of a dynamic array data structure.
// Dynamic arrays can grow or shrink in size, making them versatile for various applications.
#include "xdata/array.h"

// xdata/matrix.h: Header for Matrix Data Structure
// This header includes the implementation of a matrix data structure.
// Matrices are often used for mathematical and scientific computations.
#include "xdata/matrix.h"

// xdata/vector.h: Header for Vector Data Structure
// This header contains the implementation of a vector data structure.
// Vectors are dynamic arrays that are commonly used for storing elements of the same data type.
#include "xdata/vector.h"

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

// xdata/map.h: Header for Map Data Structure
// This header includes the implementation of a map data structure, which stores key-value pairs.
// Maps are useful for fast lookups and associative data storage.
#include "xdata/map.h"

// xdata/set.h: Header for Set Data Structure
// This header provides an implementation of a set data structure, which stores unique elements.
// Sets are useful for tasks requiring unique element storage and set operations.
#include "xdata/set.h"

// xdata/hash.h: Header for Hashing Utilities
// This header includes utilities for hashing data, which are often used in hash tables and other data structures for fast retrieval.
// Hashing is a technique used for indexing and searching data efficiently.
#include "xdata/hash.h"

// xdata/tuple.h: Header for Tuple Data Structure
// This header provides an implementation of a tuple data structure that can store a fixed number of elements of different types.
// Tuples are useful for returning multiple values from a function or grouping data.
#include "xdata/tuple.h"

// xdata/graph.h: Header for Graph Data Structure
// This header includes the implementation of a graph data structure, which represents connections between entities.
// Graphs are used in various applications, including network analysis, social networks, and routing algorithms.
#include "xdata/graph.h"

// xdata/tofu.h: Header for TriloTofu Data Structure
// This header defines a custom data structure named TriloTofu, which can hold data of different types (int, double, string, char, bool).
// It also provides functions for creating, manipulating, and converting TriloTofu instances.
#include "xdata/tofu.h"

// xdata/tlist.h: Header for Ternary Linked List Data Structure
// This header includes the implementation of a ternary linked list (TList) data structure.
// Ternary linked lists extend the concept of linked lists by allowing nodes to have up to three pointers: left, middle, and right.
// These additional pointers provide flexibility for building complex hierarchical or tree-like structures.
// Ternary linked lists are useful when you need to organize and traverse data in a more intricate manner.
#include "xdata/tlist.h"

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

// xdata/dict.h: Header for Dictionary (Dict) Data Structure
// This header includes the implementation of a dictionary data structure, often referred to as a "map" or "associative array."
// Dictionaries store key-value pairs, allowing fast lookups and associative data storage.
// They are useful for maintaining associations between data elements and are commonly used in various applications.
#include "xdata/dict.h"

const char * const TRILOBITE_XDATA_STD = "Redlichiids";

#ifdef __cplusplus
}
#endif

#endif
