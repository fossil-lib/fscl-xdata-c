
#include "trilobite/xdata/matrix.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Create a matrix of integers with 3 rows and 3 columns
    TriloMatrix* intMatrix = trilo_xdata_matrix_create(INTEGER_TYPE, 3, 3);

    // Set values in the matrix
    trilo_xdata_matrix_set(intMatrix, 0, 0, trilo_xdata_tofu_create_from_integer(1));
    trilo_xdata_matrix_set(intMatrix, 0, 1, trilo_xdata_tofu_create_from_integer(2));
    trilo_xdata_matrix_set(intMatrix, 0, 2, trilo_xdata_tofu_create_from_integer(3));
    trilo_xdata_matrix_set(intMatrix, 1, 0, trilo_xdata_tofu_create_from_integer(4));
    trilo_xdata_matrix_set(intMatrix, 1, 1, trilo_xdata_tofu_create_from_integer(5));
    trilo_xdata_matrix_set(intMatrix, 1, 2, trilo_xdata_tofu_create_from_integer(6));
    trilo_xdata_matrix_set(intMatrix, 2, 0, trilo_xdata_tofu_create_from_integer(7));
    trilo_xdata_matrix_set(intMatrix, 2, 1, trilo_xdata_tofu_create_from_integer(8));
    trilo_xdata_matrix_set(intMatrix, 2, 2, trilo_xdata_tofu_create_from_integer(9));

    // Print the contents of the matrix
    printf("Matrix contents:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            TriloTofu data = trilo_xdata_matrix_get(intMatrix, i, j);
            int value = trilo_xdata_tofu_get_integer(data);
            printf("%d ", value);
        }
        printf("\n");
    }

    // Clean up and destroy the matrix
    trilo_xdata_matrix_destroy(intMatrix);

    return 0;
} // end of func
