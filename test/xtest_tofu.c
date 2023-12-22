/*  ----------------------------------------------------------------------------
    File: xtest_tofu.c

    Description:
    This test file contains unit tests for the various functions and utilities provided
    by the Trilobite Stdlib. These tests ensure the correctness and reliability of the
    library's components and demonstrate their intended usage.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xdata/tofu.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

#define EPSILON 0.001 // Define a small epsilon value for double comparisons

//
// XUNIT TEST CASES
//

XTEST_CASE(test_tofu_create_and_erase) {
    ctofu_data data;
    data.integer_type = 42;

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tofu_create(INTEGER_TYPE, &data, &result));
    TEST_ASSERT_NOT_NULL_PTR(result);

    tscl_tofu_erase(result);
    TEST_ASSERT_NULL_PTR(result);
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

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tofu_create(INTEGER_TYPE, &data1, &node1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tofu_create(INTEGER_TYPE, &data2, &node2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tofu_create(INTEGER_TYPE, &data3, &node3));

    // Sort the linked list using insertion sort
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tofu_sort_insertion(node1, 3));

    // Clean up
    tscl_tofu_erase(node1);
    tscl_tofu_erase(node2);
    tscl_tofu_erase(node3);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_tofu_group) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(test_tofu_create_and_erase, runner);
    XTEST_RUN_UNIT(test_tofu_sort_insertion,   runner);
} // end of func
