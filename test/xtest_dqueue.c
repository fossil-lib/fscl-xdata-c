/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/dqueue.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test TriloDQueue creation and destruction
XTEST_CASE(xdata_let_dqueue_create_and_destroy) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(dqueue);

    trilo_xdata_dqueue_destroy(dqueue);
    XASSERT_PTR_NULL(dqueue);
}

// Test case 2: Test TriloDQueue insertion and retrieval
XTEST_CASE(xdata_let_dqueue_insert_and_get) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(dqueue);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    TofuError result = trilo_xdata_dqueue_insert(dqueue, tofu);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_dqueue_getter(dqueue, tofu);
    XASSERT_PTR_NOT_NULL(retrieved_tofu);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(*retrieved_tofu));

    trilo_xdata_dqueue_destroy(dqueue);
}

// Test case 3: Test TriloDQueue removal
XTEST_CASE(xdata_let_dqueue_remove) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(dqueue);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    TofuError result = trilo_xdata_dqueue_insert(dqueue, tofu);
    XASSERT_INT_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_dqueue_remove(dqueue, tofu);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_dqueue_getter(dqueue, tofu);
    XASSERT_PTR_NULL(retrieved_tofu);

    trilo_xdata_dqueue_destroy(dqueue);
}

// Test case 4: Test TriloDQueue size
XTEST_CASE(xdata_let_dqueue_size) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(dqueue);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_dqueue_insert(dqueue, tofu1);
    trilo_xdata_dqueue_insert(dqueue, tofu2);
    trilo_xdata_dqueue_insert(dqueue, tofu3);

    size_t size = trilo_xdata_dqueue_size(dqueue);
    XASSERT_INT_EQUAL(3, size);

    trilo_xdata_dqueue_destroy(dqueue);
}

// Test case 5: Test TriloDQueue empty check
XTEST_CASE(xdata_let_dqueue_empty_check) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(dqueue);

    XASSERT_BOOL_TRUE(trilo_xdata_dqueue_is_empty(dqueue));
    XASSERT_BOOL_FALSE(trilo_xdata_dqueue_not_empty(dqueue));

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_dqueue_insert(dqueue, tofu);

    XASSERT_BOOL_FALSE(trilo_xdata_dqueue_is_empty(dqueue));
    XASSERT_BOOL_TRUE(trilo_xdata_dqueue_not_empty(dqueue));

    trilo_xdata_dqueue_destroy(dqueue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_dqueue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for dqueue:");

    XTEST_RUN_UNIT(xdata_let_dqueue_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_insert_and_get,     runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_remove,             runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_size,               runner);
} // end of func
