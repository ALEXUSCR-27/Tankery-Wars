#ifndef PRINTER_HPP
#define PRINTER_HPP
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

#include "Player.hpp"

using namespace std;

class Printer {
    private:
        HANDLE aHConsole; //CLI handler

        const int cli_width = 200;
        char welcome_msg[32] = "Tankery Wars";
        char msg_tanks[15] = "Tank selection";
        char msg_error01[29] = "Please enter a valid option!";
        char msg_player1[11] = "Player 1: ";
        char msg_player2[11] = "Player 2: ";
        char pause_msg[29] = "Press any key to continue...";
        char msg_difficulty02[24] ="Easy: 1         Hard: 2";
        char input [3]= "> ";
        
        const string terrain_msg = "Stage selection";
        const string difficulty_msg = "Game mode";
        const string tank1 = "[1].[T-28 TANKER 100 LP - 30 DG]";
        const string tank2 = "[2].[T-14 ARMATA 100 LP - 60 DG]";
        const string tank3 = "[3].[LEOPARDO II 150 LP - 15 DG]";
        const string tank4 = "[4].[BLACK NIGHT 100 LP - 25 DG]";

        const string terrain1 = "[1].[POISON SWAMP]";
        const string terrain2 = "[2].[HILLS OF FIRE]";
        const string terrain3 = "[3].[ABYSS OF DEATH]";
        char stage_terrain[200];
        
    public:
        Printer() {
            aHConsole=GetStdHandle(STD_OUTPUT_HANDLE);
            
            // set full screen mode by resizing the console window
            keybd_event(VK_F11, 0, 0, 0);
            keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0);
        }
    
    // function just to jump lines
    void jumpLines(int spaces) { for (int i=0;i<spaces;i++) cout<<"\n"; }

    // function to locate the printer in the left side of the CLI
    void locatePrinter() {
        for(int i=0;i<30;i++) cout<<" ";
    }

    void locatePrinter02(char *a) {
        int msg=strlen(a);
        int pos=(int)(((cli_width)-msg)/2);
        for(int i=0;i<pos;i++) cout<<" ";
    }

    void printWelcome() {
        system("cls");

		jumpLines(5);
		locatePrinter02(welcome_msg);
		SetConsoleTextAttribute(aHConsole,2);

        int msg=strlen(welcome_msg);
		for (int i=0;i!=msg;i++) {
            cout<<welcome_msg[i];
			Sleep(50);
		}
        
        jumpLines(2);
        locatePrinter02(pause_msg);
        system("pause");
        SetConsoleTextAttribute(aHConsole,7);
    }
    
    
    void printGetPlayer1NameMenu() {
        system("cls");
        jumpLines(9);
        locatePrinter();
        cout<<msg_player1;
    }
    
    void printGetPlayer2NameMenu() {
        cout<<endl;    
        locatePrinter();
        cout<<msg_player2;
    }
    
    void printPlayerName(Player *player) {
        locatePrinter();
        cout<<player->getName()<<" > ";
    }

    void printGetGameModeMenu(string &n1, string &n2) {
        system("cls");

        locatePrinter();
        jumpLines(10);
        locatePrinter();

        cout<<"GET READY!\n\n";
        locatePrinter();

        cout<<n1<<" VS "<<n2<<endl<<endl;

        jumpLines(9);
        locatePrinter();
        cout<<difficulty_msg<<"\n\n";

        locatePrinter();
        cout<<msg_difficulty02<<"\n\n";

        //char MsgDifficulty03[] = "> ";
        locatePrinter();
        cout<<input;
    }

    void printGetTankSelectionMenu(Player *player) {
        system("cls");

        jumpLines(10);
        locatePrinter();
        cout<<msg_tanks<<endl;

        string player_name = player->getName();
        cout<<"\n\n";

        locatePrinter();
        cout<<tank1<<"\n\n";
        locatePrinter();
        cout<<tank2<<"\n\n";
        locatePrinter();
        cout<<tank3<<"\n\n";
        locatePrinter();
        cout<<tank4<<"\n\n";
        locatePrinter();

        jumpLines(2);
        locatePrinter();
        cout<<player_name<<input;
    }

    void printGetTerrainSelectionMenu() {
        jumpLines(3);
        locatePrinter();
        cout<<terrain_msg<<"\n\n";
        locatePrinter();
        cout<<terrain1<<"\n\n";
        locatePrinter();
        cout<<terrain2<<"\n\n";
        locatePrinter();
        cout<<terrain3<<"\n\n";
        locatePrinter();
        cout<<input;
    }

    void printError01() {
        locatePrinter();
        cout<<msg_error01;
        locatePrinter();
        cout<<input<<endl;
    }

    void printPlayerTankInfo(Player *player){
        cout<<"\n\n";

        string player_name = player->getName();
        string player_tank = player->getTank()->getName();

        char MsgVida[] = "LP: ";
        char MsgDamage[] = "Damage: ";
        char MsgCoordinates[] = "Coordinates: ";


        cout<<player_name<<endl;
        cout<<player_tank<<endl<<MsgVida<<player->getTank()->getLife()<<"pt"<<endl;
        cout<<MsgDamage<<player->getTank()->getDamage()<<"pt"<<endl;
        cout<<MsgCoordinates<<player->getTank()->getPosition()<<"m"<<endl;
    }

    void printPlayerTurn(Player *player) {
        cout<<"\n\n";
        locatePrinter();
        cout<<player->getName()<<"'s turn"<<endl;
    }

    void printShotParameters() {
        char MsgPower [] ="Shot Power(0-100): ";
        locatePrinter();
        cout<<MsgPower; 
    }


    void printAngleParameters() {
        cout<<endl;
        char MsgAngle[] ="Angle(30-80): ";
        locatePrinter();
        cout<<MsgAngle; 
    }

    void printShotImpact(int coordinates) {
        SetConsoleTextAttribute(aHConsole, 4);
        cout<<endl;
        char MsgMeters[] = "The shot landed at: ";
        locatePrinter();
        cout<<MsgMeters<<coordinates<<endl;
        SetConsoleTextAttribute(aHConsole, 7);
    }

    void printMissedShotMsg() {
        cout<<endl;
        char Msg[] = "Missed shot!";
        locatePrinter();
        cout<<Msg<<endl;
    }

    void printAccurateShotMsg() {
        cout<<endl;
        char Msg[] = "Direct hit!";
        locatePrinter();
        cout<<Msg<<endl;
    }

    void SetTerrainString(int player1_position, int player2_position) {
        int terrain = 1000*0.20;
        int player1_resized_position = player1_position*0.20;
        int player2_resized_position = player2_position*0.20;
        for (int i=0;i<terrain;i++) {
            if (i == player1_resized_position) {
                stage_terrain[i] = '1';
            } else if (i == player2_resized_position) {
                stage_terrain[i] = '2';
            } else {
                stage_terrain[i] = '_';
            }
        }
        cout<<endl;
    }

    void printStageTerrain() {
        SetConsoleTextAttribute(aHConsole, 2);
        jumpLines(2);
        cout<<"     ";
        for (int i=0;i<200;i++) {
            cout<<stage_terrain[i];
        }
        cout<<endl;
        SetConsoleTextAttribute(aHConsole, 7);
    }

    void setShotTerrain(int position_shot) {
        int resized_position = position_shot*0.20;
        if (stage_terrain[resized_position]!='1' and stage_terrain[resized_position]!='2') {
            stage_terrain[resized_position] = 'X';
        }
    }
    
    void gameOver(Player *J) {
        cout<<endl;
        char MsgGameOver[] = "[GAME OVER]";
        char MsgWinner[] = "[WINNER] -> ";
        locatePrinter();
        cout<<MsgGameOver<<endl;
        locatePrinter();
        cout<<MsgWinner<<J->getName()<<endl;
        locatePrinter();
    }
};

#endif
