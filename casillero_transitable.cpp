#include "casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_transitable::Casillero_transitable(): Casillero(){

}

bool Casillero_transitable::esta_ocupado(){
    return this->ocupado;
}

void Casillero_transitable::imprimir_resumen(){
    if(this->esta_ocupado()){
        cout << "\tSoy un casillero transitable y no me encuentro vacío" << endl;
        this->material->imprimir_resumen();
    }else{
        cout << "\tSoy un casillero transitable y me encuentro vacío" << endl;
    }
}