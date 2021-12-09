#include "obj_comprar_andypolis.h"
#include <iomanip>
#include "emojis.h"

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
    verificar_estado_objetivo();
    string completado = EMOJI_MAL;
    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;
    cout << "\t║ " << devolver_tipo_objetivo() << "  │ " << descripcion_objetivo << " │ " << setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Comprar_andypolis::devolver_porcentaje_completado(){
    double porcentaje = ( ( (double ) andycoins_recolectados / (double ) OBJETIVO_COMPRAR_ANDYCOINS )) * 100;
    if (devolver_estado_objetivo())
        porcentaje = 100;

    return porcentaje;
}

void Comprar_andypolis::verificar_estado_objetivo(){
    if (andycoins_recolectados >= OBJETIVO_COMPRAR_ANDYCOINS)
        objetivo_realizado = true;
}

Comprar_andypolis::~Comprar_andypolis(){}