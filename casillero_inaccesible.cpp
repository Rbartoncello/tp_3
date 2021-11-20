#include "casillero_inaccesible.h"

using namespace std;

Casillero_inaccesible::Casillero_inaccesible(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_inaccesible::Casillero_inaccesible(): Casillero(){

}

bool Casillero_inaccesible::esta_ocupado(){
    return this->ocupado;
}