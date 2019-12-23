//
// Created by Kelvin on 19/12/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Point {
    int x, y;
};

struct Segment {
    Point start, end;
    int minX = std::min(start.x, end.x);
    int maxX = std::max(start.x, end.x);
    int minY = std::min(start.y, end.y);
    int maxY = std::max(start.y, end.y);
};

int calculateManhattanDistance(Point a, Point b) { return std::abs(a.x - b.x) + std::abs(a.y - b.y); }

int main() {
    const Point CENTRAL_PORT = {0, 0};

    std::ifstream file("input.txt");
    std::string commands;

    Point currPoint;
    Point newPoint;

    std::vector<Segment> firstWire;
    std::vector<Segment> secondWire;

    bool isSecondWire = false;
    while(getline(file, commands, '\n')) {
        std::istringstream strCommand(commands);
        newPoint = CENTRAL_PORT;
        while(strCommand.good()) {
            std::string command;
            getline(strCommand, command, ',');
            char direction = command.at(0);
            command.erase(command.begin());
            int steps = stoi(command);
            currPoint = newPoint;
            switch (direction) {
                case 'R':
                    newPoint.x = newPoint.x += steps;
                    break;
                case 'L':
                    newPoint.x = newPoint.x -= steps;
                    break;
                case 'U':
                    newPoint.y = newPoint.y += steps;
                    break;
                case 'D':
                    newPoint.y = newPoint.y -= steps;
                    break;
                default:
                    // It should never hit this condition
                    continue;
            }
            isSecondWire ? secondWire.push_back({currPoint, newPoint}) : firstWire.push_back({currPoint, newPoint});
        }
        isSecondWire = true;
    }

    std::vector<Point> intersections;

    for (Segment s1 : firstWire) {
        for (Segment s2 : secondWire) {
            if ((s1.minX >= s2.minX && s1.minX <= s2.maxX) && (s2.minY >= s1.minY && s2.minY <= s1.maxY)) {
                intersections.push_back({s1.minX, s2.minY});
            } else if ((s2.minX >= s1.minX && s2.minX <= s1.maxX) && (s1.minY >= s2.minY && s1.minY <= s2.maxX)) {
                intersections.push_back({s2.minX, s1.minY});
            }
        }
    }

    int minManhattanDistance = 0;
    for (Point intersection : intersections) {
        if (&intersection != &CENTRAL_PORT) {
            if (minManhattanDistance != 0) {
                minManhattanDistance = std::min(minManhattanDistance, calculateManhattanDistance(intersection, CENTRAL_PORT));
            } else {
                minManhattanDistance = calculateManhattanDistance(intersection, CENTRAL_PORT);
            }
        }
    }

    std::cout << "The result of the first part of the puzzle is: " << minManhattanDistance << std::endl;

    return 0;
}