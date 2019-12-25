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

std::vector<std::string> calculatePathToBeginning(std::string origPlanet, std::vector<std::string> currPath) {
    if (orbits.find(origPlanet) != orbits.end()) {
        currPath.push_back(origPlanet);
        return calculatePathToBeginning(orbits[origPlanet], currPath);
    }
    return currPath;
}

std::string findCommonAncestor(std::vector<std::string> originPath, std::vector<std::string> destinationPath) {
    std::string commonAncestor;
    for (const std::string& oPlanetStep : originPath) {
        bool foundCommonAncestor = false;
        for (const std::string& dPlanetStep : destinationPath) {
            if (oPlanetStep == dPlanetStep) {
                commonAncestor = oPlanetStep;
                foundCommonAncestor = true;
                break;
            }
        }
        if (foundCommonAncestor) {
            break;
        }
    }
    return commonAncestor;
}

int calculateStepsToSanta() {
    std::vector<std::string> origPlanetPath;
    origPlanetPath = calculatePathToBeginning("YOU", origPlanetPath);
    std::vector<std::string> destPlanetPath;
    destPlanetPath = calculatePathToBeginning("SAN", destPlanetPath);

    std::string commonAncestor = findCommonAncestor(origPlanetPath, destPlanetPath);

    int stepsFromOrigin = 0;
    for (int i = 0; i < origPlanetPath.size(); i++) {
        if (origPlanetPath[i] != commonAncestor) {
            stepsFromOrigin++;
        } else {
            break;
        }
    }

    int stepsFromDest = 0;
    for (int i = 0; i < destPlanetPath.size(); i++) {
        if (destPlanetPath[i] != commonAncestor) {
            stepsFromDest++;
        } else {
            break;
        }
    }
    return (stepsFromOrigin + stepsFromDest) - 2;  // Can't considerer both origin and destination
}

int main() {
    std::ifstream file("input.txt");
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

    std::cout << "The result of the second part of the puzzle is: " << calculateStepsToSanta() << std::endl;

    return 0;
}
