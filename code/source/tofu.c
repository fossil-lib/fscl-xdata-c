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

// Function to check if a ctofu object is even
bool isEven(const ctofu* value) {
    if (value->type == TOFU_INT_TYPE) {
        return (value->data.intager_type % 2 == 0);
    }
    return false;  // Return false for unsupported types
}

// Function to sum two ctofu objects
ctofu sumReducer(const ctofu* a, const ctofu* b) {
    ctofu result;
    if (a->type == TOFU_INT_TYPE && b->type == TOFU_INT_TYPE) {
        result.type = TOFU_INT_TYPE;
        result.data.intager_type = a->data.intager_type + b->data.intager_type;
    } else {
        // Return a default value for unsupported types
        result.type = TOFU_INT_TYPE;
        result.data.intager_type = 0;
    }
    return result;
}

char* tofu_custom_strdup(const char* source) {
    if (source == NULL) {
        return NULL;
    }

    size_t length = strlen(source) + 1;  // +1 for the null terminator
    char* destination = (char*)malloc(length);

    if (destination != NULL) {
        memcpy(destination, source, length);
    }

    return destination;
}

// create and erase
ctofu_error fscl_tofu_create(ctofu_type type, ctofu_data* value, ctofu** result) {
    *result = (ctofu*)malloc(sizeof(ctofu));
    if (*result == NULL) {
        return TOFU_WAS_BAD_MALLOC;
    }
    
    (*result)->type = type;

    switch(type) {
        case TOFU_INT_TYPE:
            (*result)->data.intager_type = value->intager_type;
            break;
        case TOFU_INT8_TYPE:
            (*result)->data.int8_type = value->int8_type;
            break;
        case TOFU_INT16_TYPE:
            (*result)->data.int16_type = value->int16_type;
            break;
        case TOFU_INT32_TYPE:
            (*result)->data.int32_type = value->int32_type;
            break;
        case TOFU_INT64_TYPE:
            (*result)->data.int64_type = value->int64_type;
            break;
        case TOFU_UINT_TYPE:
            (*result)->data.uint_type = value->uint_type;
            break;
        case TOFU_UINT8_TYPE:
            (*result)->data.uint8_type = value->uint8_type;
            break;
        case TOFU_UINT16_TYPE:
            (*result)->data.uint16_type = value->uint16_type;
            break;
        case TOFU_UINT32_TYPE:
            (*result)->data.uint32_type = value->uint32_type;
            break;
        case TOFU_UINT64_TYPE:
            (*result)->data.uint64_type = value->uint64_type;
            break;
        case TOFU_FLOAT_TYPE:
            (*result)->data.float_type = value->float_type;
            break;
        case TOFU_DOUBLE_TYPE:
            (*result)->data.double_type = value->double_type;
            break;
        case TOFU_OCTAL8_TYPE:
            (*result)->data.octal8_type = value->octal8_type;
            break;
        case TOFU_OCTAL16_TYPE:
            (*result)->data.octal16_type = value->octal16_type;
            break;
        case TOFU_OCTAL32_TYPE:
            (*result)->data.octal32_type = value->octal32_type;
            break;
        case TOFU_OCTAL64_TYPE:
            (*result)->data.octal64_type = value->octal64_type;
            break;
        case TOFU_BITWISE8_TYPE:
            (*result)->data.bitwise8_type = value->bitwise8_type;
            break;
        case TOFU_BITWISE16_TYPE:
            (*result)->data.bitwise16_type = value->bitwise16_type;
            break;
        case TOFU_BITWISE32_TYPE:
            (*result)->data.bitwise32_type = value->bitwise32_type;
            break;
        case TOFU_BITWISE64_TYPE:
            (*result)->data.bitwise64_type = value->bitwise64_type;
            break;
        case TOFU_HEX8_TYPE:
            (*result)->data.hex8_type = value->hex8_type;
            break;
        case TOFU_HEX16_TYPE:
            (*result)->data.hex16_type = value->hex16_type;
            break;
        case TOFU_HEX32_TYPE:
            (*result)->data.hex32_type = value->hex32_type;
            break;
        case TOFU_HEX64_TYPE:
            (*result)->data.hex64_type = value->hex64_type;
            break;
        case TOFU_NULLPTR_TYPE:
            (*result)->data.nullptr_type = value->nullptr_type;
            break;
        case TOFU_CHAR_TYPE:
            (*result)->data.char_type = value->char_type;
            break;
        case TOFU_BOOLEAN_TYPE:
            (*result)->data.boolean_type = value->boolean_type;
            break;
        case TOFU_ARRAY_TYPE:
            (*result)->data.array_type = value->array_type;
            break;
        case TOFU_QBIT_TYPE:
            (*result)->data.qbit_type = value->qbit_type;
            break;
        case TOFU_STRING_TYPE:
            (*result)->data.string_type = tofu_custom_strdup(value->string_type);
            if ((*result)->data.string_type == NULL) {
                free(*result);
                return TOFU_WAS_BAD_MALLOC;
            }
            break;
        default:
            // Handle other cases if needed
            free(*result);
            return TOFU_INVALID_TYPE;
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
ctofu_error fscl_tofu_filter(ctofu* objects, size_t num, ctofu* result, bool (*filterFunc)(const ctofu*)) {
    if (objects == NULL || result == NULL || filterFunc == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    size_t filteredCount = 0;

    // Count the number of elements that pass the filter
    for (size_t i = 0; i < num; ++i) {
        if (filterFunc(&objects[i])) {
            ++filteredCount;
        }
    }

    // Allocate memory for the result array
    result->type = TOFU_ARRAY_TYPE;
    result->data.array_type.size = filteredCount;
    result->data.array_type.elements = (ctofu*)malloc(filteredCount * sizeof(ctofu));
    if (result->data.array_type.elements == NULL) {
        return TOFU_WAS_BAD_MALLOC;
    }

    // Populate the result array with elements that pass the filter
    size_t resultIndex = 0;
    for (size_t i = 0; i < num; ++i) {
        if (filterFunc(&objects[i])) {
            fscl_tofu_value_copy(&objects[i], &result->data.array_type.elements[resultIndex]);
            ++resultIndex;
        }
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_reduce(ctofu* objects, size_t num, ctofu* result, ctofu (*reduceFunc)(const ctofu*, const ctofu*)) {
    if (objects == NULL || result == NULL || reduceFunc == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    if (num == 0) {
        // Return a default value for an empty array
        result->type = TOFU_INT_TYPE;
        result->data.intager_type = 0;
        return TOFU_SUCCESS;
    }

    // Initialize the result with the first element
    fscl_tofu_value_copy(&objects[0], result);

    // Apply the reduce function to the remaining elements
    for (size_t i = 1; i < num; ++i) {
        ctofu tempResult = reduceFunc(result, &objects[i]);
        fscl_tofu_value_setter(&tempResult, result);
        fscl_tofu_value_erase(&tempResult);
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_accumulate(ctofu* objects, size_t num, ctofu* result) {
    if (objects == NULL || result == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    result->type = TOFU_INT_TYPE;
    result->data.intager_type = 0;

    for (size_t i = 0; i < num; ++i) {
        if (objects[i].type != TOFU_INT_TYPE) {
            // Handle unsupported types
            printf("Unsupported type for accumulation\n");
            return TOFU_WAS_UNKNOWN;
        }
        result->data.intager_type += objects[i].data.intager_type;
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_transform(ctofu* objects, size_t num, ctofu* result, int (*transformFunc)(int)) {
    if (objects == NULL || result == NULL || transformFunc == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    result->type = TOFU_ARRAY_TYPE;
    result->data.array_type.size = num;
    result->data.array_type.elements = (ctofu*)malloc(num * sizeof(ctofu));
    if (result->data.array_type.elements == NULL) {
        return TOFU_WAS_BAD_MALLOC;
    }

    for (size_t i = 0; i < num; ++i) {
        if (objects[i].type != TOFU_INT_TYPE) {
            // Handle unsupported types
            printf("Unsupported type for transformation\n");
            return TOFU_WAS_UNKNOWN;
        }
        result->data.array_type.elements[i].type = TOFU_INT_TYPE;
        result->data.array_type.elements[i].data.intager_type = transformFunc(objects[i].data.intager_type);
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_shuffle(ctofu* objects, size_t num) {
    if (objects == NULL || num <= 1) {
        return TOFU_WAS_NULLPTR;  // or TOFU_NOT_FOUND, depending on your preference
    }

    for (size_t i = num - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap elements i and j
        ctofu temp = objects[i];
        objects[i] = objects[j];
        objects[j] = temp;
    }

    return TOFU_SUCCESS;
}

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

    if (a->type != b->type) {
        // Types are different, cannot compare
        printf("Incompatible types for comparison\n");
        return TOFU_WAS_MISMATCH;
    }

    switch (a->type) {
        case TOFU_INT_TYPE:
            *result = a->data.intager_type - b->data.intager_type;
            break;

        case TOFU_INT8_TYPE:
            *result = (int)a->data.int8_type - (int)b->data.int8_type;
            break;
        case TOFU_INT16_TYPE:
            *result = (int)a->data.int16_type - (int)b->data.int16_type;
            break;
        case TOFU_INT32_TYPE:
            *result = (int)a->data.int32_type - (int)b->data.int32_type;
            break;
        case TOFU_INT64_TYPE:
            *result = (int)a->data.int64_type - (int)b->data.int64_type;
            break;
        case TOFU_UINT_TYPE:
            *result = (int)a->data.uint_type - (int)b->data.uint_type;
            break;
        case TOFU_UINT8_TYPE:
            *result = (int)a->data.uint8_type - (int)b->data.uint8_type;
            break;
        case TOFU_UINT16_TYPE:
            *result = (int)a->data.uint16_type - (int)b->data.uint16_type;
            break;
        case TOFU_UINT32_TYPE:
            *result = (int)a->data.uint32_type - (int)b->data.uint32_type;
            break;
        case TOFU_UINT64_TYPE:
            *result = (int)a->data.uint64_type - (int)b->data.uint64_type;
            break;
        case TOFU_FLOAT_TYPE:
            if (a->data.float_type < b->data.float_type) {
                *result = -1;
            } else if (a->data.float_type > b->data.float_type) {
                *result = 1;
            } else {
                *result = 0;
            }
            break;
        case TOFU_DOUBLE_TYPE:
            if (a->data.double_type < b->data.double_type) {
                *result = -1;
            } else if (a->data.double_type > b->data.double_type) {
                *result = 1;
            } else {
                *result = 0;
            }
            break;
        case TOFU_STRING_TYPE:
            *result = strcmp(a->data.string_type, b->data.string_type);
            break;
        case TOFU_HEX8_TYPE:
            *result = (int)a->data.hex8_type - (int)b->data.hex8_type;
            break;
        case TOFU_HEX16_TYPE:
            *result = (int)a->data.hex16_type - (int)b->data.hex16_type;
            break;
        case TOFU_HEX32_TYPE:
            *result = (int)a->data.hex32_type - (int)b->data.hex32_type;
            break;
        case TOFU_HEX64_TYPE:
            *result = (int)a->data.hex64_type - (int)b->data.hex64_type;
            break;
        case TOFU_BITWISE8_TYPE:
            *result = (int)a->data.bitwise8_type - (int)b->data.bitwise8_type;
            break;
        case TOFU_BITWISE16_TYPE:
            *result = (int)a->data.bitwise16_type - (int)b->data.bitwise16_type;
            break;
        case TOFU_BITWISE32_TYPE:
            *result = (int)a->data.bitwise32_type - (int)b->data.bitwise32_type;
            break;
        case TOFU_BITWISE64_TYPE:
            *result = (int)a->data.bitwise64_type - (int)b->data.bitwise64_type;
            break;
        case TOFU_QBIT_TYPE:
            *result = (int)a->data.qbit_type - (int)b->data.qbit_type;
            break;
        case TOFU_OCTAL8_TYPE:
            *result = (int)a->data.octal8_type - (int)b->data.octal8_type;
                break;
        case TOFU_OCTAL16_TYPE:
            *result = (int)a->data.octal16_type - (int)b->data.octal16_type;
                break;
        case TOFU_OCTAL32_TYPE:
            *result = (int)a->data.octal32_type - (int)b->data.octal32_type;
                break;
        case TOFU_OCTAL64_TYPE:
            *result = (int)a->data.octal64_type - (int)b->data.octal64_type;
            break;
        case TOFU_NULLPTR_TYPE:
            *result = 0;  // Null pointers are considered equal
            break;
        case TOFU_ARRAY_TYPE:
            // Compare arrays based on their elements and size
            if (a->data.array_type.size != b->data.array_type.size) {
                *result = a->data.array_type.size - b->data.array_type.size;
            } else {
                for (size_t i = 0; i < a->data.array_type.size; ++i) {
                    ctofu elementA = a->data.array_type.elements[i];
                    ctofu elementB = b->data.array_type.elements[i];
                    int elementResult;
                    
                    // Recursive comparison for array elements
                    ctofu_error elementComparisonResult = fscl_tofu_compare(&elementA, &elementB, &elementResult);
                    if (elementComparisonResult != TOFU_SUCCESS) {
                        return elementComparisonResult;
                    }

                    if (elementResult != 0) {
                        *result = elementResult;
                        break;  // Stop comparison if elements are not equal
                    }
                }
            }
            break;

        default:
            // Handle unsupported types
            puts("Unsupported type for comparison must be a ghost type");
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
        case TOFU_INT_TYPE:
            dest->data.intager_type = source->data.intager_type;
            break;

        case TOFU_INT8_TYPE:
            dest->data.int8_type = source->data.int8_type;
            break;

        case TOFU_INT16_TYPE:
            dest->data.int16_type = source->data.int16_type;
            break;

        case TOFU_INT32_TYPE:
            dest->data.int32_type = source->data.int32_type;
            break;

        case TOFU_INT64_TYPE:
            dest->data.int64_type = source->data.int64_type;
            break;

        case TOFU_UINT_TYPE:
            dest->data.uint_type = source->data.uint_type;
            break;

        case TOFU_UINT8_TYPE:
            dest->data.uint8_type = source->data.uint8_type;
            break;

        case TOFU_UINT16_TYPE:
            dest->data.uint16_type = source->data.uint16_type;
            break;

        case TOFU_UINT32_TYPE:
            dest->data.uint32_type = source->data.uint32_type;
            break;

        case TOFU_UINT64_TYPE:
            dest->data.uint64_type = source->data.uint64_type;
            break;

        case TOFU_OCTAL8_TYPE:
            dest->data.octal8_type = source->data.octal8_type;
            break;

        case TOFU_OCTAL16_TYPE:
            dest->data.octal16_type = source->data.octal16_type;
            break;

        case TOFU_OCTAL32_TYPE:
            dest->data.octal32_type = source->data.octal32_type;
            break;

        case TOFU_OCTAL64_TYPE:
            dest->data.octal64_type = source->data.octal64_type;
            break;

        case TOFU_BITWISE8_TYPE:
            dest->data.bitwise8_type = source->data.bitwise8_type;
            break;

        case TOFU_BITWISE16_TYPE:
            dest->data.bitwise16_type = source->data.bitwise16_type;
            break;

        case TOFU_BITWISE32_TYPE:
            dest->data.bitwise32_type = source->data.bitwise32_type;
            break;

        case TOFU_BITWISE64_TYPE:
            dest->data.bitwise64_type = source->data.bitwise64_type;
            break;

        case TOFU_HEX8_TYPE:
            dest->data.hex8_type = source->data.hex8_type;
            break;

        case TOFU_HEX16_TYPE:
            dest->data.hex16_type = source->data.hex16_type;
            break;

        case TOFU_HEX32_TYPE:
            dest->data.hex32_type = source->data.hex32_type;
            break;

        case TOFU_HEX64_TYPE:
            dest->data.hex64_type = source->data.hex64_type;
            break;

        case TOFU_FLOAT_TYPE:
            dest->data.float_type = source->data.float_type;
            break;

        case TOFU_DOUBLE_TYPE:
            dest->data.double_type = source->data.double_type;
            break;

        case TOFU_STRING_TYPE:
            source->data.string_type = tofu_custom_strdup(dest->data.string_type);
            break;

        case TOFU_CHAR_TYPE:
            dest->data.char_type = source->data.char_type;
            break;

        case TOFU_BOOLEAN_TYPE:
            dest->data.boolean_type = source->data.boolean_type;
            break;

        case TOFU_ARRAY_TYPE:
            // Check if both arrays have the same type
            if (a->data.array_type.size != b->data.array_type.size) {
                *result = a->data.array_type.size - b->data.array_type.size;
            } else if (a->data.array_type.elements[0].type != b->data.array_type.elements[0].type) {
                printf("Incompatible array element types for comparison\n");
                return TOFU_WAS_MISMATCH;
            } else {
                // Copy array A to array B
                dest->data.array_type.size = a->data.array_type.size;
                dest->data.array_type.elements = (ctofu*)malloc(dest->data.array_type.size * sizeof(ctofu));
                if (dest->data.array_type.elements == NULL) {
                    return TOFU_WAS_BAD_MALLOC;
                }
        
                for (size_t i = 0; i < dest->data.array_type.size; ++i) {
                    ctofu_error elementCopyResult = fscl_tofu_value_copy(&a->data.array_type.elements[i], &dest->data.array_type.elements[i]);
                    if (elementCopyResult != TOFU_SUCCESS) {
                        // Cleanup on failure
                        for (size_t j = 0; j < i; ++j) {
                            fscl_tofu_value_erase(&dest->data.array_type.elements[j]);
                        }
                        free(dest->data.array_type.elements);
                        dest->data.array_type.elements = NULL;
                        return elementCopyResult;
                    }
                }
            }
            break;

        case TOFU_QBIT_TYPE:
            dest->data.qbit_type = source->data.qbit_type;
            break;

        case TOFU_NULLPTR_TYPE:
            dest->data.nullptr_type = source->data.nullptr_type;
            break;

        default:
            // Handle unsupported types
            printf("Unsupported type for value copy\n");
            return TOFU_WAS_UNKNOWN;
    }

    return TOFU_SUCCESS;
}

void fscl_tofu_value_erase(ctofu* value) {
    if (value == NULL) {
        return;
    }

    switch (value->type) {
        case TOFU_STRING_TYPE:
            free(value->data.string_type);
            break;

        case TOFU_ARRAY_TYPE:
            for (size_t i = 0; i < value->data.array_type.size; ++i) {
                fscl_tofu_value_erase(&value->data.array_type.elements[i]);
            }
            free(value->data.array_type.elements);
            break;

        default:
            // No specific cleanup needed for other types
            break;
    }
}

void fscl_tofu_value_setter(const ctofu* source, ctofu* dest) {
    if (source == NULL || dest == NULL) {
        return;
    }

    dest->type = source->type;

    switch (source->type) {
        case TOFU_INT_TYPE:
            dest->data.intager_type = source->data.intager_type;
            break;

        case TOFU_INT8_TYPE:
            dest->data.int8_type = source->data.int8_type;
            break;

        case TOFU_INT16_TYPE:
            dest->data.int16_type = source->data.int16_type;
            break;

        case TOFU_INT32_TYPE:
            dest->data.int32_type = source->data.int32_type;
            break;

        case TOFU_INT64_TYPE:
            dest->data.int64_type = source->data.int64_type;
            break;

        case TOFU_UINT_TYPE:
            dest->data.uint_type = source->data.uint_type;
            break;

        case TOFU_UINT8_TYPE:
            dest->data.uint8_type = source->data.uint8_type;
            break;

        case TOFU_UINT16_TYPE:
            dest->data.uint16_type = source->data.uint16_type;
            break;

        case TOFU_UINT32_TYPE:
            dest->data.uint32_type = source->data.uint32_type;
            break;

        case TOFU_UINT64_TYPE:
            dest->data.uint64_type = source->data.uint64_type;
            break;

        case TOFU_OCTAL8_TYPE:
            dest->data.octal8_type = source->data.octal8_type;
            break;

        case TOFU_OCTAL16_TYPE:
            dest->data.octal16_type = source->data.octal16_type;
            break;

        case TOFU_OCTAL32_TYPE:
            dest->data.octal32_type = source->data.octal32_type;
            break;

        case TOFU_OCTAL64_TYPE:
            dest->data.octal64_type = source->data.octal64_type;
            break;

        case TOFU_BITWISE8_TYPE:
            dest->data.bitwise8_type = source->data.bitwise8_type;
            break;

        case TOFU_BITWISE16_TYPE:
            dest->data.bitwise16_type = source->data.bitwise16_type;
            break;

        case TOFU_BITWISE32_TYPE:
            dest->data.bitwise32_type = source->data.bitwise32_type;
            break;

        case TOFU_BITWISE64_TYPE:
            dest->data.bitwise64_type = source->data.bitwise64_type;
            break;

        case TOFU_HEX8_TYPE:
            dest->data.hex8_type = source->data.hex8_type;
            break;

        case TOFU_HEX16_TYPE:
            dest->data.hex16_type = source->data.hex16_type;
            break;

        case TOFU_HEX32_TYPE:
            dest->data.hex32_type = source->data.hex32_type;
            break;

        case TOFU_HEX64_TYPE:
            dest->data.hex64_type = source->data.hex64_type;
            break;

        case TOFU_FLOAT_TYPE:
            dest->data.float_type = source->data.float_type;
            break;

        case TOFU_DOUBLE_TYPE:
            dest->data.double_type = source->data.double_type;
            break;

        case TOFU_STRING_TYPE:
            source->data.string_type = tofu_custom_strdup(dest->data.string_type);
            break;

        case TOFU_CHAR_TYPE:
            dest->data.char_type = source->data.char_type;
            break;

        case TOFU_BOOLEAN_TYPE:
            dest->data.boolean_type = source->data.boolean_type;
            break;

        case TOFU_ARRAY_TYPE:
            // Check if both arrays have the same type
            if (source->data.array_type.size != dest->data.array_type.size ||
                source->data.array_type.elements[0].type != dest->data.array_type.elements[0].type) {
                printf("Incompatible array types for value setter\n");
                break;  // or return an error code
            }
        
            // Set array B to array A
            dest->data.array_type.size = source->data.array_type.size;
        
            // Cleanup existing array elements in B
            for (size_t i = 0; i < dest->data.array_type.size; ++i) {
                fscl_tofu_value_erase(&dest->data.array_type.elements[i]);
            }
        
            // Allocate memory for new array elements in B
            dest->data.array_type.elements = (ctofu*)malloc(dest->data.array_type.size * sizeof(ctofu));
            if (dest->data.array_type.elements == NULL) {
                // Handle memory allocation failure
                printf("Memory allocation failed for array elements\n");
                break;  // or return an error code
            }
        
            // Copy elements from A to B
            for (size_t i = 0; i < dest->data.array_type.size; ++i) {
                fscl_tofu_value_setter(&source->data.array_type.elements[i], &dest->data.array_type.elements[i]);
            }
            break;


        case TOFU_QBIT_TYPE:
            dest->data.qbit_type = source->data.qbit_type;
            break;

        case TOFU_NULLPTR_TYPE:
            dest->data.nullptr_type = source->data.nullptr_type;
            break;

        default:
            // Handle unsupported types
            printf("Unsupported type for value setter\n");
    }
}

ctofu_data fscl_tofu_value_getter(const ctofu* current) {
    ctofu_data result;

    if (current == NULL) {
        // You might want to handle this case differently based on your requirements
        result.intager_type = 0;
        return result;
    }

    switch (current->type) {
        case TOFU_INT_TYPE:
            result.intager_type = current->data.intager_type;
            break;

        case TOFU_INT8_TYPE:
            result.int8_type = current->data.int8_type;
            break;

        case TOFU_INT16_TYPE:
            result.int16_type = current->data.int16_type;
            break;

        case TOFU_INT32_TYPE:
            result.int32_type = current->data.int32_type;
            break;

        case TOFU_INT64_TYPE:
            result.int64_type = current->data.int64_type;
            break;

        case TOFU_UINT_TYPE:
            result.uint_type = current->data.uint_type;
            break;

        case TOFU_UINT8_TYPE:
            result.uint8_type = current->data.uint8_type;
            break;

        case TOFU_UINT16_TYPE:
            result.uint16_type = current->data.uint16_type;
            break;

        case TOFU_UINT32_TYPE:
            result.uint32_type = current->data.uint32_type;
            break;

        case TOFU_UINT64_TYPE:
            result.uint64_type = current->data.uint64_type;
            break;

        case TOFU_OCTAL8_TYPE:
            result.octal8_type = current->data.octal8_type;
            break;

        case TOFU_OCTAL16_TYPE:
            result.octal16_type = current->data.octal16_type;
            break;

        case TOFU_OCTAL32_TYPE:
            result.octal32_type = current->data.octal32_type;
            break;

        case TOFU_OCTAL64_TYPE:
            result.octal64_type = current->data.octal64_type;
            break;

        case TOFU_BITWISE8_TYPE:
            result.bitwise8_type = current->data.bitwise8_type;
            break;

        case TOFU_BITWISE16_TYPE:
            result.bitwise16_type = current->data.bitwise16_type;
            break;

        case TOFU_BITWISE32_TYPE:
            result.bitwise32_type = current->data.bitwise32_type;
            break;

        case TOFU_BITWISE64_TYPE:
            result.bitwise64_type = current->data.bitwise64_type;
            break;

        case TOFU_HEX8_TYPE:
            result.hex8_type = current->data.hex8_type;
            break;

        case TOFU_HEX16_TYPE:
            result.hex16_type = current->data.hex16_type;
            break;

        case TOFU_HEX32_TYPE:
            result.hex32_type = current->data.hex32_type;
            break;

        case TOFU_HEX64_TYPE:
            result.hex64_type = current->data.hex64_type;
            break;

        case TOFU_FLOAT_TYPE:
            result.float_type = current->data.float_type;
            break;

        case TOFU_DOUBLE_TYPE:
            result.double_type = current->data.double_type;
            break;

        case TOFU_STRING_TYPE:
            result.string_type = current->data.string_type;
            break;

        case TOFU_CHAR_TYPE:
            result.char_type = current->data.char_type;
            break;

        case TOFU_BOOLEAN_TYPE:
            result.boolean_type = current->data.boolean_type;
            break;

        case TOFU_QBIT_TYPE:
            result.qbit_type = current->data.qbit_type;
            break;

        case TOFU_NULLPTR_TYPE:
            result.nullptr_type = current->data.nullptr_type;
            break;

        default:
            // Handle unsupported types
            printf("Unsupported type for value getter\n");
            // You might want to set a default value or handle this case differently
            result.intager_type = 0;
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

// Move the iterator to the next element
void fscl_tofu_iterator_next(ctofu_iterator* iterator, size_t num) {
    if (iterator->index < num - 1) {
        ++iterator->index;
        iterator->current = &array[iterator->index];
    } else {
        iterator->current = NULL;  // End of array
    }
}

// Move the iterator to the previous element
void fscl_tofu_iterator_prev(ctofu_iterator* iterator, size_t num) {
    if (iterator->index > 0) {
        --iterator->index;
        iterator->current = &array[iterator->index];
    } else {
        iterator->current = NULL;  // Beginning of array
    }
}

// Move the iterator to a specific index
void fscl_tofu_iterator_jump(ctofu_iterator* iterator, size_t num, size_t index) {
    if (index < num) {
        iterator->index = index;
        iterator->current = &array[iterator->index];
    } else {
        iterator->current = NULL;  // Out of bounds
    }
}
