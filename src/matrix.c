/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/matrix.h"
#include <stdio.h>
#include <stdlib.h>

TriloMatrix* trilo_xdata_matrix_create(enum DataType matrix_type, size_t rows, size_t cols) {
    TriloMatrix* matrix = (TriloMatrix*)malloc(sizeof(TriloMatrix));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    matrix->matrix_type = matrix_type;
    matrix->rows = rows;
    matrix->cols = cols;

    // Allocate memory for the matrix data
    matrix->data = (TriloTofu**)malloc(sizeof(TriloTofu*) * rows);
    if (matrix->data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(matrix);
        exit(EXIT_FAILURE);
    } // end if

    // Initialize the matrix with default values
    for (size_t i = 0; i < rows; i++) {
        matrix->data[i] = (TriloTofu*)malloc(sizeof(TriloTofu) * cols);
        if (matrix->data[i] == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            // Clean up previously allocated memory
            for (size_t j = 0; j < i; j++) {
                free(matrix->data[j]);
            } // end for
            free(matrix->data);
            free(matrix);
            exit(EXIT_FAILURE);
        } // end if
        for (size_t j = 0; j < cols; j++) {
            matrix->data[i][j].type = matrix_type;
        } // end for
    } // end for

    return matrix;
} // end of func

void trilo_xdata_matrix_destroy(TriloMatrix* matrix) {
    if (matrix == NULL) {
        return;
    } // end if

    for (size_t i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    } // end for

    free(matrix->data);
    free(matrix);
} // end of func

void trilo_xdata_matrix_set(TriloMatrix* matrix, size_t row, size_t col, TriloTofu data) {
    if (row >= matrix->rows || col >= matrix->cols || data.type != matrix->matrix_type) {
        fprintf(stderr, "Invalid matrix index or data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    matrix->data[row][col] = data;
} // end of func

TriloTofu trilo_xdata_matrix_get(const TriloMatrix* matrix, size_t row, size_t col) {
    if (row >= matrix->rows || col >= matrix->cols) {
        fprintf(stderr, "Invalid matrix index!\n");
        exit(EXIT_FAILURE);
    } // end if

    return matrix->data[row][col];
} // end of func

size_t trilo_xdata_matrix_rows(const TriloMatrix* matrix) {
    return matrix->rows;
} // end of func

size_t trilo_xdata_matrix_cols(const TriloMatrix* matrix) {
    return matrix->cols;
} // end of func

void trilo_xdata_matrix_print(const TriloMatrix* matrix) {
    for (size_t i = 0; i < matrix->rows; i++) {
        for (size_t j = 0; j < matrix->cols; j++) {
            printf("Data[%zu][%zu]: ", i, j);
            switch (matrix->data[i][j].type) {
                case INTEGER_TYPE:
                    printf("%d\n", matrix->data[i][j].data.integer_type);
                    break;
                case DOUBLE_TYPE:
                    printf("%lf\n", matrix->data[i][j].data.double_type);
                    break;
                case STRING_TYPE:
                    printf("%s\n", matrix->data[i][j].data.string_type);
                    break;
                case CHAR_TYPE:
                    printf("%c\n", matrix->data[i][j].data.char_type);
                    break;
                case BOOLEAN_TYPE:
                    printf("%s\n", matrix->data[i][j].data.boolean_type ? "true" : "false");
                    break;
                default:
                    printf("Unknown type\n");
                    break;
            } // end switch
        } // end for
    } // end for
} // end of func
