if get_option('with_tests').enabled()
    test_deps = [
        dependency('trilo-xtest-c'),
        dependency('trilo-xmock-c')
    ]

    test_src = files(
        'xtest_queue.c' , 'xtest_pqueue.c', 'xtest_dqueue.c',
        'xtest_flist.c' , 'xtest_dlist.c' , 'xtest_tree.c'  ,
        'xtest_set.c'   , 'xtest_stack.c' , 'xtest_tofu.c'  ,
        'xunit_runner.c')

    test('Execute project Xunit tests', 
        executable('xrunner', test_src,
        dependencies : [test_deps, trilo_xdata_c_dep]))
endif
