cmake_minimum_required(VERSION 3.6)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

project(ExternalDLL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

file(GLOB SOURCE_FILES
        "*.h"
        "*.cpp"
        )

add_executable(ExternalDLL ${SOURCE_FILES})
target_link_libraries( ExternalDLL ${OpenCV_LIBS} )