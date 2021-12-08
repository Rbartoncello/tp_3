#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodo_lista.h"
#include "constantes.h"
#include "material.h"


template<typename T>
class Lista{
    private:
        int cantidad_en_lista;
        Nodo_lista<T>* primero;
        Nodo_lista<T>* ultimo;    
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Lista.
         */
        Lista();

        /*
         * Pre: posicion >= cantidad lista.
         * Post: Me agrega un nuevo elemento a la lista en la posicion ingresada.
         */
        void agregar_elemento(T* elemento, int posicion);

        /*
         * Pre: -.
         * Post: Me agrega un nuevo elemento a la lista.
         */
        void agregar(string nuevo_elemento);

        /*
         * Pre: -.
         * Post: Me devuelve el primer elemento de la lista.
         */
        Nodo_lista<T>*& retornar_primero();

        /*
         * Pre: -.
         * Post: Me devuelve la cantidad de elementos de la lista.
         */
        int devolver_cantidad_en_lista();


        int obtener_cantidad(int posicion);

        /*
         * Pre: -.
         * Post: Me devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra.
         */
        int obtener_posicion(string nombre);

        int devolver_material(string material);

        /*
         * Pre: -.
         * Post: Me devuelve el nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra.
         */
        string obtener_nombre(int posicion);

        /*
         * Pre: posicion >= cantidad lista.
         * Post: Me devuelve la direccion del nodo de esa posicion.
         */
        Nodo_lista<T>* obtener_direccion_nodo(int posicion);

        /*
         * Pre: la posicion del elemento a eliminar
         * Post: elimina el elemento de la listas
         */
        void remover_elemento(int posicion);
        
        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Lista.
         */
        ~Lista();
};

template<typename T>
Lista<T>::Lista(){
    cantidad_en_lista = 0;
    primero = nullptr;
    ultimo = nullptr;
}

template<typename T>
void Lista<T>::agregar_elemento(T* elemento, int posicion){
    Nodo_lista<T>* nuevo = new Nodo_lista<T>(elemento);
    Nodo_lista<T>* auxiliar;

    if (posicion==1){
        auxiliar = primero;
        primero = nuevo;
    }
    else{
        Nodo_lista<T>* nodo_anterior_a_posicion;
        nodo_anterior_a_posicion = obtener_direccion_nodo(posicion-1);
        auxiliar = nodo_anterior_a_posicion->direccion_siguiente();
        nodo_anterior_a_posicion->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(auxiliar);
    cantidad_en_lista++;
}

template <typename T>
void Lista<T>::remover_elemento(int posicion){
    
    Nodo_lista<T> *posicion_siguiente_nodo;

    if (posicion == 1)
    {
        posicion_siguiente_nodo = primero->direccion_siguiente();
        delete primero;
        primero = posicion_siguiente_nodo;
    }
    else
    {
        Nodo_lista<T> *nodo_anterior_a_posicion;
        Nodo_lista<T> *posicion_nodo_a_eliminar;
        nodo_anterior_a_posicion = obtener_direccion_nodo(posicion-1);
        posicion_nodo_a_eliminar = nodo_anterior_a_posicion->direccion_siguiente();
        posicion_siguiente_nodo = posicion_nodo_a_eliminar->direccion_siguiente();
        delete posicion_nodo_a_eliminar;
        nodo_anterior_a_posicion->cambiar_siguiente(posicion_siguiente_nodo);
    }
    cantidad_en_lista--;
}

template < typename T >
void Lista<T>::agregar(string nuevo_elemento) {
    Nodo_lista<T>* nuevo_nodo = new Nodo_lista<T>(nuevo_elemento);
    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo -> cambiar_siguiente(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
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
    return primero;
}

template<typename T>
int Lista<T>::devolver_cantidad_en_lista(){
    return cantidad_en_lista;
}

template<typename T>
int Lista<T>::obtener_posicion(string nombre) {
    bool elemento_encontrado = false;
    int i = 0;
    Nodo_lista<T>* auxiliar = primero;

    while(!elemento_encontrado && i < cantidad_en_lista){
        if(auxiliar->devolver_dato()->devolver_nombre() == nombre){
            elemento_encontrado = true;
        }
        i++;
        auxiliar = auxiliar->direccion_siguiente();
    }

    if(!elemento_encontrado)
        return -1;
    
    return i - 1;
}
template<typename T>
int Lista<T>::devolver_material(string material){
    for (int i = 0; i < cantidad_en_lista; ++i) {
        if(this->obtener_nombre(i+1) == material)
        {
            return this->obtener_direccion_nodo(i)->obtener_cantidad();
        }
    }
    return ERROR;
}

template<typename T>
int Lista<T>::obtener_cantidad(int posicion) {
    int i = 0;
    Nodo_lista<T>* auxiliar = primero;

    if(posicion > cantidad_en_lista){
        return ERROR;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> direccion_siguiente();
        i++;
    }
    return auxiliar -> obtener_cantidad();
}

template<typename T>
Lista<T>::~Lista(){   
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

template<typename T>
string Lista<T>::obtener_nombre(int posicion) {
    int i = 0;
    Nodo_lista<T>* auxiliar = primero;

    if(posicion > cantidad_en_lista){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> direccion_siguiente();
        i++;
    }
    return auxiliar -> obtener_nombre();
}

#endif