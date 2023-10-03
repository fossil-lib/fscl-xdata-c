/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_PQUEUE_H
#define TRILOBITE_XDATA_PQUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Node structure for the priority queue
typedef struct TriloPQueueNode {
    TriloTofu data;
    int priority;
    struct TriloPQueueNode* next;
} TriloPQueueNode;

// Priority queue structure
typedef struct TriloPQueue {
    TriloPQueueNode* front;
    enum DataType queue_type;  // Type of the priority queue
} TriloPQueue;

// Function to create a new TriloPQueue
TriloPQueue* trilo_xdata_pqueue_create(enum DataType queue_type);

// Function to destroy the TriloPQueue
void trilo_xdata_pqueue_destroy(TriloPQueue* queue);

// Function to check if the priority queue is empty
bool trilo_xdata_pqueue_is_empty(const TriloPQueue* queue);

// Function to enqueue a TriloTofu data with a priority
void trilo_xdata_pqueue_enqueue(TriloPQueue* queue, TriloTofu data, int priority);

// Function to dequeue the highest-priority TriloTofu data
void trilo_xdata_pqueue_dequeue(TriloPQueue* queue);

// Function to peek at the highest-priority TriloTofu data
TriloTofu trilo_xdata_pqueue_peek(const TriloPQueue* queue);

// Function to print the data in the priority queue
void trilo_xdata_pqueue_print(const TriloPQueue* queue);

#ifdef __cplusplus
}
#endif

#endif
