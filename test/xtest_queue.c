/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xdata/queue.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_queue_create_and_erase) {
    cqueue* queue = fscl_queue_create(TOFU_INTEGER_TYPE);

    // Check if the queue is created with the expected values
    TEST_ASSERT_NOT_CNULLPTR(queue);
    TEST_ASSERT_CNULLPTR(queue->front);
    TEST_ASSERT_CNULLPTR(queue->rear);
    TEST_ASSERT_EQUAL(TOFU_INTEGER_TYPE, queue->queue_type);

    fscl_queue_erase(queue);

    // Check if the queue is erased
    TEST_ASSERT_CNULLPTR(queue->front);
    TEST_ASSERT_CNULLPTR(queue->rear);
    TEST_ASSERT_CNULLPTR(queue);
}

XTEST_CASE(test_queue_insert_and_size) {
    cqueue* queue = fscl_queue_create(TOFU_INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { TOFU_INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { TOFU_INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_queue_insert(queue, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_queue_insert(queue, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_queue_insert(queue, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, fscl_queue_size(queue));

    fscl_queue_erase(queue);
}

XTEST_CASE(test_queue_remove) {
    cqueue* queue = fscl_queue_create(TOFU_INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { TOFU_INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { TOFU_INTEGER_TYPE, { .integer_type = 5 } };

    fscl_queue_insert(queue, element1);
    fscl_queue_insert(queue, element2);
    fscl_queue_insert(queue, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_queue_remove(queue, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(42, removedElement.data.integer_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, fscl_queue_size(queue));

    fscl_queue_erase(queue);
}

XTEST_CASE(test_queue_not_empty_and_is_empty) {
    cqueue* queue = fscl_queue_create(TOFU_INTEGER_TYPE);

    // Check initially not empty
    TEST_ASSERT_FALSE(fscl_queue_not_empty(queue));
    TEST_ASSERT_TRUE(fscl_queue_is_empty(queue));

    // Insert an element
    ctofu element = { TOFU_INTEGER_TYPE, { .integer_type = 42 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_queue_insert(queue, element));

    // Check not empty after insertion
    TEST_ASSERT_TRUE(fscl_queue_not_empty(queue));
    TEST_ASSERT_FALSE(fscl_queue_is_empty(queue));

    // Remove the element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_queue_remove(queue, &removedElement));

    // Check empty after removal
    TEST_ASSERT_FALSE(fscl_queue_not_empty(queue));
    TEST_ASSERT_TRUE(fscl_queue_is_empty(queue));

    fscl_queue_erase(queue);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_queue_group) {
    XTEST_NOTE("Running all test cases for queue:");

    XTEST_RUN_UNIT(test_queue_create_and_erase);
    XTEST_RUN_UNIT(test_queue_insert_and_size);
    XTEST_RUN_UNIT(test_queue_remove);
    XTEST_RUN_UNIT(test_queue_not_empty_and_is_empty);
} // end of func
