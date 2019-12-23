//
// Created by Kelvin on 23/12/2019.
//

#include <iostream>
#include <array>
#include <vector>

struct password {
    std::array<int, 6> digits;
    password(int num) {
        digits[0] = num % 10;
        digits[1] = (num / 10) % 10;
        digits[2] = (num / 100) % 10;
        digits[3] = (num / 1000) % 10;
        digits[4] = (num / 10000) % 10;
        digits[5] = (num / 100000) % 10;
    }
};

inline bool increasing(const password pass) {
    return pass.digits[0] >= pass.digits[1] && pass.digits[1] >= pass.digits[2] && pass.digits[2] >= pass.digits[3] && pass.digits[3] >= pass.digits[4] && pass.digits[4] >= pass.digits[5];
}

inline bool adjacent(const password pass) {
    return pass.digits[0] == pass.digits[1] || pass.digits[1] == pass.digits[2] || pass.digits[2] == pass.digits[3] || pass.digits[3] == pass.digits[4] || pass.digits[4] == pass.digits[5];
}

int main() {
    const int minValue = 382345;
    const int maxValue = 843167;
    int possiblePasswordsCount = 0;
    std::vector<int> possiblePasswords;

    for (int i = minValue; i < maxValue; i++) {
        possiblePasswords.push_back(i);
    }

    for (int pass : possiblePasswords) {
        password p(pass);
        if (increasing(p) && adjacent(p)) {
            possiblePasswordsCount++;
        }
    }

    std::cout << "The result of the first part of the puzzle is: " << possiblePasswordsCount << std::endl;
    return 0;
}