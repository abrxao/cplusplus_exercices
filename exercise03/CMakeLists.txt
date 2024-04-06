cmake_minimum_required(VERSION 3.8)

project(CoolProject)

add_executable(main
  main.cpp

  # Remove funcs.h and funcs.cpp from here
  funcs.h
  funcs.cpp
  )


# Add the "add_library" command and include funcs.h and funcs.cpp in the library



# Add the target_link_libraries command to link the "main" target with your new library
