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
// XUNIT TEST CASES
//

// Test case 1: Test TriloSet creation and destruction
XTEST_CASE(xdata_let_set_create_and_destroy) {
    TriloSet* set = trilo_xdata_set_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(set);

    trilo_xdata_set_destroy(set);
    XASSERT_PTR_NULL(set);
}

// Test case 2: Test TriloSet insertion and removal
XTEST_CASE(xdata_let_set_insert_and_remove) {
    TriloSet* set = trilo_xdata_set_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(set);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    TofuError result = trilo_xdata_set_insert(set, tofu1);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_set_insert(set, tofu2);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_set_insert(set, tofu3);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_set_remove(set, tofu2);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    TofuError found_tofu2 = trilo_xdata_set_search(set, tofu2);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, found_tofu2);

    trilo_xdata_set_destroy(set);
}

// Test case 3: Test TriloSet size
XTEST_CASE(xdata_let_set_size) {
    TriloSet* set = trilo_xdata_set_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(set);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);

    trilo_xdata_set_insert(set, tofu1);
    trilo_xdata_set_insert(set, tofu2);

    size_t size = trilo_xdata_set_size(set);
    XASSERT_INT_EQUAL(2, size);

    trilo_xdata_set_destroy(set);
}

// Test case 4: Test TriloSet empty check
XTEST_CASE(xdata_let_set_empty_check) {
    TriloSet* set = trilo_xdata_set_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(set);

    XASSERT_BOOL_TRUE(trilo_xdata_set_is_empty(set));
    XASSERT_BOOL_FALSE(trilo_xdata_set_not_empty(set));

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_set_insert(set, tofu);

    XASSERT_BOOL_FALSE(trilo_xdata_set_is_empty(set));
    XASSERT_BOOL_TRUE(trilo_xdata_set_not_empty(set));

    trilo_xdata_set_destroy(set);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_set_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for set:");

    XTEST_RUN_UNIT(xdata_let_set_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_set_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_set_insert_and_remove,  runner);
    XTEST_RUN_UNIT(xdata_let_set_size,               runner);
} // end of func
