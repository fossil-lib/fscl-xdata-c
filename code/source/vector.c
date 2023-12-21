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

cvector vector_create(ctofu_type expected_type) {
    cvector new_vector;
    new_vector.data = (ctofu*)malloc(INITIAL_CAPACITY * sizeof(ctofu));
    if (new_vector.data == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }

    new_vector.size = 0;
    new_vector.capacity = INITIAL_CAPACITY;
    new_vector.expected_type = expected_type;

    return new_vector;
}

void vector_erase(cvector* vector) {
    if (vector == NULL) {
        return;
    }

    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

void vector_push_back(cvector* vector, ctofu element) {
    if (vector == NULL) {
        return;
    }

    // Check if the vector needs to be resized
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = (ctofu*)realloc(vector->data, vector->capacity * sizeof(ctofu));
        if (vector->data == NULL) {
            // Handle memory allocation failure
            exit(EXIT_FAILURE);
        }
    }

    // Check if the type matches the expected type
    if (element.type != vector->expected_type) {
        // Handle type mismatch
        exit(EXIT_FAILURE);
    }

    // Add the element to the vector
    vector->data[vector->size++] = element;
}

int vector_search(const cvector* vector, ctofu target) {
    if (vector == NULL) {
        return -1;
    }

    for (size_t i = 0; i < vector->size; ++i) {
        if (tofu_compare(&target, &vector->data[i], NULL) == TOFU_SUCCESS) {
            return i; // Element found at index i
        }
    }

    return -1; // Element not found
}

void vector_reverse(cvector* vector) {
    if (vector == NULL) {
        return;
    }

    for (size_t i = 0, j = vector->size - 1; i < j; ++i, --j) {
        // Swap elements at positions i and j
        ctofu temp = vector->data[i];
        vector->data[i] = vector->data[j];
        vector->data[j] = temp;
    }
}

// =======================
// UTILITY FUNCTIONS
// =======================

bool vector_is_cnullptr(const cvector* vector) {
    return vector == NULL;
}

bool vector_not_cnullptr(const cvector* vector) {
    return vector != NULL;
}

bool vector_is_empty(const cvector* vector) {
    return vector == NULL || vector->size == 0;
}

bool vector_not_empty(const cvector* vector) {
    return vector != NULL && vector->size != 0;
}

void vector_setter(cvector* vector, size_t index, ctofu element) {
    if (vector == NULL || index >= vector->size) {
        return;
    }

    // Check if the type matches the expected type
    if (element.type != vector->expected_type) {
        // Handle type mismatch
        exit(EXIT_FAILURE);
    }

    vector->data[index] = element;
}

ctofu vector_getter(const cvector* vector, size_t index) {
    if (vector == NULL || index >= vector->size) {
        return (ctofu){.type = INVALID_TYPE}; // Invalid or out-of-bounds access
    }

    return vector->data[index];
}

size_t vector_size(const cvector* vector) {
    return vector != NULL ? vector->size : 0;
}

// Print ctofu value based on its type
void print_ctofu_value(const ctofu value) {
    switch (value.type) {
        case INTEGER_TYPE:
            printf("%d", value.data.integer_type);
            break;
        case DOUBLE_TYPE:
            printf("%f", value.data.double_type);
            break;
        case STRING_TYPE:
            printf("%s", value.data.string_type);
            break;
        case CHAR_TYPE:
            printf("%c", value.data.char_type);
            break;
        case BOOLEAN_TYPE:
            printf("%s", value.data.boolean_type ? "true" : "false");
            break;
        case NULLPTR_TYPE:
            printf("cnullptr");
            break;
        case ARRAY_TYPE:
        case INVALID_TYPE:
        case UNKNOWN_TYPE:
            printf("[Invalid or Unknown Type]");
            break;
    }
}

void vector_peek(const cvector* vector) {
    if (vector == NULL) {
        return;
    }

    printf("Vector contents: [");
    for (size_t i = 0; i < vector->size; ++i) {
        if (i > 0) {
            printf(", ");
        }
        print_ctofu_value(vector->data[i]);
    }
    printf("]\n");
}

// =======================
// ITERATOR FUNCTIONS
// =======================

ctofu_iterator vector_iterator_start(const cvector* vector) {
    if (vector == NULL || vector->size == 0) {
        return (ctofu_iterator){.current_value = NULL, .index = 0};
    }

    return (ctofu_iterator){.current_value = &vector->data[0], .index = 0};
}

ctofu_iterator vector_iterator_end(const cvector* vector) {
    if (vector == NULL || vector->size == 0) {
        return (ctofu_iterator){.current_value = NULL, .index = vector->size};
    }

    return (ctofu_iterator){.current_value = &vector->data[vector->size - 1], .index = vector->size - 1};
}

ctofu_iterator vector_iterator_next(const cvector* vector, ctofu_iterator iterator) {
    if (vector == NULL || iterator.index >= vector->size - 1) {
        return (ctofu_iterator){.current_value = NULL, .index = iterator.index + 1};
    }

    return (ctofu_iterator){.current_value = &vector->data[iterator.index + 1], .index = iterator.index + 1};
}

bool vector_iterator_has_next(const cvector* vector, ctofu_iterator iterator) {
    return vector != NULL && iterator.index < vector->size - 1;
}
