cmake_minimum_required(VERSION 3.26.3)

project(sfmlcpp)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLFW_INCLUDE_DIRS})

file(GLOB_RECURSE source_lib
    "src/2d/*.cpp"
    "src/3d/*.cpp"
    "src/utilities/*.cpp"
)

add_library(sfmlcpp STATIC
    ${source_lib}
)

target_link_libraries(sfmlcpp
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
    GL
    ${GLFW_LIBRARIES}
)

set_target_properties(sfmlcpp PROPERTIES
	IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libsfmlcpp.a
)

target_include_directories(sfmlcpp PUBLIC include/2d include/3d include/utilities)
