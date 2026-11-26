cmake_minimum_required(VERSION 3.25)
project(wosDB VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Warnings applied to our own targets only (not third-party code).
add_library(wosdb_warnings INTERFACE)
target_compile_options(wosdb_warnings INTERFACE
    -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion)

# The database engine. No third-party dependencies.
add_library(wosdb
    src/version.cpp)
target_include_directories(wosdb PUBLIC include)
target_link_libraries(wosdb PRIVATE wosdb_warnings)

enable_testing()
add_subdirectory(tests)
