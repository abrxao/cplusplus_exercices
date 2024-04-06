#include <iostream>
#include "funcs.h"
#include <vector>
#include <algorithm>
#include <iterator>

int main(int argc, char *argv[])
{
    double input = 25.66;
    double output = doubleInput(input);

    std::cout << "The double of " << input << " is " << output << std::endl;

    std::vector<double> myvec{2.3, -6.5, 7.4, 0.996};

    // Output vector where we will store the double of the elements in myvec
    std::vector<double> myvec2;
    myvec2.reserve(myvec.size());
    // TODO Create a lambda function here

    auto doubleInput = [](double num) {
        return num * 2;
    };
    
    // Use use a "for each" for iterating the vector -> Note that if the vector
    // was of objects we should use "auto& elem" instead to avoid a copy
    for(auto &elem : myvec) {
        // TODO: Change doubleInput to your lambda function
        myvec2.push_back(doubleInput(elem));
    }

    std::cout << "myvec2: [";
    for(auto elem : myvec2) {
        std::cout << elem << ", ";
    }
    std::cout << "]" << std::endl;

    // Now create another lambda function that receives a double number, but now
    // it captures the variable "numTimes" below and multiply the input by
    // numTimes
    double numTimes = 3.5;

    // auto f2 = [...   // Continue the implementation
    // this code below is the lambda function that will multiply the input by numTimes the variable numTimes is captured to the fn when i put her in the [] brackets
    auto f2 = [numTimes](double num) {
        return num * numTimes;
    };

    // This code will create a std::vector of double numbers and then use the
    // std::transform algorithm from the standard library to call your lambda
    // function on each element and add the result to otherVec using push_back
    std::vector<double> otherVec;
    std::transform(myvec.begin(), myvec.end(), std::back_inserter(otherVec), f2);

    // This code just prints the otherVec. You could also use a for loop as in
    // previous exercises
    std::cout << "otherVec: ";
    std::copy(otherVec.begin(), otherVec.end(), std::ostream_iterator<double>(std::cout, " "));

    //This code will clear the vectors
    otherVec.clear();
    myvec2.clear();

    //This code will hold the window for 'n' seconds
    sleepSeconds(10);
    return 0;
}
