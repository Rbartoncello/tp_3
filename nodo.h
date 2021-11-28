#ifndef DICCIONARIO_NODO_H
#define DICCIONARIO_NODO_H
#include "edificacion.h"
#include "material.h"


template<typename T>
class Nodo{
    private:
        T* contenido;
        string clave;
        Nodo<T>* izquierda;
        Nodo<T>* derecha;
        Nodo<T>* padre;
    public:
        /*
         * Constructor
         * Pre: -.
         * Post: Me va a crear el objeto Nodo con edificio = edificio, izquierda = NULL, derecha = NULL y padre = NULL
         */
        Nodo(T* contenido,string clave);

        /*
         * Pre: -.
         * Post: Me va a devolver edificio
         */
        T*& devolver_contenido();

        /*
         * Pre: -.
         * Post: Me va a devolver el nodo de la izquierda
         */
        Nodo<T>*& devolver_izquierda();

        /*
         * Pre: -.
         * Post: Me va a devolver la clave del nodo
         */
        string devolver_clave();

        /*
         * Pre: -.
         * Post: Me va a devolver el nodo de la derecha
         */
        Nodo<T>*& devolver_derecha();

        /*
         * Pre: -.
         * Post: Me va a devolver el nodo padre
         */
        Nodo*& devolver_padre();

        /*
         * Pre: -.
         * Post: Me va a modificar el edificio por edificio
         */
        void modificar_edificio(T* edificio);
        
        /*
         * Pre: -.
         * Post: Me va a modificar el nodo de la izquierda
         */
        void modificar_izquierda(Nodo* izquierda);
        
        /*
         * Pre: -.
         * Post: Me va a modificar el nodo de la derecha
         */
        void modificar_derecha(Nodo* derecha);

        /*
         * Pre: -.
         * Post: Me va a modificar el nodo padre
         */
        void modificar_padre(Nodo* padre);

        /*
         * Pre: -.
         * Post: Me va a modificar el nodo de la izquierda y el padre
         */
        void modificar_izquierda(Nodo* izquierda, Nodo* padre);
        
        /*
         * Pre: -.
         * Post: Me va a modificar el nodo de la derecha y el padre
         */
        void modificar_derecha(Nodo* derecha, Nodo* padre);

        /*
         * Desstructor
         * Pre: -.
         * Post: Me va a destruir el objeto Nodo.
         */
        ~Nodo();
};

template<typename T>
Nodo<T>::Nodo(T* contenido,string clave){
    this->contenido = contenido;
    this->izquierda = NULL;
    this->derecha = NULL;
    this->padre = NULL;
    this->clave = clave;
}

template<typename T>
T*& Nodo<T>::devolver_contenido() {
    return this->contenido;
}

template<typename T>
Nodo<T>*& Nodo<T>::devolver_izquierda() {
    return this->izquierda;
}

template<typename T>
string Nodo<T>::devolver_clave() {
    return this->clave;
}

template<typename T>
Nodo<T>*& Nodo<T>::devolver_derecha() {
    return this->derecha;
}

template<typename T>
Nodo<T>*& Nodo<T>::devolver_padre() {
    return this->izquierda;
}

template<typename T>
void Nodo<T>::modificar_izquierda(Nodo* izquierda) {
    this->izquierda = izquierda;
}

template<typename T>
void Nodo<T>::modificar_derecha(Nodo* derecha) {
    this->derecha = derecha;
}

template<typename T>
void Nodo<T>::modificar_padre(Nodo* padre) {
    this->padre = padre;
}

template<typename T>
void Nodo<T>::modificar_izquierda(Nodo* izquierda, Nodo* padre) {
    this->izquierda = izquierda;
    this->padre = padre;
}

template<typename T>
void Nodo<T>::modificar_derecha(Nodo* derecha, Nodo* padre) {
    this->derecha = derecha;
    this->padre = padre;
}

template<typename T>
Nodo<T>::~Nodo(){

    delete contenido;
}

#endif //DICCIONARIO_NODO_H
