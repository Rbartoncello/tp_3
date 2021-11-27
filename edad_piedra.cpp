#include "edad_piedra.h"

Edad_piedra::Edad_piedra(Inventario*& inventario_jugador) : Objetivos("Comprar Andypolis") {

  descripcion_objetivo = "Debes tener en el inventario 50000 Piedras";
  this->inventario_jugador = inventario_jugador;

}

void Edad_piedra::mostrar_descripcion(){
    cout << descripcion_objetivo << endl;
    //cout << "Actualmente tienes " << inventario_jugador->cantidad_piedra << " piedras" << endl;
}

void Edad_piedra::verificar_estado_objetivo(){

    //if (inventario_jugador->piedra_disponible) == OBJETIVO_EDAD_PIEDRA) buscar en diccionario materiales el inventario del jugador y traer la piedra
      //  objetivo_realizado = true;
    
}

void Edad_piedra::agregar_datos(){}

Edad_piedra::~Edad_piedra(){}