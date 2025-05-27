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
        
    public:
        Printer() {
            aHConsole=GetStdHandle(STD_OUTPUT_HANDLE);
			aSBSize=GetLargestConsoleWindowSize(aHConsole);
        }
    void print_player(Jugador *player) {
        Locate_printer();
        cout<<player->GetNombre()<<" > ";
    }

    void Print_Welcome() {
        system("cls");
        char MsgBienvenida[] = "Tankery Wars";

		Sleep(10);
		for (int i=0;i<5;i++) cout<<"\n";

		int msg=strlen(MsgBienvenida);
		int pos=(int)(((aSBSize.X)-msg)/3);
		for(int i=0;i<pos;i++) cout<<" ";

		SetConsoleTextAttribute(aHConsole,2);

		for (int i=0;i!=msg;i++) {
			cout<<MsgBienvenida[i];
			Sleep(50);
		}

        cout<<endl<<endl<<endl;
        Print_Tank();
    }

	void Locate_printer() {
		for(int i=0;i<25;i++) cout<<" ";
	}


    void CursorIzquierda(char *a) {
		int msg=strlen(a);
		int pos=(int)(((aSBSize.X)-msg)/4);
		for(int i=0;i<pos;i++) cout<<" ";
	}

    void Print_Tank() {
        char parte1[] = "       ________";
        char parte2[] = "   __/        \\_____________";
        char parte3[] = "   |___         _____________|=====|>";
        char parte4[] = "______|       |_____________";
        char parte5[] = "|___________________________|";
        char parte6[] = "\\_/\\_/\\_/\\_/\\_/\\_/\\_/";
        char* parts[] = {parte1, parte2, parte3, parte4, parte5, parte6}; 
        Print_Tank_aux(parts);
    }

    void Print_Tank_aux(char* a[]) {
        for (int i=0;i<6;i++) {
            Locate_printer();
            cout<<a[i]<<endl;
        }
        cout<<endl;
        Locate_printer();
        system("pause");
    }

    void Get_Player1_Name() {
        system("cls");
        for (int i=0;i<9;i++) cout<<"\n";
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

    void Game_Mode(string &n1, string &n2) {
        system("cls");

        Locate_printer();
        for (int i=0;i<5;i++) cout<<"\n";
        
        Locate_printer();
        cout<<"GET READY!\n\n";
        Locate_printer();

        cout<<n1<<" VS "<<n2<<endl<<endl;

        char MsgDificultad[] = "Game mode";
        Locate_printer();
        cout<<MsgDificultad<<"\n\n";

        char MsgDificultad2[] ="Easy > 1         Hard > 2";
        Locate_printer();
        cout<<MsgDificultad2<<"\n\n";

        char MsgDificultad3[] = "> ";
        Locate_printer();
        cout<<MsgDificultad3;
    }

    void ImpresionTerreno() {
        cout<<endl<<endl<<endl;
        char MsgTerreno[] = "Stage selection";
        char MsgTerreno1[] = "[1].[PANTANO VENENOSO]";
        char MsgTerreno2[] = "[2].[COLINAS DE FUEGO]";
        char MsgTerreno3[] = "[3].[DISTRITO DE MUERTE]";
        char MsgTerreno4[] = ">";

        Locate_printer();
        cout<<MsgTerreno<<"\n\n";
        Locate_printer();
        cout<<MsgTerreno1<<"\n\n";
        Locate_printer();
        cout<<MsgTerreno2<<"\n\n";
        Locate_printer();
        cout<<MsgTerreno3<<"\n\n";
        Locate_printer();
        cout<<MsgTerreno4;

    }

    void ImpresionError01() {
        char MsgError01[] = "Please enter a valid option!";
        Locate_printer();
        cout<<MsgError01;
        Locate_printer();
        cout<<"> "<<endl;
    }


    void ImpresionTanks(Jugador *player) {
        //Jugador *J2 = new Jugador();
        char MsgTanks[] = "Tank selection";
        
        for (int i=0;i<3;i++) cout<<"\n";
        Locate_printer();
        cout<<MsgTanks<<endl;

        char Tank1[] = "[1].[T-28 TANKER 100 LP - 30 DG]";
        char Tank2[] = "[2].[T-14 ARMATA 100 LP - 60 DG]";
        char Tank3[] = "[3].[LEOPARDO II 150 LP - 15 DG]";
        char Tank4[] = "[4].[BLACK NIGHT 100 LP - 25 DG]";
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
        cout<<nombreJ1<<InputTank1;
    }


    void ImprimirInformacionTank(Jugador *player){
        cout<<"\n\n";

        string nombre = player->GetNombre();
        string player_tank = player->GetTank()->GetNombre();

        char MsgNTank[] = "Tank name: ";
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

    void ImprimirTurno(Jugador *player) {
        cout<<"\n\n";
        Locate_printer();
        cout<<player->GetNombre()<<"'s turn"<<endl;
    }

    void ImprimirParametros() {
        char MsgPotencia [] ="Shot Power(0-100): ";
        Locate_printer();
        cout<<MsgPotencia; 
    }


    void ImprimirParametros02() {
        cout<<endl;
        char MsgAngulo[] ="[ANGULO(30-80)] = ";
        Locate_printer();
        cout<<MsgAngulo; 
    }


    void ImpresionMetros(int metros) {
        cout<<endl;
        char MsgMetros[] = "[EL DISPARO IMPACTO EN LA POSICION] = ";
        Locate_printer();
        cout<<MsgMetros<<metros<<endl;
    }

    void ImpresionNoImpacto() {
        cout<<endl;
        char Msg[] = "[NO HUBO IMPACTO]";
        Locate_printer();
        cout<<Msg<<endl;
    }


    void ImpresionImpacto() {
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
