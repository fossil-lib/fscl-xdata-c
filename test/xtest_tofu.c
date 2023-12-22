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
    // Create an array of integers
    ctofu_data data_array[] = { {INTEGER_TYPE, 5}, {INTEGER_TYPE, 3}, {INTEGER_TYPE, 7} };
    ctofu* array = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tofu_create(ARRAY_TYPE, data_array, &array));

    // Sort the array using insertion sort
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tofu_sort_insertion(array->data.array_type.elements, array->data.array_type.size));

    // Check if the array is sorted
    TEST_ASSERT_EQUAL_INT(3, array->data.array_type.elements[0].data.integer_type);
    TEST_ASSERT_EQUAL_INT(5, array->data.array_type.elements[1].data.integer_type);
    TEST_ASSERT_EQUAL_INT(7, array->data.array_type.elements[2].data.integer_type);

    tscl_tofu_erase(array);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_tofu_group) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(test_tofu_create_and_erase, runner);
    XTEST_RUN_UNIT(test_tofu_sort_insertion,   runner);
} // end of func
