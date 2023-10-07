/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tofu.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestTofuData) {
    TriloTofu *tofu_int;
    TriloTofu *tofu_double;
    TriloTofu *tofu_string;
    TriloTofu *tofu_char;
    TriloTofu *tofu_bool;
}tofu_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_tofu_create_and_get) {
    // Test creating a TriloTofu instance and getting its data
    tofu_data.tofu_int = trilo_xdata_tofu_create_from_integer(42);
    XASSERT_INT_EQUAL(INTEGER_TYPE, tofu_data.tofu.type);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(tofu_data.tofu));
    trilo_xdata_tofu_print(tofu_data.tofu); // Print the tofu data
}

XTEST_CASE(xdata_let_tofu_type) {
    // Test creating TriloTofu instances with different types
    tofu_data.tofu_int = trilo_xdata_tofu_create_from_integer(42);
    tofu_data.tofu_double = trilo_xdata_tofu_create_from_double(3.14);
    tofu_data.tofu_string = trilo_xdata_tofu_create_from_string("Hello");
    tofu_data.tofu_char = trilo_xdata_tofu_create_from_char('A');
    tofu_data.tofu_bool = trilo_xdata_tofu_create_from_boolean(true);

    XASSERT_INT_EQUAL(INTEGER_TYPE, tofu_data.tofu_int.type);
    XASSERT_INT_EQUAL(DOUBLE_TYPE,  tofu_data.tofu_double.type);
    XASSERT_INT_EQUAL(STRING_TYPE,  tofu_data.tofu_string.type);
    XASSERT_INT_EQUAL(CHAR_TYPE,    tofu_data.tofu_char.type);
    XASSERT_INT_EQUAL(BOOLEAN_TYPE, tofu_data.tofu_bool.type);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_tofu_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(xdata_let_tofu_create_and_get, runner);
    XTEST_RUN_UNIT(xdata_let_tofu_type,           runner);
    XTEST_RUN_UNIT(xdata_let_tofu_conversion,     runner);
    XTEST_RUN_UNIT(xdata_let_tofu_type_mismatch,  runner);
} // end of func
