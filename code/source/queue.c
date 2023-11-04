/*  ----------------------------------------------------------------------------
    File: queue.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
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
TofuError trilo_xdata_queue_remove(TriloQueue* queue) {
    // Check if the queue is NULL or empty
    if (queue == NULL || trilo_xdata_queue_is_empty(queue)) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    // Save a reference to the front node
    TriloQueueNode* frontNode = queue->front;

    // Update the front pointer to the next node
    queue->front = frontNode->next;

    // If the removed node was the last one, update the rear pointer
    if (queue->front == NULL) {
        queue->rear = NULL;
    } // end if

    // Free the memory of the removed node
    free(frontNode);

    return TRILO_XDATA_TYPE_SUCCESS;
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
