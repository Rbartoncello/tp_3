#include "edad_piedra.h"

Edad_piedra::Edad_piedra(Lista<Material>*& inventario_jugador) : Objetivos(EDAD_PIEDRA) {

  descripcion_objetivo = "Debes tener en el inventario " + to_string(OBJETIVO_EDAD_PIEDRA)+ " Piedras";
  this->inventario_jugador = inventario_jugador;

}

void Edad_piedra::mostrar_descripcion(){
    cout << descripcion_objetivo << endl;
    cout << "Actualmente tienes " << inventario_jugador->devolver_material(PIEDRA) << " piedras" << endl;   
    verificar_estado_objetivo();
}

void Edad_piedra::verificar_estado_objetivo(){

    if (inventario_jugador->devolver_material(PIEDRA) >= OBJETIVO_EDAD_PIEDRA)
        objetivo_realizado = true;
}

void Edad_piedra::agregar_datos(int cantidad){}

Edad_piedra::~Edad_piedra(){}