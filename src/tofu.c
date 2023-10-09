/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tofu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to create a new TriloTofu instance from an integer
TriloTofu trilo_xdata_tofu_create_from_integer(int value) {
    TriloTofu tofu;
    tofu.type = INTEGER_TYPE;
    tofu.data.integer_type = value;
    return tofu;
} // end of func

// Function to create a new TriloTofu instance from a double
TriloTofu trilo_xdata_tofu_create_from_double(double value) {
    TriloTofu tofu;
    tofu.type = DOUBLE_TYPE;
    tofu.data.double_type = value;
    return tofu;
} // end of func

// Function to create a new TriloTofu instance from a string
TriloTofu trilo_xdata_tofu_create_from_string(const char* value) {
    TriloTofu tofu;
    tofu.type = STRING_TYPE;
    strncpy(tofu.data.string_type, value, sizeof(tofu.data.string_type));
    return tofu;
} // end of func

// Function to create a new TriloTofu instance from a char
TriloTofu trilo_xdata_tofu_create_from_char(char value) {
    TriloTofu tofu;
    tofu.type = CHAR_TYPE;
    tofu.data.char_type = value;
    return tofu;
} // end of func

// Function to create a new TriloTofu instance from a bool
TriloTofu trilo_xdata_tofu_create_from_boolean(bool value) {
    TriloTofu tofu;
    tofu.type = BOOLEAN_TYPE;
    tofu.data.boolean_type = value;
    return tofu;
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

TofuError trilo_xdata_tofu_compare(const TriloTofu a, const TriloTofu b) {
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


// Function to perform insertion sort on an array of TriloTofu instances
void trilo_xdata_tofu_insertion_sort(TriloTofu* arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        TriloTofu key = arr[i];
        int j = i - 1;
        while (j >= 0 && trilo_xdata_tofu_compare(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        } // end while
        arr[j + 1] = key;
    } // end for
} // end of func

// Function to perform selection sort on an array of TriloTofu instances
void trilo_xdata_tofu_selection_sort(TriloTofu* arr, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < n; j++) {
            if (trilo_xdata_tofu_compare(arr[j], arr[min_index]) < 0) {
                min_index = j;
            } // end if
        } // end for
        // Swap arr[i] and arr[min_index]
        TriloTofu temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    } // end for
} // end of func

// Function to perform binary search for a TriloTofu instance in a sorted array
// Returns the index of the target or -1 if not found
int trilo_xdata_tofu_binary_search(const TriloTofu* arr, size_t n, TriloTofu target) {
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

// Function to perform linear search for a TriloTofu instance in an array
// Returns the index of the first occurrence of the target or -1 if not found
int trilo_xdata_tofu_linear_search(const TriloTofu* arr, size_t n, TriloTofu target) {
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

// Function to print the data in a TriloTofu instance
void trilo_xdata_tofu_print(TriloTofu tofu) {
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

// Function to get the integer data from a TriloTofu instance
int trilo_xdata_tofu_get_integer(TriloTofu tofu) {
    if (tofu.type == INTEGER_TYPE) {
        return tofu.data.integer_type;
    } // end if
    return 0; // Return a default value or handle the error as needed
} // end of func

// Function to get the double data from a TriloTofu instance
double trilo_xdata_tofu_get_double(TriloTofu tofu) {
    if (tofu.type == DOUBLE_TYPE) {
        return tofu.data.double_type;
    } // end if
    return 0.0; // Return a default value or handle the error as needed
} // end of func

// Function to get the string data from a TriloTofu instance
const char* trilo_xdata_tofu_get_string(TriloTofu tofu) {
    if (tofu.type == STRING_TYPE) {
        return tofu.data.string_type;
    } // end if
    return ""; // Return a default value or handle the error as needed
} // end of func

// Function to get the char data from a TriloTofu instance
char trilo_xdata_tofu_get_char(TriloTofu tofu) {
    if (tofu.type == CHAR_TYPE) {
        return tofu.data.char_type;
    } // end if
    return '\0'; // Return a default value or handle the error as needed
} // end of func

// Function to get the boolean data from a TriloTofu instance
bool trilo_xdata_tofu_get_boolean(TriloTofu tofu) {
    if (tofu.type == BOOLEAN_TYPE) {
        return tofu.data.boolean_type;
    } // end if
    return false; // Return a default value or handle the error as needed
} // end of func
