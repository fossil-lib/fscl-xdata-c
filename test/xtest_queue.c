/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/queue.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test TriloQueue creation and destruction
XTEST_CASE(xdata_let_queue_create_and_destroy) {
    TriloQueue* queue = trilo_xdata_queue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(queue);

    trilo_xdata_queue_destroy(queue);
    XASSERT_PTR_NULL(queue);
}

// Test case 2: Test TriloQueue enqueue and dequeue
XTEST_CASE(xdata_let_queue_enqueue_and_dequeue) {
    TriloQueue* queue = trilo_xdata_queue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(queue);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    TofuError result = trilo_xdata_queue_insert(queue, tofu1);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_queue_insert(queue, tofu2);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_queue_insert(queue, tofu3);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* dequeued_tofu1 = trilo_xdata_queue_remove(queue, 1;
    XASSERT_PTR_NOT_NULL(dequeued_tofu1);
    XASSERT_INT_EQUAL(1, trilo_xdata_tofu_get_integer(*dequeued_tofu1));

    TriloTofu* dequeued_tofu2 = trilo_xdata_queue_remove(queue, 2);
    XASSERT_PTR_NOT_NULL(dequeued_tofu2);
    XASSERT_INT_EQUAL(2, trilo_xdata_tofu_get_integer(*dequeued_tofu2));

    TriloTofu* dequeued_tofu3 = trilo_xdata_queue_remove(queue, 3);
    XASSERT_PTR_NOT_NULL(dequeued_tofu3);
    XASSERT_INT_EQUAL(3, trilo_xdata_tofu_get_integer(*dequeued_tofu3));

    trilo_xdata_queue_destroy(queue);
}

// Test case 3: Test TriloQueue size
XTEST_CASE(xdata_let_queue_size) {
    TriloQueue* queue = trilo_xdata_queue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(queue);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);

    trilo_xdata_queue_insert(queue, tofu1);
    trilo_xdata_queue_insert(queue, tofu2);

    size_t size = trilo_xdata_queue_size(queue);
    XASSERT_INT_EQUAL(2, size);

    trilo_xdata_queue_destroy(queue);
}

// Test case 4: Test TriloQueue empty check
XTEST_CASE(xdata_let_queue_empty_check) {
    TriloQueue* queue = trilo_xdata_queue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(queue);

    XASSERT_BOOL_TRUE(trilo_xdata_queue_is_empty(queue));
    XASSERT_BOOL_FALSE(trilo_xdata_queue_not_empty(queue));

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_queue_insert(queue, tofu);

    XASSERT_BOOL_FALSE(trilo_xdata_queue_is_empty(queue));
    XASSERT_BOOL_TRUE(trilo_xdata_queue_not_empty(queue));

    trilo_xdata_queue_destroy(queue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_queue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for queue:");

    XTEST_RUN_UNIT(xdata_let_queue_create_and_destroy,  runner);
    XTEST_RUN_UNIT(xdata_let_queue_empty_check,         runner);
    XTEST_RUN_UNIT(xdata_let_queue_enqueue_and_dequeue, runner);
    XTEST_RUN_UNIT(xdata_let_queue_size,                runner);
} // end of func
