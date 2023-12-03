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

// Function to create a new cdlist
cdlist* trilo_xdata_dlist_create(enum ctofu_type list_type) {
    cdlist* dlist = (cdlist*)malloc(sizeof(cdlist));
    if (dlist == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    dlist->head = NULL;
    dlist->list_type = list_type;
    return dlist;
} // end of func

// Function to destroy the cdlist
void trilo_xdata_dlist_destroy(cdlist* dlist) {
    cdlist_node* current = dlist->head;
    while (current != NULL) {
        cdlist_node* temp = current;
        current = current->next;
        free(temp);
    } // end while
    free(dlist);
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Function to insert a ctofu data into the list
ctofu_error trilo_xdata_dlist_insert(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dlist->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cdlist_node* newNode = (cdlist_node*)malloc(sizeof(cdlist_node));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end of

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dlist->head;

    if (dlist->head != NULL) {
        dlist->head->prev = newNode;
    } // end if

    dlist->head = newNode;

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to remove a ctofu data from the list
ctofu_error trilo_xdata_dlist_remove(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dlist->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cdlist_node* current = dlist->head;
    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            // Found the data to remove
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                dlist->head = current->next;
            } // end if else
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } // end if
            free(current);
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Data not found
} // end of func

// Function to search for a ctofu data in the list
ctofu_error trilo_xdata_dlist_search(const cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dlist->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cdlist_node* current = dlist->head;
    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            return TRILO_XDATA_TYPE_SUCCESS; // Data found
        } // end if
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Data not found
} // end of func

// Function to reverse the list in the forward direction
void trilo_xdata_dlist_reverse_forword(cdlist* dlist) {
    if (dlist == NULL || dlist->head == NULL) {
        return;
    } // end if

    cdlist_node* current = dlist->head;
    cdlist_node* prev = NULL;

    while (current != NULL) {
        cdlist_node* next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    } // end while

    dlist->head = prev;
} // end of func

// Function to reverse the list in the backward direction
void trilo_xdata_dlist_reverse_backward(cdlist* dlist) {
    if (dlist == NULL || dlist->head == NULL) {
        return;
    } // end if

    cdlist_node* current = dlist->head;

    while (current->next != NULL) {
        current = current->next;
    } // end while

    dlist->head = current;

    while (current != NULL) {
        cdlist_node* temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } // end while
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================
// Function to get the size of the cdlist
size_t trilo_xdata_dlist_size(const cdlist* dlist) {
    size_t count = 0;
    cdlist_node* current = dlist->head;
    while (current != NULL) {
        count++;
        current = current->next;
    } // end while
    return count;
} // end of func

// Function to insert a ctofu data into the list
ctofu* trilo_xdata_dlist_getter(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return NULL;
    } // end if

    cdlist_node* current = dlist->head;
    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            return &(current->data); // Data found, return a pointer to it
        } // end if
        current = current->next;
    } // end while

    return NULL; // Data not found
} // end of func

// Function to insert a ctofu data into the list
ctofu_error trilo_xdata_dlist_setter(cdlist* dlist, ctofu data) {
    if (dlist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dlist->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cdlist_node* newNode = (cdlist_node*)malloc(sizeof(cdlist_node));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dlist->head;

    if (dlist->head != NULL) {
        dlist->head->prev = newNode;
    } // end if

    dlist->head = newNode;

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to check if the list is empty
bool trilo_xdata_dlist_not_empty(const cdlist* dlist) {
    return dlist != NULL && dlist->head != NULL;
} // end of func

// Function to check if the list is null
bool trilo_xdata_dlist_not_nullptr(const cdlist* dlist) {
    return dlist != NULL;
} // end of func

// Function to check if the list is empty
bool trilo_xdata_dlist_is_empty(const cdlist* dlist) {
    return dlist == NULL || dlist->head == NULL;
} // end of func

// Function to check if the list is null
bool trilo_xdata_dlist_is_nullptr(const cdlist* dlist) {
    return dlist == NULL;
} // end of func
