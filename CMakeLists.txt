cmake_minimum_required(VERSION 3.0)
project(Game)

add_executable(game src/main.c)
set_property(TARGET game PROPERTY C_STANDARD 90)
if(NOT MSVC)
    target_compile_options(game PRIVATE -Wall -Werror -Wextra -Wpedantic)
endif()
