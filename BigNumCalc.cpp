#include "BigNumCalc.h"
#include <vector>

// Build a list from a string representing a big number
std::list<int> BigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> result;
    for (char ch : numString) {
        result.push_back(ch - '0');
    }
    return result;
}

// Add two big numbers
std::list<int> BigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int carry = 0;

    while (it1 != num1.rend() || it2 != num2.rend() || carry != 0) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1;
            ++it1;
        }
        if (it2 != num2.rend()) {
            sum += *it2;
            ++it2;
        }
        result.push_front(sum % 10);
        carry = sum / 10;
    }

    return result;
}

// Subtract two big numbers
std::list<int> BigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int borrow = 0;

    while (it1 != num1.rend()) {
        int diff = *it1 - borrow;
        if (it2 != num2.rend()) {
            diff -= *it2;
            ++it2;
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
        ++it1;
    }

    // Remove leading zeroes
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }

    return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    // Convert the lists to vectors for easier access by index
    std::vector<int> n1(num1.rbegin(), num1.rend());
    std::vector<int> n2(num2.rbegin(), num2.rend());
    
    std::vector<int> product(n1.size() + n2.size(), 0);
    
    // Perform multiplication digit by digit
    for (size_t i = 0; i < n1.size(); ++i) {
        for (size_t j = 0; j < n2.size(); ++j) {
            product[i + j] += n1[i] * n2[j];
            if (product[i + j] >= 10) {
                product[i + j + 1] += product[i + j] / 10;  // Carry over
                product[i + j] %= 10;
            }
        }
    }
    
    // Remove leading zeros
    while (product.size() > 1 && product.back() == 0) {
        product.pop_back();
    }
    
    // Convert back to list and reverse the order
    result.assign(product.rbegin(), product.rend());
    return result;
}
