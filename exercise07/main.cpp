#include <iostream>
#include "funcs.h"
#include <vector>
#include <armadillo>

int main(int argc, char *argv[])
{
    double input = 25.66;
    double output = doubleInput(input);

    std::cout << "The double of " << input << " is " << output << std::endl;

    arma::vec myvec{2.3, -6.5, 7.4, 0.996};

    // Output vector where we will store the double of the elements in myvec
    arma::vec myvec2 = 2 * myvec;
    myvec2.print();

    return 0;
}
