cmake_minimum_required(VERSION 3.6)
project(GTUOSProcess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp 8080emu.cpp gtuos.cpp memoryOS.cpp memoryOS.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\alper\\ClionProjects\\GTUOSProcess")
add_executable(GTUOSProcess ${SOURCE_FILES})