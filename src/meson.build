source = files(
    'package.c')

lib = library('trilo-c',
    source,
    include_directories: dir)

trilo_c_dep = declare_dependency(link_with: lib,
    include_directories: dir)
