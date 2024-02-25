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
#include "fossil/xdata/dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
cdlist* fscl_dlist_create(ctofu_type list_type) {
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

void fscl_dlist_erase(cdlist* dlist) {
    if (dlist == NULL) {
        return;
    }

    while (dlist->head != NULL) {
        ctofu data;
        fscl_dlist_remove(dlist, &data);
    }

    free(dlist);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_dlist_insert(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    cdlist_node* new_node = (cdlist_node*)malloc(sizeof(cdlist_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return fscl_tofu_error(TOFU_WAS_BAD_MALLOC);
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

    return fscl_tofu_error(TOFU_SUCCESS);
}

ctofu_error fscl_dlist_remove(cdlist* dlist, ctofu* data) {
    if (dlist == NULL || data == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    if (dlist->head == NULL) {
        return fscl_tofu_error(TOFU_NOT_FOUND); // List is empty
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

    return fscl_tofu_error(TOFU_SUCCESS);
}

ctofu_error fscl_dlist_search(const cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    cdlist_node* current = dlist->head;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data) == 0) {
            return fscl_tofu_error(TOFU_SUCCESS); // Found
        }

        current = current->next;
    }

    return fscl_tofu_error(TOFU_NOT_FOUND); // Not found
}

void fscl_dlist_reverse_forward(cdlist* dlist) {
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

void fscl_dlist_reverse_backward(cdlist* dlist) {
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

size_t fscl_dlist_size(const cdlist* dlist) {
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

ctofu* fscl_dlist_getter(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return NULL;
    }

    cdlist_node* current = dlist->head;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error fscl_dlist_setter(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    cdlist_node* current = dlist->head;

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

bool fscl_dlist_not_empty(const cdlist* dlist) {
    return dlist != NULL && dlist->head != NULL;
}

bool fscl_dlist_not_cnullptr(const cdlist* dlist) {
    return dlist != NULL;
}

bool fscl_dlist_is_empty(const cdlist* dlist) {
    return dlist == NULL || dlist->head == NULL;
}

bool fscl_dlist_is_cnullptr(const cdlist* dlist) {
    return dlist == NULL;
}