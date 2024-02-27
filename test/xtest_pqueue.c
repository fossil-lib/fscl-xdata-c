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
#include "fossil/xdata/pqueue.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_pqueue_create_and_erase) {
    cpqueue* pqueue = fscl_pqueue_create(TOFU_INT_TYPE);

    // Check if the priority queue is created with the expected values
    TEST_ASSERT_NOT_CNULLPTR(pqueue);
    TEST_ASSERT_CNULLPTR(pqueue->front);
    TEST_ASSERT_EQUAL(TOFU_INT_TYPE, pqueue->queue_type);

    fscl_pqueue_erase(pqueue);

    // Check if the priority queue is erased
    TEST_ASSERT_CNULLPTR(pqueue->front);
    TEST_ASSERT_CNULLPTR(pqueue);
}

XTEST_CASE(test_pqueue_insert_and_size) {
    cpqueue* pqueue = fscl_pqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_pqueue_insert(pqueue, element1, 2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_pqueue_insert(pqueue, element2, 1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_pqueue_insert(pqueue, element3, 3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, fscl_pqueue_size(pqueue));

    fscl_pqueue_erase(pqueue);
}

XTEST_CASE(test_pqueue_remove) {
    cpqueue* pqueue = fscl_pqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fscl_pqueue_insert(pqueue, element1, 2);
    fscl_pqueue_insert(pqueue, element2, 1);
    fscl_pqueue_insert(pqueue, element3, 3);

    // Remove an element
    ctofu removedElement;
    int removedPriority;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check if the removed element and priority are correct
    TEST_ASSERT_EQUAL_INT(10, removedElement.data.int_type);
    TEST_ASSERT_EQUAL_INT(1, removedPriority);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, fscl_pqueue_size(pqueue));

    fscl_pqueue_erase(pqueue);
}

XTEST_CASE(test_pqueue_not_empty_and_is_empty) {
    cpqueue* pqueue = fscl_pqueue_create(TOFU_INT_TYPE);

    // Check initially not empty
    TEST_ASSERT_FALSE(fscl_pqueue_not_empty(pqueue));
    TEST_ASSERT_TRUE(fscl_pqueue_is_empty(pqueue));

    // Insert an element
    ctofu element = { TOFU_INT_TYPE, { .int_type = 42 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_pqueue_insert(pqueue, element, 2));

    // Check not empty after insertion
    TEST_ASSERT_TRUE(fscl_pqueue_not_empty(pqueue));
    TEST_ASSERT_FALSE(fscl_pqueue_is_empty(pqueue));

    // Remove the element
    ctofu removedElement;
    int removedPriority;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check empty after removal
    TEST_ASSERT_FALSE(fscl_pqueue_not_empty(pqueue));
    TEST_ASSERT_TRUE(fscl_pqueue_is_empty(pqueue));

    fscl_pqueue_erase(pqueue);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_pqueue_group) {
    XTEST_NOTE("Running all test cases for pqueue:");

    XTEST_RUN_UNIT(test_pqueue_create_and_erase);
    XTEST_RUN_UNIT(test_pqueue_insert_and_size);
    XTEST_RUN_UNIT(test_pqueue_remove);
    XTEST_RUN_UNIT(test_pqueue_not_empty_and_is_empty);
} // end of func
