#include "obj_armado.h"
#include <iomanip>
#include "emojis.h"

Armado::Armado(Lista<Material>*& inventario_jugador) : Objetivos(ARMADO) {
    nombre = ARMADO;
    descripcion_objetivo = "Debes tener en el inventario " + to_string(OBJETIVO_ARMADO)+ " Bombas";
    this->inventario_jugador = inventario_jugador;
}

void Armado::mostrar_descripcion(){
    verificar_estado_objetivo();
    string completado = EMOJI_MAL;
    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;
    cout << "\t║       " << nombre << "       │ " << descripcion_objetivo << "                        │ "<< setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Armado::devolver_porcentaje_completado(){
    double porcentaje = ( ( (double) inventario_jugador->devolver_material(BOMBA) / (double) OBJETIVO_ARMADO )) * 100;
    if (devolver_estado_objetivo()){
        porcentaje = 100;
    }

    return porcentaje;
}

void Armado::verificar_estado_objetivo(){
    if ( !objetivo_realizado ){
        if (inventario_jugador->devolver_material(BOMBA) >= OBJETIVO_ARMADO)
            objetivo_realizado = true;
    }
}

void Armado::agregar_datos(int cantidad){}

Armado::~Armado(){}