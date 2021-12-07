#include "comprar_andypolis.h"
#include <iomanip>
#include "emojis.h"

Comprar_andypolis::Comprar_andypolis(int andycoins_iniciales) : Objetivos(COMPRAR_ANDYPOLIS) {
    nombre = COMPRAR_ANDYPOLIS;
    andycoins_recolectados = 0;
    descripcion_objetivo = "Debes haber juntado " + to_string(OBJETIVO_COMPRAR_ANDYCOINS) + " andycoins a lo largo de la partida";
    andycoins_recolectados = andycoins_iniciales;
}


void Comprar_andypolis::agregar_datos(int sumar_andycoins){
    andycoins_recolectados = andycoins_recolectados + sumar_andycoins;
    verificar_estado_objetivo();
}

void Comprar_andypolis::mostrar_descripcion(){
    string completado = EMOJI_MAL;
    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;
    cout << "\t║ " << nombre << "  │ " << descripcion_objetivo << " │ " << setfill(' ') << setw(14) << ( ( (double ) andycoins_recolectados / (double ) OBJETIVO_COMPRAR_ANDYCOINS )) * 100 << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

void Comprar_andypolis::verificar_estado_objetivo(){

    if (andycoins_recolectados >= OBJETIVO_COMPRAR_ANDYCOINS)
        objetivo_realizado = true;
}

Comprar_andypolis::~Comprar_andypolis(){}