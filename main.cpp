#include <iostream>
#include "Truckloads.h"
#include "Reverser.h"
#include <string>
using namespace std;
int main()
{

    Truckloads truck;
    std::cout << truck.numTrucks(15, 3) << endl;
    Reverser num;
    std::cout << num.reverseDigit(1234) << std::endl;
    std::cout << num.reverseString("Rafid");
}