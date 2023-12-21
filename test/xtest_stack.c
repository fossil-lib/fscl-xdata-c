/*  ----------------------------------------------------------------------------
    File: xtest_stack.c

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
#include "trilobite/xdata/stack.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

XTEST_CASE(test_stack_create_and_erase) {
    // Normal Case: Creating and erasing a stack
    cstack* stack = stack_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(stack);
    stack_erase(stack);

    // Edge Case: Creating with an invalid type
    stack = stack_create(INVALID_TYPE);
    TEST_ASSERT_NULL_PTR(stack);
}

XTEST_CASE(test_stack_insert_and_remove) {
    // Normal Case: Inserting and removing elements from the stack
    cstack* stack = stack_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(stack);

    ctofu element = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, stack_insert(stack, element));
    TEST_ASSERT_EQUAL(1, stack_size(stack));

    ctofu popped;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, stack_remove(stack, &popped));
    TEST_ASSERT_EQUAL(42, popped.data.integer_type);
    TEST_ASSERT_EQUAL(0, stack_size(stack));

    stack_erase(stack);

    // Edge Case: Removing from an empty stack
    TEST_ASSERT_EQUAL(TOFU_WAS_UNKNOWN
    TEST_ASSERT_NOT_NULL_PTR(stack);

    ctofu element = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, stack_insert(stack, element));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, stack_insert(stack, element));

    TEST_ASSERT_EQUAL(1, stack_search(stack, element));

    stack_erase(stack);

    // Edge Case: Searching in an empty stack
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, stack_search(stack, element));
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_stack_group) {
    XTEST_NOTE("Running all test cases for stack:");

    XTEST_RUN_UNIT(test_stack_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_stack_insert_and_remove, runner);
    XTEST_RUN_UNIT(test_stack_search,            runner);
} // end of func
