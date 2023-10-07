/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tuple.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestTupleData) {
    TriloTuple *tuple;
}tuple_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_tuple_create) {
    // Test if a tuple is created successfully
    tuple_data.tuple = trilo_xdata_tuple_create(INTEGER_TYPE, DOUBLE_TYPE, STRING_TYPE);
    XASSERT_PTR_NOT_NULL(tuple_data.tuple);
    trilo_xdata_tuple_destroy(tuple_data.tuple);
}

XTEST_CASE(xdata_let_tuple_set_and_get) {
    // Test setting and getting values in a tuple
    tuple_data.tuple = trilo_xdata_tuple_create(INTEGER_TYPE, DOUBLE_TYPE, STRING_TYPE);
    XASSERT_PTR_NOT_NULL(tuple_data.tuple);

    // Set values
    trilo_xdata_tuple_set_integer(tuple_data.tuple, 0, 42);
    trilo_xdata_tuple_set_double(tuple_data.tuple, 1, 3.14);
    trilo_xdata_tuple_set_string(tuple_data.tuple, 2, "Hello");

    // Get values and check
    XASSERT_INT_EQUAL(42, trilo_xdata_tuple_get_integer(tuple_data.tuple, 0));
    XASSERT_DOUBLE_EQUAL(3.14, trilo_xdata_tuple_get_double(tuple_data.tuple, 1), 3.00);
    XASSERT_STRING_EQUAL("Hello", trilo_xdata_tuple_get_string(tuple_data.tuple, 2));

    trilo_xdata_tuple_destroy(tuple_data.tuple);
}

XTEST_CASE(xdata_let_tuple_type_mismatch) {
    // Test type mismatch when setting values in a tuple
    tuple_data.tuple = trilo_xdata_tuple_create(INTEGER_TYPE, DOUBLE_TYPE, STRING_TYPE);
    XASSERT_PTR_NOT_NULL(tuple_data.tuple);

    // Attempt to set values with incorrect types
    XASSERT_INT_EQUAL(TRILO_XDATA_TUPLE_TYPE_MISMATCH, trilo_xdata_tuple_set_double(tuple_data.tuple, 0, 3.14));
    XASSERT_INT_EQUAL(TRILO_XDATA_TUPLE_TYPE_MISMATCH, trilo_xdata_tuple_set_string(tuple_data.tuple, 1, "World"));

    trilo_xdata_tuple_destroy(tuple_data.tuple);
}

XTEST_CASE(xdata_let_tuple_out_of_range) {
    // Test out-of-range index when setting values in a tuple
    tuple_data.tuple = trilo_xdata_tuple_create(INTEGER_TYPE, DOUBLE_TYPE, STRING_TYPE);
    XASSERT_PTR_NOT_NULL(tuple_data.tuple);

    // Attempt to set values with out-of-range indices
    XASSERT_INT_EQUAL(TRILO_XDATA_TUPLE_OUT_OF_RANGE, trilo_xdata_tuple_set_integer(tuple_data.tuple, 3, 42));
    XASSERT_INT_EQUAL(TRILO_XDATA_TUPLE_OUT_OF_RANGE, trilo_xdata_tuple_set_double(tuple_data.tuple, -1, 3.14));

    trilo_xdata_tuple_destroy(tuple_data.tuple);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_tuple_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for tuple:");

    XTEST_RUN_UNIT(xdata_let_tuple_create,        runner);
    XTEST_RUN_UNIT(xdata_let_tuple_set_and_get,   runner);
    XTEST_RUN_UNIT(xdata_let_tuple_type_mismatch, runner);
    XTEST_RUN_UNIT(xdata_let_tuple_out_of_range,  runner);

} // end of func
