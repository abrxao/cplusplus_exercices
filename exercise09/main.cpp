#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "funcs.h"

int main(int argc, char *argv[])
{
    // Note that the map keys could be other things, but here we are using
    // strings
    std::unordered_map<std::string, std::vector<double>> map1;
    std::unordered_map<std::string, std::vector<int>> map2;

    // You can use the insert method or the the [] operator -> The insert method
    // is slightly better because the [] operator will create an empty vector
    // first which will then be replaced with the vector in the right size of
    // the "=" operator
    map1.insert({"some string", {1.1, 2.7, 5.5, 7.7, -3.14}});
    map1["some other string"] = {10.11, 12.14, 15.99};

    std::vector<int> someVec{1,2,3,4,5};
    map2["lala"] = someVec; // The vector in the someVec variable will be copied
                            // to the map
    std::vector<int> someOtherVec{10, 15, 16, 99};
    // The vector someOtherVec will be moved to the map -> The elements are not
    // in the someOtherVec variable anymore
    map2["lele"] = std::move(someOtherVec);

    // Print the vector for each key in map1.
    for(const auto& keyAndValue : map1) {
        // Use structured binding to separate the first and second values of the
        // tuple
        const auto& [key, value] = keyAndValue;
        std::cout << key << " ";
        printVector(value);

    }
    // The vector is empty cause it was moved to the map
    std::cout << "someOtherVec: ";
    printVector(someOtherVec);

    // we can also directly use the structured binding in the for loop
    for(const auto& [key, value] : map2) {
        std::cout << key << " ";
        printVector(value);
    }

    return 0;
}
