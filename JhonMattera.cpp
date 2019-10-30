//
// Created by Fane on 4/24/2019.
//

#include "JhonMattera.h"

#include "Map.h"


JhonMattera::JhonMattera(Map &harta) {
    Alive();
    SetName('J');
    priority = 3;
    SetStartPosition(harta.dimension);
    harta.map[GetPositionX()][GetPositionY()] = 'J';
}

void JhonMattera::move(Map &harta) {
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
            cout << "Jhon Mattera found a treasure on position (" << GetPositionX() << "," << GetPositionY()
                 << ") : Found it " << endl;
            harta.TreasureFound();
            harta.DecreaseNr();
            Dead();
            cout << "there are only " << harta.getNr() << " hunters left" << endl;
        } else {
            if (harta.map[GetPositionX() - 1][GetPositionY() - 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() - 1][GetPositionY() - 1] = 'J';
                SetpozX(GetPositionX() - 1);
                SetpozY(GetPositionY() - 1);
                cout << "Jhon Mattera moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else if (harta.map[GetPositionX() - 1][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() - 1][GetPositionY() + 1] = 'J';
                SetpozY(GetPositionY() + 1);
                SetpozX(GetPositionX() - 1);
                cout << "Jhon Mattera moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else if (harta.map[GetPositionX() + 1][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() + 1][GetPositionY() + 1] = 'J';
                SetpozX(GetPositionX() + 1);
                SetpozY(GetPositionY() + 1);
                cout << "Jhon Mattera moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else if (harta.map[GetPositionX() - 1][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() - 1][GetPositionY() + 1] = 'J';
                SetpozY(GetPositionY() + 1);
                SetpozX(GetPositionX() - 1);
                cout << "Jhon Mattera moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else if (harta.map[GetPositionX()][GetPositionY() + 1] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX()][GetPositionY() + 1] = 'J';
                SetpozY(GetPositionY() + 1);
                cout << "Jhon Mattera moved to position: (" << GetPositionX() << "," << GetPositionY() << ")" << endl;
            } else if (harta.map[GetPositionX() + 1][GetPositionY()] == '-') {
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.map[GetPositionX() + 1][GetPositionY()] = 'J';
                SetpozX(GetPositionX() + 1);
                cout << "Jhon Mattera moved to position: (" << GetPositionX() << "," << GetPositionY() << ")"
                     << endl;
            } else {
                cout << "John Mattera had nowhere to go and died" << endl;
                harta.map[GetPositionX()][GetPositionY()] = '*';
                harta.DecreaseNr();
                Dead();
                cout << "there are only " << harta.getNr() << " hunters left" << endl;


            }
        }
    }


}



