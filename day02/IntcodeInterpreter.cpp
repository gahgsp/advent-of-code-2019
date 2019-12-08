//
// Created by Kelvin on 08/12/2019.
//

#include "IntcodeInterpreter.h"

IntcodeInterpreter::IntcodeInterpreter(std::istream &file) {
    _originalSequence = readFile(file);
    _numberSequence = _originalSequence;
}

int IntcodeInterpreter::readSequence(int noun, int verb) {
    // Before each run we reset the sequence to the original values
    _numberSequence = _originalSequence;

    _numberSequence.at(1) = noun;
    _numberSequence.at(2) = verb;

    bool isHalt = false;
    for (int i = 0; i < _numberSequence.size(); i+= 4) {
        if (isHalt) {
            break;
        }
        int opCode = _numberSequence.at(i);
        switch (opCode) {
            case 1:
                _numberSequence.at(_numberSequence.at(i + 3)) = _numberSequence.at(_numberSequence.at(i + 1)) + _numberSequence.at(_numberSequence.at(i + 2));
                break;
            case 2:
                _numberSequence.at(_numberSequence.at(i + 3)) = _numberSequence.at(_numberSequence.at(i + 1)) * _numberSequence.at(_numberSequence.at(i + 2));
                break;
            case 99:
                isHalt = true;
                break;
        }
    }

    return _numberSequence[0];
}

#include <sstream>
std::vector<int> IntcodeInterpreter::readFile(std::istream &file) {
    std::string line;
    std::vector<int> intCode;
    while(getline(file, line)) {
        std::istringstream lineStream(line);
        while (lineStream.good()) {
            std::string splitLine;
            getline(lineStream, splitLine, ',');
            intCode.push_back(stoi(splitLine));
        }
    }
    return intCode;
}