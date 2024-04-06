cmake_minimum_required(VERSION 3.8)

project(CoolProject)

add_executable(main
  main.cpp
  )

add_library(lib
  funcs.h
  funcs.cpp
)

target_link_libraries(main lib)

