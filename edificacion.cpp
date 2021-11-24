#include "edificacion.h"

Edificacion::Edificacion(string nombre_edificio) {
    nombre = nombre_edificio;
}


Edificacion::Edificacion(string nombre_edificio, int piedra, int madera, int metal, int   maxima_cantidad_permitidos)
{
    nombre = nombre_edificio;
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
}

string Edificacion::devolver_nombre_edificio(){
    return this->nombre;
}

int Edificacion::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}

string Edificacion::devolverNombre(){ 
    
    return (nombre);
}

Edificacion::~Edificacion(){}