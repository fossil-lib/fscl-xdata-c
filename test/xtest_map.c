/*  ----------------------------------------------------------------------------
    File: xtest_map.c

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
#include "trilobite/xdata/map.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test cmap creation and destruction
XTEST_CASE(xdata_let_map_create_and_destroy) {
    cmap* map = trilo_xdata_map_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);

    trilo_xdata_map_destroy(map);
}

// Test case 2: Test cmap insert and search
XTEST_CASE(xdata_let_map_insert_and_search) {
    cmap* map = trilo_xdata_map_create(STRING_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);

    ctofu key = trilo_xdata_tofu_create_from_string("name");
    ctofu value = trilo_xdata_tofu_create_from_string("John");

    ctofu_error insertResult = trilo_xdata_map_insert(map, key, value);
    TEST_ASSERT_EQUAL_ENUM(TRILO_XDATA_TYPE_SUCCESS, insertResult);

    ctofu_error searchResult = trilo_xdata_map_search(map, key);
    TEST_ASSERT_EQUAL_ENUM(TRILO_XDATA_TYPE_SUCCESS, searchResult);

    // Clean up
    trilo_xdata_map_destroy(map);
}

// Test case 3: Test cmap remove operation
XTEST_CASE(xdata_let_map_remove) {
    cmap* map = trilo_xdata_map_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);

    ctofu key = trilo_xdata_tofu_create_from_string("age");
    ctofu value = trilo_xdata_tofu_create_from_integer(30);

    ctofu_error insertResult = trilo_xdata_map_insert(map, key, value);
    TEST_ASSERT_EQUAL_ENUM(TRILO_XDATA_TYPE_SUCCESS, insertResult);

    ctofu_error removeResult = trilo_xdata_map_remove(map, key);
    TEST_ASSERT_EQUAL_ENUM(TRILO_XDATA_TYPE_SUCCESS, removeResult);

    ctofu_error searchResult = trilo_xdata_map_search(map, key);
    TEST_ASSERT_EQUAL_ENUM(TRILO_XDATA_TYPE_WAS_UNKNOWN, searchResult);

    // Clean up
    trilo_xdata_map_destroy(map);
}

// Test case 4: Test cmap setter and getter operations
XTEST_CASE(xdata_let_map_getter_and_setter) {
    cmap* map = trilo_xdata_map_create(BOOLEAN_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);

    ctofu key = trilo_xdata_tofu_create_from_string("is_valid");
    ctofu value = trilo_xdata_tofu_create_from_boolean(true);

    ctofu_error insertResult = trilo_xdata_map_insert(map, key, value);
    TEST_ASSERT_EQUAL_ENUM(TRILO_XDATA_TYPE_SUCCESS, insertResult);

    ctofu newValue = trilo_xdata_tofu_create_from_boolean(false);
    ctofu_error setResult = trilo_xdata_map_setter(map, key, newValue);
    TEST_ASSERT_EQUAL_ENUM(TRILO_XDATA_TYPE_SUCCESS, setResult);

    ctofu retrievedValue;
    ctofu_error getResult = trilo_xdata_map_getter(map, key, &retrievedValue);
    TEST_ASSERT_EQUAL_ENUM(TRILO_XDATA_TYPE_SUCCESS, getResult);
    TEST_ASSERT_TRUE(trilo_xdata_tofu_get_boolean(retrievedValue) == false);

    // Clean up
    trilo_xdata_map_destroy(map);
}

// Test case 5: Test cmap size operation
XTEST_CASE(xdata_let_map_size) {
    cmap* map = trilo_xdata_map_create(DOUBLE_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);

    TEST_ASSERT_EQUAL_ENUM(0, trilo_xdata_map_size(map));

    ctofu key1 = trilo_xdata_tofu_create_from_string("price");
    ctofu value1 = trilo_xdata_tofu_create_from_double(19.99);
    trilo_xdata_map_insert(map, key1, value1);

    TEST_ASSERT_EQUAL_ENUM(1, trilo_xdata_map_size(map));

    ctofu key2 = trilo_xdata_tofu_create_from_string("quantity");
    ctofu value2 = trilo_xdata_tofu_create_from_integer(5);
    trilo_xdata_map_insert(map, key2, value2);

    TEST_ASSERT_EQUAL_ENUM(2, trilo_xdata_map_size(map));

    // Clean up
    trilo_xdata_map_destroy(map);
}

// Test case 6: Test cmap contains operation
XTEST_CASE(xdata_let_map_contains) {
    cmap* map = trilo_xdata_map_create(CHAR_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);

    ctofu key = trilo_xdata_tofu_create_from_char('A');
    ctofu value = trilo_xdata_tofu_create_from_string("Apple");
    trilo_xdata_map_insert(map, key, value);

    TEST_ASSERT_TRUE(trilo_xdata_map_contains(map, key));
    TEST_ASSERT_FALSE(trilo_xdata_map_contains(map, trilo_xdata_tofu_create_from_char('B')));

    // Clean up
    trilo_xdata_map_destroy(map);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_map_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for map:");

    XTEST_RUN_UNIT(xdata_let_map_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_map_insert_and_search,  runner);
    XTEST_RUN_UNIT(xdata_let_map_remove,             runner);
    XTEST_RUN_UNIT(xdata_let_map_getter_and_setter,  runner);
    XTEST_RUN_UNIT(xdata_let_map_size,               runner);
    XTEST_RUN_UNIT(xdata_let_map_contains,           runner);
} // end of func
