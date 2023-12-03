/*  ----------------------------------------------------------------------------
    File: vector.c

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
#include "trilobite/xdata/vector.h"
#include <stdio.h>
#include <stdlib.h>

// =======================
// CREATE and DELETE
// =======================

cvector trilo_xdata_vector_create(enum ctofu_type expected_type) {
    cvector vector;
    vector.data = (ctofu*)malloc(INITIAL_CAPACITY * sizeof(ctofu));
    if (vector.data == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }
    vector.size = 0;
    vector.capacity = INITIAL_CAPACITY;
    vector.expected_type = expected_type;
    return vector;
} // end of func

void trilo_xdata_vector_destroy(cvector* vector) {
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

void trilo_xdata_vector_push_back(cvector* vector, ctofu element) {
    if (vector->size == vector->capacity) {
        // Resize the vector if it reaches its capacity
        vector->capacity *= 2;
        vector->data = (ctofu*)realloc(vector->data, vector->capacity * sizeof(ctofu));
        if (vector->data == NULL) {
            // Handle memory allocation failure
            exit(EXIT_FAILURE);
        }
    }

    if (element.type == vector->expected_type || vector->expected_type == UNKNOWN_TYPE) {
        vector->data[vector->size] = element;
        vector->size++;
    } else {
        // Handle data type mismatch
        fprintf(stderr, "Data type mismatch. Expected: %d, Actual: %d\n", vector->expected_type, element.type);
        exit(EXIT_FAILURE);
    }
} // end of func


int trilo_xdata_vector_search(const cvector* vector, ctofu target) {
    for (size_t i = 0; i < vector->size; ++i) {
        if (trilo_xdata_tofu_equal(vector->data[i], target)) {
            return (int)i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
} // end of func

void trilo_xdata_vector_reverse(cvector* vector) {
    size_t left = 0;
    size_t right = vector->size - 1;

    while (left < right) {
        // Swap elements at left and right indices
        ctofu temp = vector->data[left];
        vector->data[left] = vector->data[right];
        vector->data[right] = temp;

        // Move indices towards the center
        ++left;
        --right;
    }
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================

bool trilo_xdata_vector_is_nullptr(const cvector* vector) {
    return vector->data == NULL;
} // end of func

bool trilo_xdata_vector_not_nullptr(const cvector* vector) {
    return vector->data != NULL;
} // end of func

bool trilo_xdata_vector_is_empty(const cvector* vector) {
    return vector->size == 0;
} // end of func

bool trilo_xdata_vector_not_empty(const cvector* vector) {
    return vector->size != 0;
} // end of func

void trilo_xdata_vector_setter(cvector* vector, size_t index, ctofu element) {
    if (index < vector->size) {
        if (element.type == vector->expected_type || vector->expected_type == UNKNOWN_TYPE) {
            vector->data[index] = element;
        } else {
            // Handle data type mismatch
            fprintf(stderr, "Data type mismatch. Expected: %d, Actual: %d\n", vector->expected_type, element.type);
            exit(EXIT_FAILURE);
        }
    } else {
        // Handle index out of bounds
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
} // end of func

ctofu trilo_xdata_vector_getter(const cvector* vector, size_t index) {
    if (index < vector->size) {
        return vector->data[index];
    } else {
        // Handle index out of bounds
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
} // end of func

size_t trilo_xdata_vector_size(const cvector* vector) {
    return vector->size;
} // end of func

void trilo_xdata_vector_peek(const cvector* vector) {
    for (size_t i = 0; i < vector->size; ++i) {
        trilo_xdata_tofu_print(vector->data[i]);
        printf(" ");
    }
    printf("\n");
} // end of func
