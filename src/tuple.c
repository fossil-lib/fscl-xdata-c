/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloTuple* trilo_xdata_tuple_create(enum DataType* tuple_types, size_t size) {
    TriloTuple* tuple = (TriloTuple*)malloc(sizeof(TriloTuple));
    if (tuple == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    tuple->size = size;

    // Allocate memory for the elements
    tuple->elements = (TriloTofu*)malloc(sizeof(TriloTofu) * size);
    if (tuple->elements == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(tuple);
        exit(EXIT_FAILURE);
    } // end if

    // Allocate memory for the types array and copy the provided data types
    tuple->tuple_types = (enum DataType*)malloc(sizeof(enum DataType) * size);
    if (tuple->tuple_types == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(tuple->elements);
        free(tuple);
        exit(EXIT_FAILURE);
    } // end if
    memcpy(tuple->tuple_types, tuple_types, sizeof(enum DataType) * size);

    // Initialize the tuple with default values
    for (size_t i = 0; i < size; i++) {
        tuple->elements[i].type = tuple_types[i];
    } // end for

    return tuple;
} // end of func

void trilo_xdata_tuple_destroy(TriloTuple* tuple) {
    if (tuple == NULL) {
        return;
    } // end if

    free(tuple->elements);
    free(tuple->tuple_types);
    free(tuple);
} // end of func

TriloTofu trilo_xdata_tuple_get(const TriloTuple* tuple, size_t index) {
    if (index >= tuple->size) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(EXIT_FAILURE);
    } // end if

    return tuple->elements[index];
} // end of func

void trilo_xdata_tuple_set(TriloTuple* tuple, size_t index, TriloTofu data) {
    if (index >= tuple->size || data.type != tuple->tuple_types[index]) {
        fprintf(stderr, "Invalid index or data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    tuple->elements[index] = data;
} // end of func

bool trilo_xdata_tuple_is_empty(const TriloTuple* tuple) {
    return tuple->size == 0;
} // end of func

size_t trilo_xdata_tuple_size(const TriloTuple* tuple) {
    return tuple->size;
} // end of func

void trilo_xdata_tuple_print(const TriloTuple* tuple) {
    for (size_t i = 0; i < tuple->size; i++) {
        printf("Element %zu (Type: %d): ", i, tuple->tuple_types[i]);
        switch (tuple->elements[i].type) {
            case INTEGER_TYPE:
                printf("%d\n", tuple->elements[i].data.integer_type);
                break;
            case DOUBLE_TYPE:
                printf("%lf\n", tuple->elements[i].data.double_type);
                break;
            case STRING_TYPE:
                printf("%s\n", tuple->elements[i].data.string_type);
                break;
            case CHAR_TYPE:
                printf("%c\n", tuple->elements[i].data.char_type);
                break;
            case BOOLEAN_TYPE:
                printf("%s\n", tuple->elements[i].data.boolean_type ? "true" : "false");
                break;
            default:
                printf("Unknown type\n");
                break;
        } // end switch
    } // end for
} // end of func
