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
XTEST_CASE(xdata_let_tofu_create_and_get_integer) {
    ctofu tofu = tofu_create_from_integer(42);
    TEST_ASSERT_EQUAL_BOOL(INTEGER_TYPE, tofu_get_type(tofu));
    TEST_ASSERT_EQUAL_INT(42, tofu_get_integer(tofu));
}

// Test case 2: Test ctofu creation and retrieval of double value
XTEST_CASE(xdata_let_tofu_create_and_get_double) {
    ctofu tofu = tofu_create_from_double(3.14);
    TEST_ASSERT_EQUAL_BOOL(DOUBLE_TYPE, tofu_get_type(tofu));
    TEST_ASSERT_DOUBLE_EQUAL(3.14, tofu_get_double(tofu));
}

// Test case 3: Test ctofu equality
XTEST_CASE(xdata_let_tofu_equality) {
    ctofu tofu1 = tofu_create_from_integer(42);
    ctofu tofu2 = tofu_create_from_integer(42);
    ctofu tofu3 = tofu_create_from_double(3.14);

    TEST_ASSERT_TRUE_BOOL(tofu_equal(tofu1, tofu2));
    TEST_ASSERT_FALSE_BOOL(tofu_equal(tofu1, tofu3));
}

// Test case 4: Test ctofu copy
XTEST_CASE(xdata_let_tofu_copy) {
    ctofu tofu1 = tofu_create_from_integer(42);
    ctofu tofu2 = tofu_copy(tofu1);

    TEST_ASSERT_TRUE_BOOL(tofu_equal(tofu1, tofu2));
}

XTEST_CASE(xdata_let_tofu_create_and_get_string_edge_cases) {
    const char* empty_str = "";
    const char* special_chars_str = "!@#$%^&*()";

    ctofu empty_tofu = tofu_create_from_string(empty_str);
    TEST_ASSERT_EQUAL_BOOL(STRING_TYPE, tofu_get_type(empty_tofu));
    TEST_ASSERT_EQUAL_STRING(empty_str, tofu_get_string(empty_tofu));

    ctofu special_chars_tofu = tofu_create_from_string(special_chars_str);
    TEST_ASSERT_EQUAL_BOOL(STRING_TYPE, tofu_get_type(special_chars_tofu));
    TEST_ASSERT_EQUAL_STRING(special_chars_str, tofu_get_string(special_chars_tofu));
}

XTEST_CASE(xdata_let_tofu_create_and_get_boolean_edge_cases) {
    ctofu true_tofu = tofu_create_from_boolean(true);
    TEST_ASSERT_EQUAL_BOOL(BOOLEAN_TYPE, tofu_get_type(true_tofu));
    TEST_ASSERT_TRUE_BOOL(tofu_get_boolean(true_tofu));

    ctofu false_tofu = tofu_create_from_boolean(false);
    TEST_ASSERT_EQUAL_BOOL(BOOLEAN_TYPE, tofu_get_type(false_tofu));
    TEST_ASSERT_FALSE_BOOL(tofu_get_boolean(false_tofu));
}

// Test cases for ctofu functions
XTEST_CASE(test_tofu_create_and_erase) {
    // Test creating ctofu instances and erasing them
    ctofu tofu1 = tofu_create_from_integer(42);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, tofu1.type);
    TEST_ASSERT_EQUAL(42, tofu_get_integer(tofu1));

    ctofu tofu2 = tofu_create_from_string("Hello, Tofu!");
    TEST_ASSERT_EQUAL(STRING_TYPE, tofu2.type);
    TEST_ASSERT_EQUAL_STRING("Hello, Tofu!", tofu_get_string(tofu2));

    ctofu tofu3 = tofu_create_from_double(3.14);
    TEST_ASSERT_EQUAL(DOUBLE_TYPE, tofu3.type);
    TEST_ASSERT_DOUBLE_EQUAL(3.14, tofu_get_double(tofu3));

    tofu_erase(&tofu1);
    tofu_erase(&tofu2);
    tofu_erase(&tofu3);
}

XTEST_CASE(test_tofu_compare) {
    // Test comparing ctofu instances
    ctofu tofu1 = tofu_create_from_integer(42);
    ctofu tofu2 = tofu_create_from_integer(42);
    ctofu tofu3 = tofu_create_from_integer(100);

    TEST_ASSERT_EQUAL(TRILO_XDATA_TYPE_SUCCESS, tofu_compare(tofu1, tofu2));
    TEST_ASSERT_EQUAL(TRILO_XDATA_TYPE_WAS_MISMATCH, tofu_compare(tofu1, tofu3));

    tofu_erase(&tofu1);
    tofu_erase(&tofu2);
    tofu_erase(&tofu3);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_tofu_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(test_tofu_create_and_erase,            runner);
    XTEST_RUN_UNIT(test_tofu_compare,                     runner);
    XTEST_RUN_UNIT(xdata_let_tofu_copy,                   runner);
    XTEST_RUN_UNIT(xdata_let_tofu_create_and_get_double,  runner);
    XTEST_RUN_UNIT(xdata_let_tofu_create_and_get_integer, runner);
    XTEST_RUN_UNIT(xdata_let_tofu_equality,               runner);
    XTEST_RUN_UNIT(xdata_let_tofu_create_and_get_string_edge_cases,  runner);
    XTEST_RUN_UNIT(xdata_let_tofu_create_and_get_boolean_edge_cases, runner);
} // end of func
