#ifndef NODO_EDIFICIOS_H
#define NODO_EDIFICIOS_H
#include "edificacion.h"

template<typename T>
class Nodo_edificios{
    private:
        T* contenido;
        Nodo_edificios<T>* siguiente;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Nodo_edificios.
         */
        Nodo_edificios(string nombre);

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Nodo_edificios.
         */
        Nodo_edificios(T* contenido);

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

        string obtener_direccion();

        /*
         * Pre: -.
         * Post: Devuelve el nodo siguiente.
         */
        Nodo_edificios<T>*& direccion_siguiente();

        void anular_dato();

        /*
         * Pre: -.
         * Post: Le asigna como siguiente el nodo recibido.
         */
        void cambiar_siguiente(Nodo_edificios<T>* nuevo_siguiente);

        int obtener_cantidad();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Nodo_edificios.
         */
        ~Nodo_edificios();
};

template<typename T>
Nodo_edificios<T>::Nodo_edificios(string nombre) {
    contenido = new T(nombre);
    siguiente = nullptr;
}

template<typename T>
Nodo_edificios<T>::Nodo_edificios(T* contenido){
    this->contenido = contenido;
    siguiente = nullptr;
}

template<typename T>
void Nodo_edificios<T>::cambiar_dato(T* cotenido){
    this->contenido = contenido;
}

template<typename T>
void Nodo_edificios<T>::anular_dato(){
    contenido = NULL;
}

template<typename T>
T*& Nodo_edificios<T>::devolver_dato(){
    return contenido;
}

template<typename T>
string Nodo_edificios<T>::obtener_nombre() {
    return contenido -> devolver_nombre();
}

template<typename T>
string Nodo_edificios<T>::obtener_direccion() {
    return contenido -> devolver_direccion();
}

template<typename T>
int Nodo_edificios<T>::obtener_cantidad() {
    return contenido -> devolver_cantidad();
}

template<typename T>
Nodo_edificios<T>*& Nodo_edificios<T>::direccion_siguiente(){
    return siguiente;
}

template<typename T>
void Nodo_edificios<T>::cambiar_siguiente(Nodo_edificios<T>* nuevo_siguiente){
    siguiente = nuevo_siguiente;
}

template<typename T>
Nodo_edificios<T>::~Nodo_edificios(){}


#endif