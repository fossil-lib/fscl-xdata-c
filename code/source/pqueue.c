/*  ----------------------------------------------------------------------------
    File: pqueue.c

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
#include "trilobite/xdata/pqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

// Function to create a new TriloPQueue
TriloPQueue* trilo_xdata_pqueue_create(enum DataType queue_type) {
    TriloPQueue* pqueue = (TriloPQueue*)malloc(sizeof(TriloPQueue));
    if (pqueue == NULL) {
        // Handle memory allocation failure
        return NULL;
    } // end if

    pqueue->front = NULL;
    pqueue->queue_type = queue_type;
    return pqueue;
} // end of func

// Function to destroy the TriloPQueue
void trilo_xdata_pqueue_destroy(TriloPQueue* pqueue) {
    if (pqueue == NULL) {
        return;
    } // end if

    // Free nodes and their data
    TriloPQueueNode* current = pqueue->front;
    while (current != NULL) {
        TriloPQueueNode* temp = current;
        current = current->next;
        free(temp);
    } // end while

    // Free the queue structure
    free(pqueue);
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

TofuError trilo_xdata_pqueue_insert(TriloPQueue* pqueue, TriloTofu data, int priority) {
    if (pqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloPQueueNode* newNode = (TriloPQueueNode*)malloc(sizeof(TriloPQueueNode));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    // Insert at appropriate position based on priority
    if (pqueue->front == NULL || priority > pqueue->front->priority) {
        newNode->next = pqueue->front;
        pqueue->front = newNode;
    } else {
        TriloPQueueNode* current = pqueue->front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        } // end while
        newNode->next = current->next;
        current->next = newNode;
    } // end if else

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

TofuError trilo_xdata_pqueue_remove(TriloPQueue* pqueue, TriloTofu data, int priority) {
    if (pqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (pqueue->front == NULL) {
        return TRILO_XDATA_TYPE_SUCCESS;  // Queue is empty, nothing to remove
    } // end if

    // Remove the node with matching data and priority
    TriloPQueueNode* current = pqueue->front;
    TriloPQueueNode* prev = NULL;

    while (current != NULL) {
        if (current->priority == priority) {
            // Check data match based on type
            switch (current->data.type) {
                case INTEGER_TYPE:
                    if (current->data.data.integer_type == data.data.integer_type) {
                        break;
                    } else {
                        prev = current;
                        current = current->next;
                        continue;
                    }
                case DOUBLE_TYPE:
                    if (current->data.data.double_type == data.data.double_type) {
                        break;
                    } else {
                        prev = current;
                        current = current->next;
                        continue;
                    }
                case STRING_TYPE:
                    if (strcmp(current->data.data.string_type, data.data.string_type) == 0) {
                        break;
                    } else {
                        prev = current;
                        current = current->next;
                        continue;
                    }
                case CHAR_TYPE:
                    if (current->data.data.char_type == data.data.char_type) {
                        break;
                    } else {
                        prev = current;
                        current = current->next;
                        continue;
                    }
                case BOOLEAN_TYPE:
                    if (current->data.data.boolean_type == data.data.boolean_type) {
                        break;
                    } else {
                        prev = current;
                        current = current->next;
                        continue;
                    }
                default:
                    return TRILO_XDATA_TYPE_WAS_UNKNOWN;  // Unsupported data type
            } // end switch

            // Found matching node, remove it
            if (prev == NULL) {
                pqueue->front = current->next;
            } else {
                prev->next = current->next;
            } // end if else
            free(current);
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if
        prev = current;
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;  // No matching data and priority found
} // end of func

TofuError trilo_xdata_pqueue_search(const TriloPQueue* pqueue, TriloTofu data, int priority) {
    if (pqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloPQueueNode* current = pqueue->front;
    while (current != NULL) {
        if (current->priority == priority) {
            // Check data match based on type
            switch (current->data.type) {
                case INTEGER_TYPE:
                    if (current->data.data.integer_type == data.data.integer_type) {
                        return TRILO_XDATA_TYPE_SUCCESS;
                    }
                    break;
                case DOUBLE_TYPE:
                    if (current->data.data.double_type == data.data.double_type) {
                        return TRILO_XDATA_TYPE_SUCCESS;
                    }
                    break;
                case STRING_TYPE:
                    if (strcmp(current->data.data.string_type, data.data.string_type) == 0) {
                        return TRILO_XDATA_TYPE_SUCCESS;
                    }
                    break;
                case CHAR_TYPE:
                    if (current->data.data.char_type == data.data.char_type) {
                        return TRILO_XDATA_TYPE_SUCCESS;
                    }
                    break;
                case BOOLEAN_TYPE:
                    if (current->data.data.boolean_type == data.data.boolean_type) {
                        return TRILO_XDATA_TYPE_SUCCESS;
                    }
                    break;
                default:
                    return TRILO_XDATA_TYPE_WAS_UNKNOWN;  // Unsupported data type
            } // end switch
        } // end if
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================

size_t trilo_xdata_pqueue_size(const TriloPQueue* pqueue) {
    if (pqueue == NULL) {
        return 0;
    } // end if

    size_t size = 0;
    TriloPQueueNode* current = pqueue->front;
    while (current != NULL) {
        size++;
        current = current->next;
    } // end while

    return size;
} // end of func

TriloTofu* trilo_xdata_pqueue_getter(TriloPQueue* pqueue, TriloTofu data, int priority) {
    if (pqueue == NULL) {
        return NULL;
    } // end if

    TriloPQueueNode* current = pqueue->front;
    while (current != NULL) {
        if (current->priority == priority) {
            // Check data match based on type
            switch (current->data.type) {
                case INTEGER_TYPE:
                    if (current->data.data.integer_type == data.data.integer_type) {
                        return &(current->data);
                    }
                    break;
                case DOUBLE_TYPE:
                    if (current->data.data.double_type == data.data.double_type) {
                        return &(current->data);
                    }
                    break;
                case STRING_TYPE:
                    if (strcmp(current->data.data.string_type, data.data.string_type) == 0) {
                        return &(current->data);
                    }
                    break;
                case CHAR_TYPE:
                    if (current->data.data.char_type == data.data.char_type) {
                        return &(current->data);
                    }
                    break;
                case BOOLEAN_TYPE:
                    if (current->data.data.boolean_type == data.data.boolean_type) {
                        return &(current->data);
                    }
                    break;
                default:
                    return NULL;  // Unsupported data type
            } // end switch
        } // end if
        current = current->next;
    } // end while

    return NULL;  // No matching data and priority found
} // end of func

TofuError trilo_xdata_pqueue_setter(TriloPQueue* pqueue, TriloTofu data, int priority) {
    if (pqueue == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloTofu* existingData = trilo_xdata_pqueue_getter(pqueue, data, priority);
    if (existingData != NULL) {
        *existingData = data;
        return TRILO_XDATA_TYPE_SUCCESS;
    } // end if

    return TRILO_XDATA_TYPE_WAS_MISMATCH;  // Data and priority not found
} // end of func

bool trilo_xdata_pqueue_not_empty(const TriloPQueue* pqueue) {
    return pqueue != NULL && pqueue->front != NULL;
} // end of func

bool trilo_xdata_pqueue_not_nullptr(const TriloPQueue* pqueue) {
    return pqueue != NULL;
} // end of func

bool trilo_xdata_pqueue_is_empty(const TriloPQueue* pqueue) {
    return pqueue == NULL || pqueue->front == NULL;
} // end of func

bool trilo_xdata_pqueue_is_nullptr(const TriloPQueue* pqueue) {
    return pqueue == NULL;
} // end of func
