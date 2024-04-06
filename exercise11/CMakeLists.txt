cmake_minimum_required(VERSION 3.8)

project(CoolProject)

# In this exercise we use some features only available since C++17, such as
# structured bindings
set(CMAKE_CXX_STANDARD 17)

# These two lines are a good practice to make sure we only use standard C++ and
# don't include, for instance, GCC extensions that are not valid in other
# compilers.
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main
  main.cpp
  )


add_library(mylib
  RegularPolygon.h
  RegularPolygon.cpp
  Triangle.h
  Triangle.cpp
  Hexagon.h
  Hexagon.cpp
  )

target_link_libraries(main mylib)
