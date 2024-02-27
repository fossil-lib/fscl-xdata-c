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
#include "fossil/xdata/set.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_set_create_and_erase) {
    cset* set = fscl_set_create(TOFU_INT_TYPE);

    // Check if the set is created with the expected values
    TEST_ASSERT_NOT_CNULLPTR(set);
    TEST_ASSERT_CNULLPTR(set->head);
    TEST_ASSERT_EQUAL(TOFU_INT_TYPE, set->set_type);

    fscl_set_erase(set);

    // Check if the set is erased
    TEST_ASSERT_CNULLPTR(set->head);
    TEST_ASSERT_CNULLPTR(set);
}

XTEST_CASE(test_set_insert_and_size) {
    cset* set = fscl_set_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_set_insert(set, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_set_insert(set, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_set_insert(set, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, fscl_set_size(set));

    fscl_set_erase(set);
}

XTEST_CASE(test_set_remove) {
    cset* set = fscl_set_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fscl_set_insert(set, element1);
    fscl_set_insert(set, element2);
    fscl_set_insert(set, element3);

    // Remove an element
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_set_remove(set, element2));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, fscl_set_size(set));

    fscl_set_erase(set);
}

XTEST_CASE(test_set_contains) {
    cset* set = fscl_set_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fscl_set_insert(set, element1);
    fscl_set_insert(set, element2);
    fscl_set_insert(set, element3);

    // Check if elements are contained in the set
    TEST_ASSERT_TRUE(fscl_set_contains(set, element1));
    TEST_ASSERT_TRUE(fscl_set_contains(set, element3));

    // Check for non-existing element
    ctofu nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    TEST_ASSERT_FALSE(fscl_set_contains(set, nonExistingElement));

    fscl_set_erase(set);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_set_group) {
    XTEST_NOTE("Running all test cases for set:");

    XTEST_RUN_UNIT(test_set_create_and_erase);
    XTEST_RUN_UNIT(test_set_insert_and_size);
    XTEST_RUN_UNIT(test_set_remove);
    XTEST_RUN_UNIT(test_set_contains);
} // end of func
