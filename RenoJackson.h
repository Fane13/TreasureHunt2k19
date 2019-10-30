//
// Created by Fane on 4/24/2019.
//

#ifndef TREASUREHUNT2K19_RENOJACKSON_H
#define TREASUREHUNT2K19_RENOJACKSON_H


#include "TreasureHunters.h"
#include "Map.h"

class RenoJackson : public TreasureHunters {

public:

    RenoJackson(Map &harta);

    void move(Map &harta);

    friend class Map;

};

#endif //TREASUREHUNT2K19_RENOJACKSON_H
