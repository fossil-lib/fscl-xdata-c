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
#include "fossil/xdata/flist.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_flist_create_and_erase) {
    cflist* flist = fscl_flist_create(TOFU_INT_TYPE);

    // Check if the linked list is created with the expected values
    TEST_ASSERT_NOT_CNULLPTR(flist);
    TEST_ASSERT_CNULLPTR(flist->head);
    TEST_ASSERT_EQUAL(TOFU_INT_TYPE, flist->list_type);

    fscl_flist_erase(flist);

    // Check if the linked list is erased
    TEST_ASSERT_CNULLPTR(flist->head);
    TEST_ASSERT_CNULLPTR(flist);
}

XTEST_CASE(test_flist_insert_and_size) {
    cflist* flist = fscl_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .integer_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .integer_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_flist_insert(flist, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_flist_insert(flist, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_flist_insert(flist, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, fscl_flist_size(flist));

    fscl_flist_erase(flist);
}

XTEST_CASE(test_flist_remove) {
    cflist* flist = fscl_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .integer_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .integer_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .integer_type = 5 } };

    fscl_flist_insert(flist, element1);
    fscl_flist_insert(flist, element2);
    fscl_flist_insert(flist, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_flist_remove(flist, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(42, removedElement.data.integer_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, fscl_flist_size(flist));

    fscl_flist_erase(flist);
}

XTEST_CASE(test_flist_reverse_forward) {
    cflist* flist = fscl_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .integer_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .integer_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .integer_type = 5 } };

    fscl_flist_insert(flist, element1);
    fscl_flist_insert(flist, element2);
    fscl_flist_insert(flist, element3);

    // Reverse the linked list forward
    fscl_flist_reverse_forward(flist);

    // Check if the elements are in reverse order
    ctofu* retrievedElement = fscl_flist_getter(flist, element3);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.integer_type);

    retrievedElement = fscl_flist_getter(flist, element2);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(10, retrievedElement->data.integer_type);

    retrievedElement = fscl_flist_getter(flist, element1);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(5, retrievedElement->data.integer_type);

    fscl_flist_erase(flist);
}

XTEST_CASE(test_flist_reverse_backward) {
    cflist* flist = fscl_flist_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .integer_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .integer_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .integer_type = 5 } };

    fscl_flist_insert(flist, element1);
    fscl_flist_insert(flist, element2);
    fscl_flist_insert(flist, element3);

    // Reverse the linked list backward
    fscl_flist_reverse_backward(flist);

    // Check if the elements are in reverse order
    ctofu* retrievedElement = fscl_flist_getter(flist, element3);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.integer_type);

    retrievedElement = fscl_flist_getter(flist, element2);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(10, retrievedElement->data.integer_type);

    retrievedElement = fscl_flist_getter(flist, element1);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(5, retrievedElement->data.integer_type);

    fscl_flist_erase(flist);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_flist_group) {
    XTEST_NOTE("Running all test cases for flist:");

    XTEST_RUN_UNIT(test_flist_create_and_erase);
    XTEST_RUN_UNIT(test_flist_insert_and_size);
    XTEST_RUN_UNIT(test_flist_remove);
    XTEST_RUN_UNIT(test_flist_reverse_forward);
    XTEST_RUN_UNIT(test_flist_reverse_backward);
} // end of func
