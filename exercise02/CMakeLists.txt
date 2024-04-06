cmake_minimum_required(VERSION 3.8)

project(DoubleProject)

add_executable(my_program 
  main.cpp)

add_library(my_library 
  funcs.h
  funcs.cpp)

# Include directory
target_link_libraries(my_program my_library)