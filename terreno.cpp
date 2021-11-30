#include <iostream>
#include "terreno.h"
#include "interface.h"

using namespace std;

Terreno::Terreno() {
    this->costo = 25;
    edificacion = nullptr;
}

Terreno::Terreno(char tipo_terreno, int pos_x, int pos_y) : Casillero_construible(tipo_terreno, pos_x, pos_y) {
    this->costo = 25;
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
        edificacion = new Obelisco;
    }
    else if(nombre_edificio == EDIFICIO_MINA){
        edificacion = new Mina;
    } 
    else if(nombre_edificio == EDIFICIO_MINA_ORO){
        edificacion = new Mina_oro;
    } 
    else if(nombre_edificio == EDIFICIO_PLANTA_ELECTRICA){
        edificacion = new Planta;
    }
    else if(nombre_edificio == EDIFICIO_ESCUELA){
        edificacion = new Escuela;
    }
    else if(nombre_edificio == EDIFICIO_FABRICA){
        edificacion = new Fabrica;
    }
    else if(nombre_edificio == EDIFICIO_ASERRADERO){
        edificacion = new Aserradero;
    }
}

void Terreno::remover_edificio(){
    delete edificacion;
    edificacion = nullptr;
}

void Terreno::modificar_costo(int costo) {
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
    if(!this->esta_ocupado())
        cout << BGND_DARK_GREEN_28  << "  " << END_COLOR;
    else if (edificacion != nullptr)
        cout << BGND_DARK_GREEN_28  << this->edificacion->devolver_emoji() << END_COLOR;
    else
        cout << BGND_DARK_GREEN_28  << devolver_jugador()->devolver_emoji() << END_COLOR;
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
        if (edificacion != nullptr)
            this->edificacion->imprimir_resumen();
        else
            cout <<"\tSoy el jugador: " << devolver_jugador()->devolver_numero() << " ( " << devolver_jugador()->devolver_emoji() << " ) y me encuentro en el casillero consultado."<< endl;
    } else
        cout << "\tSoy un casillero construible y me encuentro vacío" << endl;
}

void Terreno::mostrar_casillero(Jugador* jugador, int cantidad_construidos){
    imprimir_edificio(this->edificacion, jugador, devolver_pos_y(), devolver_pos_x(),cantidad_construidos);
}

void Terreno::agregar_jugador(Jugador* jugador) {
    modificar_jugador(jugador);
    modificar_ocupado(true);
}

void Terreno::eliminar_jugador() {
    modificar_jugador(nullptr);
    modificar_ocupado(false);
}

void Terreno::mover_jugador(Jugador* jugador) {
    modificar_jugador(jugador);
    modificar_ocupado(true);
}
