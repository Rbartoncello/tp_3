#include <iostream>
#include "terreno.h"

using namespace std;

Terreno::Terreno() {
    this->costo = 0;
    puntero_edificio = nullptr;
}

Terreno::Terreno(char tipo_terreno, int pos_x, int pos_y) : Casillero_construible(tipo_terreno, pos_x, pos_y) {
    this->costo = 0;
    puntero_edificio = nullptr;
}

void Terreno::modificar_terreno(string nombre_edificio,int accion){

    if(accion == CONSTRUYENDO)
    {
        crear_edificio(nombre_edificio);
    }
    else if (accion == DEMOLIENDO)
    {
        remover_edificio();
    }
}

void Terreno::crear_edificio(string nombre_edificio){

    if(nombre_edificio == EDIFICIO_OBELISCO){
        puntero_edificio = new Obelisco(nombre_edificio);
    }
    else if(nombre_edificio == EDIFICIO_MINA){
        puntero_edificio = new Mina(nombre_edificio);
    }
    else if(nombre_edificio == EDIFICIO_PLANTA_ELECTRICA){
        puntero_edificio = new Planta(nombre_edificio);
    }
    else if(nombre_edificio == EDIFICIO_ESCUELA){
        puntero_edificio = new Escuela(nombre_edificio);
    }
    else if(nombre_edificio == EDIFICIO_FABRICA){
        puntero_edificio = new Fabrica(nombre_edificio);
    }
    else if(nombre_edificio == EDIFICIO_ASERRADERO){
        puntero_edificio = new Aserradero(nombre_edificio);
    }

}

void Terreno::remover_edificio(){
    delete puntero_edificio;
    puntero_edificio = nullptr;
}

void Terreno::modicar_costo(int costo) {
    this->costo = costo;
}

int Terreno::devolver_costo() {
    return this->costo;
}

Terreno::~Terreno() {
    if (puntero_edificio != nullptr)
        delete puntero_edificio;
}

void Terreno::mostrar(){
    if (!this->esta_ocupado())
        cout << BGND_DARK_GREEN_28 << "  " << END_COLOR;
}
