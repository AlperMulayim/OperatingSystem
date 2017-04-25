cmake_minimum_required(VERSION 3.6)
project(OSHW2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp 8080emu.cpp gtuos.cpp processTableEntry.cpp ProcessTable.cpp memory.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\alper\\ClionProjects\\OSHW2")
add_executable(HW2_Alper_Mulayim ${SOURCE_FILES})