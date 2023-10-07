/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XDATA_MATRIX_H
#define TRILOBITE_XDATA_MATRIX_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xdata/tofu.h"

// Define error constants for tuple operations
enum {
    TRILO_XDATA_MATRIX_TYPE_MISMATCH = -1,
    TRILO_XDATA_MATRIX_OUT_OF_RANGE  = -2
};

// Matrix structure
typedef struct TriloMatrix {
    TriloTofu** data;
    enum DataType matrix_type; // Type of the matrix
    size_t rows;
    size_t cols;
} TriloMatrix;

// Function to create a new TriloMatrix with a specified data type
TriloMatrix* trilo_xdata_matrix_create(enum DataType matrix_type, size_t rows, size_t cols);

// Function to destroy the TriloMatrix
void trilo_xdata_matrix_destroy(TriloMatrix* matrix);

// Function to set a TriloTofu data into the matrix at the specified row and column
void trilo_xdata_matrix_set(TriloMatrix* matrix, size_t row, size_t col, TriloTofu data);

// Function to get a TriloTofu data from the matrix at the specified row and column
TriloTofu trilo_xdata_matrix_get(const TriloMatrix* matrix, size_t row, size_t col);

// Function to get the number of rows in the matrix
size_t trilo_xdata_matrix_rows(const TriloMatrix* matrix);

// Function to get the number of columns in the matrix
size_t trilo_xdata_matrix_cols(const TriloMatrix* matrix);

// Function to print the elements in the matrix
void trilo_xdata_matrix_print(const TriloMatrix* matrix);

#ifdef __cplusplus
}
#endif

#endif
