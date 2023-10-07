/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/vector.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts
#include <stdbool.h>

//
// TEST DATA
//
XTEST_DATA(ProjectVectorTestData) {
    TriloVector* vector;
}vect_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_vector_of_int_create) {
    // Test if a vector is created successfully
    vect_data.vector = trilo_xdata_vector_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);
    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_int_insert) {
    // Test vector insertion of elements
    vect_data.vector = trilo_xdata_vector_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_integer(10));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_int_remove) {
    // Test vector removal of elements
    vect_data.vector = trilo_xdata_vector_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_integer(10));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_remove(vect_data.vector, trilo_xdata_tofu_create_from_integer(10));
    XASSERT_INT_EQUAL(0, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_int_size) {
    // Test vector size after insertion
    vect_data.vector = trilo_xdata_vector_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_integer(10));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_integer(20));
    XASSERT_INT_EQUAL(2, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_int_access) {
    // Test vector element access
    vect_data.vector = trilo_xdata_vector_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_integer(20));

    TriloTofu element = trilo_xdata_vector_get(vect_data.vector, 1);
    XASSERT_INT_EQUAL(20, trilo_xdata_tofu_get_integer(element));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_str_create) {
    // Test if a vector is created successfully
    vect_data.vector = trilo_xdata_vector_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);
    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_str_insert) {
    // Test vector insertion of elements
    vect_data.vector = trilo_xdata_vector_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_string("ten"));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_str_remove) {
    // Test vector removal of elements
    vect_data.vector = trilo_xdata_vector_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_string("coffee"));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_remove(vect_data.vector, trilo_xdata_tofu_create_from_string("coffee"));
    XASSERT_INT_EQUAL(0, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_str_size) {
    // Test vector size after insertion
    vect_data.vector = trilo_xdata_vector_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_string("magnet"));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_string("lego"));
    XASSERT_INT_EQUAL(2, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_str_access) {
    // Test vector element access
    vect_data.vector = trilo_xdata_vector_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_string("Tea"));
    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_string("Coffee"));

    TriloTofu element = trilo_xdata_vector_get(vect_data.vector, 1);
    XASSERT_STRING_EQUAL("Coffee", trilo_xdata_tofu_get_string(element));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_char_create) {
    // Test if a vector is created successfully
    vect_data.vector = trilo_xdata_vector_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);
    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_char_insert) {
    // Test vector insertion of elements
    vect_data.vector = trilo_xdata_vector_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_char('x'));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_char_remove) {
    // Test vector removal of elements
    vect_data.vector = trilo_xdata_vector_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_char('x'));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_remove(vect_data.vector, trilo_xdata_tofu_create_from_char('x'));
    XASSERT_INT_EQUAL(0, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_char_size) {
    // Test vector size after insertion
    vect_data.vector = trilo_xdata_vector_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_char('o'));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_char('x'));
    XASSERT_INT_EQUAL(2, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_char_access) {
    // Test vector element access
    vect_data.vector = trilo_xdata_vector_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_char('A'));
    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_char('B'));

    TriloTofu element = trilo_xdata_vector_get(vect_data.vector, 1);
    XASSERT_CHAR_EQUAL('B', trilo_xdata_tofu_get_char(element));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_bool_create) {
    // Test if a vector is created successfully
    vect_data.vector = trilo_xdata_vector_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);
    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_bool_insert) {
    // Test vector insertion of elements
    vect_data.vector = trilo_xdata_vector_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_boolean(true));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_bool_remove) {
    // Test vector removal of elements
    vect_data.vector = trilo_xdata_vector_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_boolean(true));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_remove(vect_data.vector, trilo_xdata_tofu_create_from_boolean(true));
    XASSERT_INT_EQUAL(0, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_bool_size) {
    // Test vector size after insertion
    vect_data.vector = trilo_xdata_vector_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_boolean(true));
    XASSERT_INT_EQUAL(1, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_boolean(false));
    XASSERT_INT_EQUAL(2, trilo_xdata_vector_size(vect_data.vector));

    trilo_xdata_vector_destroy(vect_data.vector);
}

XTEST_CASE(xdata_let_vector_of_bool_access) {
    // Test vector element access
    vect_data.vector = trilo_xdata_vector_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(vect_data.vector);

    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_boolean(true));
    trilo_xdata_vector_insert(vect_data.vector, trilo_xdata_tofu_create_from_boolean(false));

    TriloTofu element = trilo_xdata_vector_get(vect_data.vector, 1);
    XASSERT_BOOL_EQUAL(false, trilo_xdata_tofu_get_char(element));

    trilo_xdata_vector_destroy(vect_data.vector);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_vector_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for vector:");

    XTEST_RUN_UNIT(xdata_let_vector_of_int_create, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_int_insert, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_int_remove, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_int_size,   runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_int_access, runner);

    XTEST_RUN_UNIT(xdata_let_vector_of_str_create, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_str_insert, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_str_remove, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_str_size,   runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_str_access, runner);

    XTEST_RUN_UNIT(xdata_let_vector_of_char_create, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_char_insert, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_char_remove, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_char_size,   runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_char_access, runner);

    XTEST_RUN_UNIT(xdata_let_vector_of_bool_create, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_bool_insert, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_bool_remove, runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_bool_size,   runner);
    XTEST_RUN_UNIT(xdata_let_vector_of_bool_access, runner);
} // end of func
