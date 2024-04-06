#include <iostream>
#include "funcs.h"
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<double> doubles_vec ={1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    std::vector<double> doubles_vec_output;
    
    for (auto &d : doubles_vec)
    {
        doubles_vec_output.push_back(doubleInput(d));
    }

    for (int i = 0; i < doubles_vec.size(); i++)
    {
        std::cout << "The double of " << doubles_vec[i] << " is " << doubles_vec_output[i] << std::endl;
    }

    sleepSeconds(5);
    return 0;
}
