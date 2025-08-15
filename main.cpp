#include <iostream>
#include "Truckloads.h"
#include "Reverser.h"
using namespace std;
int main(){

    Truckloads truck;
    std::cout<<truck.numTrucks(15,3)<<endl;
    Reverser num;
    std::cout<<num.reverseDigit(1234);
}