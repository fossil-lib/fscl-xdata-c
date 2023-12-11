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
XTEST_CASE(xdata_let_vector_create_and_destroy) {
    cvector vector = vector_create(INTEGER_TYPE);

    TEST_ASSERT_EQUAL(INTEGER_TYPE, vector.expected_type);
    TEST_ASSERT_TRUE(vector_is_empty(&vector));

    vector_erase(&vector);

    TEST_ASSERT_TRUE(vector_is_cnullptr(&vector));
}

XTEST_CASE(xdata_let_vector_push_back_and_peek) {
    cvector vector = vector_create(DOUBLE_TYPE);

    vector_push_back(&vector, tofu_create_from_double(3.14));

    TEST_ASSERT_FALSE(vector_is_empty(&vector));
    TEST_ASSERT_EQUAL(1, vector_size(&vector));

    ctofu element = vector_getter(&vector, 0);
    TEST_ASSERT_DOUBLE_EQUAL(3.14, tofu_get_double(element));

    vector_erase(&vector);
}

XTEST_CASE(xdata_let_vector_search) {
    cvector vector = vector_create(STRING_TYPE);

    vector_push_back(&vector, tofu_create_from_string("Hello"));
    vector_push_back(&vector, tofu_create_from_string("World"));

    int index = vector_search(&vector, tofu_create_from_string("World"));
    TEST_ASSERT_EQUAL(1, index);

    index = vector_search(&vector, tofu_create_from_string("NotInVector"));
    TEST_ASSERT_EQUAL(-1, index);

    vector_erase(&vector);
}

XTEST_CASE(xdata_let_vector_reverse) {
    cvector vector = vector_create(BOOLEAN_TYPE);

    vector_push_back(&vector, tofu_create_from_boolean(true));
    vector_push_back(&vector, tofu_create_from_boolean(false));

    vector_reverse(&vector);

    TEST_ASSERT_EQUAL(false, tofu_get_boolean(vector_getter(&vector, 0)));
    TEST_ASSERT_EQUAL(true, tofu_get_boolean(vector_getter(&vector, 1)));

    vector_erase(&vector);
}

XTEST_CASE(xdata_let_vector_create_and_destroy_with_types) {
    cvector int_vector = vector_create(INTEGER_TYPE);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, int_vector.expected_type);
    vector_erase(&int_vector);

    cvector double_vector = vector_create(DOUBLE_TYPE);
    TEST_ASSERT_EQUAL(DOUBLE_TYPE, double_vector.expected_type);
    vector_erase(&double_vector);

    cvector string_vector = vector_create(STRING_TYPE);
    TEST_ASSERT_EQUAL(STRING_TYPE, string_vector.expected_type);
    vector_erase(&string_vector);

    cvector bool_vector = vector_create(BOOLEAN_TYPE);
    TEST_ASSERT_EQUAL(BOOLEAN_TYPE, bool_vector.expected_type);
    vector_erase(&bool_vector);

    // Test creating a vector with an invalid type
    cvector invalid_vector = vector_create(INVALID_TYPE);
    TEST_ASSERT_TRUE(vector_is_cnullptr(&invalid_vector));
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_vector_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for vector:");

    XTEST_RUN_UNIT(xdata_let_vector_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_vector_push_back_and_peek, runner);
    XTEST_RUN_UNIT(xdata_let_vector_search,             runner);
    XTEST_RUN_UNIT(xdata_let_vector_reverse,            runner);
    XTEST_RUN_UNIT(xdata_let_vector_create_and_destroy_with_types, runner);
} // end of func
