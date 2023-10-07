/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tree.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts
#include <stdbool.h>

//
// TEST DATA
//
XTEST_DATA(ProjectTestTreeData) {
    TriloTree *tree;
}tree_data;

//
// XUNIT TEST CASES
//
XTEST_CASE(xdata_let_tree_of_int_create) {
    // Test if a tree is created successfully
    tree_data.tree = trilo_xdata_tree_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);
    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_int_insert) {
    // Test tree insertion of elements
    tree_data.tree = trilo_xdata_tree_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_integer(10));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_int_remove) {
    // Test tree removal of elements
    tree_data.tree = trilo_xdata_tree_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_integer(10));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_remove(tree_data.tree, trilo_xdata_tofu_create_from_integer(10));
    XASSERT_INT_EQUAL(0, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_int_size) {
    // Test tree size after insertion
    tree_data.tree = trilo_xdata_tree_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_integer(10));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_integer(20));
    XASSERT_INT_EQUAL(2, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_int_search) {
    // Test tree searching for elements
    tree_data.tree = trilo_xdata_tree_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_integer(30));

    XASSERT_BOOL_TRUE(trilo_xdata_tree_search(tree_data.tree, trilo_xdata_tofu_create_from_integer(20)));
    XASSERT_BOOL_FALSE(trilo_xdata_tree_search(tree_data.tree, trilo_xdata_tofu_create_from_integer(40)));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_str_create) {
    // Test if a tree is created successfully
    tree_data.tree = trilo_xdata_tree_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);
    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_str_insert) {
    // Test tree insertion of elements
    tree_data.tree = trilo_xdata_tree_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_string("Beef"));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_str_remove) {
    // Test tree removal of elements
    tree_data.tree = trilo_xdata_tree_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_string("Beef"));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_remove(tree_data.tree, trilo_xdata_tofu_create_from_string("Beef"));
    XASSERT_INT_EQUAL(0, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_str_size) {
    // Test tree size after insertion
    tree_data.tree = trilo_xdata_tree_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_string("Beef"));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_string("Fish"));
    XASSERT_INT_EQUAL(2, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_str_search) {
    // Test tree searching for elements
    tree_data.tree = trilo_xdata_tree_create(STRING_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_string("Tea"));
    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_string("Coffee"));
    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_string("Water"));

    XASSERT_BOOL_TRUE(trilo_xdata_tree_search(tree_data.tree, trilo_xdata_tofu_create_from_string("Coffee")));
    XASSERT_BOOL_FALSE(trilo_xdata_tree_search(tree_data.tree, trilo_xdata_tofu_create_from_string("Mint")));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_bool_create) {
    // Test if a tree is created successfully
    tree_data.tree = trilo_xdata_tree_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);
    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_bool_insert) {
    // Test tree insertion of elements
    tree_data.tree = trilo_xdata_tree_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_boolean(true));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_bool_remove) {
    // Test tree removal of elements
    tree_data.tree = trilo_xdata_tree_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_boolean(true));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_remove(tree_data.tree, trilo_xdata_tofu_create_from_boolean(true));
    XASSERT_INT_EQUAL(0, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_bool_size) {
    // Test tree size after insertion
    tree_data.tree = trilo_xdata_tree_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_boolean(true));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_boolean(true));
    XASSERT_INT_EQUAL(2, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_bool_search) {
    // Test tree searching for elements
    tree_data.tree = trilo_xdata_tree_create(BOOLEAN_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_boolean(true));
    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_boolean(true));
    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_boolean(false));

    XASSERT_BOOL_TRUE(trilo_xdata_tree_search(tree_data.tree, trilo_xdata_tofu_create_from_boolean(true)));
    XASSERT_BOOL_FALSE(trilo_xdata_tree_search(tree_data.tree, trilo_xdata_tofu_create_from_boolean(40)));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_char_create) {
    // Test if a tree is created successfully
    tree_data.tree = trilo_xdata_tree_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);
    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_char_insert) {
    // Test tree insertion of elements
    tree_data.tree = trilo_xdata_tree_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_char('X'));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_char_remove) {
    // Test tree removal of elements
    tree_data.tree = trilo_xdata_tree_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_char('X'));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_remove(tree_data.tree, trilo_xdata_tofu_create_from_char('X'));
    XASSERT_INT_EQUAL(0, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_char_size) {
    // Test tree size after insertion
    tree_data.tree = trilo_xdata_tree_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_char('Y'));
    XASSERT_INT_EQUAL(1, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_char('X'));
    XASSERT_INT_EQUAL(2, trilo_xdata_tree_size(tree_data.tree));

    trilo_xdata_tree_destroy(tree_data.tree);
}

XTEST_CASE(xdata_let_tree_of_char_search) {
    // Test tree searching for elements
    tree_data.tree = trilo_xdata_tree_create(CHAR_TYPE);
    XASSERT_PTR_NOT_NULL(tree_data.tree);

    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_char('X'));
    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_char('Y'));
    trilo_xdata_tree_insert(tree_data.tree, trilo_xdata_tofu_create_from_char('Z'));

    XASSERT_BOOL_TRUE(trilo_xdata_tree_search(tree_data.tree, trilo_xdata_tofu_create_from_char('Y')));
    XASSERT_BOOL_FALSE(trilo_xdata_tree_search(tree_data.tree, trilo_xdata_tofu_create_from_char('K')));

    trilo_xdata_tree_destroy(tree_data.tree);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_tree_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for tree:");

    XTEST_RUN_UNIT(xdata_let_tree_of_int_create, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_int_insert, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_int_remove, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_int_size,   runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_int_search, runner);

    XTEST_RUN_UNIT(xdata_let_tree_of_str_create, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_str_insert, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_str_remove, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_str_size,   runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_str_search, runner);

    XTEST_RUN_UNIT(xdata_let_tree_of_char_create, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_char_insert, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_char_remove, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_char_size,   runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_char_search, runner);

    XTEST_RUN_UNIT(xdata_let_tree_of_bool_create, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_bool_insert, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_bool_remove, runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_bool_size,   runner);
    XTEST_RUN_UNIT(xdata_let_tree_of_bool_search, runner);
} // end of func
