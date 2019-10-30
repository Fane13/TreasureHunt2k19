//
// Created by Fane on 4/24/2019.
//

#include "RenoJackson.h"
#include "Map.h"
#include <iostream>

using namespace std;

RenoJackson::RenoJackson(Map &harta) {
    Alive();
    SetName('R');
    priority = 1;
    SetStartPosition(harta.dimension);
    harta.map[GetPositionX()][GetPositionY()] = 'R';
}

void RenoJackson::move(Map &harta) {
    if (Getstatus() == 1) {
        if ((harta.map[GetPositionX()][GetPositionY() + 1] == 't') ||
            (harta.map[GetPositionX() + 1][GetPositionY()] == 't') ||
            (harta.map[GetPositionX()][GetPositionY() - 1] == 't') ||
            (harta.map[GetPositionX() - 1][GetPositionY()] == 't')) {
            harta.map[GetPositionX()][GetPositionY()] = '*';
            if (harta.map[GetPositionX()][GetPositionY() + 1] == 't') {
                harta.map[GetPositionX()][GetPositionY() + 1] = '*';
                SetpozY(GetPositionY() + 1);

            }
            if (harta.map[GetPositionX() + 1][GetPositionY()] == 't') {
                harta.map[GetPositionX() + 1][GetPositionY()] = '*';
                SetpozX(GetPositionX() + 1);

            }

            if (harta.map[GetPositionX()][GetPositionY() - 1] == 't') {
                harta.map[GetPositionX()][GetPositionY() - 1] = '*';
                SetpozY(GetPositionY() - 1);
            }
            if (harta.map[GetPositionX() - 1][GetPositionY()] == 't') {
                harta.map[GetPositionX() - 1][GetPositionY()] = '*';
                SetpozX(GetPositionX() - 1);

            }
            cout << "Reno Jackson found a treasure on position (" << GetPositionX() << "," << GetPositionY()
                 << ") :we're gonna be rich" << endl;
            harta.TreasureFound();
            harta.DecreaseNr();
            Dead();
            cout << "there are only " << harta.getNr() << " hunters left" << endl;
        } else {
            if (harta.map[GetPositionX()][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX()][GetPositionY() + 1] = 'R';
                SetpozY(GetPositionY() + 1);
                cout << "Reno Jackson moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else if (harta.map[GetPositionX() + 1][GetPositionY()] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() + 1][GetPositionY()] = 'R';
                SetpozX(GetPositionX() + 1);
                cout << "Reno Jackson moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else if (harta.map[GetPositionX()][GetPositionY() - 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX()][GetPositionY() - 1] = 'R';
                SetpozY(GetPositionY() - 1);
                cout << "Reno Jackson moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else if (harta.map[GetPositionX() - 1][GetPositionY()] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() - 1][GetPositionY()] = 'R';
                SetpozX(GetPositionX() - 1);
                cout << "Reno Jackson moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else if (harta.map[GetPositionX() + 1][GetPositionY() - 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() + 1][GetPositionY() - 1] = 'R';
                SetpozY(GetPositionY() - 1);
                SetpozX(GetPositionX() + 1);
                cout << "Reno Jackson moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else {
                cout << "Reno Jackson had nowhere to go and died " << endl;
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.DecreaseNr();
                Dead();
                cout << "there are only " << harta.getNr() << " hunters left" << endl;


            }
        }
    }


}

