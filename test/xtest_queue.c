/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
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
    XASSERT_PTR_NOT_NULL(queue);
    
    trilo_xdata_queue_destroy(queue);
    // Ensure queue is successfully destroyed
}

XTEST_CASE(xdata_let_queue_insert) {
    TriloQueue* queue = trilo_xdata_queue_create(DOUBLE_TYPE);
    
    TriloTofu data = trilo_xdata_tofu_create_from_double(42.5);
    TofuError error = trilo_xdata_queue_insert(queue, data);
    
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, error);
    
    trilo_xdata_queue_destroy(queue);
}

XTEST_CASE(xdata_let_queue_remove) {
    TriloQueue* queue = trilo_xdata_queue_create(STRING_TYPE);
    
    TriloTofu data = trilo_xdata_tofu_create_from_string("Hello");
    trilo_xdata_queue_insert(queue, data);
    
    TofuError error = trilo_xdata_queue_remove(queue);
    
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, error);
    
    trilo_xdata_queue_destroy(queue);
}

XTEST_CASE(xdata_let_queue_search) {
    TriloQueue* queue = trilo_xdata_queue_create(CHAR_TYPE);
    
    TriloTofu data = trilo_xdata_tofu_create_from_char('A');
    trilo_xdata_queue_insert(queue, data);
    
    TofuError error = trilo_xdata_queue_search(queue, data);
    
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, error);
    
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
