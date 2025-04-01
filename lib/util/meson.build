# Define library data here
lib_name = 'util_lib'
src = [
  'src/logger.c',
]
dependencies = []


# Declares the library

lib_deps = []
deps_var = []

foreach deps : dependencies
  lib_deps += LIB_DICT[deps]
  deps_var += DEPS_DICT[deps]
endforeach

LIB_DICT += {
  lib_name: library(lib_name, src,
  include_directories: include_directories('./header'),
  dependencies: deps_var,
  link_with: lib_deps,)
}
DEPS_DICT += {
  lib_name: declare_dependency(
    include_directories: include_directories('./header'),
    link_with: [LIB_DICT[lib_name]],
    dependencies: deps_var,)
}
