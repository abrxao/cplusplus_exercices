#include <iostream>
#include "funcs.h"
#include <thread>
#include <string>

int main(int argc, char *argv[])
{
    double input = 25.66;
    double output = doubleInput(input);

    std::cout << "The double of " << input << " is " << output << std::endl;
    int counter_seconds = 3;
    for (int i = counter_seconds; i != -1; i--)
    {   
        std::string str = i>1? "seconds\n":"second\n";
        if(i==0){
            std::cout << "\nBye Bye";
        }else{
            std::cout  << "This window will delete after " << i <<" "<< str;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
    }
    //added sleep to see the output


    return 0;
}
