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
};

int main() {
    const Point STARTING_POINT = {0, 0};

    std::ifstream file("input.txt");
    std::string commands;

    Point currPoint;
    Point newPoint;

    std::vector<Segment> firstWire;
    std::vector<Segment> secondWire;

    bool isSecondWire = false;
    while(getline(file, commands, '\n')) {
        std::istringstream strCommand(commands);
        newPoint = STARTING_POINT;
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
            if ((std::min(s1.start.x, s1.end.x) >= std::min(s2.start.x, s2.end.x) && (std::min(s1.start.x, s1.end.x) <= std::max(s2.start.x, s2.end.x))) &&
                (std::min(s2.start.y, s2.end.y) >= std::min(s1.start.y, s1.end.y) && (std::min(s2.start.y, s2.end.y) <= std::max(s1.start.y, s1.end.y)))) {
                intersections.push_back({std::min(s1.start.x, s1.end.x), std::min(s2.start.y, s2.end.y)});
            } else if ((std::min(s2.start.x, s2.end.x) >= std::min(s1.start.x, s1.end.x) && (std::min(s2.start.x, s2.end.x) <= std::max(s1.start.x, s1.end.x))) &&
                       (std::min(s1.start.y, s1.end.y) >= std::min(s2.start.y, s2.end.y) && (std::min(s1.start.y, s1.end.y) <= std::max(s2.start.y, s2.end.y)))) {
                intersections.push_back({std::min(s2.start.x, s2.end.x), std::min(s1.start.y, s1.end.y)});
            }
        }
    }

    int minManhattanDistance = 0;
    for (Point p : intersections) {
        if (&p != &STARTING_POINT) {
            if (minManhattanDistance != 0) {
                minManhattanDistance = std::min(minManhattanDistance, std::abs(p.x - STARTING_POINT.x) + std::abs(p.y - STARTING_POINT.y));
            } else {
                minManhattanDistance = std::abs(p.x - STARTING_POINT.x) + std::abs(p.y - STARTING_POINT.y);
            }
        }
    }

    std::cout << "The result of the second part of the puzzle is: " << minManhattanDistance << std::endl;

    return 0;
}