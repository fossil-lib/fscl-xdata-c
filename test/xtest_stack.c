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
// TEST DATA
//
XTEST_DATA(ProjectTestStackData) {
    TriloStack *stack;
}stack_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_stack_of_int_create_and_destroy) {
    // Test creating and destroying a TriloStack
    stack_data.stack = trilo_xdata_stack_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(stack_data.stack);
    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_int_push_and_pop) {
    // Test pushing and popping data from the TriloStack
    stack_data.stack = trilo_xdata_stack_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_stack_push(stack_data.stack, tofu1);
    trilo_xdata_stack_push(stack_data.stack, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(2, trilo_xdata_stack_size(stack_data.stack));

    TriloTofu popped_tofu2 = trilo_xdata_stack_pop(stack_data.stack);
    XASSERT_INT_EQUAL(17, trilo_xdata_tofu_get_integer(popped_tofu2));

    TriloTofu popped_tofu1 = trilo_xdata_stack_pop(stack_data.stack);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(popped_tofu1));

    XASSERT_BOOL_TRUE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(0, trilo_xdata_stack_size(stack_data.stack));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_int_peek) {
    // Test peeking at the top element of the TriloStack
    stack_data.stack = trilo_xdata_stack_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_stack_push(stack_data.stack, tofu1);
    trilo_xdata_stack_push(stack_data.stack, tofu2);

    TriloTofu peeked_tofu = trilo_xdata_stack_peek(stack_data.stack);
    XASSERT_INT_EQUAL(17, trilo_xdata_tofu_get_integer(peeked_tofu));

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(2, trilo_xdata_stack_size(stack_data.stack));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_int_type_mismatch) {
    // Test pushing data of different types to the TriloStack
    stack_data.stack = trilo_xdata_stack_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_stack_push(stack_data.stack, tofu1);

    // Attempting to push data of different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_STACK_TYPE_MISMATCH, trilo_xdata_stack_push(stack_data.stack, tofu2));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_str_create_and_destroy) {
    // Test creating and destroying a TriloStack
    stack_data.stack = trilo_xdata_stack_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(stack_data.stack);
    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_str_push_and_pop) {
    // Test pushing and popping data from the TriloStack
    stack_data.stack = trilo_xdata_stack_create(STRING_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_string("Coffee");
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_string("Tea");

    trilo_xdata_stack_push(stack_data.stack, tofu1);
    trilo_xdata_stack_push(stack_data.stack, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(2, trilo_xdata_stack_size(stack_data.stack));

    TriloTofu popped_tofu2 = trilo_xdata_stack_pop(stack_data.stack);
    XASSERT_STRING_EQUAL("Tea", trilo_xdata_tofu_get_string(popped_tofu2));

    TriloTofu popped_tofu1 = trilo_xdata_stack_pop(stack_data.stack);
    XASSERT_STRING_EQUAL("Coffee", trilo_xdata_tofu_get_string(popped_tofu1));

    XASSERT_BOOL_TRUE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(0, trilo_xdata_stack_size(stack_data.stack));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_str_peek) {
    // Test peeking at the top element of the TriloStack
    stack_data.stack = trilo_xdata_stack_create(STRING_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_string("Coffee");
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_string("Tea");

    trilo_xdata_stack_push(stack_data.stack, tofu1);
    trilo_xdata_stack_push(stack_data.stack, tofu2);

    TriloTofu peeked_tofu = trilo_xdata_stack_peek(stack_data.stack);
    XASSERT_INT_EQUAL("Tea", trilo_xdata_tofu_get_string(peeked_tofu));

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(2, trilo_xdata_stack_size(stack_data.stack));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_str_type_mismatch) {
    // Test pushing data of different types to the TriloStack
    stack_data.stack = trilo_xdata_stack_create(STRING_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_string("Answer is 42");
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_stack_push(stack_data.stack, tofu1);

    // Attempting to push data of different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_STACK_TYPE_MISMATCH, trilo_xdata_stack_push(stack_data.stack, tofu2));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_char_create_and_destroy) {
    // Test creating and destroying a TriloStack
    stack_data.stack = trilo_xdata_stack_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(stack_data.stack);
    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_char_push_and_pop) {
    // Test pushing and popping data from the TriloStack
    stack_data.stack = trilo_xdata_stack_create(CHAR_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_char('X');
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_char('Y');

    trilo_xdata_stack_push(stack_data.stack, tofu1);
    trilo_xdata_stack_push(stack_data.stack, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(2, trilo_xdata_stack_size(stack_data.stack));

    TriloTofu popped_tofu2 = trilo_xdata_stack_pop(stack_data.stack);
    XASSERT_CHAR_EQUAL('Y', trilo_xdata_tofu_get_char(popped_tofu2));

    TriloTofu popped_tofu1 = trilo_xdata_stack_pop(stack_data.stack);
    XASSERT_CHAR_EQUAL('X', trilo_xdata_tofu_get_char(popped_tofu1));

    XASSERT_BOOL_TRUE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(0, trilo_xdata_stack_size(stack_data.stack));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_char_peek) {
    // Test peeking at the top element of the TriloStack
    stack_data.stack = trilo_xdata_stack_create(CHAR_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_char('Y');
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_char('X');

    trilo_xdata_stack_push(stack_data.stack, tofu1);
    trilo_xdata_stack_push(stack_data.stack, tofu2);

    TriloTofu peeked_tofu = trilo_xdata_stack_peek(stack_data.stack);
    XASSERT_INT_EQUAL('X', trilo_xdata_tofu_get_char(peeked_tofu));

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(2, trilo_xdata_stack_size(stack_data.stack));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_char_type_mismatch) {
    // Test pushing data of different types to the TriloStack
    stack_data.stack = trilo_xdata_stack_create(CHAR_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_char('X');
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_stack_push(stack_data.stack, tofu1);

    // Attempting to push data of different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_STACK_TYPE_MISMATCH, trilo_xdata_stack_push(stack_data.stack, tofu2));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_bool_create_and_destroy) {
    // Test creating and destroying a TriloStack
    stack_data.stack = trilo_xdata_stack_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(stack_data.stack);
    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_bool_push_and_pop) {
    // Test pushing and popping data from the TriloStack
    stack_data.stack = trilo_xdata_stack_create(BOOLEAN_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_boolean(true);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_boolean(false);

    trilo_xdata_stack_push(stack_data.stack, tofu1);
    trilo_xdata_stack_push(stack_data.stack, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(2, trilo_xdata_stack_size(stack_data.stack));

    TriloTofu popped_tofu2 = trilo_xdata_stack_pop(stack_data.stack);
    XASSERT_BOOL_EQUAL(false, trilo_xdata_tofu_get_boolean(popped_tofu2));

    TriloTofu popped_tofu1 = trilo_xdata_stack_pop(stack_data.stack);
    XASSERT_BOOL_EQUAL(true, trilo_xdata_tofu_get_boolean(popped_tofu1));

    XASSERT_BOOL_TRUE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(0, trilo_xdata_stack_size(stack_data.stack));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_bool_peek) {
    // Test peeking at the top element of the TriloStack
    stack_data.stack = trilo_xdata_stack_create(BOOLEAN_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_boolean(true);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_boolean(false);

    trilo_xdata_stack_push(stack_data.stack, tofu1);
    trilo_xdata_stack_push(stack_data.stack, tofu2);

    TriloTofu peeked_tofu = trilo_xdata_stack_peek(stack_data.stack);
    XASSERT_INT_EQUAL(false, trilo_xdata_tofu_get_boolean(peeked_tofu));

    XASSERT_BOOL_FALSE(trilo_xdata_stack_is_empty(stack_data.stack));
    XASSERT_INT_EQUAL(2, trilo_xdata_stack_size(stack_data.stack));

    trilo_xdata_stack_destroy(stack_data.stack);
}

XTEST_CASE(xdata_let_stack_of_bool_type_mismatch) {
    // Test pushing data of different types to the TriloStack
    stack_data.stack = trilo_xdata_stack_create(BOOLEAN_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_boolean(true);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_stack_push(stack_data.stack, tofu1);

    // Attempting to push data of different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_STACK_TYPE_MISMATCH, trilo_xdata_stack_push(stack_data.stack, tofu2));

    trilo_xdata_stack_destroy(stack_data.stack);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_stack_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for stack:");

    XTEST_RUN_UNIT(xdata_let_stack_of_int_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_int_push_and_pop,       runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_int_peek,               runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_int_type_mismatch,      runner);

    XTEST_RUN_UNIT(xdata_let_stack_of_str_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_str_push_and_pop,       runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_str_peek,               runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_str_type_mismatch,      runner);

    XTEST_RUN_UNIT(xdata_let_stack_of_char_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_char_push_and_pop,       runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_char_peek,               runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_char_type_mismatch,      runner);

    XTEST_RUN_UNIT(xdata_let_stack_of_bool_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_bool_push_and_pop,       runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_bool_peek,               runner);
    XTEST_RUN_UNIT(xdata_let_stack_of_bool_type_mismatch,      runner);
} // end of func
