cmake_minimum_required(VERSION 3.0)
project(KassiDebugger)

add_compile_options(-std=c++14)

include_directories(external/libelfin external/linenoise include)
add_executable(kdb src/kdb.cpp external/linenoise/linenoise.c)

# Compile C++ programs in the "samples" directory
add_executable(hello samples/hello.cpp)
set_target_properties(hello
        PROPERTIES COMPILE_FLAGS "-g -O0")

add_executable(variable samples/variable.cpp)
set_target_properties(variable
        PROPERTIES COMPILE_FLAGS "-gdwarf-2 -O0")

add_executable(unwinding samples/stack_unwinding.cpp)
set_target_properties(unwinding
        PROPERTIES COMPILE_FLAGS "-g -O0")


add_custom_target(
        libelfin
        COMMAND make
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/external/libelfin
)

# When linking kdb use the listed shared objects
target_link_libraries(kdb
        ${PROJECT_SOURCE_DIR}/external/libelfin/dwarf/libdwarf++.so
        ${PROJECT_SOURCE_DIR}/external/libelfin/elf/libelf++.so)

#
add_dependencies(kdb libelfin)