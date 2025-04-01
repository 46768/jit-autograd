project('jit-autograd', 'c',
  version: '0.0.0')

LIB_DICT = {}
DEPS_DICT = {}

subdir('lib/util')
subdir('lib/math_ir')

build_targets = [
  # name    src       deps names
  ['main', 'main.c', ['math_ir']],
]

foreach target : build_targets
  lib_deps = []
  deps_var = []

  foreach deps : target[2]
    lib_deps += LIB_DICT[deps]
    deps_var += DEPS_DICT[deps]
  endforeach

  executable(target[0], 'src/'+target[1],
    dependencies: deps_var,
    link_with: lib_deps)
endforeach
