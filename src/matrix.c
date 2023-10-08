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

void trilo_xdata_matrix_set_element(TriloMatrix* matrix, int row, int col, TriloTofu data) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols)
        return;

    TriloMatrixNode* new_node = (TriloMatrixNode*)malloc(sizeof(TriloMatrixNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    new_node->data = data;
    new_node->right = NULL;
    new_node->down = NULL;

    if (matrix->top_left == NULL) {
        matrix->top_left = new_node;
    } else {
        TriloMatrixNode* current_row = matrix->top_left;
        for (int i = 0; i < row; i++) {
            if (current_row->down == NULL) {
                TriloMatrixNode* new_row = (TriloMatrixNode*)malloc(sizeof(TriloMatrixNode));
                if (new_row == NULL) {
                    fprintf(stderr, "Memory allocation failed!\n");
                    exit(EXIT_FAILURE);
                } // end if
                new_row->data = trilo_xdata_tofu_create_from_integer(0);
                new_row->right = NULL;
                new_row->down = NULL;
                current_row->down = new_row;
            } // end if
            current_row = current_row->down;
        } // end for

        TriloMatrixNode* current_col = current_row;
        for (int j = 0; j < col; j++) {
            if (current_col->right == NULL) {
                TriloMatrixNode* new_col = (TriloMatrixNode*)malloc(sizeof(TriloMatrixNode));
                if (new_col == NULL) {
                    fprintf(stderr, "Memory allocation failed!\n");
                    exit(EXIT_FAILURE);
                } // end if
                new_col->data = trilo_xdata_tofu_create_from_integer(0);
                new_col->right = NULL;
                new_col->down = NULL;
                current_col->right = new_col;
            } // end if
            current_col = current_col->right;
        } // end for

        current_col->right = new_node;
    } // end if else
} // end of func

TriloTofu* trilo_xdata_matrix_get_element(const TriloMatrix* matrix, int row, int col) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols)
        return NULL;

    TriloMatrixNode* current_row = matrix->top_left;
    for (int i = 0; i < row; i++) {
        current_row = current_row->down;
    } // end for

    TriloMatrixNode* current_col = current_row;
    for (int j = 0; j < col; j++) {
        current_col = current_col->right;
    } // end for

    return &(current_col->data);
} // end of func
