#include "juego.h"
#include "constantes.h"

Juego::Juego(){
    this->materiales = new Materiales();
}

Juego::~Juego(){
    delete this->materiales;
}

bool Juego::se_abrieron_archivos() {
    return (this->materiales->devolver_existe_archivo());
}

void Juego::mostrar() 
{
    this->materiales->mostrar();
}
