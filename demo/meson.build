if get_option('with_demos').enabled()
    demo_srcs = [
        'queue.c', 'pqueue.c', 'dqueue.c',
        'flist.c', 'dlist.c' , 'tree.c'  ,
        'set.c'  , 'stack.c' , 'tofu.c']

    foreach iter : demo_srcs
        executable('demo_' + iter, 'demo_' + iter, dependencies : [trilo_xcore_c_dep])
    endforeach
endif