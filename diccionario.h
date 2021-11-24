#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "nodo.h"

using namespace std;

class Diccionario {
    public:
        Nodo* rama;
    
    public:
        Diccionario();

        void insertar(Edificio* edificio);

        Receta buscar(string edificio);

        void imprimir_in_orden();

        Nodo* devolver_rama();

        void borrar_todo();

        ~Diccionario();
    private:
        Nodo* insertar(Nodo* nodo, Edificio* edificio);

        void imprimir_in_order(Nodo * nodo);

        Nodo* buscar(Nodo* nodo, string edificio);

        void borrar_todo(Nodo* nodo);

};


#endif //DICCIONARIO_H
