cmake_minimum_required(VERSION 3.12)

set(ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}/../../)
set(CMAKE_TOOLCHAIN_FILE ${ROOT_DIR}/toolchain-rv32.cmake)

project(hello_world)

add_executable(hello_world hello_world.c)

add_subdirectory(${ROOT_DIR}/common common)
target_link_libraries(hello_world PRIVATE common)
# Force linking of _write from syscalls.c
target_link_options(hello_world PUBLIC -Wl,--undefined=_write)

target_compile_options(hello_world PUBLIC -Wall -Werror -Wextra)

include(${ROOT_DIR}/utils.cmake)
add_linker_scripts(hello_world)
add_map_file(hello_world hello_world.map)
make_binary(hello_world hello_world.bin)
