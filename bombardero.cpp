#include "bombardero.h"

Bombardero::Bombardero() : Objetivos("Bombardero") {

    bombas_usadas = 0;
    descripcion_objetivo = "Debes haber utilizado 5 bombas durante la partida";
}


void Bombardero::agregar_datos(int sumar_andycoins){

    //cantidad_obelisco =+ sumar_andycoins

    //llamar a verificar_estado_objetivo
}

void Bombardero::verificar_estado_objetivo(){

    if (bombas_usadas == OBJETIVO_BOMBARDERO)
        objetivo_realizado = true;
}

void Bombardero::mostrar_descripcion(){
    cout << descripcion_objetivo << endl;
    cout << "Actualmente ha usado " << bombas_usadas << " bombas" << endl;
}

Bombardero::~Bombardero(){}