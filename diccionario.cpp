#include <iostream>
#include "diccionario.h"


Diccionario::Diccionario() {
    this->rama = NULL;
}

void Diccionario::insertar(Edificio* edificio) {
    this->rama = insertar(this->rama, edificio);
}

Nodo* Diccionario::insertar(Nodo* nodo, Edificio* edificio) {
    if (nodo == NULL)
        nodo = new Nodo(edificio);
    else if (edificio->devolver_nombre_edificio() > nodo->devolver_edificio()->devolver_nombre_edificio())
        nodo->modificar_derecha(insertar(nodo->devolver_derecha(), edificio), nodo);
    else
        nodo->modificar_izquierda(insertar(nodo->devolver_izquierda(), edificio), nodo);
    return nodo;
}

Receta Diccionario::buscar(string edificio) {
    return buscar(this->rama, edificio)->devolver_edificio()->devolver_receta();
}

Nodo* Diccionario::buscar(Nodo* nodo, string edificio) {
    if (nodo->devolver_edificio()->devolver_nombre_edificio() == edificio)
        return nodo;
    else if (edificio > nodo->devolver_edificio()->devolver_nombre_edificio())
        return buscar(nodo->devolver_derecha(), edificio);
    else 
        return buscar(nodo->devolver_izquierda(), edificio);
    
}

void Diccionario::imprimir_in_orden() {
    imprimir_in_order(this->rama);
}

void Diccionario::imprimir_in_order(Nodo * nodo) {
    if (nodo != NULL){
        imprimir_in_order(nodo->devolver_izquierda());
        std::cout<< nodo->devolver_edificio()->devolver_nombre_edificio() << " " ;
        imprimir_in_order(nodo->devolver_derecha());
    }
}

Nodo* Diccionario::devolver_rama() {
    return this->rama;
}

Diccionario::~Diccionario() {
    borrar_todo();
}

void Diccionario::borrar_todo() {
    borrar_todo(this->rama);
}

void Diccionario::borrar_todo(Nodo* nodo) {
    if (nodo == NULL)
        return;

    borrar_todo(nodo->devolver_izquierda());
    borrar_todo(nodo->devolver_derecha());
    
    delete nodo;
}










