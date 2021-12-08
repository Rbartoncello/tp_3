#include "edificacion.h"

Edificacion::Edificacion(string tipoEdificacion, string emoji) {
    this->nombre = tipoEdificacion;
    this->emoji = emoji;
    this->fue_atacado = false;
}

void Edificacion::modificar_duenio(int duenio){
    this->duenio = duenio;
}

string Edificacion::devolver_nombre_edificio(){ 
    return this->nombre;
}

string Edificacion::devolver_emoji(){
    return this->emoji;
}

int Edificacion::devolver_duenio(){
    return this->duenio;
}

int Edificacion::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}

bool Edificacion::devolver_reparable(){
    return this->reparable;
}

string Edificacion::devolver_direccion(){
    return this->direccion;
}

void Edificacion::agregar_direccion(int fila, int columna){
    direccion = to_string(fila) + to_string(columna);
}

Edificacion::~Edificacion(){}

void Edificacion::imprimir_resumen(){
    cout <<"\tSoy un edificio de nombre " << nombre << " ( " << emoji << " ) y me encuentro en el casillero consultado."<< endl;
}

bool Edificacion::devolver_fue_atacado(){
    return this->fue_atacado;
}

void Edificacion::fue_atacado_true(){
    this->fue_atacado=true;
}

void Edificacion::fue_atacado_false(){
    this->fue_atacado=false;
}