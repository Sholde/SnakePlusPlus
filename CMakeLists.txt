cmake_minimum_required(VERSION 3.13.4)

# Variable

set(EXECUTABLE_NAME SnakePlusPlus)
set(${EXECUTABLE_NAME}_VERSION_MAJOR 0)
set(${EXECUTABLE_NAME}_VERSION_MINOR 1)

# Project configuration

project(${EXECUTABLE_NAME} CXX)

# Source files list generation

file(GLOB_RECURSE source_files src/*)

# Executable

add_executable(${EXECUTABLE_NAME} ${source_files})
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/includes)

# Detect and add SFML

find_package(SFML 2.5.1 COMPONENTS window graphics audio REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} sfml-window sfml-graphics sfml-audio)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/bin)