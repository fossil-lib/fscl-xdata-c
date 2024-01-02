/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xdata/tofu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create and erase
ctofu_error fscl_tofu_create(ctofu_type type, ctofu_data* value, ctofu** result) {
    *result = (ctofu*)malloc(sizeof(ctofu));
    if (*result == NULL) {
        return TOFU_WAS_BAD_MALLOC;
    }
    
    (*result)->type = type;

    switch(type) {
        case INTEGER_TYPE:
            (*result)->data.integer_type = value->integer_type;
            break;
        case DOUBLE_TYPE:
            (*result)->data.double_type = value->double_type;
            break;
        case STRING_TYPE:
            (*result)->data.string_type = value->string_type;
            break;
        case CHAR_TYPE:
            (*result)->data.char_type = value->char_type;
            break;
        case BOOLEAN_TYPE:
            (*result)->data.boolean_type = value->boolean_type;
            break;
        case ARRAY_TYPE:
            (*result)->data.array_type = value->array_type;
            break;
        default:
            // Handle other cases if needed
            break;
    }

    return TOFU_SUCCESS;
}

void fscl_tofu_erase(ctofu* value) {
    if (value != NULL) {
        free(value);
    }
}

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_tofu_sort_insertion(ctofu* array, size_t num) {
    if (array == NULL || num == 0) {
        return TOFU_WAS_NULLPTR;
    }

    for (size_t i = 1; i < num; ++i) {
        ctofu key = array[i];
        size_t j = i;

        while (j > 0) {
            int cmpResult;
            ctofu_error compareError = fscl_tofu_compare(&array[j - 1], &key, &cmpResult);
            if (compareError != TOFU_SUCCESS) {
                return compareError;
            }

            if (cmpResult > 0) {
                array[j] = array[j - 1];
                --j;
            } else {
                break;
            }
        }

        array[j] = key;
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_sort_selection(ctofu* array, size_t num) {
    if (array == NULL || num == 0) {
        return TOFU_WAS_NULLPTR;
    }

    for (size_t i = 0; i < num - 1; ++i) {
        size_t min_index = i;

        for (size_t j = i + 1; j < num; ++j) {
            int cmpResult;
            ctofu_error compareError = fscl_tofu_compare(&array[j], &array[min_index], &cmpResult);
            if (compareError != TOFU_SUCCESS) {
                return compareError;
            }

            if (cmpResult < 0) {
                min_index = j;
            }
        }

        if (min_index != i) {
            ctofu temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }

    return TOFU_SUCCESS;
}

size_t fscl_tofu_search_linear(ctofu* array, size_t num, ctofu* key) {
    if (array == NULL || num == 0 || key == NULL) {
        return num; // Not found
    }

    for (size_t i = 0; i < num; ++i) {
        int cmpResult;
        ctofu_error compareError = fscl_tofu_compare(&array[i], key, &cmpResult);
        if (compareError != TOFU_SUCCESS) {
            // Handle comparison error
            return num; // Not found
        }

        if (cmpResult == 0) {
            return i; // Found
        }
    }

    return num; // Not found
}

size_t fscl_tofu_search_binary(ctofu* array, size_t num, ctofu* key) {
    if (array == NULL || num == 0 || key == NULL) {
        return num; // Not found
    }

    size_t low = 0, high = num - 1;

    while (low <= high) {
        size_t mid = low + (high - low) / 2;

        int cmpResult;
        ctofu_error compareError = fscl_tofu_compare(&array[mid], key, &cmpResult);
        if (compareError != TOFU_SUCCESS) {
            // Handle comparison error
            return num; // Not found
        }

        if (cmpResult == 0) {
            return mid; // Found
        } else if (cmpResult < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return num; // Not found
}

ctofu_error fscl_tofu_reverse(ctofu* array, size_t num) {
    if (array == NULL || num == 0) {
        return TOFU_WAS_NULLPTR;
    }

    size_t start = 0;
    size_t end = num - 1;

    while (start < end) {
        // Swap elements at start and end indices
        ctofu temp = array[start];
        array[start] = array[end];
        array[end] = temp;

        // Move indices towards each other
        ++start;
        --end;
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_compare(const ctofu* a, const ctofu* b, int* result) {
    if (a == NULL || b == NULL || result == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    switch (a->type) {
        case INTEGER_TYPE:
            *result = a->data.integer_type - b->data.integer_type;
            break;

        case DOUBLE_TYPE:
            if (a->data.double_type < b->data.double_type) {
                *result = -1;
            } else if (a->data.double_type > b->data.double_type) {
                *result = 1;
            } else {
                *result = 0;
            }
            break;

        case STRING_TYPE:
            // Assuming string comparison for demonstration purposes
            *result = strcmp(a->data.string_type, b->data.string_type);
            break;

        // Add cases for other types as needed

        default:
            // Handle unsupported types
            printf("Unsupported type for comparison\n");
            return TOFU_WAS_UNKNOWN;
    }

    return TOFU_SUCCESS;
}

// =======================
// UTILITY FUNCTIONS
// =======================
ctofu_error fscl_tofu_value_copy(const ctofu* source, ctofu* dest) {
    if (source == NULL || dest == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    dest->type = source->type;

    switch (source->type) {
        case INTEGER_TYPE:
            dest->data.integer_type = source->data.integer_type;
            break;

        case DOUBLE_TYPE:
            dest->data.double_type = source->data.double_type;
            break;

        case STRING_TYPE:
            // Using strcpy for string copy
            strcpy(dest->data.string_type, source->data.string_type);
            break;

        case CHAR_TYPE:
            dest->data.char_type = source->data.char_type;
            break;

        case BOOLEAN_TYPE:
            dest->data.boolean_type = source->data.boolean_type;
            break;

        case ARRAY_TYPE:
            // Copying array type may require a more complex logic
            // You might want to iterate through the array elements and copy each one
            return TOFU_WAS_UNKNOWN;

        // Add cases for other types as needed

        default:
            // Handle unsupported types
            printf("Unsupported type for value copy\n");
            return TOFU_WAS_UNKNOWN;
    }

    return TOFU_SUCCESS;
}

void fscl_tofu_value_setter(const ctofu* source, ctofu* dest) {
    if (source == NULL || dest == NULL) {
        return;
    }

    dest->type = source->type;

    switch (source->type) {
        case INTEGER_TYPE:
            dest->data.integer_type = source->data.integer_type;
            break;

        case DOUBLE_TYPE:
            dest->data.double_type = source->data.double_type;
            break;

        case STRING_TYPE:
            // Using strcpy for string copy
            strcpy(dest->data.string_type, source->data.string_type);
            break;

        case CHAR_TYPE:
            dest->data.char_type = source->data.char_type;
            break;

        case BOOLEAN_TYPE:
            dest->data.boolean_type = source->data.boolean_type;
            break;

        case ARRAY_TYPE:
            // Copying array type may require a more complex logic
            // You might want to iterate through the array elements and copy each one
            break;

        // Add cases for other types as needed

        default:
            // Handle unsupported types
            printf("Unsupported type for value setter\n");
    }
}

ctofu_data fscl_tofu_value_getter(const ctofu* current) {
    ctofu_data result;

    if (current == NULL) {
        // You might want to handle this case differently based on your requirements
        result.integer_type = 0;
        return result;
    }

    switch (current->type) {
        case INTEGER_TYPE:
            result.integer_type = current->data.integer_type;
            break;

        case DOUBLE_TYPE:
            result.double_type = current->data.double_type;
            break;

        case STRING_TYPE:
            result.string_type = current->data.string_type;
            break;

        case CHAR_TYPE:
            result.char_type = current->data.char_type;
            break;

        case BOOLEAN_TYPE:
            result.boolean_type = current->data.boolean_type;
            break;

        case ARRAY_TYPE:
        case NULLPTR_TYPE:
        default:
            // Handle unsupported types
            printf("Unsupported type for value getter\n");
            // You might want to set a default value or handle this case differently
            result.integer_type = 0;
    }

    return result;
}

ctofu_type fscl_tofu_type_getter(const ctofu* current) {
    if (current == NULL) {
        // You might want to handle this case differently based on your requirements
        return INVALID_TYPE;
    }

    return current->type;
}

bool fscl_tofu_not_cnullptr(const ctofu* value) {
    return value != NULL;
}

bool fscl_tofu_its_cnullptr(const ctofu* value) {
    return value == NULL;
}

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator fscl_tofu_iterator_at(ctofu* array, size_t num, size_t at) {
    ctofu_iterator iterator;

    if (array == NULL || num == 0 || at >= num) {
        iterator.current_value = NULL;
        iterator.index = num;
        return iterator;
    }

    iterator.current_value = &array[at];
    iterator.index = at;

    return iterator;
}

ctofu_iterator fscl_tofu_iterator_start(ctofu* array, size_t num) {
    return fscl_tofu_iterator_at(array, num, 0);
}

ctofu_iterator fscl_tofu_iterator_end(ctofu* array, size_t num) {
    return fscl_tofu_iterator_at(array, num, num);
}
