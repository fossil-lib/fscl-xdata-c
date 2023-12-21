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

// Test case 1: Test ctofu creation and retrieval of integer value
XTEST_CASE(test_tofu_create_and_erase) {
    // Normal Case: Creating and erasing a tofu value
    ctofu_data value = {.data.integer_type = 42};
    ctofu* result;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tofu_create(INTEGER_TYPE, &value, &result));
    TEST_ASSERT_NOT_NULL_PTR(result);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, tofu_type_getter(result));
    tofu_erase(result);

    // Edge Case: Creating with an invalid type
    TEST_ASSERT_EQUAL(TOFU_WAS_UNKNOWN, tofu_create(INVALID_TYPE, &value, &result));
    TEST_ASSERT_NULL_PTR(result);

    // Edge Case: Creating with a NULL value
    TEST_ASSERT_EQUAL(TOFU_WAS_NULLPTR, tofu_create(INTEGER_TYPE, NULL, &result));
    TEST_ASSERT_NULL_PTR(result);

    // Edge Case: Creating with a NULL result
    TEST_ASSERT_EQUAL(TOFU_WAS_NULLPTR, tofu_create(INTEGER_TYPE, &value, NULL));
}

XTEST_CASE(test_tofu_sort_insertion) {
    // Normal Case: Sorting an array using insertion sort
    ctofu array[] = {{"one", STRING_TYPE}, {"four", STRING_TYPE}, {"two", STRING_TYPE}};
    size_t num = sizeof(array) / sizeof(array[0]);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tofu_sort_insertion(array, num));
    TEST_ASSERT_EQUAL_STRING("four", array[0].data.string_type);
    TEST_ASSERT_EQUAL_STRING("one", array[1].data.string_type);
    TEST_ASSERT_EQUAL_STRING("two", array[2].data.string_type);

    // Edge Case: Sorting an empty array
    ctofu empty_array[0];
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tofu_sort_insertion(empty_array, 0));

    // Edge Case: Sorting with a NULL array
    TEST_ASSERT_EQUAL(TOFU_WAS_NULLPTR, tofu_sort_insertion(NULL, num));
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_tofu_group) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(test_tofu_create_and_erase, runner);
    XTEST_RUN_UNIT(test_tofu_sort_insertion,   runner);
} // end of func
