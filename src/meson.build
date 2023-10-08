source = files(
    'queue.c', 'pqueue.c', 'dqueue.c',
    'flist.c', 'dlist.c' , 'tree.c'  ,
    'set.c'  , 'stack.c' , 'tofu.c')

trilo_xdata_c_lib = library('trilo-xdata-c',
    source,
    include_directories: dir)

trilo_xdata_c_dep = declare_dependency(
    link_with: trilo_xdata_c_lib,
    include_directories: dir)
