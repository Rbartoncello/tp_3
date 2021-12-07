#include "edad_piedra.h"
#include <iomanip>
#include "emojis.h"

Edad_piedra::Edad_piedra(Lista<Material>*& inventario_jugador) : Objetivos(EDAD_PIEDRA) {
  nombre = EDAD_PIEDRA;
  descripcion_objetivo = "Debes tener en el inventario " + to_string(OBJETIVO_EDAD_PIEDRA)+ " Piedras";
  this->inventario_jugador = inventario_jugador;
}

void Edad_piedra::mostrar_descripcion(){
    string completado = EMOJI_MAL;
    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;
    cout << "\t║   " << nombre << "   │ " << descripcion_objetivo << "                    │ "<< setfill(' ') << setw(14) << ( ( (double ) inventario_jugador->devolver_material(PIEDRA) / (double ) OBJETIVO_EDAD_PIEDRA )) * 100 << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

void Edad_piedra::verificar_estado_objetivo(){

    if (inventario_jugador->devolver_material(PIEDRA) >= OBJETIVO_EDAD_PIEDRA)
        objetivo_realizado = true;
}

void Edad_piedra::agregar_datos(int cantidad){}

Edad_piedra::~Edad_piedra(){}