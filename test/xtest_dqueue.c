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
// TEST DATA
//
XTEST_DATA(ProjectTestDQueueData) {
    TriloDQueue *dqueue;
}dqueue_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_dqueue_of_int_create_and_destroy) {
    // Test creating and destroying a TriloDQueue
    dqueue_data.dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL(dqueue_data.dqueue);
    TEST_ASSERT_EQUAL_INT(INTEGER_TYPE, dqueue_data.dqueue->deque_type);
    trilo_xdata_dqueue_destroy(dqueue_data.dqueue);
}

XTEST_CASE(xdata_let_dqueue_of_int_push_and_pop) {
    // Test pushing and popping elements from the TriloDQueue
    dqueue_data.dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value3 = trilo_xdata_tofu_create_from_integer(3);

    // Push values to the front and rear of the queue
    trilo_xdata_dqueue_push_front(dqueue_data.dqueue, value1);
    trilo_xdata_dqueue_push_rear(dqueue_data.dqueue, value2);
    trilo_xdata_dqueue_push_rear(dqueue_data.dqueue, value3);

    // Check the front and rear values
    TEST_ASSERT_EQUAL_INT(1, trilo_xdata_tofu_get_integer(trilo_xdata_dqueue_front(dqueue_data.dqueue)));
    TEST_ASSERT_EQUAL_INT(3, trilo_xdata_tofu_get_integer(trilo_xdata_dqueue_rear(dqueue_data.dqueue)));

    // Pop values from the front and rear
    trilo_xdata_dqueue_pop_front(dqueue_data.dqueue);
    trilo_xdata_dqueue_pop_rear(dqueue_data.dqueue);

    // Check the new front and rear values
    TEST_ASSERT_EQUAL_INT(2, trilo_xdata_tofu_get_integer(trilo_xdata_dqueue_front(dqueue_data.dqueue)));
    TEST_ASSERT_EQUAL_INT(2, trilo_xdata_tofu_get_integer(trilo_xdata_dqueue_rear(dqueue_data.dqueue)));

    trilo_xdata_dqueue_destroy(dqueue_data.dqueue);
}

XTEST_CASE(xdata_let_dqueue_of_int_type_mismatch) {
    // Test pushing values of different types into the TriloDQueue
    dqueue_data.dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);

    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value2 = trilo_xdata_tofu_create_from_double(3.14);

    // Attempting to push a value of a different type should result in an error
    TEST_ASSERT_EQUAL_INT(TRILO_XDATA_DQUEUE_TYPE_MISMATCH, trilo_xdata_dqueue_push_front(dqueue_data.dqueue, value2));

    trilo_xdata_dqueue_destroy(dqueue_data.dqueue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_dqueue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for dqueue:");

    XTEST_RUN_UNIT(xdata_let_dqueue_of_int_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_of_int_push_and_pop,       runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_of_int_type_mismatch,      runner);
} // end of func
