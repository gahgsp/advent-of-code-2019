//
// Created by Kelvin on 07/12/2019.
//

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int calculateAmountOfFuel(int moduleMass) {
    int totalFuel = 0;
    int currModuleFuel = floor(moduleMass / 3) - 2;
    totalFuel += currModuleFuel;

    // Second part: the fuel is also considered a module.
    int fuelToFuelModule = currModuleFuel;
    do {
        fuelToFuelModule = floor(fuelToFuelModule / 3) - 2;
        if (fuelToFuelModule <= 0) {
            fuelToFuelModule = 0;
        }
        totalFuel += fuelToFuelModule;
    } while (fuelToFuelModule > 0);

    return totalFuel;
}

int main() {
    ifstream file("input.txt");
    string line;

    int amountOfFuelToAllModules = 0;

    while(getline(file, line)) {
        int currMass = stoi(line); // Converts the line from String to Int
        amountOfFuelToAllModules += calculateAmountOfFuel(currMass);
    }

    cout << "The total of fuel needed is: " << amountOfFuelToAllModules << endl;
    return 0;
}