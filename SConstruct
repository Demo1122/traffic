
env = Environment()

# Set CPPFLAGS
env.Append(CPPFLAGS = '-std=c++0x')

env.VariantDir('build', 'src', duplicate = 0)

target = 'build/entry'
sources = Glob('build/*.cc')

exe = env.Program(target = target, source = sources)