#include <iostream>
#include <vector>
#include <sstream>
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::vector<int> numbers;
    int number;

    while (ss >> number) {
        numbers.push_back(number);
    }

    QuickSort quickSort;
    numbers = quickSort.sort(numbers);

    RecursiveBinarySearch binarySearch;
    bool found = binarySearch.search(numbers, 1);

    std::cout << (found ? "true" : "false");
    for (const int& num : numbers) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}