cmake_minimum_required(VERSION 3.19)
project(studentManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(studentManager main.cpp src/head/student.h src/head/class.h src/class.cpp src/File.cpp src/head/File.h src/util.cpp src/head/util.h)