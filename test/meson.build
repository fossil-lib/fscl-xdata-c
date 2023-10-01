if get_option('with_tests').enabled()
    test_deps = [
        dependency('trilo-xtest-c'),
        dependency('trilo-xmock-c')
    ]

    test('Execute project Xunit tests', 
        executable('xrunner', 'test_cases.c',
        dependencies : [test_deps, trilo_xdata_c_dep]))
endif
