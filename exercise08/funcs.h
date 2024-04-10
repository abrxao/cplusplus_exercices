#ifndef FUNCS_H
#define FUNCS_H

#include <vector>

template<typename T>
void printVector(const std::vector<T> &vec) {
    std::cout << "Vector: ";
    for (auto &elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void sleepSeconds(int seconds);

#endif
