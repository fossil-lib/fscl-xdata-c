/*  ----------------------------------------------------------------------------
    File: set.c

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
#include "trilobite/xdata/set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

cset* set_create(ctofu_type set_type) {
    cset* new_set = (cset*)malloc(sizeof(cset));
    if (new_set == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_set->head = NULL;
    new_set->set_type = set_type;

    return new_set;
}

void set_erase(cset* set) {
    if (set == NULL) {
        return;
    }

    // Remove all nodes
    cset_node* current = set->head;
    while (current != NULL) {
        cset_node* next = current->next;
        free(current);
        current = next;
    }

    free(set);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error set_insert(cset* set, ctofu data) {
    if (set == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    // Check if the element already exists
    cset_node* current = set->head;
    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return TOFU_WAS_MISMATCH; // Duplicate element
        }
        current = current->next;
    }

    // Create a new node
    cset_node* new_node = (cset_node*)malloc(sizeof(cset_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return TOFU_WAS_BAD_MALLOC;
    }

    new_node->data = data;
    new_node->next = set->head;
    set->head = new_node;

    return TOFU_SUCCESS;
}

ctofu_error set_remove(cset* set, ctofu data) {
    if (set == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cset_node* current = set->head;
    cset_node* prev = NULL;

    // Find the node to remove
    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            if (prev == NULL) {
                set->head = current->next; // Remove the head node
            } else {
                prev->next = current->next; // Remove a non-head node
            }

            free(current);
            return TOFU_SUCCESS;
        }

        prev = current;
        current = current->next;
    }

    return TOFU_NOT_FOUND; // Element not found
}

ctofu_error set_search(const cset* set, ctofu data) {
    if (set == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cset_node* current = set->head;

    // Search for the element
    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return TOFU_SUCCESS; // Element found
        }
        current = current->next;
    }

    return TOFU_NOT_FOUND; // Element not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t set_size(const cset* set) {
    if (set == NULL) {
        return 0;
    }

    size_t size = 0;
    cset_node* current = set->head;

    // Count the number of elements
    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

ctofu* set_getter(cset* set, ctofu data) {
    if (set == NULL) {
        return NULL;
    }

    cset_node* current = set->head;

    // Search for the element
    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return &current->data; // Return a pointer to the element
        }
        current = current->next;
    }

    return NULL; // Element not found
}

ctofu_error set_setter(cset* set, ctofu data) {
    if (set == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cset_node* current = set->head;

    // Search for the element
    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            current->data = data; // Update the element
            return TOFU_SUCCESS;
        }
        current = current->next;
    }

    return TOFU_NOT_FOUND; // Element not found
}

bool set_not_empty(const cset* set) {
    return set != NULL && set->head != NULL;
}

bool set_not_cnullptr(const cset* set) {
    return set != NULL;
}

bool set_is_empty(const cset* set) {
    return set == NULL || set->head == NULL;
}

bool set_is_cnullptr(const cset* set) {
    return set == NULL;
}

bool set_contains(const cset* set, ctofu data) {
    if (set == NULL) {
        return false;
    }

    cset_node* current = set->head;

    // Check if the element exists
    while (current != NULL) {
        if (tofu_compare(&current->data, &data, NULL) == 0) {
            return true; // Element found
        }
        current = current->next;
    }

    return false; // Element not found
}

// =======================
// ITERATOR FUNCTIONS
// =======================

ctofu_iterator set_iterator_start(cset* set) {
    ctofu_iterator iterator;
    iterator.current_value = set->head;

    return iterator;
}

ctofu_iterator set_iterator_end(cset* set) {
    ctofu_iterator iterator;
    iterator.current_value = NULL;

    return iterator;
}

ctofu_iterator set_iterator_next(ctofu_iterator iterator) {
    iterator = iterator.next;

    return iterator;
}

bool set_iterator_has_next(ctofu_iterator iterator) {
    return iterator.current_value != NULL;
}