#include "juego.h"
#include "constantes.h"
#include "interface.h"

Juego::Juego(){
    this->materiales = new Materiales();
    this->mapa = new Mapa();
}

Juego::~Juego(){
    delete this->materiales;
    delete this->mapa;
}

int Juego::cargar() {
    int ejecucion = 0;

    if( this->materiales->leer_archivo() == ERROR )
        ejecucion = ERROR;
    else if ( this->mapa->leer_archivo() == ERROR )
        ejecucion = ERROR;

    return ejecucion;
}

void Juego::mostrar() {
    imprimir_mensaje_bienvenida();
    imprimir_menu_principal();
    imprimir_menu_juego();
    imprimir_objetos_mapa();
    this->materiales->mostrar();
    this->mapa->mostrar();
}
