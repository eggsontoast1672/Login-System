cmake_minimum_required(VERSION 3.0)
project(LoginSystem)

set(CMAKE_BUILD_TYPE Debug)

add_executable(login src/main.c)
set_property(TARGET login PROPERTY C_STANDARD 90)
if(NOT MSVC)
    target_compile_options(login PRIVATE -Wall -Werror -Wextra -Wpedantic)
endif()
