#include "casillero_inaccesible.h"

using namespace std;

Casillero_inaccesible::Casillero_inaccesible(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_inaccesible::Casillero_inaccesible(): Casillero(){

}

void Casillero_inaccesible::modificar_terreno(string elemento,int accion){}


bool Casillero_inaccesible::esta_ocupado(){
    return this->ocupado;
}

void Casillero_inaccesible::imprimir_resumen(){
    cout <<"\tSoy un casillero inaccesible y me encuentro vacío" << endl;
}

void Casillero_inaccesible::modificar_ocupado(bool estado) {
    this->ocupado = estado;
}

Material* Casillero_inaccesible::devolver_material(){return nullptr;}