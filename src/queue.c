/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
// Function to create a new TriloQueue
TriloQueue* trilo_xdata_queue_create(enum DataType queue_type) {
    TriloQueue* queue = (TriloQueue*)malloc(sizeof(TriloQueue));
    if (queue != NULL) {
        queue->front = NULL;
        queue->rear = NULL;
        queue->queue_type = queue_type;
    } // end if
    return queue;
} // end of func

// Function to destroy the TriloQueue
void trilo_xdata_queue_destroy(TriloQueue* queue) {
    if (queue != NULL) {
        // Free all nodes in the queue
        while (queue->front != NULL) {
            TriloQueueNode* temp = queue->front;
            queue->front = queue->front->next;
            free(temp);
        } // end while
        free(queue);
    } // end if
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================
// Function to insert a TriloTofu data into the queue
TofuError trilo_xdata_queue_insert(TriloQueue* queue, TriloTofu data) {
    if (queue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloQueueNode* newNode = (TriloQueueNode*)malloc(sizeof(TriloQueueNode));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    } // end if else

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to remove a TriloTofu data from the queue
TofuError trilo_xdata_queue_remove(TriloQueue* queue, TriloTofu data) {
    if (queue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloQueueNode* current = queue->front;
    TriloQueueNode* prev = NULL;

    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            if (prev == NULL) {
                queue->front = current->next;
            } else {
                prev->next = current->next;
            } // end if else

            if (current == queue->rear) {
                queue->rear = prev;
            } // end if

            free(current);
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if

        prev = current;
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;  // No matching data found
} // end of func

// Function to search for a TriloTofu data in the queue
TofuError trilo_xdata_queue_search(const TriloQueue* queue, TriloTofu data) {
    if (queue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloQueueNode* current = queue->front;

    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if

        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;  // No matching data found
} // end of func


// =======================
// UTILITY FUNCTIONS
// =======================
// Function to get the size of the TriloQueue
size_t trilo_xdata_queue_size(const TriloQueue* queue) {
    if (queue == NULL) {
        return 0;
    } // end if

    size_t size = 0;
    TriloQueueNode* current = queue->front;

    while (current != NULL) {
        size++;
        current = current->next;
    } // end while

    return size;
} // end of func

// Function to insert a TriloTofu data into the queue
TriloTofu* trilo_xdata_queue_getter(TriloQueue* queue, TriloTofu data) {
    if (queue == NULL) {
        return NULL;
    } // end if

    TriloQueueNode* current = queue->front;

    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            return &current->data;
        } // end if

        current = current->next;
    } // end while

    return NULL;  // No matching data found
} // end of func

// Function to insert a TriloTofu data into the queue
TofuError trilo_xdata_queue_setter(TriloQueue* queue, TriloTofu data) {
    if (queue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloQueueNode* current = queue->front;

    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            // Data with the same value already exists
            current->data = data;
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if

        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;  // No matching data found, insert as a new node
} // end of func

// Function to check if the queue is not empty
bool trilo_xdata_queue_not_empty(const TriloQueue* queue) {
    return queue != NULL && queue->front != NULL;
} // end of func

// Function to check if the queue is not null
bool trilo_xdata_queue_not_nullptr(const TriloQueue* queue) {
    return queue != NULL;
} // end of func

// Function to check if the queue is empty
bool trilo_xdata_queue_is_empty(const TriloQueue* queue) {
    return queue == NULL || queue->front == NULL;
} // end of func

// Function to check if the queue is null
bool trilo_xdata_queue_is_nullptr(const TriloQueue* queue) {
    return queue == NULL;
} // end of func
