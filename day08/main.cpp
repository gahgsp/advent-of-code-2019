//
// Created by Kelvin on 25/12/2019.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string image;
    std::ifstream file("input.txt");

    std::vector<std::vector<std::vector<int>>> imgLayers;

    while (getline(file, image, ' ')) {
        std::vector<std::vector<int>> auxImgLayer;
        std::vector<int> auxImgSubLayer;
        for (int i = 0; i < image.size(); i++) {
            if (auxImgSubLayer.size() == 25) {
                if (auxImgLayer.size() == 6) {
                    imgLayers.push_back(auxImgLayer);
                    auxImgLayer.clear();
                }
                auxImgLayer.push_back(auxImgSubLayer);
                auxImgSubLayer.clear();
            }
            auxImgSubLayer.push_back((int) image.at(i) - 48);
        }
    }

    int layerWithFewestZeroes = 0, currTotalZeroes = 0, totalZeroes = INT_MAX;
    for (int i = 0; i < imgLayers.size(); i++) {
        for (int j = 0; j < imgLayers[i].size(); j++) {
            currTotalZeroes += std::count_if(imgLayers[i][j].begin(), imgLayers[i][j].end(), [](int num) { return (num == 0); });
        }
        if (currTotalZeroes < totalZeroes) {
            totalZeroes = currTotalZeroes;
            layerWithFewestZeroes = i;
        }
        currTotalZeroes = 0;
    }

    int oneQty = 0, twoQty = 0;
    for (int i = 0; i < imgLayers[layerWithFewestZeroes].size(); i++) {
        oneQty += std::count_if(imgLayers[layerWithFewestZeroes][i].begin(), imgLayers[layerWithFewestZeroes][i].end(), [](int num) { return (num == 1); });
        twoQty += std::count_if(imgLayers[layerWithFewestZeroes][i].begin(), imgLayers[layerWithFewestZeroes][i].end(), [](int num) { return (num == 2); });
    }

    std::cout << "The result of the first part of the puzzle is: " << oneQty * twoQty << std::endl;

    return 0;
}
