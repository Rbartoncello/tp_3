#include "lista.h"

Lista::Lista()
{
    cantidadEnLista = 0;
    primero = nullptr;
}

void Lista::agregar_elemento(Material* elemento, int posicion){
    Nodo_lista* nuevo = new Nodo_lista(elemento);
    Nodo_lista* posicion_siguiente_nodo;

    if (posicion==1){
        posicion_siguiente_nodo = primero;
        primero = nuevo;
    }
    else{
        Nodo_lista* nodo_anterior_a_posicion;
        nodo_anterior_a_posicion = obtener_direccion_nodo(posicion-2);
        posicion_siguiente_nodo = nodo_anterior_a_posicion->direccion_siguiente();
        nodo_anterior_a_posicion->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(posicion_siguiente_nodo);
    cantidadEnLista++;
}

Nodo_lista* Lista::obtener_direccion_nodo(int posicion){
    Nodo_lista* auxiliar = primero;

    for (int i = 0; i < posicion; i++)
    {
        auxiliar = auxiliar->direccion_siguiente();
    }
    return (auxiliar);
}

void Lista::mostrarLista(){
    Nodo_lista* auxiliar = primero;

    encabezado_materiale_jugador();

    for (int i = 0; i < cantidadEnLista; i++)
    {
        imprimir_lista_materiales_jugador(auxiliar->devolver_dato());
        auxiliar = auxiliar->direccion_siguiente();
    }
    
}


Lista::~Lista()
{   
    Nodo_lista* auxiliar;

    if (cantidadEnLista != 0){
        auxiliar = primero->direccion_siguiente();

        for (int i = 0; i < cantidadEnLista; i++)
        {
            delete primero;
            primero = auxiliar;
            if (auxiliar!= nullptr)
                auxiliar = primero->direccion_siguiente();
        }
    }
}