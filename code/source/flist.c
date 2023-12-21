/*  ----------------------------------------------------------------------------
    File: flist.c

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
#include "trilobite/xdata/flist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

cflist* flist_create(ctofu_type list_type) {
    cflist* new_flist = (cflist*)malloc(sizeof(cflist));
    if (new_flist == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_flist->list_type = list_type;
    new_flist->head = NULL;

    return new_flist;
}

void flist_erase(cflist* flist) {
    if (flist == NULL) {
        return;
    }

    while (flist->head != NULL) {
        ctofu data;
        flist_remove(flist, &data);
    }

    free(flist);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error flist_insert(cflist* flist, ctofu data) {
    if (flist == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cflist_node* new_node = (cflist_node*)malloc(sizeof(cflist_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return TOFU_WAS_BAD_MALLOC;
    }

    new_node->data = data;
    new_node->next = flist->head;
    flist->head = new_node;

    return TOFU_SUCCESS;
}

ctofu_error flist_remove(cflist* flist, ctofu* data) {
    if (flist == NULL || data == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    if (flist->head == NULL) {
        return TOFU_NOT_FOUND; // List is empty
    }

    cflist_node* temp = flist->head;
    flist->head = flist->head->next;

    *data = temp->data;
    free(temp);

    return TOFU_SUCCESS;
}

ctofu_error flist_search(const cflist* flist, ctofu data) {
    if (flist == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cflist_node* current = flist->head;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return TOFU_SUCCESS; // Found
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

void flist_reverse_forward(cflist* flist) {
    if (flist == NULL || flist->head == NULL) {
        return;
    }

    cflist_node* prev = NULL;
    cflist_node* current = flist->head;
    cflist_node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    flist->head = prev;
}

void flist_reverse_backward(cflist* flist) {
    if (flist == NULL || flist->head == NULL) {
        return;
    }

    cflist_node* prev = NULL;
    cflist_node* current = flist->head;
    cflist_node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    flist->head = prev;
}

// =======================
// UTILITY FUNCTIONS
// =======================
size_t flist_size(const cflist* flist) {
    if (flist == NULL) {
        return 0;
    }

    size_t size = 0;
    cflist_node* current = flist->head;

    while (current != NULL) {
        ++size;
        current = current->next;
    }

    return size;
}

ctofu* flist_getter(cflist* flist, ctofu data) {
    if (flist == NULL) {
        return NULL;
    }

    cflist_node* current = flist->head;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error flist_setter(cflist* flist, ctofu data) {
    if (flist == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cflist_node* current = flist->head;

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

bool flist_not_empty(const cflist* flist) {
    return flist != NULL && flist->head != NULL;
}

bool flist_not_cnullptr(const cflist* flist) {
    return flist != NULL;
}

bool flist_is_empty(const cflist* flist) {
    return flist == NULL || flist->head == NULL;
}

bool flist_is_cnullptr(const cflist* flist) {
    return flist == NULL;
}