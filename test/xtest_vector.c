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
XTEST_CASE(test_vector_creation) {
    // Edge Case: Creating a vector with an invalid type
    TEST_ASSERT_NULL_PTR(vector_create(INVALID_TYPE));

    // Normal Case: Creating a vector with a valid type
    cvector* vector = vector_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(vector);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, vector->expected_type);
    vector_erase(vector);
}

XTEST_CASE(test_vector_push_back) {
    // Normal Case: Pushing back an element
    cvector vector = vector_create(INTEGER_TYPE);
    vector_push_back(&vector, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 42});
    TEST_ASSERT_EQUAL(1, vector_size(&vector));
    
    // Use vector_getter for validation
    ctofu retrieved_data = vector_getter(&vector, 0);
    TEST_ASSERT_EQUAL(42, retrieved_data.data.integer_type);
    
    vector_erase(&vector);

    // Edge Case: Pushing back into a NULL vector
    TEST_ASSERT_NULL_PTR(vector_getter(NULL, 0).data.integer_type);
}

XTEST_CASE(test_vector_search) {
    // Normal Case: Searching for an element
    cvector vector = vector_create(INTEGER_TYPE);
    for (int i = 0; i < 10; ++i) {
        vector_push_back(&vector, (ctofu){.type = INTEGER_TYPE, .data.integer_type = i * 2});
    }
    int result = vector_search(&vector, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 6});
    TEST_ASSERT_EQUAL(3, result);
    vector_erase(&vector);

    // Edge Case: Searching in an empty vector
    cvector empty_vector = vector_create(INTEGER_TYPE);
    result = vector_search(&empty_vector, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 6});
    TEST_ASSERT_EQUAL(-1, result);
    vector_erase(&empty_vector);
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
