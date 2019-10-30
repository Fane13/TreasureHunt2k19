//
// Created by Fane on 4/24/2019.
//

#include <iostream>
#include "Map.h"
#include <ctime>
#include <cstdlib>

using namespace std;


Map::Map(int n) {
    dimension = n;
    map = new char *[dimension + 2];
    for (int i = 0; i < dimension + 2; i++)
        map[i] = new char[dimension + 2];
    for (int i = 1; i < dimension + 1; i++)
        for (int j = 1; j < dimension + 1; j++)
            map[i][j] = '-';
    for (int i = 0; i < dimension + 2; i++) {
        map[i][0] = '*';
        map[i][dimension + 1] = '*';
        map[0][i] = '*';
        map[dimension + 1][i] = '*';
    }

}

Map::~Map() {
    for (int i = 0; i < dimension; i++)
        delete map[i];
    delete map;
}

int Map::GetDimension() {
    return dimension;
}

ostream &operator<<(ostream &out, const Map &a) {
    for (int i = 0; i < a.dimension + 2; i++) {
        for (int j = 0; j < a.dimension + 2; j++)
            out << a.map[i][j] << " ";
        out << '\n';
    }
    out << '\n';
    return out;
}

void Map::SpawnChest() {
    NrOfTreasures = 3;
    srand(time(0));
    int pozx, pozy;
    for (int i = 0; i < 3; i++) {
        pozx = rand() % dimension + 1;
        pozy = rand() % dimension + 1;
        while ((pozx == 1 && pozy != 1) || (pozx == 1 && pozy == dimension) ||
               (pozx == dimension && pozy == 1) || (pozx == dimension && pozy == dimension)) {
            pozx = rand() % dimension + 1;
            pozy = rand() % dimension + 1;
        }
        map[pozx][pozy] = 't';
    }

}

void Map::SetNrOfHunters(int x) {

    NrOfHunters = x;
}

void Map::DecreaseNr() {

    NrOfHunters--;
}

int Map::getNr() {
    return NrOfHunters;
}

int Map::GetNrOfTreasures() {
    return NrOfTreasures;

}

void Map::TreasureFound() {
    NrOfTreasures--;

}



