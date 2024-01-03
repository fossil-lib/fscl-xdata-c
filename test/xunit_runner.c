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
#include <fossil/xtest.h>   // basic test tools

//
// XUNIT-TEST GROUPS
//
XTEST_EXTERN_POOL(xdata_test_flist_group );
XTEST_EXTERN_POOL(xdata_test_dlist_group );
XTEST_EXTERN_POOL(xdata_test_tofu_group  );
XTEST_EXTERN_POOL(xdata_test_tree_group  );
XTEST_EXTERN_POOL(xdata_test_set_group   );
XTEST_EXTERN_POOL(xdata_test_map_group   );
XTEST_EXTERN_POOL(xdata_test_dqueue_group);
XTEST_EXTERN_POOL(xdata_test_pqueue_group);
XTEST_EXTERN_POOL(xdata_test_queue_group );
XTEST_EXTERN_POOL(xdata_test_stack_group );
XTEST_EXTERN_POOL(xdata_test_vector_group);

//
// XUNIT-TEST RUNNER
//
int main(int argc, char **argv) {
    XTEST_CREATE(argc, argv);

    XTEST_IMPORT_POOL(xdata_test_flist_group);
    XTEST_IMPORT_POOL(xdata_test_dlist_group);
    XTEST_IMPORT_POOL(xdata_test_tofu_group );
    XTEST_IMPORT_POOL(xdata_test_tree_group );
    XTEST_IMPORT_POOL(xdata_test_set_group  );
    XTEST_IMPORT_POOL(xdata_test_map_group  );
    XTEST_IMPORT_POOL(xdata_test_dqueue_group);
    XTEST_IMPORT_POOL(xdata_test_pqueue_group);
    XTEST_IMPORT_POOL(xdata_test_queue_group );
    XTEST_IMPORT_POOL(xdata_test_stack_group );
    XTEST_IMPORT_POOL(xdata_test_vector_group);

    return XTEST_ERASE();
} // end of function main
