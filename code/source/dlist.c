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

// Function to create a new TriloDoublyList
TriloDoublyList* trilo_xdata_dlist_create(enum DataType list_type) {
    TriloDoublyList* dlist = (TriloDoublyList*)malloc(sizeof(TriloDoublyList));
    if (dlist == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    dlist->head = NULL;
    dlist->list_type = list_type;
    return dlist;
} // end of func

// Function to destroy the TriloDoublyList
void trilo_xdata_dlist_destroy(TriloDoublyList* dlist) {
    TriloDoublyListNode* current = dlist->head;
    while (current != NULL) {
        TriloDoublyListNode* temp = current;
        current = current->next;
        free(temp);
    } // end while
    free(dlist);
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Function to insert a TriloTofu data into the list
TofuError trilo_xdata_dlist_insert(TriloDoublyList* dlist, TriloTofu data) {
    if (dlist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dlist->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloDoublyListNode* newNode = (TriloDoublyListNode*)malloc(sizeof(TriloDoublyListNode));
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

// Function to remove a TriloTofu data from the list
TofuError trilo_xdata_dlist_remove(TriloDoublyList* dlist, TriloTofu data) {
    if (dlist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dlist->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloDoublyListNode* current = dlist->head;
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

// Function to search for a TriloTofu data in the list
TofuError trilo_xdata_dlist_search(const TriloDoublyList* dlist, TriloTofu data) {
    if (dlist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dlist->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloDoublyListNode* current = dlist->head;
    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            return TRILO_XDATA_TYPE_SUCCESS; // Data found
        } // end if
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Data not found
} // end of func

// Function to reverse the list in the forward direction
void trilo_xdata_dlist_reverse_forword(TriloDoublyList* dlist) {
    if (dlist == NULL || dlist->head == NULL) {
        return;
    } // end if

    TriloDoublyListNode* current = dlist->head;
    TriloDoublyListNode* prev = NULL;

    while (current != NULL) {
        TriloDoublyListNode* next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    } // end while

    dlist->head = prev;
} // end of func

// Function to reverse the list in the backward direction
void trilo_xdata_dlist_reverse_backward(TriloDoublyList* dlist) {
    if (dlist == NULL || dlist->head == NULL) {
        return;
    } // end if

    TriloDoublyListNode* current = dlist->head;

    while (current->next != NULL) {
        current = current->next;
    } // end while

    dlist->head = current;

    while (current != NULL) {
        TriloDoublyListNode* temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } // end while
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================
// Function to get the size of the TriloDoublyList
size_t trilo_xdata_dlist_size(const TriloDoublyList* dlist) {
    size_t count = 0;
    TriloDoublyListNode* current = dlist->head;
    while (current != NULL) {
        count++;
        current = current->next;
    } // end while
    return count;
} // end of func

// Function to insert a TriloTofu data into the list
TriloTofu* trilo_xdata_dlist_getter(TriloDoublyList* dlist, TriloTofu data) {
    if (dlist == NULL) {
        return NULL;
    } // end if

    TriloDoublyListNode* current = dlist->head;
    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            return &(current->data); // Data found, return a pointer to it
        } // end if
        current = current->next;
    } // end while

    return NULL; // Data not found
} // end of func

// Function to insert a TriloTofu data into the list
TofuError trilo_xdata_dlist_setter(TriloDoublyList* dlist, TriloTofu data) {
    if (dlist == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dlist->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloDoublyListNode* newNode = (TriloDoublyListNode*)malloc(sizeof(TriloDoublyListNode));
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
bool trilo_xdata_dlist_not_empty(const TriloDoublyList* dlist) {
    return dlist != NULL && dlist->head != NULL;
} // end of func

// Function to check if the list is null
bool trilo_xdata_dlist_not_nullptr(const TriloDoublyList* dlist) {
    return dlist != NULL;
} // end of func

// Function to check if the list is empty
bool trilo_xdata_dlist_is_empty(const TriloDoublyList* dlist) {
    return dlist == NULL || dlist->head == NULL;
} // end of func

// Function to check if the list is null
bool trilo_xdata_dlist_is_nullptr(const TriloDoublyList* dlist) {
    return dlist == NULL;
} // end of func
