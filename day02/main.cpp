//
// Created by Kelvin on 07/12/2019.
//

#include <iostream>

#include "IntcodeInterpreter.h"

int main() {
    std::ifstream file("input.txt");

    IntcodeInterpreter intcodeInterpreter(file);

    std::cout << "The result of the first part of the puzzle is: " << intcodeInterpreter.readSequence(12, 2) << std::endl;

    int pairResult = 0;
    for (int noun = 0; noun < 100; noun++) {
        for (int verb = 0; verb < 100; verb++) {
            if (intcodeInterpreter.readSequence(noun, verb) == 19690720) {
                pairResult = 100 * noun + verb;
            }
        }
    }

    std::cout << "The result of the second part of the puzzle is: " << pairResult << std::endl;

    return 0;
}