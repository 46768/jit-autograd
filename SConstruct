build_path = 'build'
lib_build_path = build_path + '/lib'

env = Environment(
        COMPILATIONDB_USE_ABSPATH=True,
        BUILD_PATH=build_path,
        LIB_BUILD_PATH=lib_build_path,
        CPPPATH=[],
        LIBPATH=lib_build_path)
env.Tool('compilation_db')

Export('env')

env.CompilationDatabase()
SConscript('src/SConscript',
           variant_dir=env['BUILD_PATH'],
           duplicate=False,
           exports='env')

SConscript('lib/SConscript',
           variant_dir=env['LIB_BUILD_PATH'],
           duplicate=False,
           exports='env')
