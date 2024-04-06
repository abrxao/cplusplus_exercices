#include <iostream>
#include "funcs.h"

int main(int argc, char *argv[])
{
    double input = 25.66;
    double output = doubleInput(input);

    std::cout << "The double of " << input << " is " << output << std::endl;

    sleepSeconds(3);

    return 0;
}
