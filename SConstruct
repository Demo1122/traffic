import os

env = Environment(
    CXX = 'clang++',
    CXXFLAGS = '-std=c++14',
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

exe = env.Program(target = 'entry', source = sources)
