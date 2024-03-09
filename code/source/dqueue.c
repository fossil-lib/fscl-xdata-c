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
#include "fossil/xstructures/dqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
cdqueue* fscl_dqueue_create(ctofu_type list_type) {
    cdqueue* new_dqueue = (cdqueue*)malloc(sizeof(cdqueue));
    if (new_dqueue == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_dqueue->list_type = list_type;
    new_dqueue->front = NULL;
    new_dqueue->rear = NULL;

    return new_dqueue;
}

void fscl_dqueue_erase(cdqueue* dqueue) {
    if (dqueue == NULL) {
        return;
    }

    while (dqueue->front != NULL) {
        ctofu data;
        fscl_dqueue_remove(dqueue, &data);
    }

    free(dqueue);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error fscl_dqueue_insert(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    cdqueue_node* new_node = (cdqueue_node*)malloc(sizeof(cdqueue_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return fscl_tofu_error(TOFU_WAS_BAD_MALLOC);
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (dqueue->front == NULL) {
        // Queue is empty
        dqueue->front = new_node;
        dqueue->rear = new_node;
    } else {
        new_node->next = dqueue->front;
        dqueue->front->prev = new_node;
        dqueue->front = new_node;
    }

    return fscl_tofu_error(TOFU_SUCCESS);
}

ctofu_error fscl_dqueue_remove(cdqueue* dqueue, ctofu* data) {
    if (dqueue == NULL || data == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    if (dqueue->front == NULL) {
        return fscl_tofu_error(TOFU_NOT_FOUND); // Queue is empty
    }

    cdqueue_node* temp = dqueue->front;
    *data = temp->data;

    if (dqueue->front == dqueue->rear) {
        // Only one element in the queue
        free(temp);
        dqueue->front = NULL;
        dqueue->rear = NULL;
    } else {
        dqueue->front = dqueue->front->next;
        dqueue->front->prev = NULL;
        free(temp);
    }

    return fscl_tofu_error(TOFU_SUCCESS);
}

ctofu_error fscl_dqueue_search(const cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    cdqueue_node* current = dqueue->front;

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

size_t fscl_dqueue_size(const cdqueue* dqueue) {
    if (dqueue == NULL) {
        return 0;
    }

    size_t size = 0;
    cdqueue_node* current = dqueue->front;

    while (current != NULL) {
        ++size;
        current = current->next;
    }

    return size;
}

ctofu* fscl_dqueue_getter(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return NULL;
    }

    cdqueue_node* current = dqueue->front;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error fscl_dqueue_setter(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    cdqueue_node* current = dqueue->front;

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

bool fscl_dqueue_not_empty(const cdqueue* dqueue) {
    return dqueue != NULL && dqueue->front != NULL;
}

bool fscl_dqueue_not_cnullptr(const cdqueue* dqueue) {
    return dqueue != NULL;
}

bool fscl_dqueue_is_empty(const cdqueue* dqueue) {
    return dqueue == NULL || dqueue->front == NULL;
}

bool fscl_dqueue_is_cnullptr(const cdqueue* dqueue) {
    return dqueue == NULL;
}
