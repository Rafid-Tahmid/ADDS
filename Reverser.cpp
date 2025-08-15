#include "Reverser.h"
#include <iostream>

int Reverser::reverseDigit(int value)
{
    if (value<0)
    return -1;
    return reverseDigitHelper(value, 0);
};
int Reverser::reverseDigitHelper(int value, int acc)
{
    if (value == 0)
        return acc;
    else
        return reverseDigitHelper(value / 10, acc * 10 + (value % 10));
}
std::string Reverser::reverseString(std::string characters)
{
    
    if (characters == "")
        return "";
    return reverseString(characters.substr(1)) + characters[0];
}
