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

// Test case 1: Test TriloTofu creation and retrieval of integer value
XTEST_CASE(xdata_let_tofu_create_and_get_integer) {
    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    TEST_ASSERT_EQUAL_BOOL(INTEGER_TYPE, trilo_xdata_tofu_get_type(tofu));
    TEST_ASSERT_EQUAL_INT(42, trilo_xdata_tofu_get_integer(tofu));
}

// Test case 2: Test TriloTofu creation and retrieval of double value
XTEST_CASE(xdata_let_tofu_create_and_get_double) {
    TriloTofu tofu = trilo_xdata_tofu_create_from_double(3.14);
    TEST_ASSERT_EQUAL_BOOL(DOUBLE_TYPE, trilo_xdata_tofu_get_type(tofu));
    TEST_ASSERT_DOUBLE_EQUAL(3.14, trilo_xdata_tofu_get_double(tofu));
}

// Test case 3: Test TriloTofu equality
XTEST_CASE(xdata_let_tofu_equality) {
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_double(3.14);

    TEST_ASSERT_TRUE_BOOL(trilo_xdata_tofu_equal(tofu1, tofu2));
    TEST_ASSERT_FALSE_BOOL(trilo_xdata_tofu_equal(tofu1, tofu3));
}

// Test case 4: Test TriloTofu copy
XTEST_CASE(xdata_let_tofu_copy) {
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_copy(tofu1);

    TEST_ASSERT_TRUE_BOOL(trilo_xdata_tofu_equal(tofu1, tofu2));
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_tofu_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(xdata_let_tofu_copy,                   runner);
    XTEST_RUN_UNIT(xdata_let_tofu_create_and_get_double,  runner);
    XTEST_RUN_UNIT(xdata_let_tofu_create_and_get_integer, runner);
    XTEST_RUN_UNIT(xdata_let_tofu_equality,               runner);
} // end of func
