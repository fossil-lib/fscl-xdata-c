/*  ----------------------------------------------------------------------------
    File: tofu.c

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
#include "trilobite/xdata/tofu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to create a new ctofu instance from an integer
ctofu trilo_xdata_tofu_create_from_integer(int value) {
    ctofu tofu;
    tofu.type = INTEGER_TYPE;
    tofu.data.integer_type = value;
    return tofu;
} // end of func

// Function to create a new ctofu instance from a double
ctofu trilo_xdata_tofu_create_from_double(double value) {
    ctofu tofu;
    tofu.type = DOUBLE_TYPE;
    tofu.data.double_type = value;
    return tofu;
} // end of func

// Function to create a new ctofu instance from a string
ctofu trilo_xdata_tofu_create_from_string(const char* value) {
    ctofu tofu;
    tofu.type = STRING_TYPE;
    tofu.data.string_type = (char*)malloc(strlen(value) + 1);
    strcpy(tofu.data.string_type, value);
    return tofu;
} // end of func

// Function to create a new ctofu instance from a char
ctofu trilo_xdata_tofu_create_from_char(char value) {
    ctofu tofu;
    tofu.type = CHAR_TYPE;
    tofu.data.char_type = value;
    return tofu;
} // end of func

// Function to create a new ctofu instance from a bool
ctofu trilo_xdata_tofu_create_from_boolean(bool value) {
    ctofu tofu;
    tofu.type = BOOLEAN_TYPE;
    tofu.data.boolean_type = value;
    return tofu;
} // end of func

ctofu trilo_xdata_tofu_create_from_nullptr(void) {
    ctofu tofu;
    tofu.type = NULLPTR_TYPE;
    return tofu;
} // end of func

ctofu trilo_xdata_tofu_create_from_empty_array(void) {
    ctofu tofu;
    tofu.type = ARRAY_TYPE;
    tofu.data.array_type.size = 0;
    tofu.data.array_type.elements = NULL;
    return tofu;
} // end of func

// Function to free memory associated with a tofu instance
void trilo_xdata_tofu_destroy(ctofu* tofu) {
    if (tofu->type == STRING_TYPE) {
        free(tofu->data.string_type);
    } else if (tofu->type == ARRAY_TYPE) {
        free(tofu->data.array_type.elements);
    }
    // Add more cases if needed for other dynamic allocations
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error trilo_xdata_tofu_compare(const ctofu a, const ctofu b) {
    if (a.type != b.type) {
        // Different data types, consider them not equal
        return TRILO_XDATA_TYPE_WAS_MISMATCH;
    } // end of

    switch (a.type) {
        case INTEGER_TYPE:
            return a.data.integer_type - b.data.integer_type;
        case DOUBLE_TYPE:
            // Compare double values with some tolerance for precision issues
            if (fabs(a.data.double_type - b.data.double_type) < 1e-6) {
                return 0;  // Approximately equal
            } else {
                return a.data.double_type < b.data.double_type ? -1 : 1;
            } // end if else
        case STRING_TYPE:
            return strcmp(a.data.string_type, b.data.string_type);
        case CHAR_TYPE:
            return a.data.char_type - b.data.char_type;
        case BOOLEAN_TYPE:
            return (int)a.data.boolean_type - (int)b.data.boolean_type;
        default:
            return TRILO_XDATA_TYPE_WAS_UNKNOWN;  // Unsupported data type
    } // end switch
} // end of func


// Function to perform insertion sort on an array of ctofu instances
void trilo_xdata_tofu_insertion_sort(ctofu* arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        ctofu key = arr[i];
        int j = i - 1;
        while (j >= 0 && trilo_xdata_tofu_compare(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        } // end while
        arr[j + 1] = key;
    } // end for
} // end of func

// Function to perform selection sort on an array of ctofu instances
void trilo_xdata_tofu_selection_sort(ctofu* arr, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < n; j++) {
            if (trilo_xdata_tofu_compare(arr[j], arr[min_index]) < 0) {
                min_index = j;
            } // end if
        } // end for
        // Swap arr[i] and arr[min_index]
        ctofu temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    } // end for
} // end of func

// Function to perform binary search for a ctofu instance in a sorted array
// Returns the index of the target or -1 if not found
int trilo_xdata_tofu_binary_search(const ctofu* arr, size_t n, ctofu target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int comparison = trilo_xdata_tofu_compare(arr[mid], target);
        if (comparison == 0) {
            return mid; // Target found at index mid
        } // end if
        if (comparison < 0) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        } // end if else
    } // end while
    return -1; // Target not found in the sorted array
} // end of func

// Function to perform linear search for a ctofu instance in an array
// Returns the index of the first occurrence of the target or -1 if not found
int trilo_xdata_tofu_linear_search(const ctofu* arr, size_t n, ctofu target) {
    for (size_t i = 0; i < n; i++) {
        if (trilo_xdata_tofu_compare(arr[i], target) == 0) {
            return i; // Target found at index i
        } // end if
    } // end for
    return -1; // Target not found in the array
} // end of func


// =======================
// UTILITY FUNCTIONS
// =======================

// Function to print the data in a ctofu instance
void trilo_xdata_tofu_print(ctofu tofu) {
    switch (tofu.type) {
        case INTEGER_TYPE:
            printf("Data Type: int, Value: %d\n", tofu.data.integer_type);
            break;
        case DOUBLE_TYPE:
            printf("Data Type: double, Value: %lf\n", tofu.data.double_type);
            break;
        case STRING_TYPE:
            printf("Data Type: string, Value: %s\n", tofu.data.string_type);
            break;
        case CHAR_TYPE:
            printf("Data Type: char, Value: %c\n", tofu.data.char_type);
            break;
        case BOOLEAN_TYPE:
            printf("Data Type: bool, Value: %s\n", tofu.data.boolean_type ? "true" : "false");
            break;
        // Add cases for more data types as needed
        default:
            puts("Unknown Data Type");
    } // end switch
} // end of func

// Function to get the integer data from a ctofu instance
int trilo_xdata_tofu_get_integer(ctofu tofu) {
    if (tofu.type == INTEGER_TYPE) {
        return tofu.data.integer_type;
    } // end if
    return 0; // Return a default value or handle the error as needed
} // end of func

// Function to get the double data from a ctofu instance
double trilo_xdata_tofu_get_double(ctofu tofu) {
    if (tofu.type == DOUBLE_TYPE) {
        return tofu.data.double_type;
    } // end if
    return 0.0; // Return a default value or handle the error as needed
} // end of func

// Function to get the string data from a ctofu instance
const char* trilo_xdata_tofu_get_string(ctofu tofu) {
    if (tofu.type == STRING_TYPE) {
        const char *value = tofu.data.string_type;
        return value;
    } // end if
    return ""; // Return a default value or handle the error as needed
} // end of func

// Function to get the char data from a ctofu instance
char trilo_xdata_tofu_get_char(ctofu tofu) {
    if (tofu.type == CHAR_TYPE) {
        return tofu.data.char_type;
    } // end if
    return '\0'; // Return a default value or handle the error as needed
} // end of func

// Function to get the boolean data from a ctofu instance
bool trilo_xdata_tofu_get_boolean(ctofu tofu) {
    if (tofu.type == BOOLEAN_TYPE) {
        return tofu.data.boolean_type;
    } // end if
    return false; // Return a default value or handle the error as needed
} // end of func

// Function to create a copy of a ctofu instance
ctofu trilo_xdata_tofu_copy(ctofu tofu) {
    ctofu copy;
    copy.type = tofu.type;
    switch (tofu.type) {
        case INTEGER_TYPE:
            copy.data.integer_type = tofu.data.integer_type;
            break;
        case DOUBLE_TYPE:
            copy.data.double_type = tofu.data.double_type;
            break;
        case STRING_TYPE:
            strncpy(copy.data.string_type, tofu.data.string_type, sizeof(copy.data.string_type));
            break;
        case CHAR_TYPE:
            copy.data.char_type = tofu.data.char_type;
            break;
        case BOOLEAN_TYPE:
            copy.data.boolean_type = tofu.data.boolean_type;
            break;
        default:
            copy.type = UNKNOWN_TYPE;
            break;
    } // end switch
    return copy;
} // end of func

// Checks if two ctofu instances are equal.
bool trilo_xdata_tofu_equal(const ctofu a, const ctofu b) {
    if (a.type != b.type) {
        return false; // Types are different, not equal.
    } // end if

    switch (a.type) {
        case INTEGER_TYPE:
            return a.data.integer_type == b.data.integer_type;
        case DOUBLE_TYPE:
            return a.data.double_type == b.data.double_type;
        case STRING_TYPE:
            return strcmp(a.data.string_type, b.data.string_type) == 0;
        case CHAR_TYPE:
            return a.data.char_type == b.data.char_type;
        case BOOLEAN_TYPE:
            return a.data.boolean_type == b.data.boolean_type;
        default:
            return false; // Unknown type, not equal.
    } // end switch
} // end of func

// Gets the data type of a ctofu instance.
enum ctofu_type trilo_xdata_tofu_get_type(const ctofu tofu) {
    return tofu.type;
} // end of func
