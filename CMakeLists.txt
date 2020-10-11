cmake_minimum_required(VERSION 3.4.1)

project(tinygpx)

set(tinygpx_sources
    src/gpx_document.cpp
    src/route.cpp
    src/waypoint.cpp)

add_library(tinygpx ${tinygpx_sources})

target_include_directories(tinygpx
    PUBLIC include)

target_compile_options(tinygpx
        PRIVATE
        -std=c++17
        -Wall
        -Wextra-semi
        -Wshadow
        -Ofast)

target_link_libraries(tinygpx PRIVATE tinyxml2)

install(TARGETS tinygpx
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

# Also install the headers
install(DIRECTORY include/tinygpx DESTINATION include)