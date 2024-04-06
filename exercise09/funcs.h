#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <vector>


// Note that the code of template functions must be in the .h file


template <typename T>
void printVector(std::vector<T> vec) {
    std::cout << "vector: [";

    if(vec.size() > 0) {
        // The loop does not include the last element such that we avoid a comma
        // after the last element.
        for(unsigned int i=0; i < vec.size()-1; i++) {
            std::cout << vec[i] << ", ";
        }

        // Print the last element
        std::cout << vec[vec.size()-1];
    }
    std::cout << "]" << std::endl;
}


#endif
