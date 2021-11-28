#include "nodo_lista.h"

Nodo_lista::Nodo_lista(Material* contenido){
    this->contenido = contenido;
    siguiente = nullptr;
}

void Nodo_lista::cambiar_dato(Material* cotenido){

    this->contenido = contenido;
}

Nodo_lista*& Nodo_lista::direccion_siguiente(){

    return (siguiente);
}

Material*& Nodo_lista::devolver_dato(){

    return (contenido);
}

void Nodo_lista::cambiar_siguiente(Nodo_lista* nuevo_siguiente){

    siguiente = nuevo_siguiente;
}

Nodo_lista::~Nodo_lista(){
    delete contenido;

}