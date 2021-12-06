#include "mas_alto_que_las_nubes.h"

Mas_alto_que_las_nubes::Mas_alto_que_las_nubes(Edificacion* &edificios_jugador) : Objetivos(MAS_ALTO_NUBES) {

    cantidad_obelisco = 0;
    descripcion_objetivo = "Debes construir un obelisco";
    this->edificios_jugador = edificios_jugador;
}

void Mas_alto_que_las_nubes::mostrar_descripcion(){
    cout << descripcion_objetivo << endl;
}

void Mas_alto_que_las_nubes::verificar_estado_objetivo(){

    //if (edificios_jugador->validar_existencia_edificio)
      //  objetivo_realizado = true;
}

void Mas_alto_que_las_nubes::agregar_datos(){}


Mas_alto_que_las_nubes::~Mas_alto_que_las_nubes(){}