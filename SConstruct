import os

cxxflags = [
    '-std=c++14',
    '-Wall',
]

env = Environment(
    CXX = 'clang++',
    CXXFLAGS = cxxflags,
    CPPPATH = 'include'
)

# This enables colored clang output
env['ENV']['TERM'] = os.environ['TERM']

# Create build directory for output
env.VariantDir('build', 'src', duplicate = 0)

# Add source folders and glob their files
source_folders = [
    'build',
    'build/seed',
]

sources = []
for path in source_folders:
    sources.extend(Glob(path + '/*.cc'))

exe = env.Program(target = 'main', source = sources)
