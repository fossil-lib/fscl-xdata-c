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
#include "fossil/xdata/flist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

cflist* fscl_flist_create(ctofu_type list_type) {
    cflist* new_flist = (cflist*)malloc(sizeof(cflist));
    if (new_flist == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_flist->list_type = list_type;
    new_flist->head = NULL;

    return new_flist;
}

void fscl_flist_erase(cflist* flist) {
    if (flist == NULL) {
        return;
    }

    while (flist->head != NULL) {
        ctofu data;
        fscl_flist_remove(flist, &data);
    }

    free(flist);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error fscl_flist_insert(cflist* flist, ctofu data) {
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

ctofu_error fscl_flist_remove(cflist* flist, ctofu* data) {
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

ctofu_error fscl_flist_search(const cflist* flist, ctofu data) {
    if (flist == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cflist_node* current = flist->head;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            return TOFU_SUCCESS; // Found
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

void fscl_flist_reverse_forward(cflist* flist) {
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

void fscl_flist_reverse_backward(cflist* flist) {
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
size_t fscl_flist_size(const cflist* flist) {
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

ctofu* fscl_flist_getter(cflist* flist, ctofu data) {
    if (flist == NULL) {
        return NULL;
    }

    cflist_node* current = flist->head;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error fscl_flist_setter(cflist* flist, ctofu data) {
    if (flist == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cflist_node* current = flist->head;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            // Found, update the data
            current->data = data;
            return TOFU_SUCCESS;
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

bool fscl_flist_not_empty(const cflist* flist) {
    return flist != NULL && flist->head != NULL;
}

bool fscl_flist_not_cnullptr(const cflist* flist) {
    return flist != NULL;
}

bool fscl_flist_is_empty(const cflist* flist) {
    return flist == NULL || flist->head == NULL;
}

bool fscl_flist_is_cnullptr(const cflist* flist) {
    return flist == NULL;
}