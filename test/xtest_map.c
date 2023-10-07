/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/map.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestMapData) {
    TriloMap *map;
}map_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_map_of_int_create_and_destroy) {
    // Test creating and destroying a TriloMap
    map_data.map = trilo_xdata_map_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(map_data.map);
    XASSERT_INT_EQUAL(INTEGER_TYPE, map_data.map->map_type);
    trilo_xdata_map_destroy(map_data.map);
}

XTEST_CASE(xdata_let_map_of_int_insert_and_find) {
    // Test inserting and finding key-value pairs in the TriloMap
    map_data.map = trilo_xdata_map_create(INTEGER_TYPE);

    TriloTofu key1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value1 = trilo_xdata_tofu_create_from_string("One");

    TriloTofu key2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value2 = trilo_xdata_tofu_create_from_string("Two");

    trilo_xdata_map_insert(map_data.map, key1, value1);
    trilo_xdata_map_insert(map_data.map, key2, value2);

    XASSERT_STRING_EQUAL("One", trilo_xdata_tofu_get_string(trilo_xdata_map_find(map_data.map, key1)));
    XASSERT_STRING_EQUAL("Two", trilo_xdata_tofu_get_string(trilo_xdata_map_find(map_data.map, key2)));

    trilo_xdata_map_destroy(map_data.map);
}

XTEST_CASE(xdata_let_map_of_int_key_not_found) {
    // Test finding a key that does not exist in the TriloMap
    map_data.map = trilo_xdata_map_create(INTEGER_TYPE);

    TriloTofu key = trilo_xdata_tofu_create_from_integer(1);

    // Attempting to find a key that does not exist should return NULL
    XASSERT_PTR_NULL(trilo_xdata_map_find(map_data.map, key));

    trilo_xdata_map_destroy(map_data.map);
}

XTEST_CASE(xdata_let_map_of_int_type_mismatch) {
    // Test inserting key-value pairs of different types in the TriloMap
    map_data.map = trilo_xdata_map_create(INTEGER_TYPE);

    TriloTofu key = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value = trilo_xdata_tofu_create_from_double(3.14);

    // Attempting to insert a value of a different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_MAP_TYPE_MISMATCH, trilo_xdata_map_insert(map_data.map, key, value));

    trilo_xdata_map_destroy(map_data.map);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_map_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for map:");

    XTEST_RUN_UNIT(xdata_let_map_of_int_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_map_of_int_insert_and_find,    runner);
    XTEST_RUN_UNIT(xdata_let_map_of_int_key_not_found,      runner);
    XTEST_RUN_UNIT(xdata_let_map_of_int_type_mismatch,      runner);
} // end of func
