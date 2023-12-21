/*  ----------------------------------------------------------------------------
    File: dqueue.c

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
#include "trilobite/xdata/dqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
cdqueue* dqueue_create(ctofu_type list_type) {
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

void dqueue_erase(cdqueue* dqueue) {
    if (dqueue == NULL) {
        return;
    }

    while (dqueue->front != NULL) {
        ctofu data;
        dqueue_remove(dqueue, &data);
    }

    free(dqueue);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error dqueue_insert(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cdqueue_node* new_node = (cdqueue_node*)malloc(sizeof(cdqueue_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return TOFU_WAS_BAD_MALLOC;
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

    return TOFU_SUCCESS;
}

ctofu_error dqueue_remove(cdqueue* dqueue, ctofu* data) {
    if (dqueue == NULL || data == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    if (dqueue->front == NULL) {
        return TOFU_NOT_FOUND; // Queue is empty
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

    return TOFU_SUCCESS;
}

ctofu_error dqueue_search(const cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cdqueue_node* current = dqueue->front;

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

size_t dqueue_size(const cdqueue* dqueue) {
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

ctofu* dqueue_getter(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return NULL;
    }

    cdqueue_node* current = dqueue->front;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error dqueue_setter(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cdqueue_node* current = dqueue->front;

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

bool dqueue_not_empty(const cdqueue* dqueue) {
    return dqueue != NULL && dqueue->front != NULL;
}

bool dqueue_not_cnullptr(const cdqueue* dqueue) {
    return dqueue != NULL;
}

bool dqueue_is_empty(const cdqueue* dqueue) {
    return dqueue == NULL || dqueue->front == NULL;
}

bool dqueue_is_cnullptr(const cdqueue* dqueue) {
    return dqueue == NULL;
}
