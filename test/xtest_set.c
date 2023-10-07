/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/set.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestSetData) {
    TriloSet *set;
}set_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_set_of_int_create_and_destroy) {
    // Test creating and destroying a TriloSet
    set_data.set = trilo_xdata_set_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(set_data.set);
    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_int_insert_and_remove) {
    // Test inserting and removing data from the TriloSet
    set_data.set = trilo_xdata_set_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_set_insert(set_data.set, tofu1);
    trilo_xdata_set_insert(set_data.set, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(2, trilo_xdata_set_size(set_data.set));

    TriloTofu removed_tofu2 = trilo_xdata_set_remove(set_data.set, tofu2);
    XASSERT_INT_EQUAL(17, trilo_xdata_tofu_get_integer(removed_tofu2));

    TriloTofu removed_tofu1 = trilo_xdata_set_remove(set_data.set, tofu1);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(removed_tofu1));

    XASSERT_BOOL_TRUE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(0, trilo_xdata_set_size(set_data.set));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_int_contains) {
    // Test checking if the TriloSet contains a specific element
    set_data.set = trilo_xdata_set_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(17);

    trilo_xdata_set_insert(set_data.set, tofu1);

    XASSERT_BOOL_TRUE(trilo_xdata_set_contains(set_data.set, tofu1));
    XASSERT_BOOL_FALSE(trilo_xdata_set_contains(set_data.set, tofu2));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_int_type_mismatch) {
    // Test inserting data of different types to the TriloSet
    set_data.set = trilo_xdata_set_create(INTEGER_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_set_insert(set_data.set, tofu1);

    // Attempting to insert data of different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_SET_TYPE_MISMATCH, trilo_xdata_set_insert(set_data.set, tofu2));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_str_create_and_destroy) {
    // Test creating and destroying a TriloSet
    set_data.set = trilo_xdata_set_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(set_data.set);
    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_str_insert_and_remove) {
    // Test inserting and removing data from the TriloSet
    set_data.set = trilo_xdata_set_create(STRING_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_string("type func");
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_string("var = 17");

    trilo_xdata_set_insert(set_data.set, tofu1);
    trilo_xdata_set_insert(set_data.set, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(2, trilo_xdata_set_size(set_data.set));

    TriloTofu removed_tofu2 = trilo_xdata_set_remove(set_data.set, tofu2);
    XASSERT_STRING_EQUAL("var = 17", trilo_xdata_tofu_get_string(removed_tofu2));

    TriloTofu removed_tofu1 = trilo_xdata_set_remove(set_data.set, tofu1);
    XASSERT_STRING_EQUAL("type func", trilo_xdata_tofu_get_string(removed_tofu1));

    XASSERT_BOOL_TRUE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(0, trilo_xdata_set_size(set_data.set));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_str_contains) {
    // Test checking if the TriloSet contains a specific element
    set_data.set = trilo_xdata_set_create(STRING_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_string("some token");
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_string("another token");

    trilo_xdata_set_insert(set_data.set, tofu1);

    XASSERT_BOOL_TRUE(trilo_xdata_set_contains(set_data.set, tofu1));
    XASSERT_BOOL_FALSE(trilo_xdata_set_contains(set_data.set, tofu2));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_str_type_mismatch) {
    // Test inserting data of different types to the TriloSet
    set_data.set = trilo_xdata_set_create(STRING_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_string("func sometion()");
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_set_insert(set_data.set, tofu1);

    // Attempting to insert data of different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_SET_TYPE_MISMATCH, trilo_xdata_set_insert(set_data.set, tofu2));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_char_create_and_destroy) {
    // Test creating and destroying a TriloSet
    set_data.set = trilo_xdata_set_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(set_data.set);
    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_char_insert_and_remove) {
    // Test inserting and removing data from the TriloSet
    set_data.set = trilo_xdata_set_create(CHAR_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_char('X');
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_char('Y');

    trilo_xdata_set_insert(set_data.set, tofu1);
    trilo_xdata_set_insert(set_data.set, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(2, trilo_xdata_set_size(set_data.set));

    TriloTofu removed_tofu2 = trilo_xdata_set_remove(set_data.set, tofu2);
    XASSERT_CHAR_EQUAL('Y', trilo_xdata_tofu_get_char(removed_tofu2));

    TriloTofu removed_tofu1 = trilo_xdata_set_remove(set_data.set, tofu1);
    XASSERT_CHAR_EQUAL('X', trilo_xdata_tofu_get_char(removed_tofu1));

    XASSERT_BOOL_TRUE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(0, trilo_xdata_set_size(set_data.set));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_char_contains) {
    // Test checking if the TriloSet contains a specific element
    set_data.set = trilo_xdata_set_create(CHAR_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_char('x');
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_char('X');

    trilo_xdata_set_insert(set_data.set, tofu1);

    XASSERT_BOOL_TRUE(trilo_xdata_set_contains(set_data.set, tofu1));
    XASSERT_BOOL_FALSE(trilo_xdata_set_contains(set_data.set, tofu2));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_char_type_mismatch) {
    // Test inserting data of different types to the TriloSet
    set_data.set = trilo_xdata_set_create(CHAR_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_char('X');
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_set_insert(set_data.set, tofu1);

    // Attempting to insert data of different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_SET_TYPE_MISMATCH, trilo_xdata_set_insert(set_data.set, tofu2));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_bool_create_and_destroy) {
    // Test creating and destroying a TriloSet
    set_data.set = trilo_xdata_set_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(set_data.set);
    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_bool_insert_and_remove) {
    // Test inserting and removing data from the TriloSet
    set_data.set = trilo_xdata_set_create(BOOLEAN_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_boolean(true);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_boolean(false);

    trilo_xdata_set_insert(set_data.set, tofu1);
    trilo_xdata_set_insert(set_data.set, tofu2);

    XASSERT_BOOL_FALSE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(2, trilo_xdata_set_size(set_data.set));

    TriloTofu removed_tofu2 = trilo_xdata_set_remove(set_data.set, tofu2);
    XASSERT_BOOL_EQUAL(false, trilo_xdata_tofu_get_boolean(removed_tofu2));

    TriloTofu removed_tofu1 = trilo_xdata_set_remove(set_data.set, tofu1);
    XASSERT_BOOL_EQUAL(true, trilo_xdata_tofu_get_boolean(removed_tofu1));

    XASSERT_BOOL_TRUE(trilo_xdata_set_is_empty(set_data.set));
    XASSERT_INT_EQUAL(0, trilo_xdata_set_size(set_data.set));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_bool_contains) {
    // Test checking if the TriloSet contains a specific element
    set_data.set = trilo_xdata_set_create(BOOLEAN_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_boolean(true);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_boolean(false);

    trilo_xdata_set_insert(set_data.set, tofu1);

    XASSERT_BOOL_TRUE(trilo_xdata_set_contains(set_data.set, tofu1));
    XASSERT_BOOL_FALSE(trilo_xdata_set_contains(set_data.set, tofu2));

    trilo_xdata_set_destroy(set_data.set);
}

XTEST_CASE(xdata_let_set_of_bool_type_mismatch) {
    // Test inserting data of different types to the TriloSet
    set_data.set = trilo_xdata_set_create(BOOLEAN_TYPE);
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_boolean(true);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_set_insert(set_data.set, tofu1);

    // Attempting to insert data of different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_SET_TYPE_MISMATCH, trilo_xdata_set_insert(set_data.set, tofu2));

    trilo_xdata_set_destroy(set_data.set);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_set_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for set:");

    XTEST_RUN_UNIT(xdata_let_set_of_int_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_set_of_int_insert_and_remove,  runner);
    XTEST_RUN_UNIT(xdata_let_set_of_int_contains,           runner);
    XTEST_RUN_UNIT(xdata_let_set_of_int_type_mismatch,      runner);

    XTEST_RUN_UNIT(xdata_let_set_of_str_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_set_of_str_insert_and_remove,  runner);
    XTEST_RUN_UNIT(xdata_let_set_of_str_contains,           runner);
    XTEST_RUN_UNIT(xdata_let_set_of_str_type_mismatch,      runner);

    XTEST_RUN_UNIT(xdata_let_set_of_char_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_set_of_char_insert_and_remove,  runner);
    XTEST_RUN_UNIT(xdata_let_set_of_char_contains,           runner);
    XTEST_RUN_UNIT(xdata_let_set_of_char_type_mismatch,      runner);

    XTEST_RUN_UNIT(xdata_let_set_of_bool_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_set_of_bool_insert_and_remove,  runner);
    XTEST_RUN_UNIT(xdata_let_set_of_bool_contains,           runner);
    XTEST_RUN_UNIT(xdata_let_set_of_bool_type_mismatch,      runner);
} // end of func
