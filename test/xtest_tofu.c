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
#include "fossil/xdata/tofu.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

#define EPSILON 0.001 // Define a small epsilon value for double comparisons

//
// XUNIT TEST CASES
//

XTEST_CASE(test_tofu_create_and_erase) {
    ctofu_data data;
    data.integer_type = 42;

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_INTEGER_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

XTEST_CASE(test_tofu_sort_insertion) {
    // Create linked list nodes for integers
    ctofu_data data1;
    data1.integer_type = 5;
    ctofu_data data2;
    data1.integer_type = 3;
    ctofu_data data3;
    data1.integer_type = 7;

    ctofu* node1 = NULL;
    ctofu* node2 = NULL;
    ctofu* node3 = NULL;

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_INTEGER_TYPE, &data1, &node1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_INTEGER_TYPE, &data2, &node2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_INTEGER_TYPE, &data3, &node3));

    // Sort the linked list using insertion sort
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort_insertion(node1, 3));

    // Clean up
    fscl_tofu_erase(node1);
    fscl_tofu_erase(node2);
    fscl_tofu_erase(node3);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_tofu_group) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(test_tofu_create_and_erase);
    XTEST_RUN_UNIT(test_tofu_sort_insertion);
} // end of func
