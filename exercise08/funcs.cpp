#include "funcs.h"
#include <iostream>
#include <thread>
#include <chrono>

void sleepSeconds(int seconds) {
    std::cout <<"\n--------------------------------\n";
    for (int i = seconds; i != -1; i--)
    {   
        std::string str = i>1? "seconds\n":"second\n";
        if(i==0){
            std::cout << "\nBye Bye";
        }else{
            std::cout  << "This window will close after " << i <<" "<< str;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
    }
}

//This code print the vector for each key in map1 with generic type
template<typename T>
void printVector(const std::vector<T> &vec) {
    std::cout << "Vector: ";
    for (auto &elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Explicit instantiation for double and int
template void printVector<double>(const std::vector<double> &vec);
template void printVector<int>(const std::vector<int> &vec);
