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
#include "fossil/xdata/dqueue.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_dqueue_create_and_erase) {
    cdqueue* dqueue = fscl_dqueue_create(TOFU_INT_TYPE);

    // Check if the deque is created with the expected values
    TEST_ASSERT_NOT_CNULLPTR(dqueue);
    TEST_ASSERT_CNULLPTR(dqueue->front);
    TEST_ASSERT_CNULLPTR(dqueue->rear);
    TEST_ASSERT_EQUAL(TOFU_INT_TYPE, dqueue->list_type);

    fscl_dqueue_erase(dqueue);

    // Check if the deque is erased
    TEST_ASSERT_CNULLPTR(dqueue->front);
    TEST_ASSERT_CNULLPTR(dqueue->rear);
    TEST_ASSERT_CNULLPTR(dqueue);
}

XTEST_CASE(test_dqueue_insert_and_size) {
    cdqueue* dqueue = fscl_dqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dqueue_insert(dqueue, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dqueue_insert(dqueue, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dqueue_insert(dqueue, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, fscl_dqueue_size(dqueue));

    fscl_dqueue_erase(dqueue);
}

XTEST_CASE(test_dqueue_remove) {
    cdqueue* dqueue = fscl_dqueue_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fscl_dqueue_insert(dqueue, element1);
    fscl_dqueue_insert(dqueue, element2);
    fscl_dqueue_insert(dqueue, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dqueue_remove(dqueue, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(42, removedElement.data.int_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, fscl_dqueue_size(dqueue));

    fscl_dqueue_erase(dqueue);
}

XTEST_CASE(test_dqueue_getter_and_setter) {
    cdqueue* dqueue = fscl_dqueue_create(TOFU_INT_TYPE);

    // Insert an element
    ctofu element = { TOFU_INT_TYPE, { .int_type = 42 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dqueue_insert(dqueue, element));

    // Get the value for an element
    ctofu* retrievedElement = fscl_dqueue_getter(dqueue, element);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.int_type);

    // Update the value for an element
    ctofu updatedElement = { TOFU_INT_TYPE, { .int_type = 50 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dqueue_setter(dqueue, updatedElement));

    // Get the updated value for the element
    retrievedElement = fscl_dqueue_getter(dqueue, updatedElement);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(50, retrievedElement->data.int_type);

    fscl_dqueue_erase(dqueue);
}

XTEST_CASE(test_dqueue_not_empty_and_is_empty) {
    cdqueue* dqueue = fscl_dqueue_create(TOFU_INT_TYPE);

    // Check initially not empty
    TEST_ASSERT_FALSE(fscl_dqueue_not_empty(dqueue));
    TEST_ASSERT_TRUE(fscl_dqueue_is_empty(dqueue));

    // Insert an element
    ctofu element = { TOFU_INT_TYPE, { .int_type = 42 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dqueue_insert(dqueue, element));

    // Check not empty after insertion
    TEST_ASSERT_TRUE(fscl_dqueue_not_empty(dqueue));
    TEST_ASSERT_FALSE(fscl_dqueue_is_empty(dqueue));

    // Remove the element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dqueue_remove(dqueue, &removedElement));

    // Check empty after removal
    TEST_ASSERT_FALSE(fscl_dqueue_not_empty(dqueue));
    TEST_ASSERT_TRUE(fscl_dqueue_is_empty(dqueue));

    fscl_dqueue_erase(dqueue);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_dqueue_group) {
    XTEST_RUN_UNIT(test_dqueue_create_and_erase);
    XTEST_RUN_UNIT(test_dqueue_insert_and_size);
    XTEST_RUN_UNIT(test_dqueue_remove);
    XTEST_RUN_UNIT(test_dqueue_getter_and_setter);
    XTEST_RUN_UNIT(test_dqueue_not_empty_and_is_empty);
} // end of func
