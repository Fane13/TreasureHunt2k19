//
// Created by Fane on 4/25/2019.
//

#include "Game.h"
#include <iostream>
#include "Map.h"
#include "BrannBronzebeard.h"
#include "RenoJackson.h"
#include "JhonMattera.h"
#include "IndianaJhony.h"
#include "TreasureHunters.h"

void Game::Startgame() {
    Map a(40);
    CurRound = 1;
    int NrOfRounds;
    a.SpawnChest();
    a.SetNrOfHunters(4);
    BrannBronzebeard b(a);
    RenoJackson r(a);
    IndianaJhony in(a);
    JhonMattera j(a);
    cout << a << endl << endl;

    cout << "How many rounds do you want to run :";
    cin >> NrOfRounds;
    Rounds = NrOfRounds;
    while (a.getNr() > 0 && a.GetNrOfTreasures() > 0) {
        int iterator = 0;
        while (iterator < Rounds && a.getNr() > 0 && a.GetNrOfTreasures() > 0) {
            cout << "Runda " << CurRound << endl;
            r.move(a);
            in.move(a);
            j.move(a);
            b.move(a);
            cout << endl;
            iterator++;
            CurRound++;
        }
        cout << a << endl << endl;
        if (a.getNr() > 0 && a.GetNrOfTreasures() > 0) {
            cout << "How many rounds do you want to run :";
            cin >> NrOfRounds;
            Rounds = NrOfRounds;
        }

    }
    cout << "Game Over!!!";
}
