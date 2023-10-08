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
    XASSERT_PTR_NOT_NULL(flist_data.flist);
    XASSERT_INT_EQUAL(INTEGER_TYPE, flist_data.flist->list_type);
    trilo_xdata_flist_destroy(flist_data.flist);
}

XTEST_CASE(xdata_let_flist_of_int_insert_and_get_values) {
    // Create a TriloForwardList of integers
    flist_data.flist = trilo_xdata_flist_create(INTEGER_TYPE);

    // Insert values into the forward list
    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_flist_insert(flist_data.flist, value1);
    trilo_xdata_flist_insert(flist_data.flist, value2);
    trilo_xdata_flist_insert(flist_data.flist, value3);

    // Retrieve and check the values in the forward list
    TriloTofu* value = trilo_xdata_flist_get(flist_data.flist, 0);
    XASSERT_INT_EQUAL(1, trilo_xdata_tofu_get_integer(*value));

    value = trilo_xdata_flist_get(flist_data.flist, 1);
    XASSERT_INT_EQUAL(2, trilo_xdata_tofu_get_integer(*value));

    value = trilo_xdata_flist_get(flist_data.flist, 2);
    XASSERT_INT_EQUAL(3, trilo_xdata_tofu_get_integer(*value));

    // Destroy the forward list
    trilo_xdata_flist_destroy(flist_data.flist);
}

XTEST_CASE(xdata_let_flist_of_int_remove) {
    // Create a TriloForwardList of integers
    flist_data.flist = trilo_xdata_flist_create(INTEGER_TYPE);

    // Insert values into the forward list
    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_flist_insert(flist_data.flist, value1);
    trilo_xdata_flist_insert(flist_data.flist, value2);
    trilo_xdata_flist_insert(flist_data.flist, value3);

    // Remove a value from the forward list
    trilo_xdata_flist_remove(flist_data.flist, value2);

    // Check the values in the forward list after removal
    TriloTofu* value = trilo_xdata_flist_get(flist_data.flist, 0);
    XASSERT_INT_EQUAL(1, trilo_xdata_tofu_get_integer(*value));

    value = trilo_xdata_flist_get(flist_data.flist, 1);
    XASSERT_INT_EQUAL(3, trilo_xdata_tofu_get_integer(*value));

    // Destroy the forward list
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
} // end of func
