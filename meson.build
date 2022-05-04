project('temp', 'c',
  version: '0.0',
)

cc = meson.get_compiler('c')
# m_dep = cc.find_library('m', required : true)

src_lst = []
inc_lst = [
    include_directories('include')    
]
dep_lst = []

subdir('include')
subdir('src')

lib_temp = library(
  'temp',
  src_lst,
  include_directories: inc_lst,
  dependencies: dep_lst,
  install: true,
)

lib_temp_dep = declare_dependency(
  include_directories: inc_lst,
  dependencies: dep_lst,
  link_with: lib_temp,
)

subdir('tests')
