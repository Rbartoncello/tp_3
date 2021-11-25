#include "casillero_construible.h"

using namespace std;

Casillero_construible::Casillero_construible(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_construible::Casillero_construible(): Casillero(){

}

bool Casillero_construible::esta_ocupado(){
    return this->ocupado;
}

Casillero_construible::~Casillero_construible(){}

void Casillero_construible::imprimir_resumen(){
    if(this->esta_ocupado()){
        cout << "\tSoy un casillero construible y no me encuentro vacío" << endl;
        this->edificio->imprimir_resumen();
    }else{
        cout << "\tSoy un casillero construible y me encuentro vacío" << endl;
    }
}