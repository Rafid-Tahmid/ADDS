#include "Human.h"
#include <iostream>
#include <string>
Human::Human(std::string name){
    this->name = name;
}
Move* Human::makeMove() {
    std::string move;
    std::cout<<"Enter move: ";
    std::cin>>move;
    return &move;
}

std::string Human::getName() {
    return name;
}