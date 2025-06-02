#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>

#include "include/Printer.hpp"
#include "include/Jugador.hpp"
#define PI 3.14159265
using namespace std;



Printer *gImpresion = new Printer();
Jugador *gJugador1 = NULL;
Jugador *gJugador2 = NULL;
int gDificultad = 0;
int gTurno = 0;


void Inicio();
void Menu();
void Menu02();
void Menu02_2();
void Menu03();
void Menu03_2();
void Menu03_3();
void Menu04();
void Menu04_2();
void Turnos();
int END();
void Disparo(Jugador *J1);
int VerificarNumero();


int main() {
    system("cls");
    Inicio();
    return 0;
}


void Inicio() {
    system("cls");
    gImpresion->Print_Welcome();
    Menu();
}

void Menu() {
    gJugador1 = new Jugador();
    gJugador2 = new Jugador();

    gImpresion->Get_Player1_Name();
    string nombre1;
    cin>>nombre1;

    gJugador1->SetNombre(nombre1);
    gImpresion->Get_Player2_Name();
    string nombre2;
    cin>>nombre2;

    gJugador2->SetNombre(nombre2);
    gImpresion->Game_Mode(nombre1, nombre2);

    Menu02();
}


void Menu02() {
    gDificultad = VerificarNumero();
    switch(gDificultad) {
        case 1:
            gDificultad = 1;
            break;
        case 2:
            gDificultad = 2;
            Menu02_2();
            break;
        default:
            gImpresion->Print_Error01();
            Menu02();
    }
    Menu03();
}


void Menu02_2() {
    gImpresion->Print_terrain();
    int terreno = VerificarNumero();
    if (terreno>3 || terreno<1) {
        gImpresion->Print_Error01();
        Menu02_2();
    }
}


void Menu03() {
    gImpresion->Print_Tanks(gJugador1);
    Menu03_2();
    //int TankJ1 = VerificarNumero();
}


void Menu03_2() {
    int TJ1 = VerificarNumero();
    Tanque *TankJ1 = nullptr;
    switch (TJ1) {
        case 1:
            TankJ1 = new Tanque("T-28 TANKER",100,30);
            gJugador1->SetTank(TankJ1);
            break;
        case 2:
            TankJ1 = new Tanque("T-14 Armata",100,60);
            gJugador1->SetTank(TankJ1);
            break;
        case 3:
            TankJ1 = new Tanque("Leopardo II",150,15);
            gJugador1->SetTank(TankJ1);
            break;
        case 4:
            TankJ1 = new Tanque("Black Night",100,25);
            TankJ1->SetEspecial(1);
            gJugador1->SetEspecial(1);
            gJugador1->SetTank(TankJ1);
            break;
        default:
            gImpresion->Print_Error01();
            Menu03_2();
    }

    gImpresion->print_player(gJugador2);
  
    Menu03_3();

}

void Menu03_3() {
    int TJ2 = VerificarNumero();
    Tanque *TankJ2 = nullptr;
    switch (TJ2) {
        case 1:
            TankJ2 = new Tanque("T-28 TANKER",100,30);
            gJugador2->SetTank(TankJ2);
            break;
        case 2:
            TankJ2 = new Tanque("T-14 Armata",100,60);
            gJugador2->SetTank(TankJ2);
            break;
        case 3:
            TankJ2 = new Tanque("Leopardo II",150,15);
            gJugador2->SetTank(TankJ2);
            break;
        case 4:
            TankJ2 = new Tanque("Black Night",100,25);
            TankJ2->SetEspecial(1);
            gJugador2->SetEspecial(1);
            gJugador2->SetTank(TankJ2);
            break;
        default:
            gImpresion->Print_Error01();
            Menu03_3();
    }
    Menu04();
}


void Menu04(){
    system("cls");
    int posicionTank1=0;
    int posicionTank2=0;
    for (int i=0;i<2;i++) {
        posicionTank1 = rand() % 100 + 1;
        posicionTank2 = rand() % 801+200;
    }
    gJugador1->GetTank()->SetPosicion(posicionTank1);
    gJugador2->GetTank()->SetPosicion(posicionTank2);
    cout<<"Game Started!"<<endl<<endl;
    Menu04_2();
}


void Menu04_2() {
    gImpresion->Print_Tank_Info(gJugador1);
    gImpresion->Print_Tank_Info(gJugador2);
    Turnos();
}


void Turnos() {
    switch(gTurno) {
        case 0:
            gImpresion->Print_Player_Turn(gJugador1);
            Disparo(gJugador1);
            break;
        case 1:
            gImpresion->Print_Player_Turn(gJugador2);
            Disparo(gJugador2);
        default:
            break;
    }
    Menu04_2();
}


void Disparo(Jugador *J){
    gImpresion->Print_Parameters();
    int potencia = VerificarNumero();
    if (potencia<0 || potencia>100) {
        cout<<endl;
        gImpresion->Print_Error01();
        Disparo(J);
    }
    gImpresion->Print_Parameters02();
    int angulo = VerificarNumero();
    if (angulo<30 || angulo>80) {
        cout<<endl;
        gImpresion->Print_Error01();
        Disparo(J);
    }

    int metros = (pow(potencia,2)*sin(2*angulo*PI/180))/9.8;
    int posicion = J->GetTank()->GetPosicion();
    if (posicion<=200) {
        Tanque *tEnemigo = gJugador2->GetTank();
        metros+=posicion;
        gImpresion->Print_Shot_Impact(metros);
        int posicion2 = tEnemigo->GetPosicion();
        int dano = J->GetTank()->GetDano();
        if (metros == posicion2 || metros>=(posicion2-10) & metros<=(posicion2+10)) {
            tEnemigo->SetVida(tEnemigo->GetVida()-dano);
            gImpresion->Print__Accurate_Shot();
        }
        else {
            gImpresion->Print_Missed_Shot();
        }
        if (tEnemigo->GetVida()<=0) {
            gImpresion->GameOver(J);
            END();
        }
        if (metros>=(posicion2-30) & metros<=(posicion2+30) & J->GetEspecial() == 1) {
            if (J->GetTank()->GetEspecial() == 1) {
                J->GetTank()->SetEspecial(0);
            }
            else {
                J->GetTank()->SetEspecial(1);
            }
            Menu04_2();
        }
        else {
            gTurno = 1;
            Menu04_2();
        }
    }
    else {
        metros = posicion - metros;
        Tanque *tEnemigo = gJugador1->GetTank();
        gImpresion->Print_Shot_Impact(metros);
        int posicion2 = tEnemigo->GetPosicion();
        int dano = J->GetTank()->GetDano();
        if (metros == posicion2 || metros>=(posicion2-10) & metros<=(posicion2+10)) {
            tEnemigo->SetVida(tEnemigo->GetVida()-dano);
            gImpresion->Print__Accurate_Shot();
        }
        else {
            gImpresion->Print_Missed_Shot();
        }
        if (tEnemigo->GetVida()<=0) {
            gImpresion->GameOver(J);
            END();
        }
        if (metros>=(posicion2-30) & metros<=(posicion2+30) & J->GetTank()->GetEspecial() == 1) {
            if (J->GetTank()->GetEspecial() == 1) {
                J->GetTank()->SetEspecial(0);
            }
            else {
                J->GetTank()->SetEspecial(1);
            }
            Menu04_2();
        }
        else {
            gTurno = 0;
            Menu04_2();
        }
    }
}



int VerificarNumero() {
	int numero;
	while (!(cin>>numero)) {
		cin.clear();
		cin.ignore(10000,'\n');
        gImpresion->Print_Error01();
	}
	return numero;
}

int END() {
    cout<<"\n\n\n";
    system("pause");
    cout<<"\n\n\n";
    exit(-1);
}
