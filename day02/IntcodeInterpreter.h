//
// Created by Kelvin on 08/12/2019.
//

#ifndef ADVENT_OF_CODE_2019_INTCODEINTERPRETER_H
#define ADVENT_OF_CODE_2019_INTCODEINTERPRETER_H

#include <fstream>
#include <vector>

class IntcodeInterpreter {
public:
    IntcodeInterpreter(std::istream &file);
    int readSequence(int noun, int verb);
private:
    std::vector<int> _originalSequence;
    std::vector<int> _numberSequence;
private:
    std::vector<int> readFile(std::istream &file);
};


#endif //ADVENT_OF_CODE_2019_INTCODEINTERPRETER_H
