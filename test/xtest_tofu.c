/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tofu.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

#define EPSILON 0.001 // Define a small epsilon value for double comparisons

//
// XUNIT TEST CASES
//

// Test case 1: Test TriloTofu creation and retrieval of integer value
XTEST_CASE(xdata_let_tofu_create_and_get_integer) {
    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    XASSERT_BOOL_EQUAL(INTEGER_TYPE, trilo_xdata_tofu_get_type(tofu));
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(tofu));
}

// Test case 2: Test TriloTofu creation and retrieval of double value
XTEST_CASE(xdata_let_tofu_create_and_get_double) {
    TriloTofu tofu = trilo_xdata_tofu_create_from_double(3.14);
    XASSERT_BOOL_EQUAL(DOUBLE_TYPE, trilo_xdata_tofu_get_type(tofu));
    XASSERT_DOUBLE_EQUAL(3.14, trilo_xdata_tofu_get_double(tofu), EPSILON);
}

// Test case 3: Test TriloTofu equality
XTEST_CASE(xdata_let_tofu_equality) {
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_double(3.14);

    XASSERT_BOOL_TRUE(trilo_xdata_tofu_equal(tofu1, tofu2));
    XASSERT_BOOL_FALSE(trilo_xdata_tofu_equal(tofu1, tofu3));
}

// Test case 4: Test TriloTofu copy
XTEST_CASE(xdata_let_tofu_copy) {
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_copy(tofu1);

    XASSERT_BOOL_TRUE(trilo_xdata_tofu_equal(tofu1, tofu2));
}

// Test case 5: Test TriloTofu type conversion
XTEST_CASE(xdata_let_tofu_type_conversion) {
    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu2 = trilo_xdata_tofu_convert_to_double(tofu1);

    XASSERT_BOOL_EQUAL(DOUBLE_TYPE, trilo_xdata_tofu_get_type(tofu2));
    XASSERT_DOUBLE_EQUAL(42.0, trilo_xdata_tofu_get_double(tofu2), EPSILON);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_tofu_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(xdata_let_tofu_copy,                   runner);
    XTEST_RUN_UNIT(xdata_let_tofu_create_and_get_double,  runner);
    XTEST_RUN_UNIT(xdata_let_tofu_create_and_get_integer, runner);
    XTEST_RUN_UNIT(xdata_let_tofu_equality,               runner);
    XTEST_RUN_UNIT(xdata_let_tofu_type_conversion,        runner);
} // end of func
