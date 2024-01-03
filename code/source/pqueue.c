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
#include "fossil/xdata/pqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
cpqueue* fscl_pqueue_create(ctofu_type queue_type) {
    cpqueue* new_pqueue = (cpqueue*)malloc(sizeof(cpqueue));
    if (new_pqueue == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_pqueue->queue_type = queue_type;
    new_pqueue->front = NULL;

    return new_pqueue;
}

void fscl_pqueue_erase(cpqueue* pqueue) {
    if (pqueue == NULL) {
        return;
    }

    while (pqueue->front != NULL) {
        ctofu data;
        int priority;
        fscl_pqueue_remove(pqueue, &data, &priority);
    }

    free(pqueue);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error fscl_pqueue_insert(cpqueue* pqueue, ctofu data, int priority) {
    if (pqueue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cpqueue_node* new_node = (cpqueue_node*)malloc(sizeof(cpqueue_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return TOFU_WAS_BAD_MALLOC;
    }

    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    if (pqueue->front == NULL || priority > pqueue->front->priority) {
        // Insert at the beginning
        new_node->next = pqueue->front;
        pqueue->front = new_node;
    } else {
        cpqueue_node* current = pqueue->front;

        while (current->next != NULL && priority <= current->next->priority) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_pqueue_remove(cpqueue* pqueue, ctofu* data, int* priority) {
    if (pqueue == NULL || data == NULL || priority == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    if (pqueue->front == NULL) {
        return TOFU_NOT_FOUND; // Queue is empty
    }

    cpqueue_node* temp = pqueue->front;
    *data = temp->data;
    *priority = temp->priority;

    pqueue->front = pqueue->front->next;
    free(temp);

    return TOFU_SUCCESS;
}

ctofu_error fscl_pqueue_search(const cpqueue* pqueue, ctofu data, int priority) {
    if (pqueue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cpqueue_node* current = pqueue->front;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0 && current->priority == priority) {
            return TOFU_SUCCESS; // Found
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fscl_pqueue_size(const cpqueue* pqueue) {
    if (pqueue == NULL) {
        return 0;
    }

    size_t size = 0;
    cpqueue_node* current = pqueue->front;

    while (current != NULL) {
        ++size;
        current = current->next;
    }

    return size;
}

ctofu* fscl_pqueue_getter(cpqueue* pqueue, ctofu data, int priority) {
    if (pqueue == NULL) {
        return NULL;
    }

    cpqueue_node* current = pqueue->front;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0 && current->priority == priority) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error fscl_pqueue_setter(cpqueue* pqueue, ctofu data, int priority) {
    if (pqueue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cpqueue_node* current = pqueue->front;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0 && current->priority == priority) {
            // Found, update the data
            current->data = data;
            return TOFU_SUCCESS;
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

bool fscl_pqueue_not_empty(const cpqueue* pqueue) {
    return pqueue != NULL && pqueue->front != NULL;
}

bool fscl_pqueue_not_cnullptr(const cpqueue* pqueue) {
    return pqueue != NULL;
}

bool fscl_pqueue_is_empty(const cpqueue* pqueue) {
    return pqueue == NULL || pqueue->front == NULL;
}

bool fscl_pqueue_is_cnullptr(const cpqueue* pqueue) {
    return pqueue == NULL;
}
