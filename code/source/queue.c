/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xstructures/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

cqueue* fscl_queue_create(ctofu_type queue_type) {
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

void fscl_queue_erase(cqueue* queue) {
    if (queue == NULL) {
        return;
    }

    while (queue->front != NULL) {
        ctofu data;
        fscl_queue_remove(queue, &data);
    }

    free(queue);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error fscl_queue_insert(cqueue* queue, ctofu data) {
    if (queue == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    cqueue_node* new_node = (cqueue_node*)malloc(sizeof(cqueue_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return fscl_tofu_error(TOFU_WAS_BAD_MALLOC);
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

    return fscl_tofu_error(TOFU_SUCCESS);
}

ctofu_error fscl_queue_remove(cqueue* queue, ctofu* data) {
    if (queue == NULL || data == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    if (queue->front == NULL) {
        return fscl_tofu_error(TOFU_NOT_FOUND); // Queue is empty
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

    return fscl_tofu_error(TOFU_SUCCESS);
}

ctofu_error fscl_queue_search(const cqueue* queue, ctofu data) {
    if (queue == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    cqueue_node* current = queue->front;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data) == 0) {
            return fscl_tofu_error(TOFU_SUCCESS); // Found
        }

        current = current->next;
    }

    return fscl_tofu_error(TOFU_NOT_FOUND); // Not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fscl_queue_size(const cqueue* queue) {
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

ctofu* fscl_queue_getter(cqueue* queue, ctofu data) {
    if (queue == NULL) {
        return NULL;
    }

    cqueue_node* current = queue->front;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error fscl_queue_setter(cqueue* queue, ctofu data) {
    if (queue == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    cqueue_node* current = queue->front;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data) == 0) {
            // Found, update the data
            current->data = data;
            return fscl_tofu_error(TOFU_SUCCESS);
        }

        current = current->next;
    }

    return fscl_tofu_error(TOFU_NOT_FOUND); // Not found
}

bool fscl_queue_not_empty(const cqueue* queue) {
    return queue != NULL && queue->front != NULL;
}

bool fscl_queue_not_cnullptr(const cqueue* queue) {
    return queue != NULL;
}

bool fscl_queue_is_empty(const cqueue* queue) {
    return queue == NULL || queue->front == NULL;
}

bool fscl_queue_is_cnullptr(const cqueue* queue) {
    return queue == NULL;
}
