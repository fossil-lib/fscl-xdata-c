/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include <trilobite/xtest.h>   // basic test tools

//
// XUNIT-TEST GROUPS
//
extern void xdata_test_flist_group (XUnitRunner *runner);
extern void xdata_test_dlist_group (XUnitRunner *runner);
extern void xdata_test_tlist_group (XUnitRunner *runner);
extern void xdata_test_hash_group  (XUnitRunner *runner);
extern void xdata_test_dict_group  (XUnitRunner *runner);
extern void xdata_test_tofu_group  (XUnitRunner *runner);
extern void xdata_test_tree_group  (XUnitRunner *runner);
extern void xdata_test_set_group   (XUnitRunner *runner);
extern void xdata_test_map_group   (XUnitRunner *runner);
extern void xdata_test_dqueue_group(XUnitRunner *runner);
extern void xdata_test_pqueue_group(XUnitRunner *runner);
extern void xdata_test_queue_group (XUnitRunner *runner);
extern void xdata_test_stack_group (XUnitRunner *runner);
extern void xdata_test_array_group (XUnitRunner *runner);
extern void xdata_test_graph_group (XUnitRunner *runner);
extern void xdata_test_matrix_group(XUnitRunner *runner);
extern void xdata_test_tuple_group (XUnitRunner *runner);
extern void xdata_test_vector_group(XUnitRunner *runner);

//
// XUNIT-TEST RUNNER
//
int main(int argc, char **argv) {
    XUnitRunner runner = XTEST_RUNNER_START(argc, argv);

    xdata_test_flist_group(&runner);
    xdata_test_dlist_group(&runner);
    xdata_test_tlist_group(&runner);
    xdata_test_hash_group(&runner);
    xdata_test_dict_group(&runner);
    xdata_test_tofu_group(&runner);
    xdata_test_tree_group(&runner);
    xdata_test_set_group(&runner);
    xdata_test_map_group(&runner);
    xdata_test_dqueue_group(&runner);
    xdata_test_pqueue_group(&runner);
    xdata_test_queue_group(&runner);
    xdata_test_stack_group(&runner);
    xdata_test_array_group(&runner);
    xdata_test_graph_group(&runner);
    xdata_test_matrix_group(&runner);
    xdata_test_tuple_group(&runner);
    xdata_test_vector_group(&runner);

    return XTEST_RUNNER_END(runner);
} // end of function main
