//
// Created by Fane on 4/24/2019.
//

#ifndef TREASUREHUNT2K19_BRANNBRONZEBEARD_H
#define TREASUREHUNT2K19_BRANNBRONZEBEARD_H


#include "TreasureHunters.h"
#include "Map.h"

class BrannBronzebeard : public TreasureHunters {

public:
    BrannBronzebeard(Map &harta);

    void move(Map &harta);

};


#endif //TREASUREHUNT2K19_BRANNBRONZEBEARD_H
