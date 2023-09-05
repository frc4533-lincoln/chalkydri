#!/bin/sh

#
# .clangd-- The main config file

echo -e "CompileFlags:\n  Compiler: $CXX\n  CompilationDatabase: .\n" > .clangd

#
# compile_flags.txt-- The CXXFLAGS used to build the project

# This awk command both seems to work and is somewhat understandable
echo "$CXXFLAGS" | awk -F' ' '{ for (i=0; i<NF; i++) { print $(i+1) } }' - > compile_flags.txt

