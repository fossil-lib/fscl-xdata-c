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
#include "fossil/xdata/map.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_map_create_and_erase) {
    cmap* map = fscl_map_create(INTEGER_TYPE);

    // Check if the map is created with the expected values
    TEST_ASSERT_NOT_CNULLPTR(map);
    TEST_ASSERT_EQUAL_UINT(0, map->size);

    fscl_map_erase(map);

    // Check if the map is erased
    TEST_ASSERT_EQUAL_UINT(0, map->size);
    TEST_ASSERT_CNULLPTR(map);
}

XTEST_CASE(test_map_insert_and_size) {
    cmap* map = fscl_map_create(INTEGER_TYPE);

    // Insert some key-value pairs
    ctofu key1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu value1 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu key2 = { INTEGER_TYPE, { .integer_type = 5 } };
    ctofu value2 = { INTEGER_TYPE, { .integer_type = 20 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_map_insert(map, key1, value1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_map_insert(map, key2, value2));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, fscl_map_size(map));

    fscl_map_erase(map);
}

XTEST_CASE(test_map_remove) {
    cmap* map = fscl_map_create(INTEGER_TYPE);

    // Insert some key-value pairs
    ctofu key1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu value1 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu key2 = { INTEGER_TYPE, { .integer_type = 5 } };
    ctofu value2 = { INTEGER_TYPE, { .integer_type = 20 } };

    fscl_map_insert(map, key1, value1);
    fscl_map_insert(map, key2, value2);

    // Remove a key-value pair
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_map_remove(map, key1));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(1, fscl_map_size(map));

    fscl_map_erase(map);
}

XTEST_CASE(test_map_getter_and_setter) {
    cmap* map = fscl_map_create(INTEGER_TYPE);

    // Insert a key-value pair
    ctofu key = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu value = { INTEGER_TYPE, { .integer_type = 10 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_map_insert(map, key, value));

    // Get the value for a key
    ctofu retrievedValue;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_map_getter(map, key, &retrievedValue));

    // Check if the retrieved value is correct
    TEST_ASSERT_EQUAL_INT(10, retrievedValue.data.integer_type);

    // Update the value for a key
    ctofu updatedValue = { INTEGER_TYPE, { .integer_type = 50 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_map_setter(map, key, updatedValue));

    // Get the updated value for the key
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_map_getter(map, key, &retrievedValue));

    // Check if the retrieved value is correct after update
    TEST_ASSERT_EQUAL_INT(50, retrievedValue.data.integer_type);

    fscl_map_erase(map);
}

XTEST_CASE(test_map_contains) {
    cmap* map = fscl_map_create(INTEGER_TYPE);

    // Insert a key-value pair
    ctofu key = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu value = { INTEGER_TYPE, { .integer_type = 10 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_map_insert(map, key, value));

    // Check if the map contains the key
    TEST_ASSERT_TRUE(fscl_map_contains(map, key));

    // Check for a non-existing key
    ctofu nonExistingKey = { INTEGER_TYPE, { .integer_type = 100 } };
    TEST_ASSERT_FALSE(fscl_map_contains(map, nonExistingKey));

    fscl_map_erase(map);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_map_group) {
    XTEST_NOTE("Running all test cases for map:");

    XTEST_RUN_UNIT(test_map_create_and_erase);
    XTEST_RUN_UNIT(test_map_insert_and_size);
    XTEST_RUN_UNIT(test_map_remove);
    XTEST_RUN_UNIT(test_map_getter_and_setter);
    XTEST_RUN_UNIT(test_map_contains);
} // end of func
