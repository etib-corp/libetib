cmake_minimum_required(VERSION 3.26.3)

project(sfmlcpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE source_lib 
    "src/2d/*.cpp"
    "src/3d/*.cpp"
)

add_library(sfmlcpp STATIC
    ${source_lib}
)

set_target_properties(sfmlcpp PROPERTIES
	IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libsfmlcpp.a
)

target_include_directories(sfmlcpp PUBLIC include)
