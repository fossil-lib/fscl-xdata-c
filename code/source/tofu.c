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
// SMART ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_tofu_smart_accumulate(ctofu* objects, const char *algorithm) {
    if (!objects) {
        return TOFU_WAS_NULLPTR;
    }

    if (strcmp(algorithm, "auto") == 0) {
        // Automatically select an appropriate algorithm based on size and type
        // ...

    } else if (strcmp(algorithm, "std") == 0) {
        // Use the existing classic version
        if (fscl_tofu_not_cnullptr(objects)) {
            if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
                return TOFU_WAS_BAD_RANGE;
            }
            return fscl_tofu_accumulate(objects->data.array_type.elements);
        } else {
            return TOFU_WAS_NULLPTR;
        }

    } else {
        // Handle unsupported algorithm
        return TOFU_WAS_UNKNOWN;
    }
}

ctofu_error fscl_tofu_smart_transform(ctofu* objects, const char *algorithm, int (*transformFunc)(int)) {
    if (!objects) {
        return TOFU_WAS_NULLPTR;
    }

    if (strcmp(algorithm, "auto") == 0) {
        // Automatically select an appropriate algorithm based on size and type
        // ...

    } else if (strcmp(algorithm, "std") == 0) {
        // Use the existing classic version
        if (fscl_tofu_not_cnullptr(objects)) {
            if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
                return TOFU_WAS_BAD_RANGE;
            }
            return fscl_tofu_transform(objects->data.array_type.elements, transformFunc);
        } else {
            return TOFU_WAS_NULLPTR;
        }

    } else {
        // Handle unsupported algorithm
        return TOFU_WAS_UNKNOWN;
    }
}

ctofu_error fscl_tofu_smart_sort(ctofu* objects, const char *algorithm) {
    if (!objects) {
        return TOFU_WAS_NULLPTR;
    }

    if (strcmp(algorithm, "auto") == 0) {
        // Automatically select an appropriate algorithm based on size and type
        // ...

    } else if (strcmp(algorithm, "std") == 0) {
        // Use the existing classic version
        if (fscl_tofu_not_cnullptr(objects)) {
            if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
                return TOFU_WAS_BAD_RANGE;
            }
            return fscl_tofu_sort(objects->data.array_type.elements);
        } else {
            return TOFU_WAS_NULLPTR;
        }

    } else {
        // Handle unsupported algorithm
        return TOFU_WAS_UNKNOWN;
    }
}

ctofu_error fscl_tofu_smart_search(ctofu* objects, const char *algorithm, ctofu* key) {
    if (!objects || !key) {
        return TOFU_WAS_NULLPTR;
    }

    if (strcmp(algorithm, "auto") == 0) {
        // Automatically select an appropriate algorithm based on size and type
        // ...

    } else if (strcmp(algorithm, "std") == 0) {
        // Use the existing classic version
        if (fscl_tofu_not_cnullptr(objects)) {
            if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
                return TOFU_WAS_BAD_RANGE;
            }
            return fscl_tofu_search(objects->data.array_type.elements, key);
        } else {
            return TOFU_WAS_NULLPTR;
        }

    } else {
        // Handle unsupported algorithm
        return TOFU_WAS_UNKNOWN;
    }
}

ctofu_error fscl_tofu_smart_filter(ctofu* objects, const char *algorithm, bool (*filterFunc)(const ctofu*)) {
    if (!objects || !filterFunc) {
        return TOFU_WAS_NULLPTR;
    }

    if (strcmp(algorithm, "auto") == 0) {
        // Automatically select an appropriate algorithm based on size and type
        // ...

    } else if (strcmp(algorithm, "std") == 0) {
        // Use the existing classic version
        if (fscl_tofu_not_cnullptr(objects)) {
            if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
                return TOFU_WAS_BAD_RANGE;
            }
            return fscl_tofu_filter(objects->data.array_type.elements, filterFunc);
        } else {
            return TOFU_WAS_NULLPTR;
        }

    } else {
        // Handle unsupported algorithm
        return TOFU_WAS_UNKNOWN;
    }
}

ctofu_error fscl_tofu_smart_reverse(ctofu* objects, const char *algorithm) {
    if (!objects) {
        return TOFU_WAS_NULLPTR;
    }

    if (strcmp(algorithm, "auto") == 0) {
        // Automatically select an appropriate algorithm based on size and type
        // ...

    } else if (strcmp(algorithm, "std") == 0) {
        // Use the existing classic version
        if (fscl_tofu_not_cnullptr(objects)) {
            if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
                return TOFU_WAS_BAD_RANGE;
            }
            return fscl_tofu_reverse(objects->data.array_type.elements);
        } else {
            return TOFU_WAS_NULLPTR;
        }

    } else {
        // Handle unsupported algorithm
        return TOFU_WAS_UNKNOWN;
    }
}

ctofu_error fscl_tofu_smart_compare(const ctofu* right, const ctofu* left, const char *algorithm) {
    if (!right || !left) {
        return TOFU_WAS_NULLPTR;
    }

    if (strcmp(algorithm, "auto") == 0) {
        // Automatically select an appropriate algorithm based on size and type
        // ...

    } else if (strcmp(algorithm, "std") == 0) {
        // Use the existing classic version
        if (fscl_tofu_not_cnullptr(right) && fscl_tofu_not_cnullptr(left)) {
            return fscl_tofu_compare(right, left);
        } else {
            return TOFU_WAS_NULLPTR;
        }

    } else {
        // Handle unsupported algorithm
        return TOFU_WAS_UNKNOWN;
    }
}

ctofu_error fscl_tofu_smart_reduce(ctofu* objects, const char *algorithm, ctofu (*reduceFunc)(const ctofu*, const ctofu*)) {
    if (!objects || !reduceFunc) {
        return TOFU_WAS_NULLPTR;
    }

    if (strcmp(algorithm, "auto") == 0) {
        // Automatically select an appropriate algorithm based on size and type
        // ...

    } else if (strcmp(algorithm, "std") == 0) {
        // Use the existing classic version
        if (fscl_tofu_not_cnullptr(objects)) {
            return fscl_tofu_reduce(objects->data.array_type.elements, reduceFunc);
        } else {
            return TOFU_WAS_NULLPTR;
        }

    } else {
        // Handle unsupported algorithm
        return TOFU_WAS_UNKNOWN;
    }
}

ctofu_error fscl_tofu_smart_shuffle(ctofu* objects, const char *algorithm) {
    if (!objects) {
        return TOFU_WAS_NULLPTR;
    }

    if (strcmp(algorithm, "auto") == 0) {
        // Automatically select an appropriate algorithm based on size and type
        // ...

    } else if (strcmp(algorithm, "std") == 0) {
        // Use the existing classic version
        if (fscl_tofu_not_cnullptr(objects)) {
            if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
                return TOFU_WAS_BAD_RANGE;
            }
            return fscl_tofu_shuffle(objects->data.array_type.elements);
        } else {
            return TOFU_WAS_NULLPTR;
        }

    } else {
        // Handle unsupported algorithm
        return TOFU_WAS_UNKNOWN;
    }
}

// =======================
// CLASSIC ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_tofu_accumulate(ctofu* objects) {
    if (!fscl_tofu_not_cnullptr(objects)) {
        return TOFU_WAS_NULLPTR;
    }

    if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
        return TOFU_INVALID_TYPE;
    }

    // Ensure that array elements have compatible types for accumulation
    for (size_t i = 0; i < objects->data.array_type.size; ++i) {
        if (fscl_tofu_type_getter(&objects->data.array_type.elements[i]) != TOFU_INT64_TYPE) {
            return TOFU_INVALID_TYPE;
        }
    }

    ctofu_data result = { .int64_type = 0 };  // Initialize result to 0

    for (size_t i = 0; i < objects->data.array_type.size; ++i) {
        ctofu_data current = fscl_tofu_value_getter(&objects->data.array_type.elements[i]);
        result.int64_type += current.int64_type;
    }

    fscl_tofu_erase(objects);  // Clear the existing data
    fscl_tofu_create(TOFU_INT64_TYPE, &result, objects);  // Store the accumulated result

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_transform(ctofu* objects, int (*transformFunc)(int)) {
    if (!fscl_tofu_not_cnullptr(objects)) {
        return TOFU_WAS_NULLPTR;
    }

    if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
        return TOFU_INVALID_TYPE;
    }

    // Ensure that array elements have compatible types for transformation
    for (size_t i = 0; i < objects->data.array_type.size; ++i) {
        if (fscl_tofu_type_getter(&objects->data.array_type.elements[i]) != TOFU_INT64_TYPE) {
            return TOFU_INVALID_TYPE;
        }
    }

    for (size_t i = 0; i < objects->data.array_type.size; ++i) {
        ctofu_data current = fscl_tofu_value_getter(&objects->data.array_type.elements[i]);
        current.int64_type = transformFunc(current.int64_type);
        fscl_tofu_erase(&objects->data.array_type.elements[i]);  // Clear the existing data
        fscl_tofu_create(TOFU_INT64_TYPE, &current, &objects->data.array_type.elements[i]);  // Store the transformed result
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_sort(ctofu* objects) {
    if (!fscl_tofu_not_cnullptr(objects)) {
        return TOFU_WAS_NULLPTR;
    }

    if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
        return TOFU_INVALID_TYPE;
    }

    // Ensure that array elements have compatible types for sorting
    for (size_t i = 0; i < objects->data.array_type.size; ++i) {
        if (fscl_tofu_type_getter(&objects->data.array_type.elements[i]) != TOFU_INT64_TYPE) {
            return TOFU_INVALID_TYPE;
        }
    }

    // Implement a simple bubble sort algorithm
    for (size_t i = 0; i < objects->data.array_type.size - 1; ++i) {
        for (size_t j = 0; j < objects->data.array_type.size - i - 1; ++j) {
            ctofu_data current = fscl_tofu_value_getter(&objects->data.array_type.elements[j]);
            ctofu_data next = fscl_tofu_value_getter(&objects->data.array_type.elements[j + 1]);

            if (current.int64_type > next.int64_type) {
                // Swap elements if they are in the wrong order
                fscl_tofu_data temp = objects->data.array_type.elements[j].data;
                objects->data.array_type.elements[j].data = objects->data.array_type.elements[j + 1].data;
                objects->data.array_type.elements[j + 1].data = temp;
            }
        }
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_search(ctofu* objects, ctofu* key) {
    if (!fscl_tofu_not_cnullptr(objects) || !fscl_tofu_not_cnullptr(key)) {
        return TOFU_WAS_NULLPTR;
    }

    if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
        return TOFU_INVALID_TYPE;
    }

    ctofu_type keyType = fscl_tofu_type_getter(key);

    // Ensure that array elements have compatible types for searching
    for (size_t i = 0; i < objects->data.array_type.size; ++i) {
        if (fscl_tofu_type_getter(&objects->data.array_type.elements[i]) != keyType) {
            return TOFU_INVALID_TYPE;
        }
    }

    // Implement a simple linear search algorithm
    for (size_t i = 0; i < objects->data.array_type.size; ++i) {
        if (fscl_tofu_compare(&objects->data.array_type.elements[i], key) == TOFU_SUCCESS) {
            return TOFU_SUCCESS;  // Key found
        }
    }

    return TOFU_NOT_FOUND;  // Key not found
}

ctofu_error fscl_tofu_filter(ctofu* objects, bool (*filterFunc)(const ctofu*)) {
    if (!fscl_tofu_not_cnullptr(objects)) {
        return TOFU_WAS_NULLPTR;
    }

    if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
        return TOFU_INVALID_TYPE;
    }

    ctofu_data filteredArray[objects->data.array_type.size];
    size_t filteredSize = 0;

    // Filter elements based on the provided function
    for (size_t i = 0; i < objects->data.array_type.size; ++i) {
        if (filterFunc(&objects->data.array_type.elements[i])) {
            fscl_tofu_value_copy(&objects->data.array_type.elements[i], &filteredArray[filteredSize]);
            ++filteredSize;
        }
    }

    // Clear existing data and store the filtered result
    fscl_tofu_erase(objects);
    fscl_tofu_create(TOFU_ARRAY_TYPE, filteredArray, objects);
    objects->data.array_type.size = filteredSize;

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_reverse(ctofu* objects) {
    if (!fscl_tofu_not_cnullptr(objects)) {
        return TOFU_WAS_NULLPTR;
    }

    if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
        return TOFU_INVALID_TYPE;
    }

    // Reverse the array elements
    size_t i = 0;
    size_t j = objects->data.array_type.size - 1;

    while (i < j) {
        // Swap elements at positions i and j
        fscl_tofu_data temp = objects->data.array_type.elements[i].data;
        objects->data.array_type.elements[i].data = objects->data.array_type.elements[j].data;
        objects->data.array_type.elements[j].data = temp;

        ++i;
        --j;
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_compare(const ctofu* right, const ctofu* left) {
    if (!fscl_tofu_not_cnullptr(right) || !fscl_tofu_not_cnullptr(left)) {
        return TOFU_WAS_NULLPTR;
    }

    if (fscl_tofu_type_getter(right) != fscl_tofu_type_getter(left)) {
        return TOFU_WAS_MISMATCH;
    }

    // Compare the data based on their types
    switch (fscl_tofu_type_getter(right)) {
        case TOFU_INT_TYPE:
            return (right->data.intager_type == left->data.intager_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_INT8_TYPE:
            return (right->data.int8_type == left->data.int8_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_INT16_TYPE:
            return (right->data.int16_type == left->data.int16_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_INT32_TYPE:
            return (right->data.int32_type == left->data.int32_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_INT64_TYPE:
            return (right->data.int64_type == left->data.int64_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_UINT_TYPE:
            return (right->data.uint_type == left->data.uint_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_UINT8_TYPE:
            return (right->data.uint8_type == left->data.uint8_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_UINT16_TYPE:
            return (right->data.uint16_type == left->data.uint16_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_UINT32_TYPE:
            return (right->data.uint32_type == left->data.uint32_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_UINT64_TYPE:
            return (right->data.uint64_type == left->data.uint64_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_OCTAL8_TYPE:
            return (right->data.octal8_type == left->data.octal8_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_OCTAL16_TYPE:
            return (right->data.octal16_type == left->data.octal16_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_OCTAL32_TYPE:
            return (right->data.octal32_type == left->data.octal32_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_OCTAL64_TYPE:
            return (right->data.octal64_type == left->data.octal64_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_BITWISE8_TYPE:
            return (right->data.bitwise8_type == left->data.bitwise8_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_BITWISE16_TYPE:
            return (right->data.bitwise16_type == left->data.bitwise16_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_BITWISE32_TYPE:
            return (right->data.bitwise32_type == left->data.bitwise32_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_BITWISE64_TYPE:
            return (right->data.bitwise64_type == left->data.bitwise64_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_HEX8_TYPE:
            return (right->data.hex8_type == left->data.hex8_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_HEX16_TYPE:
            return (right->data.hex16_type == left->data.hex16_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_HEX32_TYPE:
            return (right->data.hex32_type == left->data.hex32_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_HEX64_TYPE:
            return (right->data.hex64_type == left->data.hex64_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_FLOAT_TYPE:
            return (right->data.float_type == left->data.float_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_DOUBLE_TYPE:
            return (right->data.double_type == left->data.double_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_STRING_TYPE:
            return (strcmp(right->data.string_type, left->data.string_type) == 0) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_CHAR_TYPE:
            return (right->data.char_type == left->data.char_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_BOOLEAN_TYPE:
            return (right->data.boolean_type == left->data.boolean_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        case TOFU_NULLPTR_TYPE:
            // Comparison for null pointers (always equal)
            return TOFU_SUCCESS;
        case TOFU_QBIT_TYPE:
            return (right->data.qbit_type == left->data.qbit_type) ? TOFU_SUCCESS : TOFU_WAS_MISMATCH;
        default:
            return TOFU_INVALID_TYPE;  // Unsupported data type for comparison
    }

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_reduce(ctofu* objects, ctofu (*reduceFunc)(const ctofu*, const ctofu*)) {
    if (!fscl_tofu_not_cnullptr(objects) || !fscl_tofu_not_cnullptr(reduceFunc)) {
        return TOFU_WAS_NULLPTR;
    }

    if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
        return TOFU_INVALID_TYPE;
    }

    if (objects->data.array_type.size < 2) {
        return TOFU_SUCCESS;  // No reduction needed for less than two elements
    }

    // Apply the reduce function iteratively
    for (size_t i = 1; i < objects->data.array_type.size; ++i) {
        ctofu reducedValue = reduceFunc(&objects->data.array_type.elements[i - 1], &objects->data.array_type.elements[i]);
        fscl_tofu_value_setter(&reducedValue, &objects->data.array_type.elements[i]);
    }

    // Update the size after reduction
    objects->data.array_type.size = 1;

    return TOFU_SUCCESS;
}

ctofu_error fscl_tofu_shuffle(ctofu* objects) {
    if (!fscl_tofu_not_cnullptr(objects)) {
        return TOFU_WAS_NULLPTR;
    }

    if (fscl_tofu_type_getter(objects) != TOFU_ARRAY_TYPE) {
        return TOFU_INVALID_TYPE;
    }

    size_t size = objects->data.array_type.size;

    // Use Fisher-Yates shuffle algorithm to randomize the array elements
    for (size_t i = size - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);

        // Swap elements at positions i and j
        ctofu_data temp = objects->data.array_type.elements[i].data;
        objects->data.array_type.elements[i].data = objects->data.array_type.elements[j].data;
        objects->data.array_type.elements[j].data = temp;
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
