#include "juego.h"
#include "constantes.h"

Juego::Juego(){
    this->materiales = new Materiales();
    this->mapa = new Mapa();
}

Juego::~Juego(){
    delete this->materiales;
    delete this->mapa;
}

bool Juego::se_abrieron_archivos() {
    return (this->materiales->devolver_existe_archivo() && this->mapa->devolver_existe_archivo());
}

void Juego::mostrar() {
    this->materiales->mostrar();
    this->mapa->mostrar();
}
