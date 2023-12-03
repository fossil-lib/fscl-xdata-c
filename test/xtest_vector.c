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
    cvector vector = trilo_xdata_vector_create(INTEGER_TYPE);

    TEST_ASSERT_EQUAL(INTEGER_TYPE, vector.expected_type);
    TEST_ASSERT_TRUE(trilo_xdata_vector_is_empty(&vector));

    trilo_xdata_vector_destroy(&vector);

    TEST_ASSERT_TRUE(trilo_xdata_vector_is_nullptr(&vector));
}

XTEST_CASE(xdata_let_vector_push_back_and_peek) {
    cvector vector = trilo_xdata_vector_create(DOUBLE_TYPE);

    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_double(3.14));

    TEST_ASSERT_FALSE(trilo_xdata_vector_is_empty(&vector));
    TEST_ASSERT_EQUAL(1, trilo_xdata_vector_size(&vector));

    ctofu element = trilo_xdata_vector_getter(&vector, 0);
    TEST_ASSERT_DOUBLE_EQUAL(3.14, trilo_xdata_tofu_get_double(element));

    trilo_xdata_vector_destroy(&vector);
}

XTEST_CASE(xdata_let_vector_search) {
    cvector vector = trilo_xdata_vector_create(STRING_TYPE);

    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_string("Hello"));
    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_string("World"));

    int index = trilo_xdata_vector_search(&vector, trilo_xdata_tofu_create_from_string("World"));
    TEST_ASSERT_EQUAL(1, index);

    index = trilo_xdata_vector_search(&vector, trilo_xdata_tofu_create_from_string("NotInVector"));
    TEST_ASSERT_EQUAL(-1, index);

    trilo_xdata_vector_destroy(&vector);
}

XTEST_CASE(xdata_let_vector_reverse) {
    cvector vector = trilo_xdata_vector_create(BOOLEAN_TYPE);

    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_boolean(true));
    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_boolean(false));

    trilo_xdata_vector_reverse(&vector);

    TEST_ASSERT_EQUAL(false, trilo_xdata_tofu_get_boolean(trilo_xdata_vector_getter(&vector, 0)));
    TEST_ASSERT_EQUAL(true, trilo_xdata_tofu_get_boolean(trilo_xdata_vector_getter(&vector, 1)));

    trilo_xdata_vector_destroy(&vector);
}

XTEST_CASE(xdata_let_vector_create_and_destroy_with_types) {
    cvector int_vector = trilo_xdata_vector_create(INTEGER_TYPE);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, int_vector.expected_type);
    trilo_xdata_vector_destroy(&int_vector);

    cvector double_vector = trilo_xdata_vector_create(DOUBLE_TYPE);
    TEST_ASSERT_EQUAL(DOUBLE_TYPE, double_vector.expected_type);
    trilo_xdata_vector_destroy(&double_vector);

    cvector string_vector = trilo_xdata_vector_create(STRING_TYPE);
    TEST_ASSERT_EQUAL(STRING_TYPE, string_vector.expected_type);
    trilo_xdata_vector_destroy(&string_vector);

    cvector bool_vector = trilo_xdata_vector_create(BOOLEAN_TYPE);
    TEST_ASSERT_EQUAL(BOOLEAN_TYPE, bool_vector.expected_type);
    trilo_xdata_vector_destroy(&bool_vector);

    // Test creating a vector with an invalid type
    cvector invalid_vector = trilo_xdata_vector_create(INVALID_TYPE);
    TEST_ASSERT_TRUE(trilo_xdata_vector_is_nullptr(&invalid_vector));
}

XTEST_CASE(xdata_let_vector_push_back_and_peek_edge_cases) {
    cvector int_vector = trilo_xdata_vector_create(INTEGER_TYPE);
    cvector double_vector = trilo_xdata_vector_create(DOUBLE_TYPE);
    cvector string_vector = trilo_xdata_vector_create(STRING_TYPE);

    // Test pushing back elements of various types
    trilo_xdata_vector_push_back(&int_vector, trilo_xdata_tofu_create_from_int(42));
    TEST_ASSERT_EQUAL(42, trilo_xdata_tofu_get_int(trilo_xdata_vector_getter(&int_vector, 0)));

    trilo_xdata_vector_push_back(&double_vector, trilo_xdata_tofu_create_from_double(3.14));
    TEST_ASSERT_DOUBLE_EQUAL(3.14, trilo_xdata_tofu_get_double(trilo_xdata_vector_getter(&double_vector, 0)));

    trilo_xdata_vector_push_back(&string_vector, trilo_xdata_tofu_create_from_string("Hello"));
    TEST_ASSERT_EQUAL_STRING("Hello", trilo_xdata_tofu_get_string(trilo_xdata_vector_getter(&string_vector, 0)));

    // Test pushing back a large number of elements
    for (int i = 0; i < 1000; ++i) {
        trilo_xdata_vector_push_back(&int_vector, trilo_xdata_tofu_create_from_int(i));
    }
    TEST_ASSERT_EQUAL(1000, trilo_xdata_vector_size(&int_vector));

    trilo_xdata_vector_destroy(&int_vector);
    trilo_xdata_vector_destroy(&double_vector);
    trilo_xdata_vector_destroy(&string_vector);
}

XTEST_CASE(xdata_let_vector_search_edge_cases) {
    cvector empty_vector = trilo_xdata_vector_create(INTEGER_TYPE);
    TEST_ASSERT_EQUAL(-1, trilo_xdata_vector_search(&empty_vector, trilo_xdata_tofu_create_from_int(42)));

    cvector duplicate_vector = trilo_xdata_vector_create(DOUBLE_TYPE);
    trilo_xdata_vector_push_back(&duplicate_vector, trilo_xdata_tofu_create_from_double(2.5));
    trilo_xdata_vector_push_back(&duplicate_vector, trilo_xdata_tofu_create_from_double(2.5));
    TEST_ASSERT_EQUAL(0, trilo_xdata_vector_search(&duplicate_vector, trilo_xdata_tofu_create_from_double(2.5)));

    trilo_xdata_vector_destroy(&empty_vector);
    trilo_xdata_vector_destroy(&duplicate_vector);
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
    XTEST_RUN_UNIT(xdata_let_vector_push_back_and_peek_edge_cases, runner);
    XTEST_RUN_UNIT(xdata_let_vector_search_edge_cases,             runner);
} // end of func
