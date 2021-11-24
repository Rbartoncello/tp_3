#include "edificacion.h"


Edificacion::Edificacion(string tipoEdificacion)
{
    nombre = tipoEdificacion;
}

string Edificacion::devolverNombre(){ 
    
    return (nombre);
}

Edificacion::~Edificacion(){}