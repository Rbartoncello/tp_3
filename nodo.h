

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
        Nodo();

        Nodo(Edificio* edificio);

        Edificio* devolver_edificio();

        Nodo* devolver_izquierda();
        Nodo* devolver_derecha();
        Nodo* devolver_padre();

        void modificar_edificio(Edificio* edificio);
        
        void modificar_izquierda(Nodo* izquierda);
        
        void modificar_derecha(Nodo* derecha);

        void modificar_padre(Nodo* padre);

        void modificar_izquierda(Nodo* izquierda, Nodo* padre);
        
        void modificar_derecha(Nodo* derecha, Nodo* padre);

        bool es_hoja();

        bool es_izquierda_solamente();

        bool es_derecha_solamente();

        ~Nodo();
};


#endif //DICCIONARIO_NODO_H
