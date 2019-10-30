//
// Created by Fane on 4/24/2019.
//

#include <iostream>
#include "TreasureHunters.h"
#include "Map.h"

TreasureHunters::TreasureHunters() {
    coordX = 0;
    coordY = 0;
    priority = 0;
}


void TreasureHunters::SetName(char x) {
    name = x;

}

void TreasureHunters::SetStartPosition(int n) {
    if (priority == 1) {
        coordX = 1;
        coordY = 1;
    }
    if (priority == 2) {
        coordX = 1;
        coordY = n;
    }
    if (priority == 3) {
        coordX = n;
        coordY = n;
    }
    if (priority == 4) {
        coordX = n;
        coordY = 1;
    }

}

int TreasureHunters::GetPositionX() {
    return coordX;
}

int TreasureHunters::GetPositionY() {
    return coordY;
}

void TreasureHunters::SetpozX(int x) {
    coordX = x;

}

void TreasureHunters::SetpozY(int x) {
    coordY = x;

}

void TreasureHunters::Alive() {
    status = 1;
}

void TreasureHunters::Dead() {
    status = 0;

}

int TreasureHunters::Getstatus() {
    return status;
}

