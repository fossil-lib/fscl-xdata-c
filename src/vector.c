/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {INITIAL_CAPACITY = 10};

TriloVector* trilo_xdata_vector_create(enum DataType vector_type) {
    TriloVector* vector = (TriloVector*)malloc(sizeof(TriloVector));
    if (vector == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    vector->vector_type = vector_type;
    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;
    vector->data = (TriloTofu*)malloc(sizeof(TriloTofu) * vector->capacity);
    if (vector->data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(vector);
        exit(EXIT_FAILURE);
    } // end if
    return vector;
} // end of func

void trilo_xdata_vector_destroy(TriloVector* vector) {
    free(vector->data);
    free(vector);
} // end of func

void trilo_xdata_vector_resize(TriloVector* vector) {
    vector->capacity *= 2;
    vector->data = (TriloTofu*)realloc(vector->data, sizeof(TriloTofu) * vector->capacity);
    if (vector->data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
} // end of func

void trilo_xdata_vector_insert(TriloVector* vector, TriloTofu data) {
    if (data.type != vector->vector_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    if (vector->size == vector->capacity) {
        trilo_xdata_vector_resize(vector);
    } // end if

    vector->data[vector->size] = data;
    vector->size++;
} // end of func

TriloTofu trilo_xdata_vector_get(const TriloVector* vector, size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(EXIT_FAILURE);
    } // end if
    return vector->data[index];
} // end of func

bool trilo_xdata_vector_is_empty(const TriloVector* vector) {
    return vector->size == 0;
} // end of func

size_t trilo_xdata_vector_size(const TriloVector* vector) {
    return vector->size;
} // end of func

size_t trilo_xdata_vector_capacity(const TriloVector* vector) {
    return vector->capacity;
} // end of func

void trilo_xdata_vector_print(const TriloVector* vector) {
    for (size_t i = 0; i < vector->size; i++) {
        printf("Data %zu: ", i);
        switch (vector->data[i].type) {
            case INTEGER_TYPE:
                printf("%d\n", vector->data[i].data.integer_type);
                break;
            case DOUBLE_TYPE:
                printf("%lf\n", vector->data[i].data.double_type);
                break;
            case STRING_TYPE:
                printf("%s\n", vector->data[i].data.string_type);
                break;
            case CHAR_TYPE:
                printf("%c\n", vector->data[i].data.char_type);
                break;
            case BOOLEAN_TYPE:
                printf("%s\n", vector->data[i].data.boolean_type ? "true" : "false");
                break;
            default:
                printf("Unknown type\n");
                break;
        } // end switch
    } // end for
} // end of func

void trilo_xdata_vector_remove(TriloVector* vector, int index) {
    if (index < 0 || index >= vector->size)
        return;

    TriloVectorNode* current = vector->head;
    if (index == 0) {
        vector->head = current->next;
        free(current);
        vector->size--;
        return;
    } // end if

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    } // end for

    TriloVectorNode* temp = current->next;
    current->next = temp->next;
    free(temp);
    vector->size--;
} // end of func