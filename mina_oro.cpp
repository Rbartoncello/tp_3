#include "mina_oro.h"
#include "constantes.h"
#include "emojis.h"

Mina_oro::Mina_oro(string nombre) : Edificacion (nombre, EDIFICIO_MINA_ORO){
    this->produce_material = true;
    this->cantidad_material = 50;
    this->material_producido = ANDYCOINS;
}

void Mina_oro::imprimir_edificio(){
    cout<< this->emoji;
}

int Mina_oro::devolver_cantidad_material(){
    return this->cantidad_material;
}

string Mina_oro::devolver_emoji() {
    return this->emoji;
}

bool Mina_oro::brinda_material(){
    return this->produce_material;
}

void Mina_oro::hablar_sobre_mi(){
    cout << "SOY UN " + devolver_nombre_edificio() +  " ( "  + devolver_emoji() + " ) Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}
