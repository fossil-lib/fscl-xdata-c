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

XTEST_CASE(xdata_let_stack_create_and_destroy) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(stack);

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_insert_and_size) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    
    TriloTofu data1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu data2 = trilo_xdata_tofu_create_from_integer(7);

    TofuError result1 = trilo_xdata_stack_insert(stack, data1);
    TofuError result2 = trilo_xdata_stack_insert(stack, data2);
    
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result1);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result2);
    
    size_t size = trilo_xdata_stack_size(stack);
    XASSERT_BOOL_EQUAL(2, size);
    
    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_remove_and_search) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    
    TriloTofu data1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu data2 = trilo_xdata_tofu_create_from_integer(7);

    trilo_xdata_stack_insert(stack, data1);
    trilo_xdata_stack_insert(stack, data2);

    TofuError result1 = trilo_xdata_stack_remove(stack, data1);
    TofuError result2 = trilo_xdata_stack_remove(stack, data2);
    
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result1);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result2);
    
    TofuError search_result1 = trilo_xdata_stack_search(stack, data1);
    TofuError search_result2 = trilo_xdata_stack_search(stack, data2);
    
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_WAS_UNKNOWN, search_result1);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_WAS_UNKNOWN, search_result2);
    
    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_getter_and_setter) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);
    
    TriloTofu data1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu data2 = trilo_xdata_tofu_create_from_integer(7);

    trilo_xdata_stack_insert(stack, data1);
    trilo_xdata_stack_insert(stack, data2);

    TriloTofu* getter_result1 = trilo_xdata_stack_getter(stack, data1);
    TriloTofu* getter_result2 = trilo_xdata_stack_getter(stack, data2);
    
    XASSERT_PTR_NOT_NULL(getter_result1);
    XASSERT_PTR_NOT_NULL(getter_result2);
    
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tofu_compare(*getter_result1, data1));
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tofu_compare(*getter_result2, data2));
    
    TriloTofu new_data1 = trilo_xdata_tofu_create_from_integer(99);
    TriloTofu new_data2 = trilo_xdata_tofu_create_from_integer(77);

    TofuError setter_result1 = trilo_xdata_stack_setter(stack, new_data1);
    TofuError setter_result2 = trilo_xdata_stack_setter(stack, new_data2);
    
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, setter_result1);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, setter_result2);

    // Check if the data was updated
    getter_result1 = trilo_xdata_stack_getter(stack, new_data1);
    getter_result2 = trilo_xdata_stack_getter(stack, new_data2);
    
    XASSERT_PTR_NOT_NULL(getter_result1);
    XASSERT_PTR_NOT_NULL(getter_result2);
    
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tofu_compare(*getter_result1, new_data1));
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tofu_compare(*getter_result2, new_data2));

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_empty_check) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);

    XASSERT_BOOL_TRUE(trilo_xdata_stack_is_empty(stack));
    XASSERT_BOOL_FALSE(trilo_xdata_stack_not_empty(stack));

    TriloTofu data = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_stack_insert(stack, data);

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack));
    XASSERT_BOOL_TRUE(trilo_xdata_stack_not_empty(stack));

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_nullptr_check) {
    TriloStack* stack = NULL;

    XASSERT_BOOL_TRUE(trilo_xdata_stack_is_nullptr(stack));
    XASSERT_BOOL_FALSE(trilo_xdata_stack_not_nullptr(stack));

    stack = trilo_xdata_stack_create(INTEGER_TYPE);

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_nullptr(stack));
    XASSERT_BOOL_TRUE(trilo_xdata_stack_not_nullptr(stack));

    trilo_xdata_stack_destroy(stack);
}

XTEST_CASE(xdata_let_stack_top) {
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);

    TriloTofu data1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu data2 = trilo_xdata_tofu_create_from_integer(7);

    trilo_xdata_stack_insert(stack, data1);
    trilo_xdata_stack_insert(stack, data2);

    XASSERT_INT_EQUAL(7, trilo_xdata_tofu_get_integer(trilo_xdata_stack_top(stack)));

    trilo_xdata_stack_destroy(stack);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_stack_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for stack:");

    XTEST_RUN_UNIT(xdata_let_stack_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_stack_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_stack_getter_and_setter,  runner);
    XTEST_RUN_UNIT(xdata_let_stack_insert_and_size,    runner);
    XTEST_RUN_UNIT(xdata_let_stack_nullptr_check,      runner);
    XTEST_RUN_UNIT(xdata_let_stack_remove_and_search,  runner);
    XTEST_RUN_UNIT(xdata_let_stack_nullptr_check,      runner);
    XTEST_RUN_UNIT(xdata_let_stack_remove_and_search,  runner);
    XTEST_RUN_UNIT(xdata_let_stack_top,                runner);
} // end of func
