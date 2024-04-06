#include <iostream>

#include <thread>

int main(int argc, char *argv[])
{
    std::cout << "Hello Brave New C++ World" << std::endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(2000));
    // Sleep for 2 seconds to see the output
    
    return 0;
}
