#include <iostream>
#include "funcs.h"
#include <vector>
#include <armadillo>

int main(int argc, char *argv[])
{
    double input = 25.66;
    double output = doubleInput(input);

    std::cout << "The double of " << input << " is " << output << std::endl;

    std::vector<double> myvec{2.3, -6.5, 7.4, 0.996};

    // Output vector where we will store the double of the elements in myvec
    std::vector<double> myvec2;
    myvec2.reserve(myvec.size());


    auto f = [](auto x){ return 2 * x;};

    // Use use a "for each" for iterating the vector -> Note that if the vector
    // was of objects we should use "auto& elem" instead to avoid a copy
    for(auto elem : myvec) {
        myvec2.push_back(f(elem));
    }

    std::cout << "myvec2: [";
    for(auto elem : myvec2) {
        std::cout << elem << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
