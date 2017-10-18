cmake_minimum_required(VERSION 3.0.2)
project(TudocompStats)

set(CMAKE_CXX_STANDARD 11)

if(STATS_DISABLED)
    message("[CAUTION] Statistic tracking is disabled!")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DSTATS_DISABLED")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DSTATS_DISABLED")
endif(STATS_DISABLED)

file(GLOB SOURCE_FILES include/*.hpp src/*.cpp)
add_library(TudocompStats ${SOURCE_FILES})
