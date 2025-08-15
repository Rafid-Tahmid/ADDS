#ifndef REVERSE_H
#define REVERSE_H
#include <string>
class Reverser{
public:
int reverseDigit(int value);
int reverseDigitHelper(int value, int acc);

std::string reverseString(std::string characters);
};

#endif