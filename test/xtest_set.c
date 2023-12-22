/*  ----------------------------------------------------------------------------
    File: xtest_set.c

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
#include "trilobite/xdata/set.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_set_create_and_erase) {
    cset* set = tscl_set_create(INTEGER_TYPE);

    // Check if the set is created with the expected values
    TEST_ASSERT_NOT_NULL_PTR(set);
    TEST_ASSERT_NULL_PTR(set->head);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, set->set_type);

    tscl_set_erase(set);

    // Check if the set is erased
    TEST_ASSERT_NULL_PTR(set->head);
    TEST_ASSERT_NULL_PTR(set);
}

XTEST_CASE(test_set_insert_and_size) {
    cset* set = tscl_set_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_set_insert(set, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_set_insert(set, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_set_insert(set, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, tscl_set_size(set));

    tscl_set_erase(set);
}

XTEST_CASE(test_set_remove) {
    cset* set = tscl_set_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_set_insert(set, element1);
    tscl_set_insert(set, element2);
    tscl_set_insert(set, element3);

    // Remove an element
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_set_remove(set, element2));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, tscl_set_size(set));

    tscl_set_erase(set);
}

XTEST_CASE(test_set_contains) {
    cset* set = tscl_set_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_set_insert(set, element1);
    tscl_set_insert(set, element2);
    tscl_set_insert(set, element3);

    // Check if elements are contained in the set
    TEST_ASSERT_TRUE(tscl_set_contains(set, element1));
    TEST_ASSERT_TRUE(tscl_set_contains(set, element3));

    // Check for non-existing element
    ctofu nonExistingElement = { INTEGER_TYPE, { .integer_type = 100 } };
    TEST_ASSERT_FALSE(tscl_set_contains(set, nonExistingElement));

    tscl_set_erase(set);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_set_group) {
    XTEST_NOTE("Running all test cases for set:");

    XTEST_RUN_UNIT(test_set_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_set_insert_and_size,   runner);
    XTEST_RUN_UNIT(test_set_remove,            runner);
    XTEST_RUN_UNIT(test_set_contains,          runner);
} // end of func
