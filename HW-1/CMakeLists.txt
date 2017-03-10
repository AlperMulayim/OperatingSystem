cmake_minimum_required(VERSION 3.6)
project(OperatingSystemHW1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp gtuos.cpp 8080emu.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\alper\\ClionProjects\\OperatingSystemHW1")
add_executable(OperatingSystemHW1 ${SOURCE_FILES})