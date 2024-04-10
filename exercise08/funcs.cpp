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