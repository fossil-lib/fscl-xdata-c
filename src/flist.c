/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/flist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

// Function to create a new TriloForwardList
TriloForwardList* trilo_xdata_flist_create(enum DataType list_type) {
    TriloForwardList* flist = (TriloForwardList*)malloc(sizeof(TriloForwardList));
    if (flist == NULL) {
        exit(EXIT_FAILURE);
    } // end if

    flist->head = NULL;
    flist->list_type = list_type;

    return flist;
} // end of func

// Function to destroy the TriloForwardList
void trilo_xdata_flist_destroy(TriloForwardList* flist) {
    TriloForwardListNode* current = flist->head;
    while (current != NULL) {
        TriloForwardListNode* temp = current;
        current = current->next;
        free(temp);
    } // end while

    free(flist);
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Function to insert a TriloTofu data into the list
TofuError trilo_xdata_flist_insert(TriloForwardList* flist, TriloTofu data) {
    if (flist == NULL || data == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if
    if (flist->list_type != data.type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloForwardListNode* newNode = (TriloForwardListNode*)malloc(sizeof(TriloForwardListNode));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->next = flist->head;
    flist->head = newNode;
    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// Function to remove a TriloTofu data from the list
TofuError trilo_xdata_flist_remove(TriloForwardList* flist, TriloTofu data) {
    if (flist == NULL || data == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if
    if (flist->list_type != data.type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloForwardListNode* current = flist->head;
    TriloForwardListNode* prev = NULL;

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
                break; // Assuming only one match should be removed
            } // end if
        } // end if

        prev = current;
        current = current->next;
    } // end while
} // end of func

// Function to search for a TriloTofu data in the list
TofuError trilo_xdata_flist_search(const TriloForwardList* flist, TriloTofu data) {
    if (flist == NULL || data == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if
    if (flist->list_type != data.type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloForwardListNode* current = flist->head;

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
void trilo_xdata_flist_reverse_forword(TriloForwardList* flist) {
    TriloForwardListNode* prev = NULL;
    TriloForwardListNode* current = flist->head;
    TriloForwardListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } // end while

    flist->head = prev;
} // end of func

// Function to reverse the list in the backward direction
void trilo_xdata_flist_reverse_backward(TriloForwardList* flist) {
    // Assuming you want to reverse the list by using additional memory
    TriloForwardListNode* current = flist->head;
    TriloForwardListNode* reversed = NULL;

    while (current != NULL) {
        TriloForwardListNode* newNode = (TriloForwardListNode*)malloc(sizeof(TriloForwardListNode));
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
        TriloForwardListNode* temp = flist->head;
        flist->head = flist->head->next;
        free(temp);
    } // end while

    flist->head = reversed;
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================

// Function to get the size of the TriloForwardList
size_t trilo_xdata_flist_size(const TriloForwardList* flist) {
    if (flist == NULL) {
        return 0;
    } // end if

    size_t count = 0;
    TriloForwardListNode* current = flist->head;
    while (current != NULL) {
        count++;
        current = current->next;
    } // end while

    return count;
} // end of func

// Function to get a pointer to a TriloTofu data in the list
TriloTofu* trilo_xdata_flist_getter(TriloForwardList* flist, TriloTofu data) {
    if (flist == NULL || flist->list_type != data.type) {
        return NULL;
    } // end if

    TriloForwardListNode* current = flist->head;
    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            // Found the matching data, return a pointer to the data
            return &(current->data);
        } // end if
        current = current->next;
    } // end while

    return NULL; // Return NULL if the data is not found
} // end of func

// Function to set a TriloTofu data in the list
TofuError trilo_xdata_flist_setter(TriloForwardList* flist, TriloTofu data) {
    if (flist == NULL || data == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if
    if (flist->list_type != data.type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    // Check if the data already exists in the list
    TriloTofu* existingData = trilo_xdata_flist_getter(flist, data);

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
bool trilo_xdata_flist_not_empty(const TriloForwardList* flist) {
    return trilo_xdata_flist_size(flist) > 0;
} // end of func

// Function to check if the list is not null
bool trilo_xdata_flist_not_nullptr(const TriloForwardList* flist) {
    return flist != NULL;
} // end of func

// Function to check if the list is empty
bool trilo_xdata_flist_is_empty(const TriloForwardList* flist) {
    return !trilo_xdata_flist_not_empty(flist);
} // end of func

// Function to check if the list is null
bool trilo_xdata_flist_is_nullptr(const TriloForwardList* flist) {
    return !trilo_xdata_flist_not_nullptr(flist);
} // end of func
