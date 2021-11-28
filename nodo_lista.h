#ifndef NODO_LISTA_H
#define NODO_LISTA_H
#include "material.h"

class Nodo_lista
{
private:
    
    Material* contenido;
    Nodo_lista* siguiente;

public:

    Nodo_lista(Material* contenido);

    void cambiar_dato(Material* contenido);

    Material*& devolver_dato();

    Nodo_lista*& direccion_siguiente();

    void cambiar_siguiente(Nodo_lista* nuevo_siguiente);
    
    ~Nodo_lista();
};


#endif