/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/dict.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestDictData) {
    TriloDict *dict;
}dict_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_dict_of_int_create_and_destroy) {
    // Test creating and destroying a TriloDict
    dict_data.dict = trilo_xdata_dict_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(dict_data.dict);
    XASSERT_INT_EQUAL(INTEGER_TYPE, dict_data.dict->dict_type);
    trilo_xdata_dict_destroy(dict_data.dict);
}

XTEST_CASE(xdata_let_dict_of_int_insert_and_get_values) {
    // Test inserting key-value pairs into the TriloDict and getting values
    dict_data.dict = trilo_xdata_dict_create(INTEGER_TYPE);

    TriloTofu key1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(100);
    TriloTofu key2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(200);

    // Insert key-value pairs into the dictionary
    trilo_xdata_dict_insert(dict_data.dict, key1, value1);
    trilo_xdata_dict_insert(dict_data.dict, key2, value2);

    // Retrieve values by keys
    TriloTofu* retrieved_value1 = trilo_xdata_dict_get(dict_data.dict, key1);
    TriloTofu* retrieved_value2 = trilo_xdata_dict_get(dict_data.dict, key2);

    XASSERT_PTR_NOT_NULL(retrieved_value1);
    XASSERT_PTR_NOT_NULL(retrieved_value2);

    // Check the retrieved values
    XASSERT_INT_EQUAL(100, trilo_xdata_tofu_get_integer(*retrieved_value1));
    XASSERT_INT_EQUAL(200, trilo_xdata_tofu_get_integer(*retrieved_value2));

    // Clean up allocated memory for retrieved values
    free(retrieved_value1);
    free(retrieved_value2);

    trilo_xdata_dict_destroy(dict_data.dict);
}

XTEST_CASE(xdata_let_dict_of_int_remove) {
    // Test removing key-value pairs from the TriloDict
    dict_data.dict = trilo_xdata_dict_create(INTEGER_TYPE);

    TriloTofu key1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value1 = trilo_xdata_tofu_create_from_integer(100);
    TriloTofu key2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(200);

    // Insert key-value pairs into the dictionary
    trilo_xdata_dict_insert(dict_data.dict, key1, value1);
    trilo_xdata_dict_insert(dict_data.dict, key2, value2);

    // Remove a key-value pair from the dictionary
    trilo_xdata_dict_remove(dict_data.dict, key1);

    // Attempt to retrieve the removed value
    TriloTofu* retrieved_value = trilo_xdata_dict_get(dict_data.dict, key1);
    TEST_ASSERT_NULL(retrieved_value);

    trilo_xdata_dict_destroy(dict_data.dict);
}

XTEST_CASE(xdata_let_dict_of_int_key_type_mismatch) {
    // Test inserting a key of different type into the TriloDict
    dict_data.dict = trilo_xdata_dict_create(INTEGER_TYPE);

    TriloTofu key = trilo_xdata_tofu_create_from_double(3.14);
    TriloTofu value = trilo_xdata_tofu_create_from_integer(100);

    // Attempting to insert a key of a different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_DICT_KEY_TYPE_MISMATCH, trilo_xdata_dict_insert(dict_data.dict, key, value));

    trilo_xdata_dict_destroy(dict_data.dict);
}

XTEST_CASE(xdata_let_dict_of_int_value_type_mismatch) {
    // Test inserting a value of different type into the TriloDict
    dict_data.dict = trilo_xdata_dict_create(INTEGER_TYPE);

    TriloTofu key = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value = trilo_xdata_tofu_create_from_double(3.14);

    // Attempting to insert a value of a different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_DICT_VALUE_TYPE_MISMATCH, trilo_xdata_dict_insert(dict_data.dict, key, value));

    trilo_xdata_dict_destroy(dict_data.dict);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_dict_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for dict:");

    XTEST_RUN_UNIT(xdata_let_dict_of_int_create_and_destroy,    runner);
    XTEST_RUN_UNIT(xdata_let_dict_of_int_insert_and_get_values, runner);
    XTEST_RUN_UNIT(xdata_let_dict_of_int_remove,                runner);
    XTEST_RUN_UNIT(xdata_let_dict_of_int_key_type_mismatch,     runner);
    XTEST_RUN_UNIT(xdata_let_dict_of_int_value_type_mismatch,   runner);
} // end of func
