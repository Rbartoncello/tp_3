#include "objetivos.h"

Objetivos::Objetivos(){

    objetivo_realizado = false;

}


//void Objetivos::sumar_datos(){

    //Meter los datos de cada objetivo
//}


bool Objetivos::devolver_estado_objetivo(){

    return (objetivo_realizado);
}