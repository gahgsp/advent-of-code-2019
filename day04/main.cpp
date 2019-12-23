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

inline bool atLeastOnePairWithTwoDigits(const password pass) {
    // This array represents numbers from 0 to 9 (the possible values in the password)
    std::array<int, 10> occurrences {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < pass.digits.size(); i++) {
        // We add each number occurrence to its position in the array
        occurrences[pass.digits[i]] = ++occurrences[pass.digits[i]];
    }
    int twoPairsCount = 0;
    for (int j = 0; j < occurrences.size(); j++) {
        // Checks for numbers that made only one valid pair
        if (occurrences[j] == 2) {
            twoPairsCount++;
        }
    }
    return twoPairsCount > 0;
}

int main() {
    const int minValue = 382345;
    const int maxValue = 843167;
    int possiblePasswordsCount = 0;
    int passwordsWithTwoDigitsPair = 0;
    std::vector<int> possiblePasswords;

    for (int i = minValue; i < maxValue; i++) {
        possiblePasswords.push_back(i);
    }

    for (int pass : possiblePasswords) {
        password p(pass);
        if (increasing(p) && adjacent(p)) {
            // Part One
            possiblePasswordsCount++;
            if (atLeastOnePairWithTwoDigits(p)) {
                // Part Two
                passwordsWithTwoDigitsPair++;
            }
        }
    }

    std::cout << "The result of the first part of the puzzle is: " << possiblePasswordsCount << std::endl;

    std::cout << "The result of the second part of the puzzle is: " << passwordsWithTwoDigitsPair << std::endl;
    return 0;
}