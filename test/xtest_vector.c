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
    TriloVector vector = trilo_xdata_vector_create(INTEGER_TYPE);

    TEST_ASSERT_EQUAL(INTEGER_TYPE, vector.expected_type);
    TEST_ASSERT_TRUE(trilo_xdata_vector_is_empty(&vector));

    trilo_xdata_vector_destroy(&vector);

    TEST_ASSERT_TRUE(trilo_xdata_vector_is_nullptr(&vector));
}

XTEST_CASE(xdata_let_vector_push_back_and_peek) {
    TriloVector vector = trilo_xdata_vector_create(DOUBLE_TYPE);

    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_double(3.14));

    TEST_ASSERT_FALSE(trilo_xdata_vector_is_empty(&vector));
    TEST_ASSERT_EQUAL(1, trilo_xdata_vector_size(&vector));

    TriloTofu element = trilo_xdata_vector_getter(&vector, 0);
    TEST_ASSERT_DOUBLE_EQUAL(3.14, trilo_xdata_tofu_get_double(element));

    trilo_xdata_vector_destroy(&vector);
}

XTEST_CASE(xdata_let_vector_search) {
    TriloVector vector = trilo_xdata_vector_create(STRING_TYPE);

    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_string("Hello"));
    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_string("World"));

    int index = trilo_xdata_vector_search(&vector, trilo_xdata_tofu_create_from_string("World"));
    TEST_ASSERT_EQUAL(1, index);

    index = trilo_xdata_vector_search(&vector, trilo_xdata_tofu_create_from_string("NotInVector"));
    TEST_ASSERT_EQUAL(-1, index);

    trilo_xdata_vector_destroy(&vector);
}

XTEST_CASE(xdata_let_vector_reverse) {
    TriloVector vector = trilo_xdata_vector_create(BOOLEAN_TYPE);

    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_boolean(true));
    trilo_xdata_vector_push_back(&vector, trilo_xdata_tofu_create_from_boolean(false));

    trilo_xdata_vector_reverse(&vector);

    TEST_ASSERT_EQUAL(false, trilo_xdata_tofu_get_boolean(trilo_xdata_vector_getter(&vector, 0)));
    TEST_ASSERT_EQUAL(true, trilo_xdata_tofu_get_boolean(trilo_xdata_vector_getter(&vector, 1)));

    trilo_xdata_vector_destroy(&vector);
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
} // end of func
