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

// Function to create a new TriloSet
TriloSet* trilo_xdata_set_create(enum DataType set_type) {
    TriloSet* set = (TriloSet*)malloc(sizeof(TriloSet));
    if (set != NULL) {
        set->head = NULL;
        set->set_type = set_type;
    } // end if
    return set;
} // end of func

// Function to destroy the TriloSet
void trilo_xdata_set_destroy(TriloSet* set) {
    if (set != NULL) {
        // Free all nodes in the set
        while (set->head != NULL) {
            TriloSetNode* temp = set->head;
            set->head = set->head->next;
            free(temp);
        } // end while
        free(set);
    } // end if
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Function to insert a TriloTofu data into the set
TofuError trilo_xdata_set_insert(TriloSet* set, TriloTofu data) {
    if (set == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloSetNode* newNode = (TriloSetNode*)malloc(sizeof(TriloSetNode));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->next = NULL;

    // Check if the data already exists in the set
    TriloSetNode* current = set->head;
    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);
        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            free(newNode); // Data already exists, don't insert it again
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if
        current = current->next;
    } // end while

    // Insert the new data into the set
    newNode->next = set->head;
    set->head = newNode;
    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to remove a TriloTofu data from the set
TofuError trilo_xdata_set_remove(TriloSet* set, TriloTofu data) {
    if (set == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloSetNode* current = set->head;
    TriloSetNode* prev = NULL;

    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            if (prev == NULL) {
                set->head = current->next;
            } else {
                prev->next = current->next;
            } // end if else

            free(current);
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if

        prev = current;
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;  // No matching data found
} // end of func

// Function to search for a TriloTofu data in the set
TofuError trilo_xdata_set_search(const TriloSet* set, TriloTofu data) {
    if (set == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloSetNode* current = set->head;

    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if

        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;  // No matching data found
} // end of func


// =======================
// UTILITY FUNCTIONS
// =======================

// Function to get the size of the TriloSet
size_t trilo_xdata_set_size(const TriloSet* set) {
    if (set == NULL) {
        return 0;
    } // end if

    size_t size = 0;
    TriloSetNode* current = set->head;

    while (current != NULL) {
        size++;
        current = current->next;
    } // end while

    return size;
} // end of func

// Function to insert a TriloTofu data into the set
TriloTofu* trilo_xdata_set_getter(TriloSet* set, TriloTofu data) {
    if (set == NULL) {
        return NULL;
    } // end if

    TriloSetNode* current = set->head;

    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            return &current->data;
        } // end if

        current = current->next;
    } // end while

    return NULL;  // No matching data found
} // end of func

// Function to insert a TriloTofu data into the set
TofuError trilo_xdata_set_setter(TriloSet* set, TriloTofu data) {
    if (set == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloSetNode* current = set->head;

    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            // Data with the same value already exists
            current->data = data;
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if

        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;  // No matching data found, insert as a new node
} // end of func

// Function to check if the set is not empty
bool trilo_xdata_set_not_empty(const TriloSet* set) {
    return set != NULL && set->head != NULL;
} // end of func

// Function to check if the set is not null
bool trilo_xdata_set_not_nullptr(const TriloSet* set) {
    return set != NULL;
} // end of func

// Function to check if the set is empty
bool trilo_xdata_set_is_empty(const TriloSet* set) {
    return set == NULL || set->head == NULL;
} // end of func

// Function to check if the set is null
bool trilo_xdata_set_is_nullptr(const TriloSet* set) {
    return set == NULL;
} // end of func

// Function to check if a TriloTofu data is in the set
bool trilo_xdata_set_contains(const TriloSet* set, TriloTofu data) {
    if (set == NULL) {
        return false;
    } // end if

    TriloSetNode* current = set->head;

    while (current != NULL) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            return true;
        } // end if

        current = current->next;
    } // end while

    return false;  // No matching data found
} // end of func
