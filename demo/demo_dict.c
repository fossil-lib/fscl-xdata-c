
#include "trilobite/xdata/dict.h"
#include <stdio.h>

int main() {
    // Create a dictionary of string keys to integer values
    TriloDict* strToIntDict = trilo_xdata_dict_create(STRING_TYPE, INTEGER_TYPE);

    // Insert key-value pairs into the dictionary
    trilo_xdata_dict_insert(strToIntDict, trilo_xdata_tofu_create_from_string("one"), trilo_xdata_tofu_create_from_integer(1));
    trilo_xdata_dict_insert(strToIntDict, trilo_xdata_tofu_create_from_string("two"), trilo_xdata_tofu_create_from_integer(2));
    trilo_xdata_dict_insert(strToIntDict, trilo_xdata_tofu_create_from_string("three"), trilo_xdata_tofu_create_from_integer(3));

    // Check if keys exist in the dictionary and retrieve values
    const char* keyToFind = "two";
    if (trilo_xdata_dict_contains(strToIntDict, trilo_xdata_tofu_create_from_string(keyToFind))) {
        TriloTofu value = trilo_xdata_dict_get(strToIntDict, trilo_xdata_tofu_create_from_string(keyToFind));
        printf("Value for key '%s': %d\n", keyToFind, trilo_xdata_tofu_get_integer(value));
    } else {
        printf("Key '%s' does not exist in the dictionary.\n", keyToFind);
    }

    // Check if a non-existent key exists in the dictionary
    const char* nonExistentKey = "four";
    if (trilo_xdata_dict_contains(strToIntDict, trilo_xdata_tofu_create_from_string(nonExistentKey))) {
        printf("Key '%s' exists in the dictionary.\n", nonExistentKey);
    } else {
        printf("Key '%s' does not exist in the dictionary.\n", nonExistentKey);
    }

    // Clean up and destroy the dictionary
    trilo_xdata_dict_destroy(strToIntDict);

    return 0;
} // end of func
