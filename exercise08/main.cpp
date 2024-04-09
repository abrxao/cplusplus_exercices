#include <unordered_map>
#include <string>
#include "funcs.h"
#include <iostream>

int main(int argc, char *argv[])
{
    // Note that the map keys could be other things, but here we are using
    // strings
    std::unordered_map<std::string, std::vector<double>> map1;
    std::unordered_map<std::string, std::vector<int>> map2;

    std::vector<double> vec1{1.1, 2.2, 3.3};
    std::vector<int> vec2{1, 2, 3};
    std::vector<double> vec3{4.4, 5.5, 6.6};
    std::vector<int> vec4{4, 5, 6};

    //Two ways to insert elements in the map
    map1.insert({"key1", vec1});
    map2.insert({"key2", vec2});
    map1["key3"] = vec3;
    map2["key4"] = vec4;

    //this code print the vector for each key in map1
    for (auto &pair : map1)
    {
        std::cout << pair.first << " ";
        printVector(pair.second);
    }
    //this code print the vector for each key in map2
    for (auto &pair : map2)
    {
        std::cout << pair.first << " ";
        printVector(pair.second);
    }

    // Clear the vectors and maps
    vec1.clear();
    vec2.clear();
    vec3.clear();
    vec4.clear();

    map2.clear();
    map1.clear();

    sleepSeconds(5); // Sleep for 5 seconds (see funcs.cpp for implementation)

    return 0;
}
