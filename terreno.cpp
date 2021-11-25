#include <iostream>
#include "terreno.h"

using namespace std;

Terreno::Terreno() {
    this->costo = 0;
    edificacion = nullptr;
}

Terreno::Terreno(char tipo_terreno, int pos_x, int pos_y) : Casillero_construible(tipo_terreno, pos_x, pos_y) {
    this->costo = 0;
    edificacion = nullptr;
}

void Terreno::modificar_terreno(string nombre_edificio,int accion){
    if(accion == CONSTRUYENDO){
        crear_edificio(nombre_edificio);
    } else if (accion == DEMOLIENDO){
        remover_edificio();
    }
}

void Terreno::crear_edificio(string nombre_edificio){

    if(nombre_edificio == EDIFICIO_OBELISCO){
        edificacion = new Obelisco(nombre_edificio);
    }
    else if(nombre_edificio == EDIFICIO_MINA){
        edificacion = new Mina(nombre_edificio);
    } 
    else if(nombre_edificio == EDIFICIO_MINA_ORO){
        edificacion = new Mina_oro(nombre_edificio);
    } 
    else if(nombre_edificio == EDIFICIO_PLANTA_ELECTRICA){
        edificacion = new Planta(nombre_edificio);
    }
    else if(nombre_edificio == EDIFICIO_ESCUELA){
        edificacion = new Escuela(nombre_edificio);
    }
    else if(nombre_edificio == EDIFICIO_FABRICA){
        edificacion = new Fabrica(nombre_edificio);
    }
    else if(nombre_edificio == EDIFICIO_ASERRADERO){
        edificacion = new Aserradero(nombre_edificio);
    }

}

void Terreno::remover_edificio(){
    delete edificacion;
    edificacion = nullptr;
}

void Terreno::modicar_costo(int costo) {
    this->costo = costo;
}

int Terreno::devolver_costo() {
    return this->costo;
}

Terreno::~Terreno() {
    if (edificacion != nullptr)
        delete edificacion;
}

void Terreno::mostrar(){
    if (!this->esta_ocupado())
        cout << BGND_DARK_GREEN_28 << "  " << END_COLOR;
    else
        cout << BGND_DARK_GREEN_28 << this->edificacion->devolver_emoji()  << END_COLOR;
}

string Terreno::devolver_nombre_edificio(){
    return this->edificacion->devolver_nombre_edificio();
}

void Terreno::agregar_edificio(Edificacion *edificio){
    this->edificacion = edificio;
    modificar_ocupado(true);
}

void Terreno::imprimir_resumen(){
    if(this->esta_ocupado()){
        cout << "\tSoy un casillero construible y no me encuentro vacío" << endl;
        this->edificacion->imprimir_resumen();
    } else
        cout << "\tSoy un casillero construible y me encuentro vacío" << endl;
}