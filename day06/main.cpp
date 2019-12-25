//
// Created by Kelvin on 24/12/2019.
//

#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

std::map<std::string, std::string> orbits;

int countOrbits(std::string planetName, int totalOrbits) {
    if (orbits.find(planetName) != orbits.end()) {
        return countOrbits(orbits[planetName], totalOrbits + 1);
    }
    return totalOrbits;
}

int main() {
    std::ifstream file(R"(C:\Web Projects\C++\advent-of-code-2019\day06\input.txt)");
    std::string line;

    while(getline(file, line, '\n')) {
        std::istringstream orbitsStream(line);
        std::string pNameKey, pNameValue;
        while(getline(getline(orbitsStream, pNameValue, ')') >> std::ws, pNameKey)) {
            orbits.insert(std::pair<std::string, std::string>(pNameKey, pNameValue));
        }
    }

    int totalOrbits = 0;
    for (auto const& orbit : orbits) {
        int currOrbitQty = countOrbits(orbit.first, 0);
        totalOrbits += currOrbitQty;
    }

    std::cout << "The result of the first part of the puzzle is: " << totalOrbits << std::endl;

    return 0;
}
