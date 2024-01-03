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
#include "fossil/xdata/set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

cset* fscl_set_create(ctofu_type set_type) {
    cset* new_set = (cset*)malloc(sizeof(cset));
    if (new_set == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_set->head = NULL;
    new_set->set_type = set_type;

    return new_set;
}

void fscl_set_erase(cset* set) {
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

ctofu_error fscl_set_insert(cset* set, ctofu data) {
    if (set == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    // Check if the element already exists
    cset_node* current = set->head;
    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
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

ctofu_error fscl_set_remove(cset* set, ctofu data) {
    if (set == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cset_node* current = set->head;
    cset_node* prev = NULL;

    // Find the node to remove
    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
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

ctofu_error fscl_set_search(const cset* set, ctofu data) {
    if (set == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cset_node* current = set->head;

    // Search for the element
    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            return TOFU_SUCCESS; // Element found
        }
        current = current->next;
    }

    return TOFU_NOT_FOUND; // Element not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fscl_set_size(const cset* set) {
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

ctofu* fscl_set_getter(cset* set, ctofu data) {
    if (set == NULL) {
        return NULL;
    }

    cset_node* current = set->head;

    // Search for the element
    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            return &current->data; // Return a pointer to the element
        }
        current = current->next;
    }

    return NULL; // Element not found
}

ctofu_error fscl_set_setter(cset* set, ctofu data) {
    if (set == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cset_node* current = set->head;

    // Search for the element
    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            current->data = data; // Update the element
            return TOFU_SUCCESS;
        }
        current = current->next;
    }

    return TOFU_NOT_FOUND; // Element not found
}

bool fscl_set_not_empty(const cset* set) {
    return set != NULL && set->head != NULL;
}

bool fscl_set_not_cnullptr(const cset* set) {
    return set != NULL;
}

bool fscl_set_is_empty(const cset* set) {
    return set == NULL || set->head == NULL;
}

bool fscl_set_is_cnullptr(const cset* set) {
    return set == NULL;
}

bool fscl_set_contains(const cset* set, ctofu data) {
    if (set == NULL) {
        return false;
    }

    cset_node* current = set->head;

    // Check if the element exists
    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            return true; // Element found
        }
        current = current->next;
    }

    return false; // Element not found
}

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator fscl_set_iterator_start(cset* set) {
    ctofu_iterator iterator;
    iterator.current_key = NULL;
    iterator.current_value = NULL;
    iterator.index = 0;

    if (set->head != NULL) {
        iterator.current_key = &set->head->data;
        iterator.current_value = &set->head->data;
    }

    return iterator;
}

ctofu_iterator fscl_set_iterator_end() {
    ctofu_iterator iterator;
    iterator.current_key = NULL;
    iterator.current_value = NULL;
    iterator.index = 0;
    return iterator;
}

ctofu_iterator fscl_set_iterator_next(ctofu_iterator iterator) {
    if (iterator.current_value != NULL) {
        iterator.current_key = &iterator.current_value[1];
        iterator.current_value = &iterator.current_value[1];
        iterator.index++;
    }

    return iterator;
}

bool fscl_set_iterator_has_next(ctofu_iterator iterator) {
    return iterator.current_value != NULL;
}