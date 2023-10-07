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
// TEST DATA
//
XTEST_DATA(ProjectTestPQueueData) {
    TriloPQueue *pqueue;
}pqueue_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_pqueue_of_int_create_and_destroy) {
    // Test creating and destroying a TriloPQueue
    pqueue_data.pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(pqueue_data.pqueue);
    trilo_xdata_pqueue_destroy(pqueue_data.pqueue);
}

XTEST_CASE(xdata_let_pqueue_of_int_enqueue_and_dequeue) {
    // Test enqueuing and dequeuing data from the TriloPQueue
    pqueue_data.pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_pqueue_enqueue(pqueue_data.pqueue, tofu1, 2);
    trilo_xdata_pqueue_enqueue(pqueue_data.pqueue, tofu2, 1);

    XASSERT_BOOL_FALSE(trilo_xdata_pqueue_is_empty(pqueue_data.pqueue));
    XASSERT_INT_EQUAL(2, trilo_xdata_pqueue_size(pqueue_data.pqueue));

    TriloTofu dequeued_tofu1;
    int priority1;
    trilo_xdata_pqueue_dequeue(pqueue_data.pqueue, &dequeued_tofu1, &priority1);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(dequeued_tofu1));
    XASSERT_INT_EQUAL(2, priority1);

    TriloTofu dequeued_tofu2;
    int priority2;
    trilo_xdata_pqueue_dequeue(pqueue_data.pqueue, &dequeued_tofu2, &priority2);
    XASSERT_INT_EQUAL(17, trilo_xdata_tofu_get_integer(dequeued_tofu2));
    XASSERT_INT_EQUAL(1, priority2);

    XASSERT_BOOL_TRUE(trilo_xdata_pqueue_is_empty(pqueue_data.pqueue));
    XASSERT_INT_EQUAL(0, trilo_xdata_pqueue_size(pqueue_data.pqueue));

    trilo_xdata_pqueue_destroy(pqueue_data.pqueue);
}

XTEST_CASE(xdata_let_pqueue_of_int_peek) {
    // Test peeking at the front element of the TriloPQueue
    pqueue_data.pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_pqueue_enqueue(pqueue_data.pqueue, tofu1, 2);
    trilo_xdata_pqueue_enqueue(pqueue_data.pqueue, tofu2, 1);

    TriloTofu peeked_tofu;
    int priority;
    trilo_xdata_pqueue_peek(pqueue_data.pqueue, &peeked_tofu, &priority);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(peeked_tofu));
    XASSERT_INT_EQUAL(2, priority);

    XASSERT_BOOL_FALSE(trilo_xdata_pqueue_is_empty(pqueue_data.pqueue));
    XASSERT_INT_EQUAL(2, trilo_xdata_pqueue_size(pqueue_data.pqueue));

    trilo_xdata_pqueue_destroy(pqueue_data.pqueue);
}

XTEST_CASE(xdata_let_pqueue_of_int_type_mismatch) {
    // Test enqueuing data of different types to the TriloPQueue
    pqueue_data.pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_pqueue_enqueue(pqueue_data.pqueue, tofu1, 2);

    // Attempting to enqueue data of different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_PQUEUE_TYPE_MISMATCH, trilo_xdata_pqueue_enqueue(pqueue_data.pqueue, tofu2, 1));

    trilo_xdata_pqueue_destroy(pqueue_data.pqueue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_pqueue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for pqueue:");

    XTEST_RUN_UNIT(xdata_let_pqueue_of_int_create_and_destroy,  runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_of_int_enqueue_and_dequeue, runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_of_int_peek,                runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_of_int_type_mismatch,       runner);
} // end of func
