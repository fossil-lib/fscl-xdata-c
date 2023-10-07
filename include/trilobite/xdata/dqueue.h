/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_DQUEUE_H
#define TRILOBITE_XDATA_DQUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Define error constants for tuple operations
enum {
    TRILO_XDATA_DQUEUE_TYPE_MISMATCH = -1,
    TRILO_XDATA_DQUEUE_OUT_OF_RANGE  = -2
};

// Node structure for the double-ended queue
typedef struct TriloDQueueNode {
    TriloTofu data;
    struct TriloDQueueNode* prev;
    struct TriloDQueueNode* next;
} TriloDQueueNode;

// Double-ended queue structure
typedef struct TriloDQueue {
    TriloDQueueNode* front;
    TriloDQueueNode* rear;
    enum DataType deque_type;  // Type of the deque
} TriloDQueue;

// Function to create a new TriloDQueue
TriloDQueue* trilo_xdata_dqueue_create(enum DataType deque_type);

// Function to destroy the TriloDQueue
void trilo_xdata_dqueue_destroy(TriloDQueue* deque);

// Function to check if the deque is empty
bool trilo_xdata_dqueue_is_empty(const TriloDQueue* deque);

// Function to insert a TriloTofu data at the front of the deque
void trilo_xdata_dqueue_push_front(TriloDQueue* deque, TriloTofu data);

// Function to insert a TriloTofu data at the rear of the deque
void trilo_xdata_dqueue_push_rear(TriloDQueue* deque, TriloTofu data);

// Function to remove a TriloTofu data from the front of the deque
void trilo_xdata_dqueue_pop_front(TriloDQueue* deque);

// Function to remove a TriloTofu data from the rear of the deque
void trilo_xdata_dqueue_pop_rear(TriloDQueue* deque);

// Function to get the front TriloTofu data from the deque
TriloTofu trilo_xdata_dqueue_front(const TriloDQueue* deque);

// Function to get the rear TriloTofu data from the deque
TriloTofu trilo_xdata_dqueue_rear(const TriloDQueue* deque);

// Function to print the data in the deque forward
void trilo_xdata_dqueue_print_forward(const TriloDQueue* deque);

// Function to print the data in the deque backward
void trilo_xdata_dqueue_print_backward(const TriloDQueue* deque);

#ifdef __cplusplus
}
#endif

#endif
