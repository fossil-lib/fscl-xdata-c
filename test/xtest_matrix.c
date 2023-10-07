/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/matrix.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestMatrixData) {
    TriloMatrix *matrix;
}matrix_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_matrix_of_int_create_and_destroy) {
    // Test creating and destroying a TriloMatrix
    matrix_data.matrix = trilo_xdata_matrix_create(INTEGER_TYPE, 2, 3);
    XASSERT_PTR_NOT_NULL(matrix_data.matrix);
    XASSERT_INT_EQUAL(INTEGER_TYPE, matrix_data.matrix->matrix_type);
    XASSERT_INT_EQUAL(2, matrix_data.matrix->rows);
    XASSERT_INT_EQUAL(3, matrix_data.matrix->cols);
    trilo_xdata_matrix_destroy(matrix_data.matrix);
}

XTEST_CASE(xdata_let_matrix_of_int_get_and_set_element) {
    // Test getting and setting elements in the TriloMatrix
    matrix_data.matrix = trilo_xdata_matrix_create(INTEGER_TYPE, 2, 3);

    trilo_xdata_matrix_set_element(matrix_data.matrix, 0, 0, trilo_xdata_tofu_create_from_integer(1));
    trilo_xdata_matrix_set_element(matrix_data.matrix, 0, 1, trilo_xdata_tofu_create_from_integer(2));
    trilo_xdata_matrix_set_element(matrix_data.matrix, 1, 2, trilo_xdata_tofu_create_from_integer(3));

    TriloTofu element1 = trilo_xdata_matrix_get_element(matrix_data.matrix, 0, 0);
    XASSERT_INT_EQUAL(1, trilo_xdata_tofu_get_integer(element1));

    TriloTofu element2 = trilo_xdata_matrix_get_element(matrix_data.matrix, 0, 1);
    XASSERT_INT_EQUAL(2, trilo_xdata_tofu_get_integer(element2));

    TriloTofu element3 = trilo_xdata_matrix_get_element(matrix_data.matrix, 1, 2);
    XASSERT_INT_EQUAL(3, trilo_xdata_tofu_get_integer(element3));

    trilo_xdata_matrix_destroy(matrix_data.matrix);
}

XTEST_CASE(xdata_let_matrix_of_int_out_of_bounds) {
    // Test accessing elements out of bounds in the TriloMatrix
    matrix_data.matrix = trilo_xdata_matrix_create(INTEGER_TYPE, 2, 3);

    // Attempting to set or get an element out of bounds should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_MATRIX_OUT_OF_BOUNDS, trilo_xdata_matrix_set_element(matrix_data.matrix, 2, 1, trilo_xdata_tofu_create_from_integer(4)));
    XASSERT_INT_EQUAL(TRILO_XDATA_MATRIX_OUT_OF_BOUNDS, trilo_xdata_matrix_get_element(matrix_data.matrix, 1, 3));

    trilo_xdata_matrix_destroy(matrix_data.matrix);
}

XTEST_CASE(xdata_let_matrix_of_int_type_mismatch) {
    // Test setting elements of different types in the TriloMatrix
    matrix_data.matrix = trilo_xdata_matrix_create(INTEGER_TYPE, 2, 3);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    // Attempting to set an element of a different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_MATRIX_TYPE_MISMATCH, trilo_xdata_matrix_set_element(matrix_data.matrix, 1, 2, tofu2));

    trilo_xdata_matrix_destroy(matrix_data.matrix);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_matrix_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for matrix:");

    XTEST_RUN_UNIT(xdata_let_matrix_of_int_create_and_destroy,  runner);
    XTEST_RUN_UNIT(xdata_let_matrix_of_int_get_and_set_element, runner);
    XTEST_RUN_UNIT(xdata_let_matrix_of_int_out_of_bounds,       runner);
    XTEST_RUN_UNIT(xdata_let_matrix_of_int_type_mismatch,       runner);
} // end of func
