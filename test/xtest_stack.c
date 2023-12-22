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
    cstack* stack = tscl_stack_create(INTEGER_TYPE);

    // Check if the stack is created with the expected values
    TEST_ASSERT_NOT_NULL_PTR(stack);
    TEST_ASSERT_NULL_PTR(stack->top);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, stack->stack_type);

    tscl_stack_erase(stack);

    // Check if the stack is erased
    TEST_ASSERT_NULL_PTR(stack->top);
    TEST_ASSERT_NULL_PTR(stack);
}

XTEST_CASE(test_stack_insert_and_size) {
    cstack* stack = tscl_stack_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_stack_insert(stack, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_stack_insert(stack, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_stack_insert(stack, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, tscl_stack_size(stack));

    tscl_stack_erase(stack);
}

XTEST_CASE(test_stack_remove) {
    cstack* stack = tscl_stack_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_stack_insert(stack, element1);
    tscl_stack_insert(stack, element2);
    tscl_stack_insert(stack, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_stack_remove(stack, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(5, removedElement.data.integer_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, tscl_stack_size(stack));

    tscl_stack_erase(stack);
}

XTEST_CASE(test_stack_top) {
    cstack* stack = tscl_stack_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_stack_insert(stack, element1);
    tscl_stack_insert(stack, element2);
    tscl_stack_insert(stack, element3);

    // Check the top element
    ctofu topElement = tscl_stack_top(stack, (ctofu){INTEGER_TYPE, {.integer_type = -1}});
    TEST_ASSERT_EQUAL_INT(5, topElement.data.integer_type);

    // Remove an element
    tscl_stack_remove(stack, NULL);

    // Check the top element after removal
    topElement = tscl_stack_top(stack, (ctofu){INTEGER_TYPE, {.integer_type = -1}});
    TEST_ASSERT_EQUAL_INT(10, topElement.data.integer_type);

    tscl_stack_erase(stack);
}


//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_stack_group) {
    XTEST_NOTE("Running all test cases for stack:");

    XTEST_RUN_UNIT(test_stack_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_stack_insert_and_size, runner);
    XTEST_RUN_UNIT(test_stack_remove,            runner);
    XTEST_RUN_UNIT(test_stack_top,               runner);
} // end of func
