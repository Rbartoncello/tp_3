#ifndef NODO_LISTA_H
#define NODO_LISTA_H
#include "material.h"

template<typename T>
class Nodo_lista{
    private:
        T* contenido;
        Nodo_lista<T>* siguiente;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Nodo_lista.
         */
        Nodo_lista(string nombre);

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Nodo_lista.
         */
        Nodo_lista(T* contenido);

        /*
         * Pre: -.
         * Post: Me va a cambiar el contenido del nodo.
         */
        void cambiar_dato(T* contenido);
        
        /*
         * Pre: -.
         * Post: Me va a devolver el contenido del nodo.
         */
        T*& devolver_dato();

        /*
         * Pre: -.
         * Post: Devuelve el nombre del nodo.
         */
        string obtener_nombre();

        /*
         * Pre: -.
         * Post: Devuelve el nodo siguiente.
         */
        Nodo_lista<T>*& direccion_siguiente();

        /*
         * Pre: -.
         * Post: Le asigna como siguiente el nodo recibido.
         */
        void cambiar_siguiente(Nodo_lista<T>* nuevo_siguiente);

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Nodo_lista.
         */
        ~Nodo_lista();
};

template<typename T>
Nodo_lista<T>::Nodo_lista(string nombre) {
    contenido = new T(nombre);
    siguiente = nullptr;
}

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
T*& Nodo_lista<T>::devolver_dato(){
    return contenido;
}

template<typename T>
string Nodo_lista<T>::obtener_nombre() {
    return contenido -> devolver_nombre();
}

template<typename T>
Nodo_lista<T>*& Nodo_lista<T>::direccion_siguiente(){
    return siguiente;
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