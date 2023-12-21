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

cqueue* queue_create(ctofu_type queue_type) {
    cqueue* new_queue = (cqueue*)malloc(sizeof(cqueue));
    if (new_queue == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_queue->queue_type = queue_type;
    new_queue->front = NULL;
    new_queue->rear = NULL;

    return new_queue;
}

void queue_erase(cqueue* queue) {
    if (queue == NULL) {
        return;
    }

    while (queue->front != NULL) {
        ctofu data;
        queue_remove(queue, &data);
    }

    free(queue);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error queue_insert(cqueue* queue, ctofu data) {
    if (queue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cqueue_node* new_node = (cqueue_node*)malloc(sizeof(cqueue_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return TOFU_WAS_BAD_MALLOC;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        // Queue is empty
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    return TOFU_SUCCESS;
}

ctofu_error queue_remove(cqueue* queue, ctofu* data) {
    if (queue == NULL || data == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    if (queue->front == NULL) {
        return TOFU_NOT_FOUND; // Queue is empty
    }

    cqueue_node* temp = queue->front;
    *data = temp->data;

    if (queue->front == queue->rear) {
        // Only one element in the queue
        free(temp);
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        free(temp);
    }

    return TOFU_SUCCESS;
}

ctofu_error queue_search(const cqueue* queue, ctofu data) {
    if (queue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cqueue_node* current = queue->front;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return TOFU_SUCCESS; // Found
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t queue_size(const cqueue* queue) {
    if (queue == NULL) {
        return 0;
    }

    size_t size = 0;
    cqueue_node* current = queue->front;

    while (current != NULL) {
        ++size;
        current = current->next;
    }

    return size;
}

ctofu* queue_getter(cqueue* queue, ctofu data) {
    if (queue == NULL) {
        return NULL;
    }

    cqueue_node* current = queue->front;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error queue_setter(cqueue* queue, ctofu data) {
    if (queue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cqueue_node* current = queue->front;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            // Found, update the data
            current->data = data;
            return TOFU_SUCCESS;
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

bool queue_not_empty(const cqueue* queue) {
    return queue != NULL && queue->front != NULL;
}

bool queue_not_cnullptr(const cqueue* queue) {
    return queue != NULL;
}

bool queue_is_empty(const cqueue* queue) {
    return queue == NULL || queue->front == NULL;
}

bool queue_is_cnullptr(const cqueue* queue) {
    return queue == NULL;
}
