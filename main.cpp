#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include <iostream>
#include <memory>

int main() {
    Referee referee;
    Human human("Mei");
    Computer computer;

    Player* winner = referee.refGame(&human, &computer);

    if (winner == nullptr) {
        std::cout << "It's a Tie." << std::endl;
    } else {
        std::cout << winner->getName() << " Wins." << std::endl;
    }

    return 0;
}