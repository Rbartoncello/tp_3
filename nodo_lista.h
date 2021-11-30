#ifndef NODO_LISTA_H
#define NODO_LISTA_H
#include "material.h"

template<typename T>
class Nodo_lista
{
private:
    
    T* contenido;
    Nodo_lista<T>* siguiente;

public:

    Nodo_lista(T* contenido);

    void cambiar_dato(T* contenido);

    T*& devolver_dato();

    Nodo_lista<T>*& direccion_siguiente();

    void cambiar_siguiente(Nodo_lista<T>* nuevo_siguiente);
    
    ~Nodo_lista();
};

template<typename T>
Nodo_lista<T>::Nodo_lista(T* contenido){
    this->contenido = contenido;
    siguiente = nullptr;
}

template<typename T>
void Nodo_lista<T>::cambiar_dato(T* cotenido){

    this->contenido = contenido;
}

template<typename T>
Nodo_lista<T>*& Nodo_lista<T>::direccion_siguiente(){

    return (siguiente);
}

template<typename T>
T*& Nodo_lista<T>::devolver_dato(){

    return (contenido);
}

template<typename T>
void Nodo_lista<T>::cambiar_siguiente(Nodo_lista<T>* nuevo_siguiente){

    siguiente = nuevo_siguiente;
}

template<typename T>
Nodo_lista<T>::~Nodo_lista(){
    delete contenido;

}


#endif