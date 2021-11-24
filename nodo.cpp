#include "nodo.h"

Nodo::Nodo(Edificacion* edificio){
    this->edificio = edificio;
    this->izquierda = NULL;
    this->derecha = NULL;
    this->padre = NULL;
}

Edificacion* Nodo::devolver_edificio() {
    return this->edificio;
}

Nodo* Nodo::devolver_izquierda() {
    return this->izquierda;
}

Nodo* Nodo::devolver_derecha() {
    return this->derecha;
}

Nodo* Nodo::devolver_padre() {
    return this->izquierda;
}

void Nodo::modificar_izquierda(Nodo* izquierda) {
    this->izquierda = izquierda;
}

void Nodo::modificar_derecha(Nodo* derecha) {
    this->derecha = derecha;
}

void Nodo::modificar_padre(Nodo* padre) {
    this->padre = padre;
}

void Nodo::modificar_izquierda(Nodo* izquierda, Nodo* padre) {
    this->izquierda = izquierda;
    this->padre = padre;
}

void Nodo::modificar_derecha(Nodo* derecha, Nodo* padre) {
    this->derecha = derecha;
    this->padre = padre;
}

Nodo::~Nodo(){
    delete this->edificio;
}


