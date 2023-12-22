/*  ----------------------------------------------------------------------------
    File: xtest_vector.c

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
#include "trilobite/xdata/vector.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_vector_create_and_erase) {
    cvector vector = tscl_vector_create(INTEGER_TYPE);
    
    // Check if the vector is created with the expected values
    TEST_ASSERT_EQUAL(INTEGER_TYPE, vector.expected_type);
    TEST_ASSERT_NULL_PTR(vector.data);
    TEST_ASSERT_EQUAL_UINT(0, vector.size);
    TEST_ASSERT_EQUAL_UINT(INITIAL_CAPACITY, vector.capacity);

    tscl_vector_erase(&vector);

    // Check if the vector is erased
    TEST_ASSERT_NULL_PTR(vector.data);
    TEST_ASSERT_EQUAL_UINT(0, vector.size);
    TEST_ASSERT_EQUAL_UINT(0, vector.capacity);
}

XTEST_CASE(test_vector_push_back) {
    cvector vector = tscl_vector_create(INTEGER_TYPE);

    // Push back some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_vector_push_back(&vector, element1);
    tscl_vector_push_back(&vector, element2);
    tscl_vector_push_back(&vector, element3);

    // Check if the elements are added correctly
    TEST_ASSERT_EQUAL_UINT(3, vector.size);
    TEST_ASSERT_EQUAL_INT(42, vector.data[0].data.integer_type);
    TEST_ASSERT_EQUAL_INT(10, vector.data[1].data.integer_type);
    TEST_ASSERT_EQUAL_INT(5, vector.data[2].data.integer_type);

    tscl_vector_erase(&vector);
}

XTEST_CASE(test_vector_search) {
    cvector vector = tscl_vector_create(INTEGER_TYPE);

    // Push back some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_vector_push_back(&vector, element1);
    tscl_vector_push_back(&vector, element2);
    tscl_vector_push_back(&vector, element3);

    // Search for elements
    TEST_ASSERT_EQUAL_INT(0, tscl_vector_search(&vector, element1));
    TEST_ASSERT_EQUAL_INT(1, tscl_vector_search(&vector, element2));
    TEST_ASSERT_EQUAL_INT(2, tscl_vector_search(&vector, element3));

    // Search for non-existing element
    ctofu nonExistingElement = { INTEGER_TYPE, { .integer_type = 100 } };
    TEST_ASSERT_EQUAL_INT(-1, tscl_vector_search(&vector, nonExistingElement));

    tscl_vector_erase(&vector);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_vector_group) {
    XTEST_NOTE("Running all test cases for vector:");

    XTEST_RUN_UNIT(test_vector_creation,  runner);
    XTEST_RUN_UNIT(test_vector_push_back, runner);
    XTEST_RUN_UNIT(test_vector_search,    runner);
} // end of func
