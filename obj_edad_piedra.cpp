#include "obj_edad_piedra.h"
#include <iomanip>
#include "emojis.h"

Edad_piedra::Edad_piedra(Lista<Material>*& inventario_jugador) : Objetivos(EDAD_PIEDRA) {
    descripcion_objetivo = "Debes tener en el inventario " + to_string(OBJETIVO_EDAD_PIEDRA)+ " Piedras";
    this->inventario_jugador = inventario_jugador;
}

void Edad_piedra::mostrar_descripcion(){
    verificar_estado_objetivo();
    string completado = EMOJI_MAL;
    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;
    cout << "\t║   " << devolver_tipo_objetivo() << "   │ " << descripcion_objetivo << "                    │ "<< setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Edad_piedra::devolver_porcentaje_completado(){
    double porcentaje = ( ( (double) inventario_jugador->devolver_material(PIEDRA) / (double) OBJETIVO_EDAD_PIEDRA )) * 100;
    if (devolver_estado_objetivo())
        porcentaje = 100;

    return porcentaje;
}

void Edad_piedra::verificar_estado_objetivo(){
    if ( !objetivo_realizado ){
        if (inventario_jugador->devolver_material(PIEDRA) >= OBJETIVO_EDAD_PIEDRA)
            objetivo_realizado = true;
    }
}

void Edad_piedra::agregar_datos(int cantidad){}

Edad_piedra::~Edad_piedra(){}