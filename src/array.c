/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TriloArray* trilo_xdata_array_create(enum DataType list_type, size_t initial_capacity) {
    TriloArray* list = (TriloArray*)malloc(sizeof(TriloArray));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    list->data = (TriloTofu*)malloc(initial_capacity * sizeof(TriloTofu));
    if (list->data == NULL) {
        free(list);
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    list->capacity = initial_capacity;
    list->size = 0;
    list->list_type = list_type;
    return list;
} // end of func

void trilo_xdata_array_destroy(TriloArray* list) {
    free(list->data);
    free(list);
} // end of func

bool trilo_xdata_array_is_empty(const TriloArray* list) {
    return list->size == 0;
} // end of func

void trilo_xdata_array_insert(TriloArray* list, TriloTofu data) {
    // Ensure the data type matches the list type
    if (data.type != list->list_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    // Check if the array needs to be resized
    if (list->size == list->capacity) {
        size_t new_capacity = list->capacity * 2;
        TriloTofu* new_data = (TriloTofu*)realloc(list->data, new_capacity * sizeof(TriloTofu));
        if (new_data == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        } // end if
        list->data = new_data;
        list->capacity = new_capacity;
    } // end if

    list->data[list->size++] = data;
} // end of func

void trilo_xdata_array_remove(TriloArray* list, TriloTofu data) {
    // Ensure the data type matches the list type
    if (data.type != list->list_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    size_t i = 0;
    while (i < list->size) {
        if (memcmp(&list->data[i], &data, sizeof(TriloTofu)) == 0) {
            // Shift elements to remove the found data
            for (size_t j = i; j < list->size - 1; j++) {
                list->data[j] = list->data[j + 1];
            } // end for
            list->size--;
            return;
        } // end if
        i++;
    } // end while
} // end of func

void trilo_xdata_array_print(const TriloArray* list) {
    for (size_t i = 0; i < list->size; i++) {
        switch (list->list_type) {
            case INTEGER_TYPE:
                printf("%d -> ", list->data[i].data.integer_type);
                break;
            case DOUBLE_TYPE:
                printf("%lf -> ", list->data[i].data.double_type);
                break;
            case STRING_TYPE:
                printf("%s -> ", list->data[i].data.string_type);
                break;
            case CHAR_TYPE:
                printf("%c -> ", list->data[i].data.char_type);
                break;
            case BOOLEAN_TYPE:
                printf("%s -> ", list->data[i].data.boolean_type ? "true" : "false");
                break;
            default:
                printf("Unknown type\n");
                break;
        } // end switch
    } // end for
    printf("NULL\n");
} // end of func
