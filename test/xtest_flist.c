/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/flist.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestFListData) {
    TriloForwardList *flist;
}flist_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_flist_of_int_create_and_destroy) {
    // Test creating and destroying a TriloForwardList
    flist_data.flist = trilo_xdata_flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL(flist_data.flist);
    TEST_ASSERT_EQUAL_INT(INTEGER_TYPE, flist_data.flist->list_type);
    trilo_xdata_flist_destroy(flist_data.flist);
}

XTEST_CASE(xdata_let_flist_of_int_insert_and_get_values) {
    // Test inserting values into the TriloForwardList and getting values
    flist_data.flist = trilo_xdata_flist_create(INTEGER_TYPE);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_flist_insert(flist_data.flist, value1);
    trilo_xdata_flist_insert(flist_data.flist, value2);
    trilo_xdata_flist_insert(flist_data.flist, value3);

    TriloTofu* values = NULL;
    int num_values = trilo_xdata_flist_get_values(flist_data.flist, &values);

    TEST_ASSERT_EQUAL_INT(3, num_values);

    // Check the values in the forward list
    TEST_ASSERT_EQUAL_INT(1, trilo_xdata_tofu_get_integer(values[0]));
    TEST_ASSERT_EQUAL_INT(2, trilo_xdata_tofu_get_integer(values[1]));
    TEST_ASSERT_EQUAL_INT(3, trilo_xdata_tofu_get_integer(values[2]));

    // Clean up allocated memory for values
    free(values);

    trilo_xdata_flist_destroy(flist);
}

XTEST_CASE(xdata_let_flist_of_int_remove) {
    // Test removing values from the TriloForwardList
    flist_data.flist = trilo_xdata_flist_create(INTEGER_TYPE);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_flist_insert(flist_data.flist, value1);
    trilo_xdata_flist_insert(flist_data.flist, value2);
    trilo_xdata_flist_insert(flist_data.flist, value3);

    // Remove a value from the forward list
    trilo_xdata_flist_remove(flist_data.flist, value2);

    TriloTofu* values = NULL;
    int num_values = trilo_xdata_flist_get_values(flist_data.flist, &values);

    TEST_ASSERT_EQUAL_INT(2, num_values);

    // Check the values in the forward list after removal
    TEST_ASSERT_EQUAL_INT(1, trilo_xdata_tofu_get_integer(values[0]));
    TEST_ASSERT_EQUAL_INT(3, trilo_xdata_tofu_get_integer(values[1]));

    // Clean up allocated memory for values
    free(values);

    trilo_xdata_flist_destroy(flist_data.flist);
}

XTEST_CASE(xdata_let_flist_of_int_type_mismatch) {
    // Test inserting values of different types into the TriloForwardList
    flist_data.flist = trilo_xdata_flist_create(INTEGER_TYPE);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_double(3.14);

    // Attempting to insert a value of a different type should result in an error
    TEST_ASSERT_EQUAL_INT(TRILO_XDATA_FLIST_TYPE_MISMATCH, trilo_xdata_flist_insert(flist_data.flist, value2));

    trilo_xdata_flist_destroy(flist_data.flist);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_flist_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for flist:");

    XTEST_RUN_UNIT(xdata_let_flist_of_int_create_and_destroy,    runner);
    XTEST_RUN_UNIT(xdata_let_flist_of_int_insert_and_get_values, runner);
    XTEST_RUN_UNIT(xdata_let_flist_of_int_remove,                runner);
    XTEST_RUN_UNIT(xdata_let_flist_of_int_type_mismatch,         runner);
} // end of func
