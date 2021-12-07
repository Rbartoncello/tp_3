#include <iomanip>
#include "bombardero.h"
#include "emojis.h"

Bombardero::Bombardero() : Objetivos(BOMBARDERO) {
    nombre = BOMBARDERO;
    bombas_usadas = 0;
    descripcion_objetivo = "Debes haber utilizado " + to_string(OBJETIVO_BOMBARDERO) + " bombas durante la partida";
}


void Bombardero::agregar_datos(int sumar_bombas){

    bombas_usadas = bombas_usadas + sumar_bombas;
    verificar_estado_objetivo();
}

void Bombardero::verificar_estado_objetivo(){

    if (bombas_usadas >= OBJETIVO_BOMBARDERO)
        objetivo_realizado = true;
}

void Bombardero::mostrar_descripcion(){
    string completado = EMOJI_MAL;
    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;
    cout << "\t║     " << nombre << "     │ " << descripcion_objetivo << "             │ " << setfill(' ') << setw(14) << ( ( (double ) bombas_usadas / (double ) OBJETIVO_BOMBARDERO )) * 100 << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

Bombardero::~Bombardero(){}