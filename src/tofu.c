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

// Function to convert TriloTofu to an integer
int trilo_xdata_tofu_to_integer(TriloTofu tofu) {
    if (tofu.type == INTEGER_TYPE) {
        return tofu.data.integer_type;
    } // end if
    return 0; // Return a default value or handle the error as needed
} // end of func

// Function to convert TriloTofu to a double
double trilo_xdata_tofu_to_double(TriloTofu tofu) {
    if (tofu.type == DOUBLE_TYPE) {
        return tofu.data.double_type;
    } // end if
    return 0.0; // Return a default value or handle the error as needed
} // end of func

// Function to convert TriloTofu to a string
char* trilo_xdata_tofu_to_string(TriloTofu tofu) {
    if (tofu.type == STRING_TYPE) {
        char value[100];
        strcpy(value, tofu.data.string_type);
        return value;
    } // end if
    return ""; // Return a default value or handle the error as needed
} // end of func

// Function to convert TriloTofu to a char
char trilo_xdata_tofu_to_char(TriloTofu tofu) {
    if (tofu.type == CHAR_TYPE) {
        return tofu.data.char_type;
    } // end if
    return '\0'; // Return a default value or handle the error as needed
} // end of func

// Function to convert TriloTofu to a bool
bool trilo_xdata_tofu_to_boolean(TriloTofu tofu) {
    if (tofu.type == BOOLEAN_TYPE) {
        return tofu.data.boolean_type;
    } // end if
    return false; // Return a default value or handle the error as needed
} // end of func
