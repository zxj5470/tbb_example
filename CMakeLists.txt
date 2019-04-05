cmake_minimum_required(VERSION 3.13)
project(tbb)

set(CMAKE_CXX_STANDARD 14)


find_package(TBB)

set(TBB /usr/local/Cellar/tbb/2019_U3_1)
include_directories(${TBB}/include)
link_directories(${TBB}/lib)
add_executable(tbb_main main.cpp)

target_link_libraries(tbb_main tbb)