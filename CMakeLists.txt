cmake_minimum_required(VERSION 3.0)
project(LoginSystem)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 90)

add_executable(login src/backend.c src/frontend.c src/main.c)
if(NOT MSVC)
    target_compile_options(login PRIVATE -Wall -Wextra -Wpedantic)
endif()
