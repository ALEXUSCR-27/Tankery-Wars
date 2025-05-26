

#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>
#include "Impresion.hpp"
#include "Jugador.hpp"
#define PI 3.14159265
using namespace std;


Impresion *gImpresion = new Impresion();
Jugador *gJugador1 = NULL;
Jugador *gJugador2 = NULL;
int gDificultad = 0;
int gTurno = 0;

HANDLE gHOut=GetStdHandle(STD_OUTPUT_HANDLE);
COORD gSBSize=GetLargestConsoleWindowSize(gHOut);

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
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
    Inicio();
    return 0;
}


void Inicio() {
    gImpresion->ImpresionPantalla1();
    system("cls");
    Menu();
}

void Menu() {
    gJugador1 = new Jugador();
    gJugador2 = new Jugador();
    gImpresion->ImpresionObtenerNombres();
    string nombre1;
    cin>>nombre1;
    gJugador1->SetNombre(nombre1);
    gImpresion->ImpresionObtenerNombres2();
    string nombre2;
    cin>>nombre2;
    gJugador2->SetNombre(nombre2);
    gImpresion->ImpresionDificultad();
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
            gImpresion->ImpresionError01();
            Menu02();
    }
    Menu03();
}


void Menu02_2() {
    gImpresion->ImpresionTerreno();
    int terreno = VerificarNumero();
    if (terreno>3 || terreno<1) {
        gImpresion->ImpresionError01();
        Menu02_2();
    }
}


void Menu03() {
    system("cls");
    gImpresion->ImpresionTanques(gJugador1);
    
    Menu03_2();
    int TanqueJ1 = VerificarNumero();
}


void Menu03_2() {
    int TJ1 = VerificarNumero();
    Tanque *TanqueJ1 = nullptr;
    switch (TJ1) {
        case 1:
            TanqueJ1 = new Tanque("T-28 Super Tank",100,30);
            gJugador1->SetTanque(TanqueJ1);
            break;
        case 2:
            TanqueJ1 = new Tanque("T-14 Armata",100,60);
            gJugador1->SetTanque(TanqueJ1);
            break;
        case 3:
            TanqueJ1 = new Tanque("Leopardo II",150,15);
            gJugador1->SetTanque(TanqueJ1);
            break;
        case 4:
            TanqueJ1 = new Tanque("Black Night",100,25);
            TanqueJ1->SetEspecial(1);
            gJugador1->SetEspecial(1);
            gJugador1->SetTanque(TanqueJ1);
            break;
        default:
            gImpresion->ImpresionError01();
            Menu03_2();
    }

    gImpresion->ImpresionTanques02(gJugador2);
  
    Menu03_3();

}

void Menu03_3() {
    int TJ2 = VerificarNumero();
    Tanque *TanqueJ2 = nullptr;
    switch (TJ2) {
        case 1:
            TanqueJ2 = new Tanque("T-28 Super Tank",100,30);
            gJugador2->SetTanque(TanqueJ2);
            break;
        case 2:
            TanqueJ2 = new Tanque("T-14 Armata",100,60);
            gJugador2->SetTanque(TanqueJ2);
            break;
        case 3:
            TanqueJ2 = new Tanque("Leopardo II",150,15);
            gJugador2->SetTanque(TanqueJ2);
            break;
        case 4:
            TanqueJ2 = new Tanque("Black Night",100,25);
            TanqueJ2->SetEspecial(1);
            gJugador2->SetEspecial(1);
            gJugador2->SetTanque(TanqueJ2);
            break;
        default:
            gImpresion->ImpresionError01();
            Menu03_3();
    }
    Menu04();
}


void Menu04(){
    system("cls");
    int posicionTanque1=0;
    int posicionTanque2=0;
    for (int i=0;i<2;i++) {
        posicionTanque1 = rand() % 100 + 1;
        posicionTanque2 = rand() % 801+200;
    }
    gJugador1->GetTanque()->SetPosicion(posicionTanque1);
    gJugador2->GetTanque()->SetPosicion(posicionTanque2);
    Menu04_2();
}


void Menu04_2() {
    gImpresion->ImprimirInformacionTanque(gJugador1);
    gImpresion->ImprimirInformacionTanque(gJugador2);
    Turnos();
}


void Turnos() {
    switch(gTurno) {
        case 0:
            gImpresion->ImprimirTurno(gJugador1);
            Disparo(gJugador1);
            break;
        case 1:
            gImpresion->ImprimirTurno(gJugador2);
            Disparo(gJugador2);
        default:
            break;
    }
    Menu04_2();
}


void Disparo(Jugador *J){
    gImpresion->ImprimirParametros();
    int potencia = VerificarNumero();
    if (potencia<0 || potencia>100) {
        cout<<endl;
        gImpresion->ImpresionError01();
        Disparo(J);
    }
    gImpresion->ImprimirParametros02();
    int angulo = VerificarNumero();
    if (angulo<30 || angulo>80) {
        cout<<endl;
        gImpresion->ImpresionError01();
        Disparo(J);
    }

    int metros = (pow(potencia,2)*sin(2*angulo*PI/180))/9.8;
    int posicion = J->GetTanque()->GetPosicion();
    if (posicion<=200) {
        Tanque *tEnemigo = gJugador2->GetTanque();
        metros+=posicion;
        gImpresion->ImpresionMetros(metros);
        int posicion2 = tEnemigo->GetPosicion();
        int dano = J->GetTanque()->GetDano();
        if (metros == posicion2 || metros>=(posicion2-10) & metros<=(posicion2+10)) {
            tEnemigo->SetVida(tEnemigo->GetVida()-dano);
            gImpresion->ImpresionImpacto();
        }
        else {
            gImpresion->ImpresionNoImpacto();
        }
        if (tEnemigo->GetVida()<=0) {
            gImpresion->GameOver(J);
            END();
        }
        if (metros>=(posicion2-30) & metros<=(posicion2+30) & J->GetEspecial() == 1) {
            if (J->GetTanque()->GetEspecial() == 1) {
                J->GetTanque()->SetEspecial(0);
            }
            else {
                J->GetTanque()->SetEspecial(1);
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
        Tanque *tEnemigo = gJugador1->GetTanque();
        gImpresion->ImpresionMetros(metros);
        int posicion2 = tEnemigo->GetPosicion();
        int dano = J->GetTanque()->GetDano();
        if (metros == posicion2 || metros>=(posicion2-10) & metros<=(posicion2+10)) {
            tEnemigo->SetVida(tEnemigo->GetVida()-dano);
            gImpresion->ImpresionImpacto();
        }
        else {
            gImpresion->ImpresionNoImpacto();
        }
        if (tEnemigo->GetVida()<=0) {
            gImpresion->GameOver(J);
            END();
        }
        if (metros>=(posicion2-30) & metros<=(posicion2+30) & J->GetTanque()->GetEspecial() == 1) {
            if (J->GetTanque()->GetEspecial() == 1) {
                J->GetTanque()->SetEspecial(0);
            }
            else {
                J->GetTanque()->SetEspecial(1);
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
        gImpresion->ImpresionError01();
	}
	return numero;
}

int END() {
    cout<<"\n\n\n";
    system("pause");
    cout<<"\n\n\n";
    exit(-1);
}
