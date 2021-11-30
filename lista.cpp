#include "lista.h"

Lista::Lista()
{
    cantidad_en_lista = 0;
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
    cantidad_en_lista++;
}

Nodo_lista* Lista::obtener_direccion_nodo(int posicion){
    Nodo_lista* auxiliar = primero;

    for (int i = 0; i < posicion; i++)
    {
        auxiliar = auxiliar->direccion_siguiente();
    }
    return (auxiliar);
}

int Lista::obtener_posicion(string nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo_lista* auxiliar = primero;

    while(!elementoEncontrado && i < cantidad_en_lista){
        if(auxiliar->devolver_dato()->devolver_nombre() == nombre){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar->direccion_siguiente();
    }

    if(!elementoEncontrado){
        return -1;
    }
    return i - 1;
}

Nodo_lista*& Lista::retornar_primero(){

    return(primero);
}

int Lista::devolver_cantidad_en_lista(){
    
    return(cantidad_en_lista);
}


Lista::~Lista()
{   
    Nodo_lista* auxiliar;

    if (cantidad_en_lista != 0){
        auxiliar = primero->direccion_siguiente();

        for (int i = 0; i < cantidad_en_lista; i++)
        {
            delete primero;
            primero = auxiliar;
            if (auxiliar!= nullptr)
                auxiliar = primero->direccion_siguiente();
        }
    }
}