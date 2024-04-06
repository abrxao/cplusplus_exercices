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

    // TODO: insert multiple vectors in each map
    // You can use the insert method or the the [] operator
    // map1.insert({key, value});
    // map2[key] = value;

    // TODO: Print the vector for each key in map1. You can use the printVector
    // function included from funcs.h file
    // printVector(map1.at(key));

    return 0;
}
