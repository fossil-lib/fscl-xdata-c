/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tlist.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// TEST DATA
//
XTEST_DATA(ProjectTestTListData) {
    TriloTernaryList *tlist;
}tlist_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_tlist_create_and_destroy) {
    // Test creating and destroying a TriloTernaryList
    TriloTernaryList* tlist = trilo_xdata_tlist_create();
    XASSERT_PTR_NOT_NULL(tlist);
    trilo_xdata_tlist_destroy(tlist);
}

XTEST_CASE(xdata_let_tlist_insert_and_search) {
    // Test inserting data into the TriloTernaryList and searching for it
    TriloTernaryList* tlist = trilo_xdata_tlist_create();
    TriloTofu tofu_int = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu_double = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_tlist_insert(tlist, tofu_int);
    trilo_xdata_tlist_insert(tlist, tofu_double);

    XASSERT_BOOL_TRUE(trilo_xdata_tlist_search(tlist, tofu_int));
    XASSERT_BOOL_TRUE(trilo_xdata_tlist_search(tlist, tofu_double));
    XASSERT_BOOL_FALSE(trilo_xdata_tlist_search(tlist, trilo_xdata_tofu_create_from_integer(100)));

    trilo_xdata_tlist_destroy(tlist);
}

XTEST_CASE(xdata_let_tlist_remove) {
    // Test removing data from the TriloTernaryList
    TriloTernaryList* tlist = trilo_xdata_tlist_create();
    TriloTofu tofu_int = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu tofu_double = trilo_xdata_tofu_create_from_double(3.14);

    trilo_xdata_tlist_insert(tlist, tofu_int);
    trilo_xdata_tlist_insert(tlist, tofu_double);

    XASSERT_BOOL_TRUE(trilo_xdata_tlist_search(tlist, tofu_int));
    XASSERT_BOOL_TRUE(trilo_xdata_tlist_search(tlist, tofu_double));

    trilo_xdata_tlist_remove(tlist, tofu_int);
    XASSERT_BOOL_FALSE(trilo_xdata_tlist_search(tlist, tofu_int));
    XASSERT_BOOL_TRUE(trilo_xdata_tlist_search(tlist, tofu_double));

    trilo_xdata_tlist_remove(tlist, tofu_double);
    XASSERT_BOOL_FALSE(trilo_xdata_tlist_search(tlist, tofu_double));

    trilo_xdata_tlist_destroy(tlist);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_tlist_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for tlist:");

    XTEST_RUN_UNIT(xdata_let_tlist_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_tlist_insert_and_search,  runner);
    XTEST_RUN_UNIT(xdata_let_tlist_remove,             runner);
} // end of func
