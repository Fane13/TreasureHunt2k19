//
// Created by Fane on 4/24/2019.
//


#include "Map.h"
#include "BrannBronzebeard.h"


BrannBronzebeard::BrannBronzebeard(Map &harta) {
    Alive();
    SetName('B');
    priority = 4;
    SetStartPosition(harta.dimension);
    harta.map[GetPositionX()][GetPositionY()] = 'B';


}

void BrannBronzebeard::move(Map &harta) {
    if (Getstatus() == 1) {

        if ((harta.map[GetPositionX() + 1][GetPositionY() + 1] == 't') ||
            (harta.map[GetPositionX() + 1][GetPositionY() - 1] == 't') ||
            (harta.map[GetPositionX() - 1][GetPositionY() - 1] == 't') ||
            (harta.map[GetPositionX() - 1][GetPositionY() + 1] == 't')) {
            harta.map[GetPositionX()][GetPositionY()] = '*';
            if (harta.map[GetPositionX() + 1][GetPositionY() + 1] == 't') {
                harta.map[GetPositionX() + 1][GetPositionY() + 1] = '*';
                SetpozY(GetPositionY() + 1);
                SetpozX(GetPositionX() + 1);

            }
            if (harta.map[GetPositionX() + 1][GetPositionY() - 1] == 't') {
                harta.map[GetPositionX() + 1][GetPositionY() - 1] = '*';
                SetpozX(GetPositionX() + 1);
                SetpozY(GetPositionY() - 1);

            }

            if (harta.map[GetPositionX() - 1][GetPositionY() - 1] == 't') {
                harta.map[GetPositionX() - 1][GetPositionY() - 1] = '*';
                SetpozY(GetPositionY() - 1);
                SetpozX(GetPositionX() - 1);

            }
            if (harta.map[GetPositionX() - 1][GetPositionY() + 1] == 't') {
                harta.map[GetPositionX() - 1][GetPositionY() + 1] = '*';
                SetpozX(GetPositionX() - 1);
                SetpozY(GetPositionY() + 1);

            }
            cout << "Brann Bronzebeard found a treasure on position (" << GetPositionX() << "," << GetPositionY()
                 << ") :who knows what secrets we'll uncover" << endl;
            harta.TreasureFound();
            harta.DecreaseNr();
            Dead();
            cout << "there are only " << harta.getNr() << " hunters left" << endl;
        } else {
            if (harta.map[GetPositionX() - 1][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() - 1][GetPositionY() + 1] = 'B';
                SetpozY(GetPositionY() + 1);
                SetpozX(GetPositionX() - 1);
                cout << "Brann Bronzebeard moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else if (harta.map[GetPositionX() - 1][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() - 1][GetPositionY() + 1] = 'B';
                SetpozX(GetPositionX() - 1);
                SetpozY(GetPositionY() + 1);
                cout << "Brann Bronzebeard moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else if (harta.map[GetPositionX() + 1][GetPositionY() - 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() + 1][GetPositionY() - 1] = 'B';
                SetpozY(GetPositionY() - 1);
                SetpozX(GetPositionX() + 1);
                cout << "Brann Bronzebeard moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else if (harta.map[GetPositionX() + 1][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() + 1][GetPositionY() + 1] = 'B';
                SetpozX(GetPositionX() + 1);
                SetpozY(GetPositionY() + 1);
                cout << "Brann Bronzebeard moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else if (harta.map[GetPositionX()][GetPositionY() - 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX()][GetPositionY() - 1] = 'B';
                SetpozY(GetPositionY() - 1);
                cout << "Brann Bronzebeard moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else if (harta.map[GetPositionX() + 1][GetPositionY()] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() + 1][GetPositionY()] = 'B';
                SetpozX(GetPositionX() + 1);
                cout << "Brann Bronzebeard moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else {
                cout << "Brann Bronzebeard had nowhere to go and died" << endl;
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.DecreaseNr();
                Dead();
                cout << "there are only " << harta.getNr() << " hunters left" << endl;


            }
        }
    }


}
