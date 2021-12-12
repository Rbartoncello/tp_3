#include "casillero.h"
#include <iostream>
#include <string>

using namespace std;

Casillero::Casillero(char tipo_terreno, int pos_x, int pos_y){
    this->tipo_terreno = tipo_terreno;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

Casillero::Casillero(){
    this->tipo_terreno = ' ';
    this->pos_x = 0;
    this->pos_y = 0;
}  

char Casillero::devolver_tipo_terreno(){
    return tipo_terreno;
}


string Casillero::devolver_posicion() {
    string posicion =  to_string(pos_y) + " " + to_string(pos_x);
    return posicion;
}

void Casillero::modificar_jugador(Jugador* jugador) {
    this->jugador = jugador;
}

Jugador* Casillero::devolver_jugador() {
    return jugador;
}