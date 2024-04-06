

This is repository acts as a checklist for people that know programming, but
haven't worked with C++ (ever, or recently). These are not focused on teaching,
but rather to identify familiarity with some of the language constructs in order
for you to focus on what you should study.

**NOTE**: The objective of these exercises is to expose you to parts
of the C++ language used in GTEL's system level simulator in an
isolated way. You are expected to search and read about things you
don't understand in any of the exercises.

Each exercise is built on the last one and it can be somewhat
considered a solution to the previous exercise. Avoid using an IDE for
these exercises (at least until exercise 4). Write the code in a text
editor and compile and run CMake manually in a terminal. In order to
do that, in each exercise folder you should create a "build" folder
and the build folder run the command `cmake ..` in a terminal (once)
and then `cmake --build .` to compile the code.

## Exercises 0

 - Clone the repository with these exercises (well, ..., you just did that)
 - Create a branch for you to work on these exercises

## Exercise 1

 - Create a simple project with CMake
   - Create the `CMakeLists.txt` file
   - Fill the `CMakeLists.txt` file in order to create an executable
     target that includes `main.cpp`

## Exercise 2

 - Add more files to your project
 - Implement a simple function called `doubleInput` that receives a
   `double` input and return the double of the input
   - The function should be declared in `funcs.h` and implemented in `funcs.h`

## Exercise 3

 - Change the CMake configuration such that `funcs.h` and `funcs.cpp` are now in a
   separated library
 - Link the "main" target with your library using the
   `target_link_libraries` command in `CMakeLists.txt`.

## Exercise 4

 - Create a `std::vector` of `double`s in `main.cpp` and initialize it
   with several numbers
 - Generate a new vector whose elements are the doubles of the first
   vector elements
   - Use the `doubleInput` function from before

## Exercise 5

 - Create a lambda function that double the input in your `main.cpp` file and call
   it instead of `doubleInput`
 - Create a second lambda function that receives a double and captures
   the `numTimes` variable. This new lambda function should return the
   input times `numTimes`

## Exercise 6

 - Change the program to use armadillo `vec` instead of `std::vector<double>`
 - Armadillo containers, such as `vec`, `mat`, etc, work with many math operations,
   including multiplication
   - Change the code to have two armadillo vectors where the second one has
     the double of the elements of the first one
   - Armadillo containers have a "`print`" method you can use to print the
     elements instead of using a for loop

 **TIP:** Armadillo source code is included in this repository and the command
 "`target_include_directories`" was already included in CMakeLists.txt for you in
 order to make "`#include <armadillo>`" work. However, in the simulator instead of
 including the source code of external dependencies in the repository we use the
 conan C++ package manager for that (later exercise)


## Exercise 7

 - Play around with other armadillo types such as, `mat`, `vec`, `cx_mat`, `cx_vec`,
   etc.
 - Read [armadillo documentation](https://arma.sourceforge.net/docs.html) on how to
   access elements, how to get one column of a matrix, how to compute an SVD, how to
   generate a vector using `linspace` function, etc.

## Exercise 8

 - In the `main.cpp` file two `unordered_map`s were already created for you
     - One has `std::string` as keys and `std::vector<double>` as values.
     - The other has `std::string` as keys and `std::vector<int>` as values.

 - Insert multiple elements in both maps (note that each element is a
   vector with many elements)

 - Use the `printVector` function already implement to print the
   vector for each key in the first map.
 - The `printVector` function does not work to print one of the values
   in the second map, since it only accept `std::vector<double>`
   - Adapt the `printVector` function such that it works for any
     `std::vector`.
     - **TIP:** Make the `printVector` function a template

 **TIP:** Some other useful containers in the standard library are
 `std::pair` and `std::tuple`. Play a bit with them as well.

## Exercise 9
 - In this exercise you won't do much, but it has much content to be understood.
 - This exercise starts with some code to implement the previous
   exercise. take some time to understand how it works and compare
   with your own solution to the previous exercise.
   - It uses initializer lists to initialize the vectors
   - It uses a "range for" to iterate the map for the key and the value
     - Then it breaks the key and the value using C++17 structured binding

 - Did you notice the `std::move` function? Do you understand its
   purpose?
   - Print the vector "someOtherVec" before and after the call to `std::move` and
     see what happened to someOtherVec.

## Exercise 10

 - Implement a `Triangle` class and an `Hexagon` class that inherits from `RegularPolygon`.
 - Implement the `calcArea` method in these two subclasses.


## Exercise 11

 - Create a vector of pointers of `RegularPolygon` objects, some of them
   triangles, some of them hexagons
   - Use a smart pointer such as `unique_ptr` instead of raw pointers
 - Iterate on this vector and call the `calcArea` method for each
   element

 **NOTE:** In order to use polymorphism you need to either use
 pointers or references, where using pointers is the most usual
 approach. That is why a vector of concrete objects would not work
 here. In that case it is better to use a smart pointer to manager the
 memory for us. That is why in `main.cpp` a vector of `unique_ptr` was
 used.

## Exercise 12

 - Make methods in `RegularPolygon` and its subclasses `const` whenever possible
   - Any method that does not change the state of the object should be `const`
 - Make `Triangle` and `Hexagon` constructors `explicit`
   - **TIP:** It's a good practice to declare constructors with a single argument
     `explicit`

## Extra Exercise: Conan package manager

For this exercise we will use the conan package manager and CMake
presets.
- [Install conan](https://docs.conan.io/2/installation.html) package manager
- After installing conan, run the command `conan profile detect` to
  create the default profile.
  - **TIP:** Check the generate profile in `.conan2/profiles/`
- Now let's use conan to install a dependence that we will use in C++.
  Create a `conanfile.txt` file with the following content (in the
  exercise folder)

  ```
  [requires]
  catch2/3.5.3

  [generators]
  CMakeDeps
  CMakeToolchain

  [options]


  [layout]
  cmake_layout
  ```

  Now run the command `conan install . --build=missing` to install the
  catch2 library.

- **Note:** Conan installs the dependencies in its "local cache",
  which is inside the `~/.conan2/` folder. We will need to tell the
  C++ compiler how to find these dependencies there.

- Up to now, you had to run `cmake ..` from inside the build folder,
  to generate the build files inside the build folder. CMake has a
  feature called [cmake
  presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html)
  and conan uses this feature to set a "toolchain", which will allow
  the compiler to find the headers and libraries installed by conan.
  - In other words, conan generated a "presets" file (likely called
    `CMakeUserPresets.json`, but it can also be `CMakePresets.json`),
    which we will use with CMake.
  - Run the command `cmake --list-presets` to list the available
    presets. You will see a preset named something like
    `conan-release` or `conan-debug` (depending on the `build_type`
    value in your default conan profile)
- Run cmake with `cmake --preset <preset-name>` with the correct "preset name"
  - **Note**: You need to run the command from the root exercise
    folder, and not from the build folder.
- Likewise, you can build the exercise code with `cmake --build
  --preset <preset-name>`


## Exercise 13 -> Unit tests

- In this exercise we will create UnitTests for the multiple public
  methods in the three classes we had created in previous exercises.
  - We will use the catch library -> See a tutorial for it
    [here](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top)
- We want to test `calcArea`, `calcTotalLength`, `calcHeight` and `getNumSides`

- Use conan to install the catch2 library according to the instructions
  in the extra exercise.
  - **Note:** If you did the previous exercise, the catch2 library
    should already be installed in your local conan cache. Conan will
    detect that and not install the library again. However, you still
    need to run the conan install command for the necessary files to
    be created in the build folder.

- Edit the `CMakeLists.txt` file and add `find_package(Catch2
  REQUIRED)` to it.

- Follow the steps below:
  1. Create the files **test_RegularPolygon.cpp**, **test_Triangle.cpp** and
     **test_Hexagon.cpp**. Each will have unit tests for the corresponding
     class.
  3. Create a new target in `CMakeLists.txt` called "tests" with the
     `add_executable` command, where the files for that target are the
     "test_*" files you just created
      - Also add the code below 
      
        ```
        target_link_libraries(tests
          Catch2::Catch2WithMain
          mylib
        )
        ```

  6. You should be able to compile the tests target now, but if you
     run it, it will just say no tests were run, since we didn't
     create any tests yet
  7. In each test file, create a `TEST_CASE` for the corresponding class
     as in the [catch tutorial](https://github.com/catchorg/Catch2/tree/devel)
     - In `test_RegularPolygon` you should test all methods defined in
       that class, except `calcArea` (which is a virtual pure method)
     - In `test_Triangle` and `test_Hexagon` only the `calcArea`
       method should be tested
     - **TIP:** Since `RegularPolygon` is an abstract class, you can't
       create an object of the `RegularPolygon` class in order to
       implement the tests. Therefore, in the
       `test_RegularPolygon.cpp` file you need to create a class that
       inherits from `RegularPolygon` (call it `MockRegularPolygon`)
       that implements all the virtual pure methods (only the
       `calcArea` method). You only need a dummy implementation for
       `calcArea`, such as returning zero from it, since you will not
       test that method in `test_RegularPolygon`.

## Extra Exercise: Install armadillo with conan

Try adapting the code in exercise 6 to use a newer armadillo version
installed with conan.
