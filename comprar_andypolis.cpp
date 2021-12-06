#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis(int andycoins_iniciales) : Objetivos(COMPRAR_ANDYPOLIS) {

    andycoins_recolectados = 0;
    descripcion_objetivo = "Debes haber juntado " + to_string(OBJETIVO_COMPRAR_ANDYCOINS) + " andycoins a lo largo de la partida";
    andycoins_recolectados = andycoins_iniciales;
}


void Comprar_andypolis::agregar_datos(int sumar_andycoins){
    andycoins_recolectados = andycoins_recolectados + sumar_andycoins;
    verificar_estado_objetivo();
}

void Comprar_andypolis::mostrar_descripcion(){
    cout << descripcion_objetivo << endl;
    cout << "Actualmente tiene " << andycoins_recolectados << " monedas" << endl;
}

void Comprar_andypolis::verificar_estado_objetivo(){

    if (andycoins_recolectados >= OBJETIVO_COMPRAR_ANDYCOINS)
        objetivo_realizado = true;
}

Comprar_andypolis::~Comprar_andypolis(){}