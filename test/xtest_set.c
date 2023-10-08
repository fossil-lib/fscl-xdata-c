/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/set.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestSetData) {
    TriloSet *set;
}set_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_set_of_int_create_and_destroy) {
    // Test creating and destroying a TriloSet
    set_data.set = trilo_xdata_set_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(set_data.set);
    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_int_insert_and_remove) {
    // Test inserting and removing data from the TriloSet
    set_data.set = trilo_xdata_set_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_set_insert(set_data.set, tofu1);
    trilo_xdata_set_insert(set_data.set, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(2, trilo_xdata_set_size(set_data.set));

    trilo_xdata_set_remove(set_data.set, tofu2);
    trilo_xdata_set_remove(set_data.set, tofu1);

    XASSERT_BOOL_TRUE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(0, trilo_xdata_set_size(set_data.set));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_int_contains) {
    // Test checking if the TriloSet contains a specific element
    set_data.set = trilo_xdata_set_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_set_insert(set_data.set, tofu1);

    XASSERT_BOOL_TRUE(trilo_xdata_set_contains(set_data.set, tofu1));
    XASSERT_BOOL_FALSE(trilo_xdata_set_contains(set_data.set, tofu2));

    trilo_xdata_set_destroy(set_data.set);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_set_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for set:");

    XTEST_RUN_UNIT(xdata_let_set_of_int_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_set_of_int_insert_and_remove,  runner);
    XTEST_RUN_UNIT(xdata_let_set_of_int_contains,           runner);
} // end of func
