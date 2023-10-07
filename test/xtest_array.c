/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/array.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestArrayData) {
    TriloArray *array;
}array_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_array_create_and_destroy) {
    // Test creating and destroying a TriloArray
    array_data.array = trilo_xdata_array_create(INTEGER_TYPE, 3);
    XASSERT_PTR_NOT_NULL(array_data.array);
    XASSERT_INT_EQUAL(INTEGER_TYPE, array_data.array->array_type);
    XASSERT_INT_EQUAL(3, array_data.array->size);
    trilo_xdata_array_destroy(array_data.array);
}

XTEST_CASE(xdata_let_array_insert_and_get_values) {
    // Test inserting values into the TriloArray and getting values
    array_data.array = trilo_xdata_array_create(INTEGER_TYPE, 3);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value3 = trilo_xdata_tofu_create_from_integer(3);

    // Insert values into the array
    trilo_xdata_array_insert(array_data.array, 0, value1);
    trilo_xdata_array_insert(array_data.array, 1, value2);
    trilo_xdata_array_insert(array_data.array, 2, value3);

    // Retrieve values by indices
    TriloTofu* retrieved_value1 = trilo_xdata_array_get(array_data.array, 0);
    TriloTofu* retrieved_value2 = trilo_xdata_array_get(array_data.array, 1);
    TriloTofu* retrieved_value3 = trilo_xdata_array_get(array_data.array, 2);

    XASSERT_PTR_NOT_NULL(retrieved_value1);
    XASSERT_PTR_NOT_NULL(retrieved_value2);
    XASSERT_PTR_NOT_NULL(retrieved_value3);

    // Check the retrieved values
    XASSERT_INT_EQUAL(1, trilo_xdata_tofu_get_integer(*retrieved_value1));
    XASSERT_INT_EQUAL(2, trilo_xdata_tofu_get_integer(*retrieved_value2));
    XASSERT_INT_EQUAL(3, trilo_xdata_tofu_get_integer(*retrieved_value3));

    // Clean up allocated memory for retrieved values
    free(retrieved_value1);
    free(retrieved_value2);
    free(retrieved_value3);

    trilo_xdata_array_destroy(array_data.array);
}

XTEST_CASE(xdata_let_array_remove) {
    // Test removing values from the TriloArray
    array_data.array = trilo_xdata_array_create(INTEGER_TYPE, 3);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value3 = trilo_xdata_tofu_create_from_integer(3);

    // Insert values into the array
    trilo_xdata_array_insert(array_data.array, 0, value1);
    trilo_xdata_array_insert(array_data.array, 1, value2);
    trilo_xdata_array_insert(array_data.array, 2, value3);

    // Remove a value from the array
    trilo_xdata_array_remove(array_data.array, 1);

    // Attempt to retrieve the removed value
    TriloTofu* retrieved_value = trilo_xdata_array_get(array_data.array, 1);
    XASSERT_PTR_NULL(retrieved_value);

    trilo_xdata_array_destroy(array_data.array);
}

XTEST_CASE(xdata_let_array_index_out_of_range) {
    // Test inserting and getting values with an out-of-range index
    array_data.array = trilo_xdata_array_create(INTEGER_TYPE, 3);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);

    // Attempting to insert and get a value with an out-of-range index should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_ARRAY_INDEX_OUT_OF_RANGE, trilo_xdata_array_insert(array_data.array, 5, value1));
    XASSERT_INT_EQUAL(TRILO_XDATA_ARRAY_INDEX_OUT_OF_RANGE, trilo_xdata_array_get(array_data.array, 5));

    trilo_xdata_array_destroy(array_data.array);
}

XTEST_CASE(xdata_let_array_type_mismatch) {
    // Test inserting values of different types into the TriloArray
    array_data.array = trilo_xdata_array_create(INTEGER_TYPE, 3);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_double(3.14);

    // Attempting to insert a value of a different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_ARRAY_TYPE_MISMATCH, trilo_xdata_array_insert(array_data.array, 1, value2));

    trilo_xdata_array_destroy(array_data.array);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_array_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for array:");

    XTEST_RUN_UNIT(xdata_let_array_create_and_destroy,    runner);
    XTEST_RUN_UNIT(xdata_let_array_insert_and_get_values, runner);
    XTEST_RUN_UNIT(xdata_let_array_remove,                runner);
    XTEST_RUN_UNIT(xdata_let_array_index_out_of_range,    runner);
    XTEST_RUN_UNIT(xdata_let_array_type_mismatch,         runner);
} // end of func
