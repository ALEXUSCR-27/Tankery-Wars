#ifndef PRINTER_HPP
#define PRINTER_HPP
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

#include "Jugador.hpp"

using namespace std;

class Printer {
    private:
        HANDLE aHConsole;
		COORD aSBSize;

        const int cli_width = 200;
        char welcome_msg[32] = "Tankery Wars";
        char msg_tanks[15] = "Tank selection";
        char msg_error01[29] = "Please enter a valid option!";
        char msg_player1[11] = "Player 1: ";
        char msg_player2[11] = "Player 2: ";
        char pause_msg[29] = "Press any key to continue...";
        char msg_difficulty02[24] ="Easy: 1         Hard: 2";
        
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
            //PrintTerrainPlayers();
        }

    void jump_lines(int spaces) { for (int i=0;i<spaces;i++) cout<<"\n"; }

    void Locate_printer() {
        for(int i=0;i<30;i++) cout<<" ";
    }

    void Locate_printer_i(char *a) {
        int msg=strlen(a);
        int pos=(int)(((cli_width)-msg)/2);
        for(int i=0;i<pos;i++) cout<<" ";
    }

    void Print_Welcome() {
        system("cls");

		jump_lines(5);
        
		Locate_printer_i(welcome_msg);
        
		SetConsoleTextAttribute(aHConsole,2);

        int msg=strlen(welcome_msg);
		for (int i=0;i!=msg;i++) {
            cout<<welcome_msg[i];
			Sleep(50);
		}
        
        jump_lines(2);
        Locate_printer_i(pause_msg);
        system("pause");
        SetConsoleTextAttribute(aHConsole,7);
        //Print_Tank();
    }
    
    
    
    // void Print_Tank() {
    //     char parte1[] = "________";
    //     char parte2[] = "   __/        \\_____________";
    //     char parte3[] = "           |___         _____________|=====|>";
    //     char parte4[] = "______|       |_____________";
    //     char parte5[] = "|___________________________|";
    //     char parte6[] = "\\_/\\_/\\_/\\_/\\_/\\_/\\_/";
    //     char* parts[] = {parte1, parte2, parte3, parte4, parte5, parte6}; 
    //     Print_Tank_aux(parts);
    // }
    
    // void Print_Tank_aux(char* a[]) {
    //     for (int i=0;i<6;i++) {
    //         Locate_printer_i(a[i]);
    //         cout<<a[i]<<endl;
    //     }
    //     cout<<endl;
    //     Locate_printer_i(a[0]);
    //     system("pause");
    // }
    
    void Get_Player1_Name() {
        system("cls");
        jump_lines(9);
        Locate_printer();
        cout<<msg_player1;
    }
    
    void Get_Player2_Name() {
        cout<<endl;    
        Locate_printer();
        cout<<msg_player2;
    }
    
    void print_player(Jugador *player) {
        Locate_printer();
        cout<<player->GetNombre()<<" > ";
    }

    void Game_Mode(string &n1, string &n2) {
        system("cls");

        Locate_printer();
        jump_lines(10);
        Locate_printer();

        cout<<"GET READY!\n\n";
        Locate_printer();

        cout<<n1<<" VS "<<n2<<endl<<endl;

        jump_lines(9);
        Locate_printer();
        cout<<difficulty_msg<<"\n\n";

        Locate_printer();
        cout<<msg_difficulty02<<"\n\n";

        char MsgDifficulty03[] = "> ";
        Locate_printer();
        cout<<MsgDifficulty03;
    }

    void Print_Tanks(Jugador *player) {
        system("cls");

        jump_lines(10);
        Locate_printer();

        cout<<msg_tanks<<endl;
        char input[] = " > ";

        string player_name = player->GetNombre();
        cout<<"\n\n";

        Locate_printer();
        cout<<tank1<<"\n\n";
        Locate_printer();
        cout<<tank2<<"\n\n";
        Locate_printer();
        cout<<tank3<<"\n\n";
        Locate_printer();
        cout<<tank4<<"\n\n";
        Locate_printer();

        jump_lines(2);
        Locate_printer();
        cout<<player_name<<input;
    }

    void Print_terrain() {
        jump_lines(3);
        
        char input[] = ">";

        Locate_printer();
        cout<<terrain_msg<<"\n\n";
        Locate_printer();
        cout<<terrain1<<"\n\n";
        Locate_printer();
        cout<<terrain2<<"\n\n";
        Locate_printer();
        cout<<terrain3<<"\n\n";
        Locate_printer();
        cout<<input;

    }

    void Print_Error01() {
        Locate_printer();
        cout<<msg_error01;
        Locate_printer();
        cout<<"> "<<endl;
    }

    void Print_Tank_Info(Jugador *player){
        cout<<"\n\n";

        string player_name = player->GetNombre();
        string player_tank = player->GetTank()->GetNombre();

        char MsgNTank[] = "Tank details: ";
        char MsgVida[] = "LP: ";
        char MsgDamage[] = "Damage: ";
        char MsgCoordinates[] = "Coordinates: ";

        Locate_printer();
        cout<<player_name<<endl;

        Locate_printer();
        cout<<MsgNTank<<player_tank<<" - "<<MsgVida<<player->GetTank()->GetVida()<<" - ";
        cout<<MsgDamage<<player->GetTank()->GetDano()<<"pt"<<" - ";
        cout<<MsgCoordinates<<player->GetTank()->GetPosicion()<<"m"<<endl;
    }

    void Print_Player_Turn(Jugador *player) {
        cout<<"\n\n";
        Locate_printer();
        cout<<player->GetNombre()<<"'s turn"<<endl;
    }

    void Print_Parameters() {
        char MsgPower [] ="Shot Power(0-100): ";
        Locate_printer();
        cout<<MsgPower; 
    }


    void Print_Parameters02() {
        cout<<endl;
        char MsgAngle[] ="Angle(30-80): ";
        Locate_printer();
        cout<<MsgAngle; 
    }

    // void PrintTerrainPlayers() {
    //     for (int i=0;i<209;i++) {
    //         cout<<" ";
    //     }
    //     system("pause");
    // }


    void Print_Shot_Impact(int &coordinates) {
        cout<<endl;
        char MsgMeters[] = "The shot landed at: ";
        Locate_printer();
        cout<<MsgMeters<<coordinates<<endl;
    }

    void Print_Missed_Shot() {
        cout<<endl;
        char Msg[] = "Missed shot!";
        Locate_printer();
        cout<<Msg<<endl;
    }


    void Print__Accurate_Shot() {
        cout<<endl;
        char Msg[] = "Direct hit!";
        Locate_printer();
        cout<<Msg<<endl;
    }

    void setTerrain(int player1_position, int player2_position) {
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
        jump_lines(2);
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
    
    void GameOver(Jugador *J) {
        cout<<endl;
        char MsgGameOver[] = "[GAME OVER]";
        char MsgWinner[] = "[WINNER] -> ";
        Locate_printer();
        cout<<MsgGameOver<<endl;
        Locate_printer();
        cout<<MsgWinner<<J->GetNombre()<<endl;
        Locate_printer();
    }
};

#endif
