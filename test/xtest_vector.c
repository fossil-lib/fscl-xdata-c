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
#include "fossil/xdata/vector.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_vector_create_and_erase) {
    cvector vector = fscl_vector_create(TOFU_INT_TYPE);
    
    // Check if the vector is created with the expected values
    TEST_ASSERT_EQUAL(TOFU_INT_TYPE, vector.expected_type);
    TEST_ASSERT_CNULLPTR(vector.data);
    TEST_ASSERT_EQUAL_UINT(0, vector.size);
    TEST_ASSERT_EQUAL_UINT(INITIAL_CAPACITY, vector.capacity);

    fscl_vector_erase(&vector);

    // Check if the vector is erased
    TEST_ASSERT_CNULLPTR(vector.data);
    TEST_ASSERT_EQUAL_UINT(0, vector.size);
    TEST_ASSERT_EQUAL_UINT(0, vector.capacity);
}

XTEST_CASE(test_vector_push_back) {
    cvector vector = fscl_vector_create(TOFU_INT_TYPE);

    // Push back some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fscl_vector_push_back(&vector, element1);
    fscl_vector_push_back(&vector, element2);
    fscl_vector_push_back(&vector, element3);

    // Check if the elements are added correctly
    TEST_ASSERT_EQUAL_UINT(3, vector.size);
    TEST_ASSERT_EQUAL_INT(42, vector.data[0].data.int_type);
    TEST_ASSERT_EQUAL_INT(10, vector.data[1].data.int_type);
    TEST_ASSERT_EQUAL_INT(5, vector.data[2].data.int_type);

    fscl_vector_erase(&vector);
}

XTEST_CASE(test_vector_search) {
    cvector vector = fscl_vector_create(TOFU_INT_TYPE);

    // Push back some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fscl_vector_push_back(&vector, element1);
    fscl_vector_push_back(&vector, element2);
    fscl_vector_push_back(&vector, element3);

    // Search for elements
    TEST_ASSERT_EQUAL_INT(0, fscl_vector_search(&vector, element1));
    TEST_ASSERT_EQUAL_INT(1, fscl_vector_search(&vector, element2));
    TEST_ASSERT_EQUAL_INT(2, fscl_vector_search(&vector, element3));

    // Search for non-existing element
    ctofu nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    TEST_ASSERT_EQUAL_INT(-1, fscl_vector_search(&vector, nonExistingElement));

    fscl_vector_erase(&vector);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_vector_group) {
    XTEST_NOTE("Running all test cases for vector:");

    XTEST_RUN_UNIT(test_vector_create_and_erase);
    XTEST_RUN_UNIT(test_vector_push_back);
    XTEST_RUN_UNIT(test_vector_search);
} // end of func
