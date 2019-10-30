//
// Created by Fane on 4/24/2019.
//

#ifndef TREASUREHUNT2K19_MAP_H
#define TREASUREHUNT2K19_MAP_H

#include <iostream>

using namespace std;

class Map {
private:
    char **map;
    int dimension, NumOfTreasure, NrOfHunters, NrOfTreasures;

public:

    Map(int n);

    ~Map();

    int GetDimension();

    void SpawnChest();

    int GetNrOfTreasures();

    void TreasureFound();

    void SetNrOfHunters(int x);

    int getNr();

    void DecreaseNr();

    friend ostream &operator<<(ostream &out, const Map &a);

    friend class RenoJackson;

    friend class IndianaJhony;

    friend class JhonMattera;

    friend class BrannBronzebeard;

    friend class TreasureHunters;
    // void SpawnHunters(RenoJackson r,IndianaJhony i , JhonMattera j ,BrannBronzebeard b);

};

#endif //TREASUREHUNT2K19_MAP_H
