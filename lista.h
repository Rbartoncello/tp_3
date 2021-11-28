#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodo_lista.h"
#include "material.h"

class Lista
{
private:

    int cantidadEnLista;
    Nodo_lista* primero;

public:
    Lista();

    void agregar_elemento(Material* elemento, int posicion);

    void mostrarLista();

    ~Lista();

private:

    Nodo_lista* obtener_direccion_nodo(int posicion);
};


#endif