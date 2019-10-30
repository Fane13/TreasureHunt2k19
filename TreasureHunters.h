//
// Created by Fane on 4/24/2019.
//

#ifndef TREASUREHUNT2K19_TREASUREHUNTERS_H
#define TREASUREHUNT2K19_TREASUREHUNTERS_H

#include "Map.h"

class TreasureHunters {
private:
    int coordX, coordY;
    char name;
    int status;
protected:
    int priority;
public:
    virtual void move(Map &harta) = 0;

    TreasureHunters();

    void Alive();

    void Dead();

    int Getstatus();

    void SetName(char x);

    void SetStartPosition(int n);

    void SetpozX(int x);

    void SetpozY(int x);


    int GetPositionX();

    int GetPositionY();


};


#endif //TREASUREHUNT2K19_TREASUREHUNTERS_H
