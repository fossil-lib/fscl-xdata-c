/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/flist.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test TriloForwardList creation and destruction
XTEST_CASE(xdata_let_flist_create_and_destroy) {
    TriloForwardList* flist = trilo_xdata_flist_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(flist);

    trilo_xdata_flist_destroy(flist);
    XASSERT_PTR_NULL(flist);
}

// Test case 2: Test TriloForwardList insertion and retrieval
XTEST_CASE(xdata_let_flist_insert_and_get) {
    TriloForwardList* flist = trilo_xdata_flist_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(flist);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    TofuError result = trilo_xdata_flist_insert(flist, tofu);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_flist_getter(flist, tofu);
    XASSERT_PTR_NOT_NULL(retrieved_tofu);
    XASSERT_INT_EQUAL(42, trilo_xdata_tofu_get_integer(*retrieved_tofu));

    trilo_xdata_flist_destroy(flist);
}

// Test case 3: Test TriloForwardList removal
XTEST_CASE(xdata_let_flist_remove) {
    TriloForwardList* flist = trilo_xdata_flist_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(flist);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    TofuError result = trilo_xdata_flist_insert(flist, tofu);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_flist_remove(flist, tofu);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_flist_getter(flist, tofu);
    XASSERT_PTR_NULL(retrieved_tofu);

    trilo_xdata_flist_destroy(flist);
}

// Test case 4: Test TriloForwardList size
XTEST_CASE(xdata_let_flist_size) {
    TriloForwardList* flist = trilo_xdata_flist_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(flist);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_flist_insert(flist, tofu1);
    trilo_xdata_flist_insert(flist, tofu2);
    trilo_xdata_flist_insert(flist, tofu3);

    size_t size = trilo_xdata_flist_size(flist);
    XASSERT_INT_EQUAL(3, size);

    trilo_xdata_flist_destroy(flist);
}

// Test case 5: Test TriloForwardList empty check
XTEST_CASE(xdata_let_flist_empty_check) {
    TriloForwardList* flist = trilo_xdata_flist_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(flist);

    XASSERT_BOOL_TRUE(trilo_xdata_flist_is_empty(flist));
    XASSERT_BOOL_FALSE(trilo_xdata_flist_not_empty(flist));

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_flist_insert(flist, tofu);

    XASSERT_BOOL_FALSE(trilo_xdata_flist_is_empty(flist));
    XASSERT_BOOL_TRUE(trilo_xdata_flist_not_empty(flist));

    trilo_xdata_flist_destroy(flist);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_flist_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for flist:");

    XTEST_RUN_UNIT(xdata_let_flist_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_flist_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_flist_insert_and_get,     runner);
    XTEST_RUN_UNIT(xdata_let_flist_remove,             runner);
    XTEST_RUN_UNIT(xdata_let_flist_size,               runner);
} // end of func
