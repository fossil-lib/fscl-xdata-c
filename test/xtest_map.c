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
    cmap* map = tscl_map_create(INTEGER_TYPE);

    // Check if the map is created with the expected values
    TEST_ASSERT_NOT_NULL_PTR(map);
    TEST_ASSERT_EQUAL_UINT(0, map->size);

    tscl_map_erase(map);

    // Check if the map is erased
    TEST_ASSERT_EQUAL_UINT(0, map->size);
    TEST_ASSERT_NULL_PTR(map);
}

XTEST_CASE(test_map_insert_and_size) {
    cmap* map = tscl_map_create(INTEGER_TYPE);

    // Insert some key-value pairs
    ctofu key1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu value1 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu key2 = { INTEGER_TYPE, { .integer_type = 5 } };
    ctofu value2 = { INTEGER_TYPE, { .integer_type = 20 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_map_insert(map, key1, value1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_map_insert(map, key2, value2));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, tscl_map_size(map));

    tscl_map_erase(map);
}

XTEST_CASE(test_map_remove) {
    cmap* map = tscl_map_create(INTEGER_TYPE);

    // Insert some key-value pairs
    ctofu key1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu value1 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu key2 = { INTEGER_TYPE, { .integer_type = 5 } };
    ctofu value2 = { INTEGER_TYPE, { .integer_type = 20 } };

    tscl_map_insert(map, key1, value1);
    tscl_map_insert(map, key2, value2);

    // Remove a key-value pair
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_map_remove(map, key1));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(1, tscl_map_size(map));

    tscl_map_erase(map);
}

XTEST_CASE(test_map_getter_and_setter) {
    cmap* map = tscl_map_create(INTEGER_TYPE);

    // Insert a key-value pair
    ctofu key = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu value = { INTEGER_TYPE, { .integer_type = 10 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_map_insert(map, key, value));

    // Get the value for a key
    ctofu retrievedValue;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_map_getter(map, key, &retrievedValue));

    // Check if the retrieved value is correct
    TEST_ASSERT_EQUAL_INT(10, retrievedValue.data.integer_type);

    // Update the value for a key
    ctofu updatedValue = { INTEGER_TYPE, { .integer_type = 50 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_map_setter(map, key, updatedValue));

    // Get the updated value for the key
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_map_getter(map, key, &retrievedValue));

    // Check if the retrieved value is correct after update
    TEST_ASSERT_EQUAL_INT(50, retrievedValue.data.integer_type);

    tscl_map_erase(map);
}

XTEST_CASE(test_map_contains) {
    cmap* map = tscl_map_create(INTEGER_TYPE);

    // Insert a key-value pair
    ctofu key = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu value = { INTEGER_TYPE, { .integer_type = 10 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_map_insert(map, key, value));

    // Check if the map contains the key
    TEST_ASSERT_TRUE(tscl_map_contains(map, key));

    // Check for a non-existing key
    ctofu nonExistingKey = { INTEGER_TYPE, { .integer_type = 100 } };
    TEST_ASSERT_FALSE(tscl_map_contains(map, nonExistingKey));

    tscl_map_erase(map);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_map_group) {
    XTEST_NOTE("Running all test cases for map:");

    XTEST_RUN_UNIT(test_map_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_map_insert_and_size,   runner);
    XTEST_RUN_UNIT(test_map_remove,            runner);
    XTEST_RUN_UNIT(test_map_getter_and_setter, runner);
    XTEST_RUN_UNIT(test_map_contains,          runner);
} // end of func
