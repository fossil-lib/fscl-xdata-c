
#include "trilobite/xdata/hash.h"
#include <stdio.h>
#include <string.h>

// Custom hash function for string keys
unsigned int custom_hash(const void *key) {
    const char *str = (const char *)key;
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + (*str++);
    }
    return hash;
} // end of func

// Custom key comparison function for string keys
int custom_key_compare(const void *key1, const void *key2) {
    return strcmp((const char *)key1, (const char *)key2);
} // end of func

int main() {
    // Create a hash table of string keys to integer values
    TriloHash *strToIntHash = trilo_xdata_hash_create(STRING_TYPE, INTEGER_TYPE, custom_hash, custom_key_compare);

    // Insert key-value pairs into the hash table
    trilo_xdata_hash_insert(strToIntHash, trilo_xdata_tofu_create_from_string("one"), trilo_xdata_tofu_create_from_integer(1));
    trilo_xdata_hash_insert(strToIntHash, trilo_xdata_tofu_create_from_string("two"), trilo_xdata_tofu_create_from_integer(2));
    trilo_xdata_hash_insert(strToIntHash, trilo_xdata_tofu_create_from_string("three"), trilo_xdata_tofu_create_from_integer(3));

    // Check if keys exist in the hash table and retrieve values
    const char *keyToFind = "two";
    if (trilo_xdata_hash_contains(strToIntHash, trilo_xdata_tofu_create_from_string(keyToFind))) {
        TriloTofu value = trilo_xdata_hash_get(strToIntHash, trilo_xdata_tofu_create_from_string(keyToFind));
        printf("Value for key '%s': %d\n", keyToFind, trilo_xdata_tofu_get_integer(value));
    } else {
        printf("Key '%s' does not exist in the hash table.\n", keyToFind);
    }

    // Check if a non-existent key exists in the hash table
    const char *nonExistentKey = "four";
    if (trilo_xdata_hash_contains(strToIntHash, trilo_xdata_tofu_create_from_string(nonExistentKey))) {
        printf("Key '%s' exists in the hash table.\n", nonExistentKey);
    } else {
        printf("Key '%s' does not exist in the hash table.\n", nonExistentKey);
    }

    // Clean up and destroy the hash table
    trilo_xdata_hash_destroy(strToIntHash);

    return 0;
} // end of func
