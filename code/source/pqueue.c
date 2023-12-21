/*  ----------------------------------------------------------------------------
    File: pqueue.c

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
#include "trilobite/xdata/pqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
cpqueue* pqueue_create(ctofu_type queue_type) {
    cpqueue* new_pqueue = (cpqueue*)malloc(sizeof(cpqueue));
    if (new_pqueue == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_pqueue->queue_type = queue_type;
    new_pqueue->front = NULL;

    return new_pqueue;
}

void pqueue_erase(cpqueue* pqueue) {
    if (pqueue == NULL) {
        return;
    }

    while (pqueue->front != NULL) {
        ctofu data;
        int priority;
        pqueue_remove(pqueue, &data, &priority);
    }

    free(pqueue);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error pqueue_insert(cpqueue* pqueue, ctofu data, int priority) {
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

ctofu_error pqueue_remove(cpqueue* pqueue, ctofu* data, int* priority) {
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

ctofu_error pqueue_search(const cpqueue* pqueue, ctofu data, int priority) {
    if (pqueue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cpqueue_node* current = pqueue->front;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0 && current->priority == priority) {
            return TOFU_SUCCESS; // Found
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t pqueue_size(const cpqueue* pqueue) {
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

ctofu* pqueue_getter(cpqueue* pqueue, ctofu data, int priority) {
    if (pqueue == NULL) {
        return NULL;
    }

    cpqueue_node* current = pqueue->front;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0 && current->priority == priority) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error pqueue_setter(cpqueue* pqueue, ctofu data, int priority) {
    if (pqueue == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cpqueue_node* current = pqueue->front;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0 && current->priority == priority) {
            // Found, update the data
            current->data = data;
            return TOFU_SUCCESS;
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

bool pqueue_not_empty(const cpqueue* pqueue) {
    return pqueue != NULL && pqueue->front != NULL;
}

bool pqueue_not_cnullptr(const cpqueue* pqueue) {
    return pqueue != NULL;
}

bool pqueue_is_empty(const cpqueue* pqueue) {
    return pqueue == NULL || pqueue->front == NULL;
}

bool pqueue_is_cnullptr(const cpqueue* pqueue) {
    return pqueue == NULL;
}
