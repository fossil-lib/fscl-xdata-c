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
XTEST_GROUP_EXTERN(xdata_test_flist_group );
XTEST_GROUP_EXTERN(xdata_test_dlist_group );
XTEST_GROUP_EXTERN(xdata_test_tofu_group  );
XTEST_GROUP_EXTERN(xdata_test_tree_group  );
XTEST_GROUP_EXTERN(xdata_test_set_group   );
XTEST_GROUP_EXTERN(xdata_test_map_group   );
XTEST_GROUP_EXTERN(xdata_test_dqueue_group);
XTEST_GROUP_EXTERN(xdata_test_pqueue_group);
XTEST_GROUP_EXTERN(xdata_test_queue_group );
XTEST_GROUP_EXTERN(xdata_test_stack_group );
XTEST_GROUP_EXTERN(xdata_test_vector_group);

//
// XUNIT-TEST RUNNER
//
int main(int argc, char **argv) {
    XUnitRunner runner = XTEST_RUNNER_START(argc, argv);

    XTEST_GROUP_REGISTER(xdata_test_flist_group , runner);
    XTEST_GROUP_REGISTER(xdata_test_dlist_group , runner);
    XTEST_GROUP_REGISTER(xdata_test_tofu_group  , runner);
    XTEST_GROUP_REGISTER(xdata_test_tree_group  , runner);
    XTEST_GROUP_REGISTER(xdata_test_set_group   , runner);
    XTEST_GROUP_REGISTER(xdata_test_map_group   , runner);
    XTEST_GROUP_REGISTER(xdata_test_dqueue_group, runner);
    XTEST_GROUP_REGISTER(xdata_test_pqueue_group, runner);
    XTEST_GROUP_REGISTER(xdata_test_queue_group , runner);
    XTEST_GROUP_REGISTER(xdata_test_stack_group , runner);
    XTEST_GROUP_REGISTER(xdata_test_vector_group, runner);

    return XTEST_RUNNER_END(runner);
} // end of function main
