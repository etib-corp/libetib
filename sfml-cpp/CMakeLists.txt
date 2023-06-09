cmake_minimum_required(VERSION 3.26.3)

project(first)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE source_files "src/*")

add_executable(first ${source_files})

target_link_libraries(first sfml-graphics sfml-window sfml-system)
target_include_directories(first PUBLIC include)
