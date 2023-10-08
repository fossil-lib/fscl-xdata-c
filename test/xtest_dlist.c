/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/dlist.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestDListData) {
    TriloDoublyList *dlist;
}dlist_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_dlist_of_int_create_and_destroy) {
    // Test creating and destroying a TriloDoublyList
    dlist_data.dlist = trilo_xdata_dlist_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(dlist_data.dlist);
    XASSERT_INT_EQUAL(INTEGER_TYPE, dlist_data.dlist->list_type);
    trilo_xdata_dlist_destroy(dlist_data.dlist);
}

XTEST_CASE(xdata_let_dlist_of_int_insert_and_get_values) {
    // Test inserting values into the TriloDoublyList and getting values
    dlist_data.dlist = trilo_xdata_dlist_create(INTEGER_TYPE);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_dlist_insert(dlist_data.dlist, value1);
    trilo_xdata_dlist_insert(dlist_data.dlist, value2);
    trilo_xdata_dlist_insert(dlist_data.dlist, value3);

    TriloTofu* values = NULL;
    int num_values = trilo_xdata_dlist_get(dlist_data.dlist, 0);

    XASSERT_INT_EQUAL(3, num_values);

    // Check the values in the doubly linked list
    XASSERT_INT_EQUAL(1, trilo_xdata_tofu_get_integer(values[0]));
    XASSERT_INT_EQUAL(2, trilo_xdata_tofu_get_integer(values[1]));
    XASSERT_INT_EQUAL(3, trilo_xdata_tofu_get_integer(values[2]));

    // Clean up allocated memory for values
    free(values);

    trilo_xdata_dlist_destroy(dlist_data.dlist);
}

XTEST_CASE(xdata_let_dlist_of_int_remove) {
    // Test removing values from the TriloDoublyList
    dlist_data.dlist = trilo_xdata_dlist_create(INTEGER_TYPE);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_dlist_insert(dlist_data.dlist, value1);
    trilo_xdata_dlist_insert(dlist_data.dlist, value2);
    trilo_xdata_dlist_insert(dlist_data.dlist, value3);

    // Remove a value from the doubly linked list
    trilo_xdata_dlist_remove(dlist_data.dlist, value2);

    // Get the number of values in the doubly linked list after removal
    int num_values = trilo_xdata_dlist_size(dlist_data.dlist);
    XASSERT_INT_EQUAL(2, num_values);

    // Check the values in the doubly linked list after removal
    TriloTofu value_at_index_0 = trilo_xdata_dlist_get(dlist_data.dlist, 0);
    TriloTofu value_at_index_1 = trilo_xdata_dlist_get(dlist_data.dlist, 1);

    XASSERT_INT_EQUAL(1, trilo_xdata_tofu_get_integer(value_at_index_0));
    XASSERT_INT_EQUAL(3, trilo_xdata_tofu_get_integer(value_at_index_1));

    trilo_xdata_dlist_destroy(dlist_data.dlist);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_dlist_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for dlist:");

    XTEST_RUN_UNIT(xdata_let_dlist_of_int_create_and_destroy,    runner);
    XTEST_RUN_UNIT(xdata_let_dlist_of_int_insert_and_get_values, runner);
    XTEST_RUN_UNIT(xdata_let_dlist_of_int_remove,                runner);
} // end of func
