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
        const int widthCLI = 200;
        char welcome_msg[32] = "Tankery Wars";
        char difficulty_msg[10] = "Game mode";
        char MsgTanks[15] = "Tank selection";
        char MsgError01[29] = "Please enter a valid option!";

        string terrain_msg = "Stage selection";

        string Tank1 = "[1].[T-28 TANKER 100 LP - 30 DG]";
        string Tank2 = "[2].[T-14 ARMATA 100 LP - 60 DG]";
        string Tank3 = "[3].[LEOPARDO II 150 LP - 15 DG]";
        string Tank4 = "[4].[BLACK NIGHT 100 LP - 25 DG]";

        string Terrain1 = "[1].[POISON SWAMP]";
        string Terrain2 = "[2].[HILLS OF FIRE]";
        string Terrain3 = "[3].[ABYSS OF DEATH]";
        
    public:
        Printer() {
            aHConsole=GetStdHandle(STD_OUTPUT_HANDLE);
            aSBSize=GetLargestConsoleWindowSize(aHConsole);
            keybd_event(VK_F11, 0, 0, 0);
            keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0);
        }

    void jump_lines(int spaces) { for (int i=0;i<spaces;i++) cout<<"\n"; }

    void Locate_printer() {
        for(int i=0;i<30;i++) cout<<" ";
    }

    void Locate_printer_i(char *a) {
        int msg=strlen(a);
        int pos=(int)(((widthCLI)-msg)/2);
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
        char pause_msg[] = "Press any key to continue...";
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
        
        char MsgJugador1[] = "Player 1: ";
        Locate_printer();
        cout<<MsgJugador1;
    }
    
    void Get_Player2_Name() {
        cout<<endl;
        char MsgJugador2[] = "Player 2: ";
        Locate_printer();
        cout<<MsgJugador2;
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

        char MsgDificultad2[] ="Easy: 1         Hard: 2";
        Locate_printer();
        cout<<MsgDificultad2<<"\n\n";

        char MsgDificultad3[] = "> ";
        Locate_printer();
        cout<<MsgDificultad3;
    }

    void Print_Tanks(Jugador *player) {
        system("cls");

        jump_lines(10);
        Locate_printer();

        cout<<MsgTanks<<endl;
        char InputTank1[] = " > ";

        string nombreJ1 = player->GetNombre();
        cout<<"\n\n";

        Locate_printer();
        cout<<Tank1<<"\n\n";
        Locate_printer();
        cout<<Tank2<<"\n\n";
        Locate_printer();
        cout<<Tank3<<"\n\n";
        Locate_printer();
        cout<<Tank4<<"\n\n";
        Locate_printer();

        jump_lines(2);
        Locate_printer();
        cout<<nombreJ1<<InputTank1;
    }

    void Print_terrain() {
        jump_lines(3);
        
        char MsgTerreno4[] = ">";

        Locate_printer();
        cout<<terrain_msg<<"\n\n";
        Locate_printer();
        cout<<Terrain1<<"\n\n";
        Locate_printer();
        cout<<Terrain2<<"\n\n";
        Locate_printer();
        cout<<Terrain3<<"\n\n";
        Locate_printer();
        cout<<MsgTerreno4;

    }

    void Print_Error01() {
        Locate_printer();
        cout<<MsgError01;
        Locate_printer();
        cout<<"> "<<endl;
    }

    void Print_Tank_Info(Jugador *player){
        cout<<"\n\n";

        string nombre = player->GetNombre();
        string player_tank = player->GetTank()->GetNombre();

        char MsgNTank[] = "Tank details: ";
        char MsgVida[] = "LP: ";
        char MsgDaño[] = "Damage: ";
        char MsgPosicion[] = "Coordinates: ";

        Locate_printer();
        cout<<nombre<<endl;

        Locate_printer();
        cout<<MsgNTank<<player_tank<<" - "<<MsgVida<<player->GetTank()->GetVida()<<" - ";
        cout<<MsgDaño<<player->GetTank()->GetDano()<<"pt"<<" - ";
        cout<<MsgPosicion<<player->GetTank()->GetPosicion()<<"m"<<endl;
    }

    void Print_Player_Turn(Jugador *player) {
        cout<<"\n\n";
        Locate_printer();
        cout<<player->GetNombre()<<"'s turn"<<endl;
    }

    void Print_Parameters() {
        char MsgPotencia [] ="Shot Power(0-100): ";
        Locate_printer();
        cout<<MsgPotencia; 
    }


    void Print_Parameters02() {
        cout<<endl;
        char MsgAngulo[] ="Angle(30-80): ";
        Locate_printer();
        cout<<MsgAngulo; 
    }


    void Print_Shot_Impact(int metros) {
        cout<<endl;
        char MsgMetros[] = "[THE SHOT HIT AT] = ";
        Locate_printer();
        cout<<MsgMetros<<metros<<endl;
    }

    void Print_Missed_Shot() {
        cout<<endl;
        char Msg[] = "[NO HUBO IMPACTO]";
        Locate_printer();
        cout<<Msg<<endl;
    }


    void Print__Accurate_Shot() {
        cout<<endl;
        char Msg[] = "[HUBO UN IMPACTO]";
        Locate_printer();
        cout<<Msg<<endl;
    }
    
    void GameOver(Jugador *J) {
        cout<<endl;
        char MsgGameOver[] = "[FIN DEL JUEGO]";
        char MsgGanador[] = "[GANADOR] = ";
        Locate_printer();
        cout<<MsgGameOver<<endl;
        Locate_printer();
        cout<<MsgGanador<<J->GetNombre()<<endl;
        Locate_printer();
    }
};

#endif
