

#ifndef DICCIONARIO_NODO_H
#define DICCIONARIO_NODO_H

#include "edificio.h"


class Nodo {
    private:
        Edificio* edificio;
        Nodo* izquierda;
        Nodo* derecha;
        Nodo* padre;
    public:
        /*
         * Constructor
         * Pre: -.
         * Post: Me va a crear el objeto Nodo con edificio = edificio, izquierda = NULL, derecha = NULL y padre = NULL
         */
        Nodo(Edificio* edificio);

        /*
         * Pre: -.
         * Post: Me va a devolver edificio
         */
        Edificio* devolver_edificio();

        /*
         * Pre: -.
         * Post: Me va a devolver el nodo de la izquierda
         */
        Nodo* devolver_izquierda();

        /*
         * Pre: -.
         * Post: Me va a devolver el nodo de la derecha
         */
        Nodo* devolver_derecha();

        /*
         * Pre: -.
         * Post: Me va a devolver el nodo padre
         */
        Nodo* devolver_padre();

        /*
         * Pre: -.
         * Post: Me va a modificar el edificio por edificio
         */
        void modificar_edificio(Edificio* edificio);
        
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


#endif //DICCIONARIO_NODO_H
