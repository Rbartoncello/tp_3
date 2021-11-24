#include "edificacion.h"

Edificacion::Edificacion(string tipoEdificacion, string emoji) {
    this->nombre = tipoEdificacion;
    this->emoji = emoji;
}

string Edificacion::devolver_nombre_edificio(){ 
    return this->nombre;
}

string Edificacion::devolver_emoji(){
    return this->emoji;
}

int Edificacion::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}

Edificacion::~Edificacion(){}