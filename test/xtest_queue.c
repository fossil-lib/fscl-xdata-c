/*  ----------------------------------------------------------------------------
    File: xtest_queue.c

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
#include "trilobite/xdata/queue.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test TriloQueue creation and destruction
XTEST_CASE(xdata_let_queue_create_destroy) {
    TriloQueue* queue = trilo_xdata_queue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(queue);
    
    trilo_xdata_queue_destroy(queue);
    // Ensure queue is successfully destroyed
}

XTEST_CASE(xdata_let_queue_insert) {
    TriloQueue* queue = trilo_xdata_queue_create(DOUBLE_TYPE);
    
    TriloTofu data = trilo_xdata_tofu_create_from_double(42.5);
    TofuError error = trilo_xdata_queue_insert(queue, data);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);
    
    trilo_xdata_queue_destroy(queue);
}

XTEST_CASE(xdata_let_queue_remove) {
    TriloQueue* queue = trilo_xdata_queue_create(STRING_TYPE);
    
    TriloTofu data = trilo_xdata_tofu_create_from_string("Hello");
    trilo_xdata_queue_insert(queue, data);
    
    TofuError error = trilo_xdata_queue_remove(queue);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);
    
    trilo_xdata_queue_destroy(queue);
}

XTEST_CASE(xdata_let_queue_search) {
    TriloQueue* queue = trilo_xdata_queue_create(CHAR_TYPE);
    
    TriloTofu data = trilo_xdata_tofu_create_from_char('A');
    trilo_xdata_queue_insert(queue, data);
    
    TofuError error = trilo_xdata_queue_search(queue, data);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);
    
    trilo_xdata_queue_destroy(queue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_queue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for queue:");

    XTEST_RUN_UNIT(xdata_let_queue_create_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_queue_insert,         runner);
    XTEST_RUN_UNIT(xdata_let_queue_remove,         runner);
    XTEST_RUN_UNIT(xdata_let_queue_search,         runner);
} // end of func
