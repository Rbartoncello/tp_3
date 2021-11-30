#include <iostream>
#include "lago.h"

using namespace std;

Lago::Lago() {
    this->costo = 2;
}

Lago::Lago(char tipo_terreno, int pos_x, int pos_y) : Casillero_inaccesible(tipo_terreno, pos_x, pos_y) {
    this->costo = 2;
}

void Lago::modicar_costo(int costo) {
    this->costo = costo;
}

int Lago::devolver_costo() {
    return this->costo;
}

Lago::~Lago() {

}

void Lago::mostrar(){
    if(!this->esta_ocupado())
        cout << BGND_LIGHT_BLUE_68  << "  " << END_COLOR;
    else
        cout << BGND_LIGHT_BLUE_68  << devolver_jugador()->devolver_emoji() << END_COLOR;
}

void Lago::agregar_jugador(Jugador* jugador) {
    modificar_jugador(jugador);
    modificar_ocupado(true);
}

void Lago::eliminar_jugador() {
    modificar_jugador(nullptr);
    modificar_ocupado(false);
}

void Lago::mover_jugador(Jugador* jugador) {
    modificar_jugador(jugador);
    modificar_ocupado(true);
}
