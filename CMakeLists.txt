cmake_minimum_required(VERSION 3.6)
project(Hulk)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES coroutine.cpp coroutine.h schedule.cpp schedule.h test.cpp noncopyable.h)
add_executable(hulk ${SOURCE_FILES})