/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/dqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

// Function to create a new TriloDQueue
TriloDQueue* trilo_xdata_dqueue_create(enum DataType list_type) {
    TriloDQueue* dqueue = (TriloDQueue*)malloc(sizeof(TriloDQueue));
    if (dqueue == NULL) {
        return NULL; // Memory allocation failed
    } // end if

    dqueue->list_type = list_type;
    dqueue->front = NULL;
    dqueue->rear = NULL;

    return dqueue;
} // end of func

// Function to destroy the TriloDQueue
void trilo_xdata_dqueue_destroy(TriloDQueue* dqueue) {
    if (dqueue == NULL) {
        return; // Nothing to destroy
    } // end if

    while (dqueue->front != NULL) {
        TriloDQueueNode* temp = dqueue->front;
        dqueue->front = dqueue->front->next;
        free(temp);
    } // end while

    free(dqueue);
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Function to insert a TriloTofu data into the list
TofuError trilo_xdata_dqueue_insert(TriloDQueue* dqueue, TriloTofu data) {
    if (dqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dqueue->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloDQueueNode* newNode = (TriloDQueueNode*)malloc(sizeof(TriloDQueueNode));
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

// Function to remove a TriloTofu data from the list
TofuError trilo_xdata_dqueue_remove(TriloDQueue* dqueue, TriloTofu data) {
    if (dqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (dqueue->front == NULL) {
        return TRILO_XDATA_TYPE_WAS_UNKNOWN;
    } // end if

    if (data.type != dqueue->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloDQueueNode* current = dqueue->front;
    TriloDQueueNode* prev = NULL;

    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == TRILO_XDATA_TYPE_SUCCESS) {
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

// Function to search for a TriloTofu data in the list
TofuError trilo_xdata_dqueue_search(const TriloDQueue* dqueue, TriloTofu data) {
    if (dqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dqueue->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloDQueueNode* current = dqueue->front;

    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == TRILO_XDATA_TYPE_SUCCESS) {
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if

        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_WAS_UNKNOWN;
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================

// Function to get the size of the TriloDQueue
size_t trilo_xdata_dqueue_size(const TriloDQueue* dqueue) {
    if (dqueue == NULL) {
        return 0;
    } // end if

    size_t size = 0;
    TriloDQueueNode* current = dqueue->front;

    while (current != NULL) {
        size++;
        current = current->next;
    } // end while

    return size;
} // end of func

// Function to insert a TriloTofu data into the list
TriloTofu* trilo_xdata_dqueue_getter(TriloDQueue* dqueue, TriloTofu data) {
    if (dqueue == NULL) {
        return NULL;
    } // end if

    if (data.type != dqueue->list_type) {
        return NULL;
    } // end if

    TriloDQueueNode* current = dqueue->front;

    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == TRILO_XDATA_TYPE_SUCCESS) {
            return &(current->data);
        } // end if

        current = current->next;
    } // end while

    return NULL;
} // end of func

// Function to insert a TriloTofu data into the list
TofuError trilo_xdata_dqueue_setter(TriloDQueue* dqueue, TriloTofu data) {
    if (dqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (data.type != dqueue->list_type) {
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end if

    TriloDQueueNode* newNode = (TriloDQueueNode*)malloc(sizeof(TriloDQueueNode));
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
bool trilo_xdata_dqueue_not_empty(const TriloDQueue* dqueue) {
    return (dqueue != NULL) && (dqueue->front != NULL);
} // end of func

// Function to check if the list is null
bool trilo_xdata_dqueue_not_nullptr(const TriloDQueue* dqueue) {
    return dqueue != NULL;
} // end of func

// Function to check if the list is empty
bool trilo_xdata_dqueue_is_empty(const TriloDQueue* dqueue) {
    return (dqueue == NULL) || (dqueue->front == NULL);
} // end of func

// Function to check if the list is null
bool trilo_xdata_dqueue_is_nullptr(const TriloDQueue* dqueue) {
    return dqueue == NULL;
} // end of func
