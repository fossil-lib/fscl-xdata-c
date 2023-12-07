code = files(
    'queue.c', 'pqueue.c', 'dqueue.c',
    'flist.c', 'dlist.c' , 'tree.c'  ,
    'set.c'  , 'stack.c' , 'map.c'   ,
    'vector.c', 'tofu.c')

lib = static_library('trilo-xdata-c',
    code,
    include_directories: dir)

trilo_xdata_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
