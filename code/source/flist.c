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

// Function to create a new cflist
cflist* trilo_xdata_flist_create(enum ctofu_type list_type) {
    cflist* flist = (cflist*)malloc(sizeof(cflist));
    if (flist == NULL) {
        exit(EXIT_FAILURE);
    } // end if

    flist->head = NULL;
    flist->list_type = list_type;

    return flist;
} // end of func

// Function to destroy the cflist
void trilo_xdata_flist_destroy(cflist* flist) {
    cflist_node* current = flist->head;
    while (current != NULL) {
        cflist_node* temp = current;
        current = current->next;
        free(temp);
    } // end while

    free(flist);
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Function to insert a ctofu data into the list
ctofu_error trilo_xdata_flist_insert(cflist* flist, ctofu data) {
    if (flist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if
    if (flist->list_type != data.type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cflist_node* newNode = (cflist_node*)malloc(sizeof(cflist_node));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->next = flist->head;
    flist->head = newNode;
    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to remove a ctofu data from the list
ctofu_error trilo_xdata_flist_remove(cflist* flist, ctofu data) {
    if (flist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if
    if (flist->list_type != data.type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cflist_node* current = flist->head;
    cflist_node* prev = NULL;

    while (current != NULL) {
        if (current->data.type == data.type) {
            // Check the data type before comparing values
            if (current->data.type == INTEGER_TYPE && current->data.data.integer_type == data.data.integer_type) {
                if (prev == NULL) {
                    flist->head = current->next;
                } else {
                    prev->next = current->next;
                } // end if else
                free(current);
                return TRILO_XDATA_TYPE_SUCCESS;
            } // end if
        } // end if

        prev = current;
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_WAS_UNKNOWN;
} // end of func

// Function to search for a ctofu data in the list
ctofu_error trilo_xdata_flist_search(const cflist* flist, ctofu data) {
    if (flist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if
    if (flist->list_type != data.type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cflist_node* current = flist->head;

    while (current != NULL) {
        if (current->data.type == data.type) {
            // Check the data type before comparing values
            if (current->data.type == INTEGER_TYPE && current->data.data.integer_type == data.data.integer_type) {
                return true;
            } // end if
        } // end if

        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to reverse the list in the forward direction
void trilo_xdata_flist_reverse_forword(cflist* flist) {
    cflist_node* prev = NULL;
    cflist_node* current = flist->head;
    cflist_node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } // end while

    flist->head = prev;
} // end of func

// Function to reverse the list in the backward direction
void trilo_xdata_flist_reverse_backward(cflist* flist) {
    // Assuming you want to reverse the list by using additional memory
    cflist_node* current = flist->head;
    cflist_node* reversed = NULL;

    while (current != NULL) {
        cflist_node* newNode = (cflist_node*)malloc(sizeof(cflist_node));
        if (newNode == NULL) {
            exit(EXIT_FAILURE);
        } // end if

        newNode->data = current->data;
        newNode->next = reversed;
        reversed = newNode;

        current = current->next;
    } // end while

    // Clean up the original list
    while (flist->head != NULL) {
        cflist_node* temp = flist->head;
        flist->head = flist->head->next;
        free(temp);
    } // end while

    flist->head = reversed;
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================

// Function to get the size of the cflist
size_t trilo_xdata_flist_size(const cflist* flist) {
    if (flist == NULL) {
        return 0;
    } // end if

    size_t count = 0;
    cflist_node* current = flist->head;
    while (current != NULL) {
        count++;
        current = current->next;
    } // end while

    return count;
} // end of func

// Function to get a pointer to a ctofu data in the list
ctofu* trilo_xdata_flist_getter(cflist* flist, ctofu data) {
    if (flist == NULL || flist->list_type != data.type) {
        return NULL;
    } // end if

    cflist_node* current = flist->head;
    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            // Found the matching data, return a pointer to the data
            return &(current->data);
        } // end if
        current = current->next;
    } // end while

    return NULL; // Return NULL if the data is not found
} // end of func

// Function to set a ctofu data in the list
ctofu_error trilo_xdata_flist_setter(cflist* flist, ctofu data) {
    if (flist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if
    if (flist->list_type != data.type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    // Check if the data already exists in the list
    ctofu* existingData = trilo_xdata_flist_getter(flist, data);

    if (existingData != NULL) {
        // Data already exists, update the existing data
        *existingData = data;
    } else {
        // Data doesn't exist, insert a new node with the provided data
        trilo_xdata_flist_insert(flist, data);
    } // end if else
    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to check if the list is not empty
bool trilo_xdata_flist_not_empty(const cflist* flist) {
    return trilo_xdata_flist_size(flist) > 0;
} // end of func

// Function to check if the list is not null
bool trilo_xdata_flist_not_nullptr(const cflist* flist) {
    return flist != NULL;
} // end of func

// Function to check if the list is empty
bool trilo_xdata_flist_is_empty(const cflist* flist) {
    return !trilo_xdata_flist_not_empty(flist);
} // end of func

// Function to check if the list is null
bool trilo_xdata_flist_is_nullptr(const cflist* flist) {
    return !trilo_xdata_flist_not_nullptr(flist);
} // end of func
