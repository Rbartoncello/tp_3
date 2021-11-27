#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis() : Objetivos("Comprar Andypolis") {

    andycoins_recolectados = 0;
    descripcion_objetivo = "Debes haber juntado 100.000 andycoins a lo largo de la partida (las monedas gastadas también cuentan para este objetivo)";
}


void Comprar_andypolis::agregar_datos(int sumar_andycoins){

    //cantidad_obelisco =+ sumar_andycoins

    //llamar a verificar_estado_objetivo
}

void Comprar_andypolis::mostrar_descripcion(){
    cout << descripcion_objetivo << endl;
    cout << "Actualmente tiene " << andycoins_recolectados << " monedas" << endl;
}

void Comprar_andypolis::verificar_estado_objetivo(){

    if (andycoins_recolectados == OBJETIVO_COMPRAR_ANDYCOINS)
        objetivo_realizado = true;
}

Comprar_andypolis::~Comprar_andypolis(){}