/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/hash.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestHashData) {
    TriloHash *hash;
}hash_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_hash_create_and_destroy) {
    // Test creating and destroying a TriloHash
    hash_data.hash = trilo_xdata_hash_create(INTEGER_TYPE, 10);
    XASSERT_PTR_NOT_NULL(hash_data.hash);
    XASSERT_INT_EQUAL(INTEGER_TYPE, hash_data.hash->hash_type);
    XASSERT_INT_EQUAL(10, hash_data.hash->table_size);
    trilo_xdata_hash_destroy(hash_data.hash);
}

XTEST_CASE(xdata_let_hash_insert_and_find) {
    // Test inserting and finding key-value pairs in the TriloHash
    hash_data.hash = trilo_xdata_hash_create(INTEGER_TYPE, 10);

    TriloTofu key1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value1 = trilo_xdata_tofu_create_from_string("One");

    TriloTofu key2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu value2 = trilo_xdata_tofu_create_from_string("Two");

    trilo_xdata_hash_insert(hash_data.hash, key1, value1);
    trilo_xdata_hash_insert(hash_data.hash, key2, value2);

    XASSERT_EQUAL_STRING("One", trilo_xdata_tofu_get_string(trilo_xdata_hash_find(hash_data.hash, key1)));
    XASSERT_EQUAL_STRING("Two", trilo_xdata_tofu_get_string(trilo_xdata_hash_find(hash_data.hash, key2)));

    trilo_xdata_hash_destroy(hash_data.hash);
}

XTEST_CASE(xdata_let_hash_key_not_found) {
    // Test finding a key that does not exist in the TriloHash
    hash_data.hash = trilo_xdata_hash_create(INTEGER_TYPE, 10);

    TriloTofu key = trilo_xdata_tofu_create_from_integer(1);

    // Attempting to find a key that does not exist should return NULL
    XASSERT_PTR_NULL(trilo_xdata_hash_find(hash_data.hash, key));

    trilo_xdata_hash_destroy(hash_data.hash);
}

XTEST_CASE(xdata_let_hash_type_mismatch) {
    // Test inserting key-value pairs of different types in the TriloHash
    hash_data.hash = trilo_xdata_hash_create(INTEGER_TYPE, 10);

    TriloTofu key = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu value = trilo_xdata_tofu_create_from_double(3.14);

    // Attempting to insert a value of a different type should result in an error
    XASSERT_INT_EQUAL(TRILO_XDATA_HASH_TYPE_MISMATCH, trilo_xdata_hash_insert(hash_data.hash, key, value));

    trilo_xdata_hash_destroy(hash_data.hash);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_hash_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for hash:");

    XTEST_RUN_UNIT(xdata_let_hash_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_hash_insert_and_find,    runner);
    XTEST_RUN_UNIT(xdata_let_hash_key_not_found,      runner);
    XTEST_RUN_UNIT(xdata_let_hash_type_mismatch,      runner);
} // end of func
