#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodo_lista.h"

template<typename T>
class Lista
{
private:

    int cantidad_en_lista;
    Nodo_lista<T>* primero;

public:

    Lista();

    void agregar_elemento(T* elemento, int posicion);

    Nodo_lista<T>*& retornar_primero();

    int devolver_cantidad_en_lista();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtener_posicion(string nombre);

    ~Lista();



    Nodo_lista<T>* obtener_direccion_nodo(int posicion);

};

template<typename T>
Lista<T>::Lista()
{
    cantidad_en_lista = 0;
    primero = nullptr;
}

template<typename T>
void Lista<T>::agregar_elemento(T* elemento, int posicion){
    Nodo_lista<T>* nuevo = new Nodo_lista<T>(elemento);
    Nodo_lista<T>* posicion_siguiente_nodo;

    if (posicion==1){
        posicion_siguiente_nodo = primero;
        primero = nuevo;
    }
    else{
        Nodo_lista<T>* nodo_anterior_a_posicion;
        nodo_anterior_a_posicion = obtener_direccion_nodo(posicion-2);
        posicion_siguiente_nodo = nodo_anterior_a_posicion->direccion_siguiente();
        nodo_anterior_a_posicion->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(posicion_siguiente_nodo);
    cantidad_en_lista++;
}

template<typename T>
Nodo_lista<T>* Lista<T>::obtener_direccion_nodo(int posicion){
    Nodo_lista<T>* auxiliar = primero;

    for (int i = 0; i < posicion; i++)
    {
        auxiliar = auxiliar->direccion_siguiente();
    }
    return (auxiliar);
}

template<typename T>
Nodo_lista<T>*& Lista<T>::retornar_primero(){

    return(primero);
}

template<typename T>
int Lista<T>::devolver_cantidad_en_lista(){
    
    return(cantidad_en_lista);
}

template<typename T>
int Lista<T>::obtener_posicion(string nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo_lista<T>* auxiliar = primero;

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

template<typename T>
Lista<T>::~Lista()
{   
    Nodo_lista<T>* auxiliar;

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


#endif