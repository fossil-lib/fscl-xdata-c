/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/stack.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test TriloStack creation and destruction
XTEST_CASE(xdata_let_stack_create_and_destroy) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(stack);

    trilo_xdata_stack_destroy(stack);
    XASSERT_PTR_NULL(stack);
}

// Test case 2: Test TriloStack push and pop operations
XTEST_CASE(xdata_let_stack_push_and_pop) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(stack);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    TofuError result = trilo_xdata_stack_push(stack, tofu1);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_stack_push(stack, tofu2);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_stack_push(stack, tofu3);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* popped_tofu = trilo_xdata_stack_pop(stack);
    XASSERT_PTR_NOT_NULL(popped_tofu);
    XASSERT_INT_EQUAL(3, trilo_xdata_tofu_get_integer(popped_tofu));

    popped_tofu = trilo_xdata_stack_pop(stack);
    XASSERT_PTR_NOT_NULL(popped_tofu);
    XASSERT_INT_EQUAL(2, trilo_xdata_tofu_get_integer(popped_tofu));

    trilo_xdata_stack_destroy(stack);
}

// Test case 3: Test TriloStack top operation
XTEST_CASE(xdata_let_stack_top) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(stack);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_stack_push(stack, tofu1);

    TriloTofu* top_tofu = trilo_xdata_stack_top(stack);
    XASSERT_PTR_NOT_NULL(top_tofu);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(top_tofu));

    trilo_xdata_stack_destroy(stack);
}

// Test case 4: Test TriloStack size
XTEST_CASE(xdata_let_stack_size) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(stack);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);

    trilo_xdata_stack_push(stack, tofu1);
    trilo_xdata_stack_push(stack, tofu2);

    size_t size = trilo_xdata_stack_size(stack);
    XASSERT_INT_EQUAL(2, size);

    trilo_xdata_stack_destroy(stack);
}

// Test case 5: Test TriloStack empty check
XTEST_CASE(xdata_let_stack_empty_check) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(stack);

    XASSERT_BOOL_TRUE(trilo_xdata_stack_is_empty(stack));
    XASSERT_BOOL_FALSE(trilo_xdata_stack_not_empty(stack));

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_stack_push(stack, tofu);

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack));
    XASSERT_BOOL_TRUE(trilo_xdata_stack_not_empty(stack));

    trilo_xdata_stack_destroy(stack);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_stack_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for stack:");

    XTEST_RUN_UNIT(xdata_let_stack, runner);
} // end of func
