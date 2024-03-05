code = files(
    'queue.c', 'pqueue.c', 'dqueue.c',
    'flist.c', 'dlist.c' , 'tree.c'  ,
    'set.c'  , 'stack.c' , 'map.c'   ,
    'vector.c')

lib = static_library('fscl-xdata-c',
    code,
    dependencies : dependency('fscl-xtofu-c'),
    include_directories: dir)

fscl_xdata_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
