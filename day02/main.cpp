//
// Created by Kelvin on 07/12/2019.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    ifstream file("input.txt");
    string line;

    vector<int> intCode;
    while(getline(file, line)) {
        istringstream lineStream(line);
        while (lineStream.good()) {
            string splitLine;
            getline(lineStream, splitLine, ',');
            intCode.push_back(stoi(splitLine));
        }
    }

    intCode.at(1) = 12;
    intCode.at(2) = 2;

    bool isHalt = false;
    for (int i = 0; i < intCode.size(); i+= 4) {
        if (isHalt) {
            break;
        }
        int opCode = intCode.at(i);
        switch (opCode) {
            case 1:
                intCode.at(intCode.at(i + 3)) = intCode.at(intCode.at(i + 1)) + intCode.at(intCode.at(i + 2));
                break;
            case 2:
                intCode.at(intCode.at(i + 3)) = intCode.at(intCode.at(i + 1)) * intCode.at(intCode.at(i + 2));
                break;
            case 99:
                isHalt = true;
                break;
        }
    }

    return 0;
}