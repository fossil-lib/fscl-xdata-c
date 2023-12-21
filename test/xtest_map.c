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
XTEST_CASE(test_map_create_and_erase) {
    // Normal Case: Creating and erasing a map
    cmap* map = map_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);
    map_erase(map);

    // Edge Case: Creating with an invalid type
    map = map_create(INVALID_TYPE);
    TEST_ASSERT_NULL_PTR(map);
}

XTEST_CASE(test_map_insert_and_remove) {
    // Normal Case: Inserting and removing elements from the map
    cmap* map = map_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);

    ctofu key = {.data.integer_type = 42};
    ctofu value = {.data.integer_type = 24};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, map_insert(map, key, value));
    TEST_ASSERT_EQUAL(1, map_size(map));

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, map_remove(map, key));
    TEST_ASSERT_EQUAL(0, map_size(map));

    map_erase(map);

    // Edge Case: Removing from an empty map
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, map_remove(map, key));
}

XTEST_CASE(test_map_search) {
    // Normal Case: Searching for an element in the map
    cmap* map = map_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);

    ctofu key = {.data.integer_type = 42};
    ctofu value = {.data.integer_type = 24};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, map_insert(map, key, value));

    TEST_ASSERT_TRUE(map_not_cnullptr(map));
    TEST_ASSERT_TRUE(map_not_empty(map));
    TEST_ASSERT_FALSE(map_is_empty(map));
    TEST_ASSERT_FALSE(map_is_cnullptr(map));

    map_erase(map);

    // Edge Case: Searching in an empty map
    TEST_ASSERT_FALSE(map_not_cnullptr(map));
    TEST_ASSERT_FALSE(map_not_empty(map));
    TEST_ASSERT_TRUE(map_is_empty(map));
    TEST_ASSERT_TRUE(map_is_cnullptr(map));
}

XTEST_CASE(test_map_setter_and_getter) {
    // Normal Case: Setting and getting elements in the map
    cmap* map = map_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(map);

    ctofu key = {.data.integer_type = 42};
    ctofu value1 = {.data.integer_type = 24};
    ctofu value2 = {.data.integer_type = 12};

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, map_insert(map, key, value1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, map_setter(map, key, value2));

    ctofu* retrieved_value = malloc(sizeof(ctofu));
    TEST_ASSERT_NOT_NULL_PTR(retrieved_value);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, map_getter(map, key, retrieved_value));
    TEST_ASSERT_EQUAL(value2.integer_type, retrieved_value->integer_type);

    free(retrieved_value);
    map_erase(map);

    // Edge Case: Getting from an empty map
    retrieved_value = malloc(sizeof(ctofu));
    TEST_ASSERT_NOT_NULL_PTR(retrieved_value);
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, map_getter(map, key, retrieved_value));
    free(retrieved_value);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_map_group) {
    XTEST_NOTE("Running all test cases for map:");

    XTEST_RUN_UNIT(test_map_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_map_insert_and_remove, runner);
    XTEST_RUN_UNIT(test_map_search,            runner);
    XTEST_RUN_UNIT(test_map_setter_and_getter, runner);
} // end of func
