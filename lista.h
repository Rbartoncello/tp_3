#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodo_lista.h"
#include "interface.h"

class Lista
{
private:

    int cantidad_en_lista;
    Nodo_lista* primero;

public:

    Lista();

    void agregar_elemento(Material* elemento, int posicion);

    Nodo_lista*& retornar_primero();

    int devolver_cantidad_en_lista();

    ~Lista();

private:

    Nodo_lista* obtener_direccion_nodo(int posicion);

};


#endif