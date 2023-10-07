
#include "trilobite/xdata/map.h"
#include <stdio.h>

int main() {
    // Create a map of integers to strings
    TriloMap* intToStrMap = trilo_xdata_map_create(INTEGER_TYPE, STRING_TYPE);

    // Insert key-value pairs into the map
    trilo_xdata_map_insert(intToStrMap, trilo_xdata_tofu_create_from_integer(1), trilo_xdata_tofu_create_from_string("One"));
    trilo_xdata_map_insert(intToStrMap, trilo_xdata_tofu_create_from_integer(2), trilo_xdata_tofu_create_from_string("Two"));
    trilo_xdata_map_insert(intToStrMap, trilo_xdata_tofu_create_from_integer(3), trilo_xdata_tofu_create_from_string("Three"));

    // Check if keys exist in the map and retrieve values
    int keyToFind = 2;
    if (trilo_xdata_map_contains(intToStrMap, trilo_xdata_tofu_create_from_integer(keyToFind))) {
        TriloTofu value = trilo_xdata_map_get(intToStrMap, trilo_xdata_tofu_create_from_integer(keyToFind));
        printf("Value for key %d: %s\n", keyToFind, trilo_xdata_tofu_get_string(value));
    } else {
        printf("Key %d does not exist in the map.\n", keyToFind);
    }

    // Check if a non-existent key exists in the map
    int nonExistentKey = 4;
    if (trilo_xdata_map_contains(intToStrMap, trilo_xdata_tofu_create_from_integer(nonExistentKey))) {
        printf("Key %d exists in the map.\n", nonExistentKey);
    } else {
        printf("Key %d does not exist in the map.\n", nonExistentKey);
    }

    // Clean up and destroy the map
    trilo_xdata_map_destroy(intToStrMap);

    return 0;
} // end of func
