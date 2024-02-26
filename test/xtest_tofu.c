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
#include "fossil/xdata/tofu.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

#define EPSILON 0.001 // Define a small epsilon value for double comparisons

//
// XUNIT TEST CASES
//

// Test Case 1: Create and Erase
XTEST_CASE(test_tofu_create_and_erase) {
    ctofu_data data;
    data.int_type = 42;

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_INT_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

// Test Case 2: Create and Erase Array
XTEST_CASE(test_tofu_create_and_erase_array) {
    // Create an array of integers: 1, 2, 3, 4
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    fscl_tofu_erase_array(array_result);
    TEST_ASSERT_CNULLPTR(array_result);
}

// Test Case 3: Accumulate
XTEST_CASE(test_tofu_accumulate) {
    // Create an array of integers: 1, 1, 1
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 3, 1, 1, 1);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_accumulate(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 4: Sort
XTEST_CASE(test_tofu_sort) {
    // Create an array of integers: 4, 2, 1, 3
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 4, 4, 2, 1, 3);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 5: Reverse
XTEST_CASE(test_tofu_reverse) {
    // Create an array of integers: 1, 2, 3
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reverse(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 6: Transform
XTEST_CASE(test_tofu_transform) {
    // Create an array of integers: 1, 2, 3
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_transform(array_result, increment_function));

    fscl_tofu_erase_array(array_result);
}

// Test Case 7: Search
XTEST_CASE(test_tofu_search) {
    // Create an array of integers: 1, 2, 3
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu key;
    key.int_type = 2;

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_search(array_result, &key));

    fscl_tofu_erase_array(array_result);
}

// Test Case 8: Filter
XTEST_CASE(test_tofu_filter) {
    // Create an array of integers: 1, 2, 3, 4
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_filter(array_result, is_even));

    fscl_tofu_erase_array(array_result);
}

// Test Case 9: Swap
XTEST_CASE(test_tofu_swap) {
    // Create an array of integers: 1, 2, 3
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu* element1 = &array_result[0];
    ctofu* element2 = &array_result[2];

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_swap(element1, element2));

    fscl_tofu_erase_array(array_result);
}

// Test Case 10: Compare
XTEST_CASE(test_tofu_compare) {
    // Create an array of integers: 1, 2, 3
    ctofu* array1 = fscl_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    TEST_ASSERT_NOT_CNULLPTR(array1);

    // Create another array of integers: 1, 2, 3
    ctofu* array2 = fscl_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    TEST_ASSERT_NOT_CNULLPTR(array2);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_compare(array1, array2));

    fscl_tofu_erase_array(array1);
    fscl_tofu_erase_array(array2);
}

// Test Case 11: Reduce
XTEST_CASE(test_tofu_reduce) {
    // Create an array of integers: 1, 2, 3
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu reduced_value;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reduce(array_result, sum_function, &reduced_value));

    fscl_tofu_erase_array(array_result);
}

// Test Case 12: Shuffle
XTEST_CASE(test_tofu_shuffle) {
    // Create an array of integers: 1, 2, 3, 4
    ctofu* array_result = fscl_tofu_create_array(TOFU_INT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_shuffle(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 13: Create and Erase for Char Type
XTEST_CASE(test_tofu_create_and_erase_char) {
    ctofu_data data;
    data.char_type = 'a';

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_CHAR_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

// Test Case 14: Create and Erase Array for Char Type
XTEST_CASE(test_tofu_create_and_erase_array_char) {
    // Create an array of characters: 'a', 'b', 'c', 'd'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 4, 'a', 'b', 'c', 'd');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    fscl_tofu_erase_array(array_result);
    TEST_ASSERT_CNULLPTR(array_result);
}

// Test Case 15: Accumulate for Char Type
XTEST_CASE(test_tofu_accumulate_char) {
    // Create an array of characters: 'a', 'a', 'a'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 3, 'a', 'a', 'a');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_accumulate(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 16: Sort for Char Type
XTEST_CASE(test_tofu_sort_char) {
    // Create an array of characters: 'd', 'b', 'a', 'c'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 4, 'd', 'b', 'a', 'c');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 17: Reverse for Char Type
XTEST_CASE(test_tofu_reverse_char) {
    // Create an array of characters: 'a', 'b', 'c'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 3, 'a', 'b', 'c');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reverse(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 18: Transform for Char Type
XTEST_CASE(test_tofu_transform_char) {
    // Create an array of characters: 'a', 'b', 'c'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 3, 'a', 'b', 'c');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_transform(array_result, increment_char_function));

    fscl_tofu_erase_array(array_result);
}

// Test Case 19: Search for Char Type
XTEST_CASE(test_tofu_search_char) {
    // Create an array of characters: 'a', 'b', 'c'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 3, 'a', 'b', 'c');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu key;
    key.char_type = 'b';

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_search(array_result, &key));

    fscl_tofu_erase_array(array_result);
}

// Test Case 20: Filter for Char Type
XTEST_CASE(test_tofu_filter_char) {
    // Create an array of characters: 'a', 'b', 'c', 'd'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 4, 'a', 'b', 'c', 'd');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_filter(array_result, is_vowel));

    fscl_tofu_erase_array(array_result);
}

// Test Case 21: Swap for Char Type
XTEST_CASE(test_tofu_swap_char) {
    // Create an array of characters: 'a', 'b', 'c'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 3, 'a', 'b', 'c');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu* element1 = &array_result[0];
    ctofu* element2 = &array_result[2];

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_swap(element1, element2));

    fscl_tofu_erase_array(array_result);
}

// Test Case 22: Compare for Char Type
XTEST_CASE(test_tofu_compare_char) {
    // Create an array of characters: 'a', 'b', 'c'
    ctofu* array1 = fscl_tofu_create_array(TOFU_CHAR_TYPE, 3, 'a', 'b', 'c');
    TEST_ASSERT_NOT_CNULLPTR(array1);

    // Create another array of characters: 'a', 'b', 'c'
    ctofu* array2 = fscl_tofu_create_array(TOFU_CHAR_TYPE, 3, 'a', 'b', 'c');
    TEST_ASSERT_NOT_CNULLPTR(array2);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_compare(array1, array2));

    fscl_tofu_erase_array(array1);
    fscl_tofu_erase_array(array2);
}

// Test Case 23: Reduce for Char Type
XTEST_CASE(test_tofu_reduce_char) {
    // Create an array of characters: 'a', 'b', 'c'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 3, 'a', 'b', 'c');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu reduced_value;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reduce(array_result, concat_chars_function, &reduced_value));

    fscl_tofu_erase_array(array_result);
}

// Test Case 24: Shuffle for Char Type
XTEST_CASE(test_tofu_shuffle_char) {
    // Create an array of characters: 'a', 'b', 'c', 'd'
    ctofu* array_result = fscl_tofu_create_array(TOFU_CHAR_TYPE, 4, 'a', 'b', 'c', 'd');
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_shuffle(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 25: Create and Erase for String Type
XTEST_CASE(test_tofu_create_and_erase_string) {
    ctofu_data data;
    data.string_type = fscl_tofu_strdup("Hello, Tofu!");

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_STRING_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

// Test Case 26: Create and Erase Array for String Type
XTEST_CASE(test_tofu_create_and_erase_array_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    fscl_tofu_erase_array(array_result);
    TEST_ASSERT_CNULLPTR(array_result);
}

// Test Case 27: Accumulate for String Type
XTEST_CASE(test_tofu_accumulate_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_accumulate(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 28: Sort for String Type
XTEST_CASE(test_tofu_sort_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 29: Reverse for String Type
XTEST_CASE(test_tofu_reverse_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reverse(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 30: Transform for String Type
XTEST_CASE(test_tofu_transform_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_transform(array_result, capitalize_string_function));

    fscl_tofu_erase_array(array_result);
}

// Test Case 31: Search for String Type
XTEST_CASE(test_tofu_search_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu key;
    key.string_type = fscl_tofu_strdup("banana");

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_search(array_result, &key));

    fscl_tofu_erase_array(array_result);
}

// Test Case 32: Filter for String Type
XTEST_CASE(test_tofu_filter_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_filter(array_result, is_long_word));

    fscl_tofu_erase_array(array_result);
}

// Test Case 33: Swap for String Type
XTEST_CASE(test_tofu_swap_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu* element1 = &array_result[0];
    ctofu* element2 = &array_result[2];

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_swap(element1, element2));

    fscl_tofu_erase_array(array_result);
}

// Test Case 34: Compare for String Type
XTEST_CASE(test_tofu_compare_string) {
    // Create an array of strings
    ctofu* array1 = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array1);

    // Create another array of strings
    ctofu* array2 = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array2);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_compare(array1, array2));

    fscl_tofu_erase_array(array1);
    fscl_tofu_erase_array(array2);
}

// Test Case 35: Reduce for String Type
XTEST_CASE(test_tofu_reduce_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu reduced_value;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reduce(array_result, concatenate_strings_function, &reduced_value));

    fscl_tofu_erase_array(array_result);
}

// Test Case 36: Shuffle for String Type
XTEST_CASE(test_tofu_shuffle_string) {
    // Create an array of strings
    ctofu* array_result = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, fscl_tofu_strdup("apple"), fscl_tofu_strdup("banana"), fscl_tofu_strdup("orange"));
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_shuffle(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 37: Create and Erase for Unsigned Integer Type
XTEST_CASE(test_tofu_create_and_erase_uint) {
    ctofu_data data;
    data.uint_type = 42;

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_UINT_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

// Test Case 38: Create and Erase Array for Unsigned Integer Type
XTEST_CASE(test_tofu_create_and_erase_array_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    fscl_tofu_erase_array(array_result);
    TEST_ASSERT_CNULLPTR(array_result);
}

// Test Case 39: Accumulate for Unsigned Integer Type
XTEST_CASE(test_tofu_accumulate_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_accumulate(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 40: Sort for Unsigned Integer Type
XTEST_CASE(test_tofu_sort_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 4, 2, 1, 3);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 41: Reverse for Unsigned Integer Type
XTEST_CASE(test_tofu_reverse_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reverse(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 42: Transform for Unsigned Integer Type
XTEST_CASE(test_tofu_transform_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_transform(array_result, multiply_by_two_function));

    fscl_tofu_erase_array(array_result);
}

// Test Case 43: Search for Unsigned Integer Type
XTEST_CASE(test_tofu_search_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu key;
    key.uint_type = 3;

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_search(array_result, &key));

    fscl_tofu_erase_array(array_result);
}

// Test Case 44: Filter for Unsigned Integer Type
XTEST_CASE(test_tofu_filter_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_filter(array_result, is_even_number));

    fscl_tofu_erase_array(array_result);
}

// Test Case 45: Swap for Unsigned Integer Type
XTEST_CASE(test_tofu_swap_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu* element1 = &array_result[0];
    ctofu* element2 = &array_result[2];

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_swap(element1, element2));

    fscl_tofu_erase_array(array_result);
}

// Test Case 46: Compare for Unsigned Integer Type
XTEST_CASE(test_tofu_compare_uint) {
    // Create an array of unsigned integers
    ctofu* array1 = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array1);

    // Create another array of unsigned integers
    ctofu* array2 = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array2);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_compare(array1, array2));

    fscl_tofu_erase_array(array1);
    fscl_tofu_erase_array(array2);
}

// Test Case 47: Reduce for Unsigned Integer Type
XTEST_CASE(test_tofu_reduce_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu reduced_value;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reduce(array_result, sum_numbers_function, &reduced_value));

    fscl_tofu_erase_array(array_result);
}

// Test Case 48: Shuffle for Unsigned Integer Type
XTEST_CASE(test_tofu_shuffle_uint) {
    // Create an array of unsigned integers
    ctofu* array_result = fscl_tofu_create_array(TOFU_UINT_TYPE, 4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_shuffle(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 49: Create and Erase for Float Type
XTEST_CASE(test_tofu_create_and_erase_float) {
    ctofu_data data;
    data.float_type = 3.14f;

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_FLOAT_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

// Test Case 50: Create and Erase Array for Float Type
XTEST_CASE(test_tofu_create_and_erase_array_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    fscl_tofu_erase_array(array_result);
    TEST_ASSERT_CNULLPTR(array_result);
}

// Test Case 51: Accumulate for Float Type
XTEST_CASE(test_tofu_accumulate_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_accumulate(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 52: Sort for Float Type
XTEST_CASE(test_tofu_sort_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 4.4f, 2.2f, 1.1f, 3.3f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 53: Reverse for Float Type
XTEST_CASE(test_tofu_reverse_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reverse(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 54: Transform for Float Type
XTEST_CASE(test_tofu_transform_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_transform(array_result, square_function));

    fscl_tofu_erase_array(array_result);
}

// Test Case 55: Search for Float Type
XTEST_CASE(test_tofu_search_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu key;
    key.float_type = 3.3f;

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_search(array_result, &key));

    fscl_tofu_erase_array(array_result);
}

// Test Case 56: Filter for Float Type
XTEST_CASE(test_tofu_filter_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_filter(array_result, is_greater_than_two));

    fscl_tofu_erase_array(array_result);
}

// Test Case 57: Swap for Float Type
XTEST_CASE(test_tofu_swap_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu* element1 = &array_result[0];
    ctofu* element2 = &array_result[2];

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_swap(element1, element2));

    fscl_tofu_erase_array(array_result);
}

// Test Case 58: Compare for Float Type
XTEST_CASE(test_tofu_compare_float) {
    // Create an array of floats
    ctofu* array1 = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array1);

    // Create another array of floats
    ctofu* array2 = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array2);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_compare(array1, array2));

    fscl_tofu_erase_array(array1);
    fscl_tofu_erase_array(array2);
}

// Test Case 59: Reduce for Float Type
XTEST_CASE(test_tofu_reduce_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu reduced_value;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reduce(array_result, sum_numbers_function, &reduced_value));

    fscl_tofu_erase_array(array_result);
}

// Test Case 60: Shuffle for Float Type
XTEST_CASE(test_tofu_shuffle_float) {
    // Create an array of floats
    ctofu* array_result = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 4, 1.1f, 2.2f, 3.3f, 4.4f);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_shuffle(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 61: Create and Erase for Hex Type
XTEST_CASE(test_tofu_create_and_erase_hex) {
    ctofu_data data;
    data.hex64_type = 0xDEADBEEF;

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_HEX64_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

// Test Case 62: Create and Erase Array for Hex Type
XTEST_CASE(test_tofu_create_and_erase_array_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    fscl_tofu_erase_array(array_result);
    TEST_ASSERT_CNULLPTR(array_result);
}

// Test Case 63: Accumulate for Hex Type
XTEST_CASE(test_tofu_accumulate_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_accumulate(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 64: Sort for Hex Type
XTEST_CASE(test_tofu_sort_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0x12345678, 0xBAADF00D, 0xC0FFEE, 0xDEADBEEF);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 65: Reverse for Hex Type
XTEST_CASE(test_tofu_reverse_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reverse(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 66: Transform for Hex Type
XTEST_CASE(test_tofu_transform_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_transform(array_result, increment_hex_function));

    fscl_tofu_erase_array(array_result);
}

// Test Case 67: Search for Hex Type
XTEST_CASE(test_tofu_search_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu key;
    key.hex64_type = 0xBAADF00D;

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_search(array_result, &key));

    fscl_tofu_erase_array(array_result);
}

// Test Case 68: Filter for Hex Type
XTEST_CASE(test_tofu_filter_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_filter(array_result, is_hex_even));

    fscl_tofu_erase_array(array_result);
}

// Test Case 69: Swap for Hex Type
XTEST_CASE(test_tofu_swap_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu* element1 = &array_result[0];
    ctofu* element2 = &array_result[2];

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_swap(element1, element2));

    fscl_tofu_erase_array(array_result);
}

// Test Case 70: Compare for Hex Type
XTEST_CASE(test_tofu_compare_hex) {
    // Create an array of hex values
    ctofu* array1 = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array1);

    // Create another array of hex values
    ctofu* array2 = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array2);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_compare(array1, array2));

    fscl_tofu_erase_array(array1);
    fscl_tofu_erase_array(array2);
}

// Test Case 71: Reduce for Hex Type
XTEST_CASE(test_tofu_reduce_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu reduced_value;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reduce(array_result, sum_hex_values_function, &reduced_value));

    fscl_tofu_erase_array(array_result);
}

// Test Case 72: Shuffle for Hex Type
XTEST_CASE(test_tofu_shuffle_hex) {
    // Create an array of hex values
    ctofu* array_result = fscl_tofu_create_array(TOFU_HEX64_TYPE, 4, 0xDEADBEEF, 0xC0FFEE, 0xBAADF00D, 0x12345678);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_shuffle(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 73: Create and Erase for Octal Type
XTEST_CASE(test_tofu_create_and_erase_octal) {
    ctofu_data data;
    data.octal64_type = 0755;

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_OCTAL64_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

// Test Case 74: Create and Erase Array for Octal Type
XTEST_CASE(test_tofu_create_and_erase_array_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    fscl_tofu_erase_array(array_result);
    TEST_ASSERT_CNULLPTR(array_result);
}

// Test Case 75: Accumulate for Octal Type
XTEST_CASE(test_tofu_accumulate_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_accumulate(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 76: Sort for Octal Type
XTEST_CASE(test_tofu_sort_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0700, 0777, 0644, 0755);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 77: Reverse for Octal Type
XTEST_CASE(test_tofu_reverse_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reverse(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 78: Transform for Octal Type
XTEST_CASE(test_tofu_transform_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_transform(array_result, increment_octal_function));

    fscl_tofu_erase_array(array_result);
}

// Test Case 79: Search for Octal Type
XTEST_CASE(test_tofu_search_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu key;
    key.octal64_type = 0644;

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_search(array_result, &key));

    fscl_tofu_erase_array(array_result);
}

// Test Case 80: Filter for Octal Type
XTEST_CASE(test_tofu_filter_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_filter(array_result, is_octal_even));

    fscl_tofu_erase_array(array_result);
}

// Test Case 81: Swap for Octal Type
XTEST_CASE(test_tofu_swap_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu* element1 = &array_result[0];
    ctofu* element2 = &array_result[2];

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_swap(element1, element2));

    fscl_tofu_erase_array(array_result);
}

// Test Case 82: Compare for Octal Type
XTEST_CASE(test_tofu_compare_octal) {
    // Create an array of octal values
    ctofu* array1 = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array1);

    // Create another array of octal values
    ctofu* array2 = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array2);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_compare(array1, array2));

    fscl_tofu_erase_array(array1);
    fscl_tofu_erase_array(array2);
}

// Test Case 83: Reduce for Octal Type
XTEST_CASE(test_tofu_reduce_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu reduced_value;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reduce(array_result, sum_octal_values_function, &reduced_value));

    fscl_tofu_erase_array(array_result);
}

// Test Case 84: Shuffle for Octal Type
XTEST_CASE(test_tofu_shuffle_octal) {
    // Create an array of octal values
    ctofu* array_result = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 4, 0755, 0644, 0777, 0700);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_shuffle(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 85: Create and Erase for Bitwise Type
XTEST_CASE(test_tofu_create_and_erase_bitwise) {
    ctofu_data data;
    data.bitwise64_type = 0b10101010;

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_BITWISE64_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

// Test Case 86: Create and Erase Array for Bitwise Type
XTEST_CASE(test_tofu_create_and_erase_array_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    fscl_tofu_erase_array(array_result);
    TEST_ASSERT_CNULLPTR(array_result);
}

// Test Case 87: Accumulate for Bitwise Type
XTEST_CASE(test_tofu_accumulate_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_accumulate(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 88: Sort for Bitwise Type
XTEST_CASE(test_tofu_sort_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b11110000, 0b10101010, 0b00001111, 0b01010101);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 89: Reverse for Bitwise Type
XTEST_CASE(test_tofu_reverse_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reverse(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 90: Transform for Bitwise Type
XTEST_CASE(test_tofu_transform_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_transform(array_result, bitwise_complement_function));

    fscl_tofu_erase_array(array_result);
}

// Test Case 91: Search for Bitwise Type
XTEST_CASE(test_tofu_search_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu key;
    key.bitwise64_type = 0b11110000;

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_search(array_result, &key));

    fscl_tofu_erase_array(array_result);
}

// Test Case 92: Filter for Bitwise Type
XTEST_CASE(test_tofu_filter_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_filter(array_result, is_bitwise_even));

    fscl_tofu_erase_array(array_result);
}

// Test Case 93: Swap for Bitwise Type
XTEST_CASE(test_tofu_swap_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu* element1 = &array_result[0];
    ctofu* element2 = &array_result[2];

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_swap(element1, element2));

    fscl_tofu_erase_array(array_result);
}

// Test Case 94: Compare for Bitwise Type
XTEST_CASE(test_tofu_compare_bitwise) {
    // Create an array of bitwise values
    ctofu* array1 = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array1);

    // Create another array of bitwise values
    ctofu* array2 = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array2);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_compare(array1, array2));

    fscl_tofu_erase_array(array1);
    fscl_tofu_erase_array(array2);
}

// Test Case 95: Reduce for Bitwise Type
XTEST_CASE(test_tofu_reduce_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu reduced_value;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reduce(array_result, bitwise_reduce_function, &reduced_value));

    fscl_tofu_erase_array(array_result);
}

// Test Case 96: Shuffle for Bitwise Type
XTEST_CASE(test_tofu_shuffle_bitwise) {
    // Create an array of bitwise values
    ctofu* array_result = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 4, 0b10101010, 0b01010101, 0b11110000, 0b00001111);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_shuffle(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 97: Create and Erase for Qbit Type
XTEST_CASE(test_tofu_create_and_erase_qbit) {
    ctofu_data data;
    data.qbit_type = true;

    ctofu* result = NULL;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_create(TOFU_QBIT_TYPE, &data, &result));
    TEST_ASSERT_NOT_CNULLPTR(result);

    fscl_tofu_erase(result);
    TEST_ASSERT_CNULLPTR(result);
}

// Test Case 98: Create and Erase Array for Qbit Type
XTEST_CASE(test_tofu_create_and_erase_array_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    fscl_tofu_erase_array(array_result);
    TEST_ASSERT_CNULLPTR(array_result);
}

// Test Case 99: Accumulate for Qbit Type
XTEST_CASE(test_tofu_accumulate_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_accumulate(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 100: Sort for Qbit Type
XTEST_CASE(test_tofu_sort_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, false, true, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_sort(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 101: Reverse for Qbit Type
XTEST_CASE(test_tofu_reverse_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reverse(array_result));

    fscl_tofu_erase_array(array_result);
}

// Test Case 102: Transform for Qbit Type
XTEST_CASE(test_tofu_transform_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_transform(array_result, qbit_toggle_function));

    fscl_tofu_erase_array(array_result);
}

// Test Case 103: Search for Qbit Type
XTEST_CASE(test_tofu_search_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu key;
    key.qbit_type = false;

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_search(array_result, &key));

    fscl_tofu_erase_array(array_result);
}

// Test Case 104: Filter for Qbit Type
XTEST_CASE(test_tofu_filter_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_filter(array_result, is_qbit_true));

    fscl_tofu_erase_array(array_result);
}

// Test Case 105: Swap for Qbit Type
XTEST_CASE(test_tofu_swap_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu* element1 = &array_result[0];
    ctofu* element2 = &array_result[2];

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_swap(element1, element2));

    fscl_tofu_erase_array(array_result);
}

// Test Case 106: Compare for Qbit Type
XTEST_CASE(test_tofu_compare_qbit) {
    // Create an array of qbit values
    ctofu* array1 = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array1);

    // Create another array of qbit values
    ctofu* array2 = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array2);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_compare(array1, array2));

    fscl_tofu_erase_array(array1);
    fscl_tofu_erase_array(array2);
}

// Test Case 107: Reduce for Qbit Type
XTEST_CASE(test_tofu_reduce_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    ctofu reduced_value;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_reduce(array_result, qbit_reduce_function, &reduced_value));

    fscl_tofu_erase_array(array_result);
}

// Test Case 108: Shuffle for Qbit Type
XTEST_CASE(test_tofu_shuffle_qbit) {
    // Create an array of qbit values
    ctofu* array_result = fscl_tofu_create_array(TOFU_QBIT_TYPE, 4, true, false, true, false);
    TEST_ASSERT_NOT_CNULLPTR(array_result);

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tofu_shuffle(array_result));

    fscl_tofu_erase_array(array_result);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_tofu_group) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(test_tofu_create_and_erase);
    XTEST_RUN_UNIT(test_tofu_create_and_erase_array);
    XTEST_RUN_UNIT(test_tofu_accumulate);
    XTEST_RUN_UNIT(test_tofu_sort);
    XTEST_RUN_UNIT(test_tofu_reverse);
    XTEST_RUN_UNIT(test_tofu_transform);
    XTEST_RUN_UNIT(test_tofu_search);
    XTEST_RUN_UNIT(test_tofu_filter);
    XTEST_RUN_UNIT(test_tofu_swap);
    XTEST_RUN_UNIT(test_tofu_compare);
    XTEST_RUN_UNIT(test_tofu_reduce);
    XTEST_RUN_UNIT(test_tofu_shuffle);

    // Test cases for Qbit type
    XTEST_RUN_UNIT(test_tofu_create_and_erase_qbit);
    XTEST_RUN_UNIT(test_tofu_create_and_erase_array_qbit);
    XTEST_RUN_UNIT(test_tofu_accumulate_qbit);
    XTEST_RUN_UNIT(test_tofu_sort_qbit);
    XTEST_RUN_UNIT(test_tofu_reverse_qbit);
    XTEST_RUN_UNIT(test_tofu_transform_qbit);
    XTEST_RUN_UNIT(test_tofu_search_qbit);
    XTEST_RUN_UNIT(test_tofu_filter_qbit);
    XTEST_RUN_UNIT(test_tofu_swap_qbit);
    XTEST_RUN_UNIT(test_tofu_compare_qbit);
    XTEST_RUN_UNIT(test_tofu_reduce_qbit);
    XTEST_RUN_UNIT(test_tofu_shuffle_qbit);

    // Test cases for other data types
    XTEST_RUN_UNIT(test_tofu_create_and_erase_char);
    XTEST_RUN_UNIT(test_tofu_create_and_erase_array_char);
    XTEST_RUN_UNIT(test_tofu_accumulate_char);
    XTEST_RUN_UNIT(test_tofu_sort_char);
    XTEST_RUN_UNIT(test_tofu_reverse_char);
    XTEST_RUN_UNIT(test_tofu_transform_char);
    XTEST_RUN_UNIT(test_tofu_search_char);
    XTEST_RUN_UNIT(test_tofu_filter_char);
    XTEST_RUN_UNIT(test_tofu_swap_char);
    XTEST_RUN_UNIT(test_tofu_compare_char);
    XTEST_RUN_UNIT(test_tofu_reduce_char);
    XTEST_RUN_UNIT(test_tofu_shuffle_char);

    // Test cases for Hex type
    XTEST_RUN_UNIT(test_tofu_create_and_erase_hex);
    XTEST_RUN_UNIT(test_tofu_create_and_erase_array_hex);
    XTEST_RUN_UNIT(test_tofu_accumulate_hex);
    XTEST_RUN_UNIT(test_tofu_sort_hex);
    XTEST_RUN_UNIT(test_tofu_reverse_hex);
    XTEST_RUN_UNIT(test_tofu_transform_hex);
    XTEST_RUN_UNIT(test_tofu_search_hex);
    XTEST_RUN_UNIT(test_tofu_filter_hex);
    XTEST_RUN_UNIT(test_tofu_swap_hex);
    XTEST_RUN_UNIT(test_tofu_compare_hex);
    XTEST_RUN_UNIT(test_tofu_reduce_hex);
    XTEST_RUN_UNIT(test_tofu_shuffle_hex);

    // Test cases for Octal type
    XTEST_RUN_UNIT(test_tofu_create_and_erase_octal);
    XTEST_RUN_UNIT(test_tofu_create_and_erase_array_octal);
    XTEST_RUN_UNIT(test_tofu_accumulate_octal);
    XTEST_RUN_UNIT(test_tofu_sort_octal);
    XTEST_RUN_UNIT(test_tofu_reverse_octal);
    XTEST_RUN_UNIT(test_tofu_transform_octal);
    XTEST_RUN_UNIT(test_tofu_search_octal);
    XTEST_RUN_UNIT(test_tofu_filter_octal);
    XTEST_RUN_UNIT(test_tofu_swap_octal);
    XTEST_RUN_UNIT(test_tofu_compare_octal);
    XTEST_RUN_UNIT(test_tofu_reduce_octal);
    XTEST_RUN_UNIT(test_tofu_shuffle_octal);

    // Test cases for Float type
    XTEST_RUN_UNIT(test_tofu_create_and_erase_float);
    XTEST_RUN_UNIT(test_tofu_create_and_erase_array_float);
    XTEST_RUN_UNIT(test_tofu_accumulate_float);
    XTEST_RUN_UNIT(test_tofu_sort_float);
    XTEST_RUN_UNIT(test_tofu_reverse_float);
    XTEST_RUN_UNIT(test_tofu_transform_float);
    XTEST_RUN_UNIT(test_tofu_search_float);
    XTEST_RUN_UNIT(test_tofu_filter_float);
    XTEST_RUN_UNIT(test_tofu_swap_float);
    XTEST_RUN_UNIT(test_tofu_compare_float);
    XTEST_RUN_UNIT(test_tofu_reduce_float);
    XTEST_RUN_UNIT(test_tofu_shuffle_float);

    // Test cases for String type
    XTEST_RUN_UNIT(test_tofu_create_and_erase_string);
    XTEST_RUN_UNIT(test_tofu_create_and_erase_array_string);
    XTEST_RUN_UNIT(test_tofu_accumulate_string);
    XTEST_RUN_UNIT(test_tofu_sort_string);
    XTEST_RUN_UNIT(test_tofu_reverse_string);
    XTEST_RUN_UNIT(test_tofu_transform_string);
    XTEST_RUN_UNIT(test_tofu_search_string);
    XTEST_RUN_UNIT(test_tofu_filter_string);
    XTEST_RUN_UNIT(test_tofu_swap_string);
    XTEST_RUN_UNIT(test_tofu_compare_string);
    XTEST_RUN_UNIT(test_tofu_reduce_string);
    XTEST_RUN_UNIT(test_tofu_shuffle_string);

    // Test cases for Bitwise type
    XTEST_RUN_UNIT(test_tofu_create_and_erase_bitwise);
    XTEST_RUN_UNIT(test_tofu_create_and_erase_array_bitwise);
    XTEST_RUN_UNIT(test_tofu_accumulate_bitwise);
    XTEST_RUN_UNIT(test_tofu_sort_bitwise);
    XTEST_RUN_UNIT(test_tofu_reverse_bitwise);
    XTEST_RUN_UNIT(test_tofu_transform_bitwise);
    XTEST_RUN_UNIT(test_tofu_search_bitwise);
    XTEST_RUN_UNIT(test_tofu_filter_bitwise);
    XTEST_RUN_UNIT(test_tofu_swap_bitwise);
    XTEST_RUN_UNIT(test_tofu_compare_bitwise);
    XTEST_RUN_UNIT(test_tofu_reduce_bitwise);
    XTEST_RUN_UNIT(test_tofu_shuffle_bitwise);

    // Test cases for Uint type
    XTEST_RUN_UNIT(test_tofu_create_and_erase_uint);
    XTEST_RUN_UNIT(test_tofu_create_and_erase_array_uint);
    XTEST_RUN_UNIT(test_tofu_accumulate_uint);
    XTEST_RUN_UNIT(test_tofu_sort_uint);
    XTEST_RUN_UNIT(test_tofu_reverse_uint);
    XTEST_RUN_UNIT(test_tofu_transform_uint);
    XTEST_RUN_UNIT(test_tofu_search_uint);
    XTEST_RUN_UNIT(test_tofu_filter_uint);
    XTEST_RUN_UNIT(test_tofu_swap_uint);
    XTEST_RUN_UNIT(test_tofu_compare_uint);
    XTEST_RUN_UNIT(test_tofu_reduce_uint);
    XTEST_RUN_UNIT(test_tofu_shuffle_uint);

} // end of xdata_test_tofu_group
