//
// Created by Fane on 4/24/2019.
//


#include "IndianaJhony.h"
#include "Map.h"


IndianaJhony::IndianaJhony(Map &harta) {
    Alive();
    SetName('I');
    priority = 2;
    SetStartPosition(harta.dimension);
    harta.map[GetPositionX()][GetPositionY()] = 'I';
}

void IndianaJhony::move(Map &harta) {


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
            cout << "Indiana Jhony found a treasure on position (" << GetPositionX() << "," << GetPositionY()
                 << ") :Hmmm What should i buy" << endl;
            harta.TreasureFound();
            harta.DecreaseNr();
            Dead();
            cout << "there are only " << harta.getNr() << " hunters left" << endl;
        } else {
            if (harta.map[GetPositionX()][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX()][GetPositionY() + 1] = 'I';
                SetpozY(GetPositionY() + 1);
                cout << "Indiana Jhony moved to position :(" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else if (harta.map[GetPositionX() + 1][GetPositionY()] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() + 1][GetPositionY()] = 'I';
                SetpozX(GetPositionX() + 1);
                cout << "Indiana moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else if (harta.map[GetPositionX()][GetPositionY() - 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX()][GetPositionY() - 1] = 'I';
                SetpozY(GetPositionY() - 1);
                cout << "Indiana Jhony moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else if (harta.map[GetPositionX() - 1][GetPositionY()] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() - 1][GetPositionY()] = 'I';
                SetpozX(GetPositionX() - 1);
                cout << "Indiana Jhony moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else if (harta.map[GetPositionX() + 1][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() + 1][GetPositionY() + 1] = 'I';
                SetpozX(GetPositionX() + 1);
                SetpozY(GetPositionY() + 1);
                cout << "Indiana Jhony moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else {
                cout << "Indiana Jhony had nowhere to go and died" << endl;
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.DecreaseNr();
                Dead();
                cout << "there are only " << harta.getNr() << " hunters left" << endl;


            }
        }
    }

}