/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xdata/stack.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

XTEST_CASE(test_stack_create_and_erase) {
    cstack* stack = fscl_stack_create(TOFU_INTEGER_TYPE);

    // Check if the stack is created with the expected values
    TEST_ASSERT_NOT_CNULLPTR(stack);
    TEST_ASSERT_CNULLPTR(stack->top);
    TEST_ASSERT_EQUAL(TOFU_INTEGER_TYPE, stack->stack_type);

    fscl_stack_erase(stack);

    // Check if the stack is erased
    TEST_ASSERT_CNULLPTR(stack->top);
    TEST_ASSERT_CNULLPTR(stack);
}

XTEST_CASE(test_stack_insert_and_size) {
    cstack* stack = fscl_stack_create(TOFU_INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { TOFU_INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { TOFU_INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_stack_insert(stack, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_stack_insert(stack, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_stack_insert(stack, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, fscl_stack_size(stack));

    fscl_stack_erase(stack);
}

XTEST_CASE(test_stack_remove) {
    cstack* stack = fscl_stack_create(TOFU_INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { TOFU_INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { TOFU_INTEGER_TYPE, { .integer_type = 5 } };

    fscl_stack_insert(stack, element1);
    fscl_stack_insert(stack, element2);
    fscl_stack_insert(stack, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_stack_remove(stack, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(5, removedElement.data.integer_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, fscl_stack_size(stack));

    fscl_stack_erase(stack);
}

XTEST_CASE(test_stack_top) {
    cstack* stack = fscl_stack_create(TOFU_INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { TOFU_INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { TOFU_INTEGER_TYPE, { .integer_type = 5 } };

    fscl_stack_insert(stack, element1);
    fscl_stack_insert(stack, element2);
    fscl_stack_insert(stack, element3);

    // Check the top element
    ctofu topElement = fscl_stack_top(stack, (ctofu){TOFU_INTEGER_TYPE, {.integer_type = -1}});
    TEST_ASSERT_EQUAL_INT(5, topElement.data.integer_type);

    // Remove an element
    fscl_stack_remove(stack, NULL);

    // Check the top element after removal
    topElement = fscl_stack_top(stack, (ctofu){TOFU_INTEGER_TYPE, {.integer_type = -1}});
    TEST_ASSERT_EQUAL_INT(10, topElement.data.integer_type);

    fscl_stack_erase(stack);
}


//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_stack_group) {
    XTEST_NOTE("Running all test cases for stack:");

    XTEST_RUN_UNIT(test_stack_create_and_erase);
    XTEST_RUN_UNIT(test_stack_insert_and_size);
    XTEST_RUN_UNIT(test_stack_remove);
    XTEST_RUN_UNIT(test_stack_top);
} // end of func
