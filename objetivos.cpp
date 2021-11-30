#include "objetivos.h"

Objetivos::Objetivos(string nombre_de_objetivo){

    objetivo_realizado = false;
    nombre_objetivo = nombre_de_objetivo;
}

//void Objetivos::sumar_datos(){

//Meter los datos de cada objetivo
//}

string Objetivos::devolver_tipo_objetivo()
{

    return (nombre_objetivo);
}

bool Objetivos::devolver_estado_objetivo()
{

    return (objetivo_realizado);
}

Objetivos::~Objetivos(){};