project('ata_antenna_weights_binary', 'c',
  version: '0.1',
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

lib_ata_antenna_weights_binary = library(
  'ata_antenna_weights_binary',
  src_lst,
  include_directories: inc_lst,
  dependencies: dep_lst,
  install: true,
)

lib_ata_antenna_weights_binary_dep = declare_dependency(
  include_directories: inc_lst,
  dependencies: dep_lst,
  link_with: lib_ata_antenna_weights_binary,
)

subdir('tests')
