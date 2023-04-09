cmake_minimum_required(VERSION 3.0)
project(LoginSystem)

set(CMAKE_BUILD_TYPE Debug)

add_executable(login src/backend.c src/frontend.c src/main.c)

set_property(TARGET login PROPERTY C_STANDARD 90)

# target_compile_definitions(login PRIVATE LOGIN_USE_SQL)
target_compile_options(login PRIVATE -Wall -Wextra -Wpedantic)

find_package(PkgConfig)
pkg_check_modules(SQLITE REQUIRED sqlite3)
target_link_libraries(login ${SQLITE_LIBRARIES})
