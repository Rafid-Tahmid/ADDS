#include "Reverser.h"
#include <iostream>

int Reverser::reverseDigit(int value)
{
    return reverseDigitHelper(value, 0);
};
int Reverser::reverseDigitHelper(int value,int acc){
    if(value==0)
        return acc;
    else 
    return reverseDigitHelper(value/10, acc*10+(value%10));
}
