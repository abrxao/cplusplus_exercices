#include "funcs.h"
#include <armadillo>

int main(int argc, char *argv[])
{
    //Creating a vector of doubles using arma::vec
    arma::vec v = {1.1,2.2,3.3};
    //Doubling the vector and storing the result in v2
    arma::vec v2 = v * 2;
    //Using print function to display the vector
    v2.print("v2 = ");
    //Sleeping for 10 seconds to see the output    
    sleepSeconds(10);

    return 0;
}
