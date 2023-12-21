/*  ----------------------------------------------------------------------------
    File: dlist.c

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
#include "trilobite/xdata/dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
cdlist* dlist_create(ctofu_type list_type) {
    cdlist* new_dlist = (cdlist*)malloc(sizeof(cdlist));
    if (new_dlist == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_dlist->list_type = list_type;
    new_dlist->head = NULL;
    new_dlist->tail = NULL;

    return new_dlist;
}

void dlist_erase(cdlist* dlist) {
    if (dlist == NULL) {
        return;
    }

    while (dlist->head != NULL) {
        ctofu data;
        dlist_remove(dlist, &data);
    }

    free(dlist);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error dlist_insert(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cdlist_node* new_node = (cdlist_node*)malloc(sizeof(cdlist_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return TOFU_WAS_BAD_MALLOC;
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (dlist->head == NULL) {
        // List is empty
        dlist->head = new_node;
        dlist->tail = new_node;
    } else {
        new_node->next = dlist->head;
        dlist->head->prev = new_node;
        dlist->head = new_node;
    }

    return TOFU_SUCCESS;
}

ctofu_error dlist_remove(cdlist* dlist, ctofu* data) {
    if (dlist == NULL || data == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    if (dlist->head == NULL) {
        return TOFU_NOT_FOUND; // List is empty
    }

    cdlist_node* temp = dlist->head;
    *data = temp->data;

    if (dlist->head == dlist->tail) {
        // Only one element in the list
        free(temp);
        dlist->head = NULL;
        dlist->tail = NULL;
    } else {
        dlist->head = dlist->head->next;
        dlist->head->prev = NULL;
        free(temp);
    }

    return TOFU_SUCCESS;
}

ctofu_error dlist_search(const cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cdlist_node* current = dlist->head;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return TOFU_SUCCESS; // Found
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

void dlist_reverse_forward(cdlist* dlist) {
    if (dlist == NULL || dlist->head == NULL || dlist->head == dlist->tail) {
        return;
    }

    cdlist_node* current = dlist->head;
    cdlist_node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = dlist->head;
    dlist->head = dlist->tail;
    dlist->tail = temp;
}

void dlist_reverse_backward(cdlist* dlist) {
    if (dlist == NULL || dlist->head == NULL || dlist->head == dlist->tail) {
        return;
    }

    cdlist_node* current = dlist->tail;
    cdlist_node* temp = NULL;

    while (current != NULL) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->next;
    }

    temp = dlist->head;
    dlist->head = dlist->tail;
    dlist->tail = temp;
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t dlist_size(const cdlist* dlist) {
    if (dlist == NULL) {
        return 0;
    }

    size_t size = 0;
    cdlist_node* current = dlist->head;

    while (current != NULL) {
        ++size;
        current = current->next;
    }

    return size;
}

ctofu* dlist_getter(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return NULL;
    }

    cdlist_node* current = dlist->head;

    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error dlist_setter(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cdlist_node* current = dlist->head;

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

bool dlist_not_empty(const cdlist* dlist) {
    return dlist != NULL && dlist->head != NULL;
}

bool dlist_not_cnullptr(const cdlist* dlist) {
    return dlist != NULL;
}

bool dlist_is_empty(const cdlist* dlist) {
    return dlist == NULL || dlist->head == NULL;
}

bool dlist_is_cnullptr(const cdlist* dlist) {
    return dlist == NULL;
}