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

XTEST_CASE(xdata_let_stack_create_and_destroy) {
    cstack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(stack);

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_insert_and_size) {
    cstack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    
    ctofu data1 = trilo_xdata_tofu_create_from_integer(42);
    ctofu data2 = trilo_xdata_tofu_create_from_integer(7);

    ctofu_error result1 = trilo_xdata_stack_insert(stack, data1);
    ctofu_error result2 = trilo_xdata_stack_insert(stack, data2);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result1);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result2);
    
    size_t size = trilo_xdata_stack_size(stack);
    TEST_ASSERT_EQUAL_BOOL(2, size);
    
    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_remove_and_search) {
    cstack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    
    ctofu data1 = trilo_xdata_tofu_create_from_integer(42);
    ctofu data2 = trilo_xdata_tofu_create_from_integer(7);

    trilo_xdata_stack_insert(stack, data1);
    trilo_xdata_stack_insert(stack, data2);

    ctofu_error result1 = trilo_xdata_stack_remove(stack, data1);
    ctofu_error result2 = trilo_xdata_stack_remove(stack, data2);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result1);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result2);
    
    ctofu_error search_result1 = trilo_xdata_stack_search(stack, data1);
    ctofu_error search_result2 = trilo_xdata_stack_search(stack, data2);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_WAS_UNKNOWN, search_result1);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_WAS_UNKNOWN, search_result2);
    
    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_getter_and_setter) {
    cstack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    
    ctofu data1 = trilo_xdata_tofu_create_from_integer(42);
    ctofu data2 = trilo_xdata_tofu_create_from_integer(7);

    trilo_xdata_stack_insert(stack, data1);
    trilo_xdata_stack_insert(stack, data2);

    ctofu* getter_result1 = trilo_xdata_stack_getter(stack, data1);
    ctofu* getter_result2 = trilo_xdata_stack_getter(stack, data2);
    
    TEST_ASSERT_NOT_NULL_PTR(getter_result1);
    TEST_ASSERT_NOT_NULL_PTR(getter_result2);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tofu_compare(*getter_result1, data1));
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tofu_compare(*getter_result2, data2));
    
    ctofu new_data1 = trilo_xdata_tofu_create_from_integer(99);
    ctofu new_data2 = trilo_xdata_tofu_create_from_integer(77);

    ctofu_error setter_result1 = trilo_xdata_stack_setter(stack, new_data1);
    ctofu_error setter_result2 = trilo_xdata_stack_setter(stack, new_data2);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, setter_result1);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, setter_result2);

    // Check if the data was updated
    getter_result1 = trilo_xdata_stack_getter(stack, new_data1);
    getter_result2 = trilo_xdata_stack_getter(stack, new_data2);
    
    TEST_ASSERT_NOT_NULL_PTR(getter_result1);
    TEST_ASSERT_NOT_NULL_PTR(getter_result2);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tofu_compare(*getter_result1, new_data1));
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tofu_compare(*getter_result2, new_data2));

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_empty_check) {
    cstack* stack = trilo_xdata_stack_create(INTEGER_TYPE);

    TEST_ASSERT_TRUE_BOOL(trilo_xdata_stack_is_empty(stack));
    TEST_ASSERT_FALSE_BOOL(trilo_xdata_stack_not_empty(stack));

    ctofu data = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_stack_insert(stack, data);

    TEST_ASSERT_FALSE_BOOL(trilo_xdata_stack_is_empty(stack));
    TEST_ASSERT_TRUE_BOOL(trilo_xdata_stack_not_empty(stack));

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_nullptr_check) {
    cstack* stack = NULL;

    TEST_ASSERT_TRUE_BOOL(trilo_xdata_stack_is_nullptr(stack));
    TEST_ASSERT_FALSE_BOOL(trilo_xdata_stack_not_nullptr(stack));

    stack = trilo_xdata_stack_create(INTEGER_TYPE);

    TEST_ASSERT_FALSE_BOOL(trilo_xdata_stack_is_nullptr(stack));
    TEST_ASSERT_TRUE_BOOL(trilo_xdata_stack_not_nullptr(stack));

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_top) {
    cstack* stack = trilo_xdata_stack_create(INTEGER_TYPE);

    ctofu data1 = trilo_xdata_tofu_create_from_integer(42);
    ctofu data2 = trilo_xdata_tofu_create_from_integer(7);

    trilo_xdata_stack_insert(stack, data1);
    trilo_xdata_stack_insert(stack, data2);

    TEST_ASSERT_EQUAL_INT(7, trilo_xdata_tofu_get_integer(trilo_xdata_stack_top(stack)));

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_insert_and_size_edge_cases) {
    cstack* stack = trilo_xdata_stack_create(INTEGER_TYPE);

    // Test inserting a large number of elements
    for (int i = 0; i < 1000; ++i) {
        ctofu data = trilo_xdata_tofu_create_from_integer(i);
        trilo_xdata_stack_insert(stack, data);
    }
    TEST_ASSERT_EQUAL_INT(1000, trilo_xdata_stack_size(stack));

    // Test inserting elements of different types
    ctofu double_data = trilo_xdata_tofu_create_from_double(3.14);
    ctofu string_data = trilo_xdata_tofu_create_from_string("Hello");

    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_stack_insert(stack, double_data));
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_stack_insert(stack, string_data));

    TEST_ASSERT_EQUAL_INT(1002, trilo_xdata_stack_size(stack));

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_remove_and_search_edge_cases) {
    cstack* empty_stack = trilo_xdata_stack_create(INTEGER_TYPE);

    // Test removing elements from an empty stack
    ctofu data = trilo_xdata_tofu_create_from_integer(42);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_WAS_UNKNOWN, trilo_xdata_stack_remove(empty_stack, data));

    // Test searching for elements in an empty stack
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_WAS_UNKNOWN, trilo_xdata_stack_search(empty_stack, data));

    trilo_xdata_stack_destroy(empty_stack);
}

XTEST_CASE(xdata_let_stack_top_edge_cases) {
    cstack* empty_stack = NULL;

    // Test getting the top element from an empty stack
    TEST_ASSERT_NULL_PTR(trilo_xdata_stack_top(empty_stack));

    trilo_xdata_stack_destroy(empty_stack);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_stack_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for stack:");

    XTEST_RUN_UNIT(xdata_let_stack_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_stack_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_stack_getter_and_setter,  runner);
    XTEST_RUN_UNIT(xdata_let_stack_insert_and_size,    runner);
    XTEST_RUN_UNIT(xdata_let_stack_nullptr_check,      runner);
    XTEST_RUN_UNIT(xdata_let_stack_remove_and_search,  runner);
    XTEST_RUN_UNIT(xdata_let_stack_nullptr_check,      runner);
    XTEST_RUN_UNIT(xdata_let_stack_remove_and_search,  runner);
    XTEST_RUN_UNIT(xdata_let_stack_top,                runner);
    XTEST_RUN_UNIT(xdata_let_stack_insert_and_size_edge_cases,   runner);
    XTEST_RUN_UNIT(xdata_let_stack_remove_and_search_edge_cases, runner);
    XTEST_RUN_UNIT(xdata_let_stack_top_edge_cases,               runner);
} // end of func
