cmake_minimum_required(VERSION 3.13.4)

# Project configuration

project(SnakePlusPlus CXX)

# Source files list generation

file(GLOB_RECURSE source_files src/*)

# Executable

add_executable(SnakePlusPlus ${source_files})