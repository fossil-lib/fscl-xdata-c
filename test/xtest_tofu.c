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

// Helper functions for algorithms
int square_transform_function(int value) {
    return value * value;
}

bool even_filter_function(const ctofu* element) {
    return (element->data.int_type % 2) == 0;
}

//
// XUNIT TEST CASES
//

XTEST_CASE(test_create_and_erase) {
    // Test creating and erasing "tofu" structures for each supported type

    // Integer types
    ctofu* int_tofu = fscl_tofu_create(TOFU_INT_TYPE, &(ctofu_data){.int_type = 42});
    TEST_ASSERT_NOT_CNULLPTR(int_tofu);
    fscl_tofu_erase(int_tofu);

    ctofu* int8_tofu = fscl_tofu_create(TOFU_INT8_TYPE, &(ctofu_data){.int8_type = 8});
    TEST_ASSERT_NOT_CNULLPTR(int8_tofu);
    fscl_tofu_erase(int8_tofu);

    ctofu* int16_tofu = fscl_tofu_create(TOFU_INT16_TYPE, &(ctofu_data){.int16_type = 16});
    TEST_ASSERT_NOT_CNULLPTR(int16_tofu);
    fscl_tofu_erase(int16_tofu);

    ctofu* int32_tofu = fscl_tofu_create(TOFU_INT32_TYPE, &(ctofu_data){.int32_type = 32});
    TEST_ASSERT_NOT_CNULLPTR(int32_tofu);
    fscl_tofu_erase(int32_tofu);

    ctofu* int64_tofu = fscl_tofu_create(TOFU_INT64_TYPE, &(ctofu_data){.int64_type = 64});
    TEST_ASSERT_NOT_CNULLPTR(int64_tofu);
    fscl_tofu_erase(int64_tofu);

    // Unsigned integer types
    ctofu* uint_tofu = fscl_tofu_create(TOFU_UINT_TYPE, &(ctofu_data){.uint_type = 42});
    TEST_ASSERT_NOT_CNULLPTR(uint_tofu);
    fscl_tofu_erase(uint_tofu);

    ctofu* uint8_tofu = fscl_tofu_create(TOFU_UINT8_TYPE, &(ctofu_data){.uint8_type = 8});
    TEST_ASSERT_NOT_CNULLPTR(uint8_tofu);
    fscl_tofu_erase(uint8_tofu);

    ctofu* uint16_tofu = fscl_tofu_create(TOFU_UINT16_TYPE, &(ctofu_data){.uint16_type = 16});
    TEST_ASSERT_NOT_CNULLPTR(uint16_tofu);
    fscl_tofu_erase(uint16_tofu);

    ctofu* uint32_tofu = fscl_tofu_create(TOFU_UINT32_TYPE, &(ctofu_data){.uint32_type = 32});
    TEST_ASSERT_NOT_CNULLPTR(uint32_tofu);
    fscl_tofu_erase(uint32_tofu);

    ctofu* uint64_tofu = fscl_tofu_create(TOFU_UINT64_TYPE, &(ctofu_data){.uint64_type = 64});
    TEST_ASSERT_NOT_CNULLPTR(uint64_tofu);
    fscl_tofu_erase(uint64_tofu);

    // Octal types
    ctofu* octal8_tofu = fscl_tofu_create(TOFU_OCTAL8_TYPE, &(ctofu_data){.octal8_type = 075});
    TEST_ASSERT_NOT_CNULLPTR(octal8_tofu);
    fscl_tofu_erase(octal8_tofu);

    ctofu* octal16_tofu = fscl_tofu_create(TOFU_OCTAL16_TYPE, &(ctofu_data){.octal16_type = 017});
    TEST_ASSERT_NOT_CNULLPTR(octal16_tofu);
    fscl_tofu_erase(octal16_tofu);

    ctofu* octal32_tofu = fscl_tofu_create(TOFU_OCTAL32_TYPE, &(ctofu_data){.octal32_type = 033});
    TEST_ASSERT_NOT_CNULLPTR(octal32_tofu);
    fscl_tofu_erase(octal32_tofu);

    ctofu* octal64_tofu = fscl_tofu_create(TOFU_OCTAL64_TYPE, &(ctofu_data){.octal64_type = 070});
    TEST_ASSERT_NOT_CNULLPTR(octal64_tofu);
    fscl_tofu_erase(octal64_tofu);

    // Bitwise types
    ctofu* bitwise8_tofu = fscl_tofu_create(TOFU_BITWISE8_TYPE, &(ctofu_data){.bitwise8_type = 0b1010});
    TEST_ASSERT_NOT_CNULLPTR(bitwise8_tofu);
    fscl_tofu_erase(bitwise8_tofu);

    ctofu* bitwise16_tofu = fscl_tofu_create(TOFU_BITWISE16_TYPE, &(ctofu_data){.bitwise16_type = 0b11001100});
    TEST_ASSERT_NOT_CNULLPTR(bitwise16_tofu);
    fscl_tofu_erase(bitwise16_tofu);

    ctofu* bitwise32_tofu = fscl_tofu_create(TOFU_BITWISE32_TYPE, &(ctofu_data){.bitwise32_type = 0b111100001111});
    TEST_ASSERT_NOT_CNULLPTR(bitwise32_tofu);
    fscl_tofu_erase(bitwise32_tofu);

    ctofu* bitwise64_tofu = fscl_tofu_create(TOFU_BITWISE64_TYPE, &(ctofu_data){.bitwise64_type = 0b11110000111100001111000011110000});
    TEST_ASSERT_NOT_CNULLPTR(bitwise64_tofu);
    fscl_tofu_erase(bitwise64_tofu);

    // Hexadecimal types
    ctofu* hex8_tofu = fscl_tofu_create(TOFU_HEX8_TYPE, &(ctofu_data){.hex8_type = 0xA});
    TEST_ASSERT_NOT_CNULLPTR(hex8_tofu);
    fscl_tofu_erase(hex8_tofu);

    ctofu* hex16_tofu = fscl_tofu_create(TOFU_HEX16_TYPE, &(ctofu_data){.hex16_type = 0xABCD});
    TEST_ASSERT_NOT_CNULLPTR(hex16_tofu);
    fscl_tofu_erase(hex16_tofu);

    ctofu* hex32_tofu = fscl_tofu_create(TOFU_HEX32_TYPE, &(ctofu_data){.hex32_type = 0x12345678});
    TEST_ASSERT_NOT_CNULLPTR(hex32_tofu);
    fscl_tofu_erase(hex32_tofu);

    ctofu* hex64_tofu = fscl_tofu_create(TOFU_HEX64_TYPE, &(ctofu_data){.hex64_type = 0x123456789ABCDEF0});
    TEST_ASSERT_NOT_CNULLPTR(hex64_tofu);
    fscl_tofu_erase(hex64_tofu);

    // Floating-point types
    ctofu* float_tofu = fscl_tofu_create(TOFU_FLOAT_TYPE, &(ctofu_data){.float_type = 3.14f});
    TEST_ASSERT_NOT_CNULLPTR(float_tofu);
    fscl_tofu_erase(float_tofu);

    ctofu* double_tofu = fscl_tofu_create(TOFU_DOUBLE_TYPE, &(ctofu_data){.double_type = 2.71828});
    TEST_ASSERT_NOT_CNULLPTR(double_tofu);
    fscl_tofu_erase(double_tofu);

    // Character type
    ctofu* char_tofu = fscl_tofu_create(TOFU_CHAR_TYPE, &(ctofu_data){.char_type = 'A'});
    TEST_ASSERT_NOT_CNULLPTR(char_tofu);
    fscl_tofu_erase(char_tofu);

    // Boolean type
    ctofu* bool_tofu = fscl_tofu_create(TOFU_BOOLEAN_TYPE, &(ctofu_data){.boolean_type = true});
    TEST_ASSERT_NOT_CNULLPTR(bool_tofu);
    fscl_tofu_erase(bool_tofu);

    // String type
    ctofu* string_tofu = fscl_tofu_create(TOFU_STRING_TYPE, &(ctofu_data){.string_type = "Hello"});
    TEST_ASSERT_NOT_CNULLPTR(string_tofu);
    fscl_tofu_erase(string_tofu);

    // Null pointer type
    ctofu* nullptr_tofu = fscl_tofu_create(TOFU_NULLPTR_TYPE, &(ctofu_data){.nullptr_type = NULL});
    TEST_ASSERT_NOT_CNULLPTR(nullptr_tofu);
    fscl_tofu_erase(nullptr_tofu);

    // Array type
    ctofu* array_tofu = fscl_tofu_create_array(TOFU_ARRAY_TYPE, 3, int_tofu, char_tofu, bool_tofu);
    TEST_ASSERT_NOT_CNULLPTR(array_tofu);
    fscl_tofu_erase_array(array_tofu);

    // Map type
    ctofu* map_tofu = fscl_tofu_create(TOFU_MAP_TYPE, &(ctofu_data){.map_type = {
        .key = int_tofu,
        .value = bool_tofu,
        .size = 1
    }});
    TEST_ASSERT_NOT_CNULLPTR(map_tofu);
    fscl_tofu_erase(map_tofu);

    // Quantum bit type
    ctofu* qbit_tofu = fscl_tofu_create(TOFU_QBIT_TYPE, &(ctofu_data){.qbit_type = 0b1101});
    TEST_ASSERT_NOT_CNULLPTR(qbit_tofu);
    fscl_tofu_erase(qbit_tofu);
}

XTEST_CASE(test_create_array_all_types) {
    // Test creating and erasing for each supported type

    // Integer array type
    ctofu* int_array_tofu = fscl_tofu_create_array(TOFU_INT_TYPE, 3, 1, 2, 3);
    TEST_ASSERT_NOT_CNULLPTR(int_array_tofu);
    fscl_tofu_erase(int_array_tofu);

    // 8-bit Integer array type
    ctofu* int8_array_tofu = fscl_tofu_create_array(TOFU_INT8_TYPE, 3, 8, 16, 32);
    TEST_ASSERT_NOT_CNULLPTR(int8_array_tofu);
    fscl_tofu_erase(int8_array_tofu);

    // 16-bit Integer array type
    ctofu* int16_array_tofu = fscl_tofu_create_array(TOFU_INT16_TYPE, 3, 16, 32, 64);
    TEST_ASSERT_NOT_CNULLPTR(int16_array_tofu);
    fscl_tofu_erase(int16_array_tofu);

    // 32-bit Integer array type
    ctofu* int32_array_tofu = fscl_tofu_create_array(TOFU_INT32_TYPE, 3, 32, 64, 128);
    TEST_ASSERT_NOT_CNULLPTR(int32_array_tofu);
    fscl_tofu_erase(int32_array_tofu);

    // 64-bit Integer array type
    ctofu* int64_array_tofu = fscl_tofu_create_array(TOFU_INT64_TYPE, 3, 64, 128, 256);
    TEST_ASSERT_NOT_CNULLPTR(int64_array_tofu);
    fscl_tofu_erase(int64_array_tofu);

    // Unsigned Integer array type
    ctofu* uint_array_tofu = fscl_tofu_create_array(TOFU_UINT_TYPE, 3, 42, 84, 168);
    TEST_ASSERT_NOT_CNULLPTR(uint_array_tofu);
    fscl_tofu_erase(uint_array_tofu);

    // 8-bit Unsigned Integer array type
    ctofu* uint8_array_tofu = fscl_tofu_create_array(TOFU_UINT8_TYPE, 3, 8, 16, 32);
    TEST_ASSERT_NOT_CNULLPTR(uint8_array_tofu);
    fscl_tofu_erase(uint8_array_tofu);

    // 16-bit Unsigned Integer array type
    ctofu* uint16_array_tofu = fscl_tofu_create_array(TOFU_UINT16_TYPE, 3, 16, 32, 64);
    TEST_ASSERT_NOT_CNULLPTR(uint16_array_tofu);
    fscl_tofu_erase(uint16_array_tofu);

    // 32-bit Unsigned Integer array type
    ctofu* uint32_array_tofu = fscl_tofu_create_array(TOFU_UINT32_TYPE, 3, 32, 64, 128);
    TEST_ASSERT_NOT_CNULLPTR(uint32_array_tofu);
    fscl_tofu_erase(uint32_array_tofu);

    // 64-bit Unsigned Integer array type
    ctofu* uint64_array_tofu = fscl_tofu_create_array(TOFU_UINT64_TYPE, 3, 64, 128, 256);
    TEST_ASSERT_NOT_CNULLPTR(uint64_array_tofu);
    fscl_tofu_erase(uint64_array_tofu);

    // Octal 8-bit array type
    ctofu* octal8_array_tofu = fscl_tofu_create_array(TOFU_OCTAL8_TYPE, 3, 075, 064, 055);
    TEST_ASSERT_NOT_CNULLPTR(octal8_array_tofu);
    fscl_tofu_erase(octal8_array_tofu);

    // Octal 16-bit array type
    ctofu* octal16_array_tofu = fscl_tofu_create_array(TOFU_OCTAL16_TYPE, 3, 0755, 0755, 0755);
    TEST_ASSERT_NOT_CNULLPTR(octal16_array_tofu);
    fscl_tofu_erase(octal16_array_tofu);

    // Octal 32-bit array type
    ctofu* octal32_array_tofu = fscl_tofu_create_array(TOFU_OCTAL32_TYPE, 3, 0755, 0755, 0755);
    TEST_ASSERT_NOT_CNULLPTR(octal32_array_tofu);
    fscl_tofu_erase(octal32_array_tofu);

    // Octal 64-bit array type
    ctofu* octal64_array_tofu = fscl_tofu_create_array(TOFU_OCTAL64_TYPE, 3, 0755, 0755, 0755);
    TEST_ASSERT_NOT_CNULLPTR(octal64_array_tofu);
    fscl_tofu_erase(octal64_array_tofu);

    // Bitwise 8-bit array type
    ctofu* bitwise8_array_tofu = fscl_tofu_create_array(TOFU_BITWISE8_TYPE, 3, 0b1010, 0b0101, 0b1100);
    TEST_ASSERT_NOT_CNULLPTR(bitwise8_array_tofu);
    fscl_tofu_erase(bitwise8_array_tofu);

    // Bitwise 16-bit array type
    ctofu* bitwise16_array_tofu = fscl_tofu_create_array(TOFU_BITWISE16_TYPE, 3, 0b10101010, 0b01010101, 0b11110000);
    TEST_ASSERT_NOT_CNULLPTR(bitwise16_array_tofu);
    fscl_tofu_erase(bitwise16_array_tofu);

    // Bitwise 32-bit array type
    ctofu* bitwise32_array_tofu = fscl_tofu_create_array(TOFU_BITWISE32_TYPE, 3, 0b1010101010101010, 0b0101010101010101, 0b1111000011110000);
    TEST_ASSERT_NOT_CNULLPTR(bitwise32_array_tofu);
    fscl_tofu_erase(bitwise32_array_tofu);

    // Bitwise 64-bit array type
    ctofu* bitwise64_array_tofu = fscl_tofu_create_array(TOFU_BITWISE64_TYPE, 3, 0b10101010101010101010101010101010, 0b01010101010101010101010101010101, 0b11110000111100001111000011110000);
    TEST_ASSERT_NOT_CNULLPTR(bitwise64_array_tofu);
    fscl_tofu_erase(bitwise64_array_tofu);

    // Hexadecimal 8-bit array type
    ctofu* hex8_array_tofu = fscl_tofu_create_array(TOFU_HEX8_TYPE, 3, 0x1F, 0x2A, 0x3C);
    TEST_ASSERT_NOT_CNULLPTR(hex8_array_tofu);
    fscl_tofu_erase(hex8_array_tofu);

    // Hexadecimal 16-bit array type
    ctofu* hex16_array_tofu = fscl_tofu_create_array(TOFU_HEX16_TYPE, 3, 0x1F2A, 0x2A3C, 0x3C1F);
    TEST_ASSERT_NOT_CNULLPTR(hex16_array_tofu);
    fscl_tofu_erase(hex16_array_tofu);

    // Hexadecimal 32-bit array type
    ctofu* hex32_array_tofu = fscl_tofu_create_array(TOFU_HEX32_TYPE, 3, 0x1F2A3C4D, 0x2A3C4D5E, 0x3C4D5E6F);
    TEST_ASSERT_NOT_CNULLPTR(hex32_array_tofu);
    fscl_tofu_erase(hex32_array_tofu);

    // Hexadecimal 64-bit array type
    ctofu* hex64_array_tofu = fscl_tofu_create_array(TOFU_HEX64_TYPE, 3, 0x1F2A3C4D5E6F7A8B, 0x2A3C4D5E6F7A8B9C, 0x3C4D5E6F7A8B9C0D);
    TEST_ASSERT_NOT_CNULLPTR(hex64_array_tofu);
    fscl_tofu_erase(hex64_array_tofu);

    // Floating-point array type (double)
    ctofu* double_array_tofu = fscl_tofu_create_array(TOFU_DOUBLE_TYPE, 3, 3.14, 2.71, 1.618);
    TEST_ASSERT_NOT_CNULLPTR(double_array_tofu);
    fscl_tofu_erase(double_array_tofu);

    // Floating-point array type (float)
    ctofu* float_array_tofu = fscl_tofu_create_array(TOFU_FLOAT_TYPE, 3, 3.14f, 2.71f, 1.618f);
    TEST_ASSERT_NOT_CNULLPTR(float_array_tofu);
    fscl_tofu_erase(float_array_tofu);

    // String array type
    ctofu* string_array_tofu = fscl_tofu_create_array(TOFU_STRING_TYPE, 3, "apple", "banana", "cherry");
    TEST_ASSERT_NOT_CNULLPTR(string_array_tofu);
    fscl_tofu_erase(string_array_tofu);

    // Character array type
    ctofu* char_array_tofu = fscl_tofu_create_array(TOFU_CHAR_TYPE, 3, 'A', 'B', 'C');
    TEST_ASSERT_NOT_CNULLPTR(char_array_tofu);
    fscl_tofu_erase(char_array_tofu);

    // Boolean array type
    ctofu* boolean_array_tofu = fscl_tofu_create_array(TOFU_BOOLEAN_TYPE, 3, true, false, true);
    TEST_ASSERT_NOT_CNULLPTR(boolean_array_tofu);
    fscl_tofu_erase(boolean_array_tofu);

    // Quantum bit array type (64-bit)
    ctofu* qbit_array_tofu = fscl_tofu_create_array(TOFU_QBIT_TYPE, 3, 0b11011010, 0b10101010, 0b01010101);
    TEST_ASSERT_NOT_CNULLPTR(qbit_array_tofu);
    fscl_tofu_erase(qbit_array_tofu);

    // Null pointer array type
    ctofu* nullptr_array_tofu = fscl_tofu_create_array(TOFU_NULLPTR_TYPE, 3, NULL, NULL, NULL);
    TEST_ASSERT_NOT_CNULLPTR(nullptr_array_tofu);
    fscl_tofu_erase(nullptr_array_tofu);

    // Invalid array type (Unknown type)
    ctofu* invalid_array_tofu = fscl_tofu_create_array(TOFU_INVALID_TYPE, 3, NULL, NULL, NULL);
    TEST_ASSERT_NULL(invalid_array_tofu);

    // Unknown array type
    ctofu* unknown_array_tofu = fscl_tofu_create_array(TOFU_UNKNOWN_TYPE, 3, NULL, NULL, NULL);
    TEST_ASSERT_NULL(unknown_array_tofu);

    // Add more test cases for other types as needed
}

XTEST_CASE(test_type_mismatch) {
    // Create a "tofu" structure with one type
    ctofu* tofu = fscl_tofu_create(TOFU_INT_TYPE, NULL);
    TEST_ASSERT_NOT_CNULLPTR(tofu);

    // Try to apply an operation with a different type
    ctofu* wrong_type = fscl_tofu_create(TOFU_FLOAT_TYPE, NULL);
    ctofu_error result = fscl_tofu_compare(tofu, wrong_type);
    TEST_ASSERT_EQUAL(TOFU_WAS_MISMATCH, result);

    // Clean up
    fscl_tofu_erase(tofu);
    fscl_tofu_erase(wrong_type);
}

XTEST_CASE(test_accumulate) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test accumulate
    ctofu_error accumulate_result = fscl_tofu_accumulate(array);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, accumulate_result);

    // Clean up
    fscl_tofu_erase_array(array);
}

XTEST_CASE(test_transform) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test transform
    ctofu_error transform_result = fscl_tofu_transform(array, square_transform_function);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, transform_result);

    // Clean up
    fscl_tofu_erase_array(array);
}

XTEST_CASE(test_sort) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test sort
    ctofu_error sort_result = fscl_tofu_sort(array);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, sort_result);

    // Clean up
    fscl_tofu_erase_array(array);
}

XTEST_CASE(test_search) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test search
    ctofu* key = fscl_tofu_create(TOFU_INT_TYPE, &(ctofu_data){.int_type = 8});
    ctofu_error search_result = fscl_tofu_search(array, key);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, search_result);
    fscl_tofu_erase(key);

    // Clean up
    fscl_tofu_erase_array(array);
}

XTEST_CASE(test_filter) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test filter
    ctofu_error filter_result = fscl_tofu_filter(array, even_filter_function);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, filter_result);

    // Clean up
    fscl_tofu_erase_array(array);
}

XTEST_CASE(test_reverse) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test reverse
    ctofu_error reverse_result = fscl_tofu_reverse(array);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, reverse_result);

    // Clean up
    fscl_tofu_erase_array(array);
}

XTEST_CASE(test_swap) {
    // Create two "tofu" structures with initial values
    ctofu* tofu1 = fscl_tofu_create(TOFU_INT_TYPE, &(ctofu_data){.int_type = 5});
    ctofu* tofu2 = fscl_tofu_create(TOFU_INT_TYPE, &(ctofu_data){.int_type = 8});

    // Test swap
    ctofu_error swap_result = fscl_tofu_swap(tofu1, tofu2);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, swap_result);

    // Clean up
    fscl_tofu_erase(tofu1);
    fscl_tofu_erase(tofu2);
}

XTEST_CASE(test_compare) {
    // Create two "tofu" structures with initial values
    ctofu* tofu1 = fscl_tofu_create(TOFU_INT_TYPE, &(ctofu_data){.int_type = 5});
    ctofu* tofu2 = fscl_tofu_create(TOFU_INT_TYPE, &(ctofu_data){.int_type = 8});

    // Test compare
    ctofu_error compare_result = fscl_tofu_compare(tofu1, tofu2);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, compare_result);

    // Clean up
    fscl_tofu_erase(tofu1);
    fscl_tofu_erase(tofu2);
}

XTEST_CASE(test_reduce) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test reduce
    ctofu_error reduce_result = fscl_tofu_reduce(array, sum_reduce_function);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, reduce_result);

    // Clean up
    fscl_tofu_erase_array(array);
}

XTEST_CASE(test_shuffle) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test shuffle
    ctofu_error shuffle_result = fscl_tofu_shuffle(array);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, shuffle_result);

    // Clean up
    fscl_tofu_erase_array(array);
}

XTEST_CASE(test_for_each) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test for_each
    ctofu_error for_each_result = fscl_tofu_for_each(array, fscl_tofu_out);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, for_each_result);

    // Clean up
    fscl_tofu_erase_array(array);
}

XTEST_CASE(test_partition) {
    // Create a "tofu" array with initial values
    ctofu* array = fscl_tofu_create_array(TOFU_INT_TYPE, 5, 5, 3, 8, 1, 7);

    // Test partition
    ctofu* partitionedResults[2];
    ctofu_error partition_result = fscl_tofu_partition(array, even_partition_function, partitionedResults);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, partition_result);

    // Clean up
    fscl_tofu_erase_array(array);
}


//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_tofu_group) {
    XTEST_NOTE("Running all test cases for tofu:");

    XTEST_RUN_UNIT(test_create_and_erase);
    XTEST_RUN_UNIT(test_create_array_all_types);
    XTEST_RUN_UNIT(test_type_mismatch);
    XTEST_RUN_UNIT(test_accumulate);
    XTEST_RUN_UNIT(test_transform);
    XTEST_RUN_UNIT(test_sort);
    XTEST_RUN_UNIT(test_search);
    XTEST_RUN_UNIT(test_filter);
    XTEST_RUN_UNIT(test_reverse);
    XTEST_RUN_UNIT(test_swap);
    XTEST_RUN_UNIT(test_compare);
    XTEST_RUN_UNIT(test_reduce);
    XTEST_RUN_UNIT(test_shuffle);
    XTEST_RUN_UNIT(test_for_each);
    XTEST_RUN_UNIT(test_partition);

} // end of xdata_test_tofu_group
