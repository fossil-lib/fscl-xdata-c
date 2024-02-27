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
#include "fossil/xdata/dlist.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_dlist_create_and_erase) {
    cdlist* dlist = fscl_dlist_create(TOFU_INT_TYPE);

    // Check if the doubly linked list is created with the expected values
    TEST_ASSERT_NOT_CNULLPTR(dlist);
    TEST_ASSERT_CNULLPTR(dlist->head);
    TEST_ASSERT_CNULLPTR(dlist->tail);
    TEST_ASSERT_EQUAL(TOFU_INT_TYPE, dlist->list_type);

    fscl_dlist_erase(dlist);

    // Check if the doubly linked list is erased
    TEST_ASSERT_CNULLPTR(dlist->head);
    TEST_ASSERT_CNULLPTR(dlist->tail);
    TEST_ASSERT_CNULLPTR(dlist);
}

XTEST_CASE(test_dlist_insert_and_size) {
    cdlist* dlist = fscl_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { int_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dlist_insert(dlist, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dlist_insert(dlist, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dlist_insert(dlist, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, fscl_dlist_size(dlist));

    fscl_dlist_erase(dlist);
}

XTEST_CASE(test_dlist_remove) {
    cdlist* dlist = fscl_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { int_type = 5 } };

    fscl_dlist_insert(dlist, element1);
    fscl_dlist_insert(dlist, element2);
    fscl_dlist_insert(dlist, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_dlist_remove(dlist, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(42, removedElement.data.int_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, fscl_dlist_size(dlist));

    fscl_dlist_erase(dlist);
}

XTEST_CASE(test_dlist_reverse_forward) {
    cdlist* dlist = fscl_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { int_type = 5 } };

    fscl_dlist_insert(dlist, element1);
    fscl_dlist_insert(dlist, element2);
    fscl_dlist_insert(dlist, element3);

    // Reverse the doubly linked list forward
    fscl_dlist_reverse_forward(dlist);

    // Check if the elements are in reverse order
    ctofu* retrievedElement = fscl_dlist_getter(dlist, element3);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.int_type);

    retrievedElement = fscl_dlist_getter(dlist, element2);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(10, retrievedElement->data.int_type);

    retrievedElement = fscl_dlist_getter(dlist, element1);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(5, retrievedElement->data.int_type);

    fscl_dlist_erase(dlist);
}

XTEST_CASE(test_dlist_reverse_backward) {
    cdlist* dlist = fscl_dlist_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { int_type = 5 } };

    fscl_dlist_insert(dlist, element1);
    fscl_dlist_insert(dlist, element2);
    fscl_dlist_insert(dlist, element3);

    // Reverse the doubly linked list backward
    fscl_dlist_reverse_backward(dlist);

    // Check if the elements are in reverse order
    ctofu* retrievedElement = fscl_dlist_getter(dlist, element3);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.int_type);

    retrievedElement = fscl_dlist_getter(dlist, element2);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(10, retrievedElement->data.int_type);

    retrievedElement = fscl_dlist_getter(dlist, element1);
    TEST_ASSERT_NOT_CNULLPTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(5, retrievedElement->data.int_type);

    fscl_dlist_erase(dlist);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_dlist_group) {
    XTEST_NOTE("Running all test cases for dlist:");

    XTEST_RUN_UNIT(test_dlist_create_and_erase);
    XTEST_RUN_UNIT(test_dlist_insert_and_size);
    XTEST_RUN_UNIT(test_dlist_remove);
    XTEST_RUN_UNIT(test_dlist_reverse_forward);
    XTEST_RUN_UNIT(test_dlist_reverse_backward);
} // end of func
