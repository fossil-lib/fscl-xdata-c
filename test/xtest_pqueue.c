/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/pqueue.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test TriloPQueue creation and destruction
XTEST_CASE(xdata_let_pqueue_create_and_destroy) {
    TriloPQueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(pqueue);

    trilo_xdata_pqueue_destroy(pqueue);
    XASSERT_PTR_NULL(pqueue);
}

// Test case 2: Test TriloPQueue insertion and retrieval
XTEST_CASE(xdata_let_pqueue_insert_and_get) {
    TriloPQueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(pqueue);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    int priority = 2;
    TofuError result = trilo_xdata_pqueue_insert(pqueue, tofu, priority);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_pqueue_getter(pqueue, tofu, priority);
    XASSERT_PTR_NOT_NULL(retrieved_tofu);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(*retrieved_tofu));

    trilo_xdata_pqueue_destroy(pqueue);
}

// Test case 3: Test TriloPQueue removal
XTEST_CASE(xdata_let_pqueue_remove) {
    TriloPQueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(pqueue);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    int priority = 2;
    TofuError result = trilo_xdata_pqueue_insert(pqueue, tofu, priority);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_pqueue_remove(pqueue, tofu, priority);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_pqueue_getter(pqueue, tofu, priority);
    XASSERT_PTR_NULL(retrieved_tofu);

    trilo_xdata_pqueue_destroy(pqueue);
}

// Test case 4: Test TriloPQueue size
XTEST_CASE(xdata_let_pqueue_size) {
    TriloPQueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(pqueue);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_pqueue_insert(pqueue, tofu1, 1);
    trilo_xdata_pqueue_insert(pqueue, tofu2, 2);
    trilo_xdata_pqueue_insert(pqueue, tofu3, 1);

    size_t size = trilo_xdata_pqueue_size(pqueue);
    XASSERT_INT_EQUAL(3, size);

    trilo_xdata_pqueue_destroy(pqueue);
}

// Test case 5: Test TriloPQueue empty check
XTEST_CASE(xdata_let_pqueue_empty_check) {
    TriloPQueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(pqueue);

    XASSERT_BOOL_TRUE(trilo_xdata_pqueue_is_empty(pqueue));
    XASSERT_BOOL_FALSE(trilo_xdata_pqueue_not_empty(pqueue));

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_pqueue_insert(pqueue, tofu, 1);

    XASSERT_BOOL_FALSE(trilo_xdata_pqueue_is_empty(pqueue));
    XASSERT_BOOL_TRUE(trilo_xdata_pqueue_not_empty(pqueue));

    trilo_xdata_pqueue_destroy(pqueue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_pqueue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for pqueue:");

    XTEST_RUN_UNIT(xdata_let_pqueue_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_insert_and_get,     runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_remove,             runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_size,               runner);
} // end of func
