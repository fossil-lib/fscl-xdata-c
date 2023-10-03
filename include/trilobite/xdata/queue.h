/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_QUEUE_H
#define TRILOBITE_XDATA_QUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Node structure for the queue
typedef struct TriloQueueNode {
    TriloTofu data;
    struct TriloQueueNode* next;
} TriloQueueNode;

// Queue structure
typedef struct TriloQueue {
    TriloQueueNode* front;
    TriloQueueNode* rear;
    enum DataType queue_type;  // Type of the queue
} TriloQueue;

// Function to create a new TriloQueue
TriloQueue* trilo_xdata_queue_create(enum DataType queue_type);

// Function to destroy the TriloQueue
void trilo_xdata_queue_destroy(TriloQueue* queue);

// Function to check if the queue is empty
bool trilo_xdata_queue_is_empty(const TriloQueue* queue);

// Function to enqueue a TriloTofu data
void trilo_xdata_queue_enqueue(TriloQueue* queue, TriloTofu data);

// Function to dequeue a TriloTofu data
void trilo_xdata_queue_dequeue(TriloQueue* queue);

// Function to peek at the front of the queue
TriloTofu trilo_xdata_queue_peek(const TriloQueue* queue);

// Function to print the data in the queue
void trilo_xdata_queue_print(const TriloQueue* queue);

#ifdef __cplusplus
}
#endif

#endif
