if get_option('with_demo').enabled()
    demo_srcs = [
        'queue', 'pqueue', 'dqueue',
        'flist', 'dlist' , 'tree'  ,
        'set'  , 'stack' , 'map',
        'vector', 'tofu']

    foreach iter : demo_srcs
        executable('demo_' + iter, 'demo_' + iter + '.c', dependencies : [tscl_xdata_c_dep])
    endforeach
endif
