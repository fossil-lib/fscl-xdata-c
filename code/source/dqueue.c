/*  ----------------------------------------------------------------------------
    File: dqueue.c

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
#include "trilobite/xdata/dqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

// Function to create a new cdqueue
cdqueue* dqueue_create(enum ctofu_type list_type) {
    cdqueue* dqueue = (cdqueue*)malloc(sizeof(cdqueue));
    if (dqueue == NULL) {
        return NULL; // Memory allocation failed
    } // end if

    dqueue->list_type = list_type;
    dqueue->front = NULL;
    dqueue->rear = NULL;

    return dqueue;
} // end of func

// Function to destroy the cdqueue
void dqueue_erase(cdqueue* dqueue) {
    if (dqueue == NULL) {
        return; // Nothing to destroy
    } // end if

    while (dqueue->front != NULL) {
        cdqueue_node* temp = dqueue->front;
        dqueue->front = dqueue->front->next;
        free(temp);
    } // end while

    free(dqueue);
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Function to insert a ctofu data into the list
ctofu_error dqueue_insert(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dqueue->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cdqueue_node* newNode = (cdqueue_node*)malloc(sizeof(cdqueue_node));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->next = NULL;

    if (dqueue->rear == NULL) {
        // If the queue is empty, set both front and rear to the new node
        dqueue->front = newNode;
        dqueue->rear = newNode;
    } else {
        // Otherwise, update the rear node's next pointer
        dqueue->rear->next = newNode;
        dqueue->rear = newNode;
    } // end if else

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to remove a ctofu data from the list
ctofu_error dqueue_remove(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (dqueue->front == NULL) {
        return TRILO_XDATA_TYPE_WAS_UNKNOWN;
    } // end if

    if (data.type != dqueue->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cdqueue_node* current = dqueue->front;
    cdqueue_node* prev = NULL;

    while (current != NULL) {
        if (tofu_compare(current->data, data) == TRILO_XDATA_TYPE_SUCCESS) {
            if (current == dqueue->front) {
                // If the front node matches, update the front pointer
                dqueue->front = current->next;
            } else if (current == dqueue->rear) {
                // If the rear node matches, update the rear pointer
                dqueue->rear = prev;
                prev->next = NULL;
            } else {
                // Update the next pointer of the previous node
                prev->next = current->next;
            } // end if else's

            // Free the memory for the removed node
            free(current);
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if

        prev = current;
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_WAS_UNKNOWN;
} // end of func

// Function to search for a ctofu data in the list
ctofu_error dqueue_search(const cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dqueue->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cdqueue_node* current = dqueue->front;

    while (current != NULL) {
        if (tofu_compare(current->data, data) == TRILO_XDATA_TYPE_SUCCESS) {
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if

        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_WAS_UNKNOWN;
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================

// Function to get the size of the cdqueue
size_t dqueue_size(const cdqueue* dqueue) {
    if (dqueue == NULL) {
        return 0;
    } // end if

    size_t size = 0;
    cdqueue_node* current = dqueue->front;

    while (current != NULL) {
        size++;
        current = current->next;
    } // end while

    return size;
} // end of func

// Function to insert a ctofu data into the list
ctofu* dqueue_getter(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return NULL;
    } // end if

    if (data.type != dqueue->list_type) {
        return NULL;
    } // end if

    cdqueue_node* current = dqueue->front;

    while (current != NULL) {
        if (tofu_compare(current->data, data) == TRILO_XDATA_TYPE_SUCCESS) {
            return &(current->data);
        } // end if

        current = current->next;
    } // end while

    return NULL;
} // end of func

// Function to insert a ctofu data into the list
ctofu_error dqueue_setter(cdqueue* dqueue, ctofu data) {
    if (dqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dqueue->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    cdqueue_node* newNode = (cdqueue_node*)malloc(sizeof(cdqueue_node));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->next = NULL;

    if (dqueue->rear == NULL) {
        // If the queue is empty, set both front and rear to the new node
        dqueue->front = newNode;
        dqueue->rear = newNode;
    } else {
        // Otherwise, update the rear node's next pointer
        dqueue->rear->next = newNode;
        dqueue->rear = newNode;
    } // end if else

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to check if the list is not empty
bool dqueue_not_empty(const cdqueue* dqueue) {
    return (dqueue != NULL) && (dqueue->front != NULL);
} // end of func

// Function to check if the list is null
bool dqueue_not_cnullptr(const cdqueue* dqueue) {
    return dqueue != NULL;
} // end of func

// Function to check if the list is empty
bool dqueue_is_empty(const cdqueue* dqueue) {
    return (dqueue == NULL) || (dqueue->front == NULL);
} // end of func

// Function to check if the list is null
bool dqueue_is_cnullptr(const cdqueue* dqueue) {
    return dqueue == NULL;
} // end of func
