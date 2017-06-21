cmake_minimum_required(VERSION 3.0.2)
project(TudocompStats)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE_FILES include/*.hpp src/*.cpp)
add_library(TudocompStats ${SOURCE_FILES})
