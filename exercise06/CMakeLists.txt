cmake_minimum_required(VERSION 3.8)

project(CoolProject)

add_executable(main
  main.cpp
  )


add_library(mylib
  funcs.h
  funcs.cpp)

target_link_libraries(main mylib)

target_include_directories(main SYSTEM PUBLIC ../external/armadillo-9.100.5/include)
