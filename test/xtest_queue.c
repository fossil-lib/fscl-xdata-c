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
// TEST DATA
//
XTEST_DATA(ProjectTestQueueData) {
    TriloQueue *queue;
}queue_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_queue_of_int_create_and_destroy) {
    // Test creating and destroying a TriloQueue
    queue_data.queue = trilo_xdata_queue_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(queue_data.queue);
    trilo_xdata_queue_destroy(queue_data.queue);
}

XTEST_CASE(xdata_let_queue_of_int_enqueue_and_dequeue) {
    // Test enqueuing and dequeuing data from the TriloQueue
    queue_data.queue = trilo_xdata_queue_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_queue_enqueue(queue_data.queue, tofu1);
    trilo_xdata_queue_enqueue(queue_data.queue, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_queue_is_empty(queue_data.queue));
    XASSERT_INT_EQUAL(2, trilo_xdata_queue_size(queue_data.queue));

    trilo_xdata_queue_dequeue(queue_data.queue);
    trilo_xdata_queue_dequeue(queue_data.queue);

    XASSERT_BOOL_TRUE(trilo_xdata_queue_is_empty(queue_data.queue));
    XASSERT_INT_EQUAL(0, trilo_xdata_queue_size(queue_data.queue));

    trilo_xdata_queue_destroy(queue_data.queue);
}

XTEST_CASE(xdata_let_queue_of_int_peek) {
    // Test peeking at the front element of the TriloQueue
    queue_data.queue = trilo_xdata_queue_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_queue_enqueue(queue_data.queue, tofu1);
    trilo_xdata_queue_enqueue(queue_data.queue, tofu2);

    TriloTofu peeked_tofu = trilo_xdata_queue_peek(queue_data.queue);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(peeked_tofu));

    XASSERT_BOOL_FALSE(trilo_xdata_queue_is_empty(queue_data.queue));
    XASSERT_INT_EQUAL(2, trilo_xdata_queue_size(queue_data.queue));

    trilo_xdata_queue_destroy(queue_data.queue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_queue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for queue:");

    XTEST_RUN_UNIT(xdata_let_queue_of_int_create_and_destroy,  runner);
    XTEST_RUN_UNIT(xdata_let_queue_of_int_enqueue_and_dequeue, runner);
    XTEST_RUN_UNIT(xdata_let_queue_of_int_peek,                runner);
} // end of func
