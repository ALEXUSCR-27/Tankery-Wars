#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>

#include "../include/Printer.hpp"
#include "../include/Player.hpp"

#define PI 3.14159265

using namespace std;

Printer* pPrinter = new Printer();
Player* pPlayer1 = nullptr;
Player* pPlayer2 = nullptr;

int pDifficulty = 0;
int pPlayerTurn = 0;


void init();
void getPlayersNameMenu();
void getGameDifficulty();
void getGameTerrain();
void printTanksSelection();
void getPlayerTank();
void getPlayerTank02();
void setPlayersPosition();
void play();
void playerTurns();
void shotAux(int shot_power, int angle, Player *J);
void shotPlayer(Tank *enemy_tank, int shot_impact_position, Player *J);
void shot(Player *J1);
int verifyInput();
int endGame();


int main() {
    system("cls");
    init();

    return 0;
}

void init() {
    system("cls");
    pPrinter->printWelcome();
    getPlayersNameMenu();
}

void getPlayersNameMenu() {
    pPlayer1 = new Player();
    pPlayer2 = new Player();

    pPrinter->printGetPlayer1NameMenu();
    string player1_name;
    cin>>player1_name;

    pPlayer1->setName(player1_name);
    pPrinter->printGetPlayer2NameMenu();
    string player2_name;
    cin>>player2_name;

    pPlayer2->setName(player2_name);
    pPrinter->printGetGameModeMenu(player1_name, player2_name);

    getGameDifficulty();
}

void getGameDifficulty() {
    pDifficulty = verifyInput();
    switch(pDifficulty) {
        case 1:
            pDifficulty = 1;
            break;
        case 2:
            pDifficulty = 2;
            getGameTerrain();
            break;
        default:
            pPrinter->printError01();
            getGameDifficulty();
    }
    printTanksSelection();
}

void getGameTerrain() {
    pPrinter->printGetTerrainSelectionMenu();
    int terrain = verifyInput();
    if (terrain>3 || terrain<1) {
        pPrinter->printError01();
        getGameTerrain();
    }
}

void printTanksSelection() {
    pPrinter->printGetTankSelectionMenu(pPlayer1);
    getPlayerTank();
}

void getPlayerTank() {
    int player1_tank = verifyInput();
    Tank* pPlayer1_tank = nullptr;
    switch (player1_tank) {
        case 1:
            pPlayer1_tank = new Tank("T-28 TANKER",100,30);
            pPlayer1->setTank(pPlayer1_tank);
            break;
        case 2:
            pPlayer1_tank = new Tank("T-14 Armata",100,60);
            pPlayer1->setTank(pPlayer1_tank);
            break;
        case 3:
            pPlayer1_tank = new Tank("Leopardo II",150,15);
            pPlayer1->setTank(pPlayer1_tank);
            break;
        case 4:
            pPlayer1_tank = new Tank("Black Night",100,25);

            pPlayer1_tank->setSpecial(1);
            pPlayer1->setSpecial(1);
            pPlayer1->setTank(pPlayer1_tank);
            break;

        default:
            pPrinter->printError01();
            getPlayerTank();
    }

    pPrinter->printPlayerName(pPlayer2);
    getPlayerTank02();

}

void getPlayerTank02() {
    int player2_tank = verifyInput();
    Tank* pPlayer2_tank = nullptr;
    switch (player2_tank) {
        case 1:
            pPlayer2_tank = new Tank("T-28 TANKER",100,30);
            pPlayer2->setTank(pPlayer2_tank);
            break;
        case 2:
            pPlayer2_tank = new Tank("T-14 Armata",100,60);
            pPlayer2->setTank(pPlayer2_tank);
            break;
        case 3:
            pPlayer2_tank = new Tank("Leopardo II",150,15);
            pPlayer2->setTank(pPlayer2_tank);
            break;
        case 4:
            pPlayer2_tank = new Tank("Black Night",100,25);
            pPlayer2_tank->setSpecial(1);
            pPlayer2->setSpecial(1);
            pPlayer2->setTank(pPlayer2_tank);
            break;
        default:
            pPrinter->printError01();
            getPlayerTank02();
    }
    setPlayersPosition();
}

void setPlayersPosition(){
    system("cls");
    srand (time(NULL));
    int tank1_location=0;
    int tank2_location=0;
    for (int i=0;i<2;i++) {
        tank1_location = rand() % 300 + 1;
        tank2_location = rand() % 900 + 401;
    }
    pPlayer1->getTank()->setPosition(tank1_location);
    pPlayer2->getTank()->setPosition(tank2_location);
    pPrinter->SetTerrainString(tank1_location, tank2_location);
    play();
}

void play() {
    pPrinter->printPlayerTankInfo(pPlayer1);
    pPrinter->printPlayerTankInfo(pPlayer2);
    pPrinter->printStageTerrain();
    playerTurns();
}

void playerTurns() {
    switch(pPlayerTurn) {
        case 0:
            pPrinter->printPlayerTurn(pPlayer1);
            shot(pPlayer1);
            break;
        case 1:
            pPrinter->printPlayerTurn(pPlayer2);
            shot(pPlayer2);
        default:
            break;
    }
    play();
}

void shot(Player *J){
    pPrinter->printShotParameters();
    int shot_power = verifyInput();
    if (shot_power<0 || shot_power>100) {
        cout<<endl;
        pPrinter->printError01();
        shot(J);
    }

    pPrinter->printAngleParameters();
    int angle = verifyInput();
    if (angle<30 || angle>80) {
        cout<<endl;
        pPrinter->printError01();
        shot(J);
    }

    shotAux(shot_power, angle, J);
}

void shotAux(int shot_power, int angle, Player *J) {
    int shot_impact_position = (pow(shot_power,2)*sin(2*angle*PI/180))/9.8;

    int tank_position = J->getTank()->getPosition();
    
    Tank* enemy_tank = nullptr;
    if (tank_position<=300) {
        enemy_tank = pPlayer2->getTank();
        shot_impact_position+=tank_position;
        pPlayerTurn = 1;
    }
    else {
        enemy_tank = pPlayer1->getTank();
        shot_impact_position = tank_position - shot_impact_position;
        pPlayerTurn = 0;
    }

    if (shot_impact_position<0) {shot_impact_position = 0;}
    if (shot_impact_position>1000) {shot_impact_position = 1000;}

    shotPlayer(enemy_tank, shot_impact_position, J);
}

void shotPlayer(Tank *enemy_tank, int shot_impact_position, Player *J) {
    pPrinter->setShotTerrain(shot_impact_position);
    pPrinter->printShotImpact(shot_impact_position);

    int enemy_tank_position = enemy_tank->getPosition();
    int dano = J->getTank()->getDamage();
    if (shot_impact_position == enemy_tank_position || shot_impact_position>=(enemy_tank_position-10) & shot_impact_position<=(enemy_tank_position+10)) {
        enemy_tank->setLife(enemy_tank->getLife()-dano);
        pPrinter->printAccurateShotMsg();
    }
    else {
        pPrinter->printMissedShotMsg();
    }
    if (enemy_tank->getLife()<=0) {
        pPrinter->gameOver(J);
        endGame();
    }
    if (shot_impact_position>=(enemy_tank_position-30) & shot_impact_position<=(enemy_tank_position+30) & J->getSpecial() == 1) {
        if (J->getTank()->getSpecial() == 1) {
            J->getTank()->setSpecial(0);
        }
        else {
            J->getTank()->setSpecial(1);
        }
        play();
    }
}

int verifyInput() {
	int numero;
	while (!(cin>>numero)) {
		cin.clear();
		cin.ignore(10000,'\n');
        pPrinter->printError01();
	}
	return numero;
}

int endGame() {
    cout<<"\n\n\n";
    system("pause");
    cout<<"\n\n\n";
    exit(-1);
}
