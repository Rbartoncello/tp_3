#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "nodo.h"
#include "mapa.h"

using namespace std;

class Diccionario {
    public:
        Nodo* rama;
    public:
        /*
         * Constructor
         * Pre: -.
         * Post: Me va a crear el objeto Diccionario con rama = NULL
         */
        Diccionario();

        /*
         * Pre: -.
         * Post: Me va a insertar el edificio en el Diccionario
         */
        void insertar(Edificio* edificio);

        /*
         * Pre: edificio tiene que estar si o si dentro del diccionario.
         * Post: Me va a la receta del edificio
         */
        Receta* buscar(string edificio);

        /*
         * Pre: -
         * Post: Me va a listar en en orden el diccionario
         */
        void listar_en_orden(Mapa* mapa);

        /*
         * Pre: -
         * Post: Me va a guardar en pre orden el diccionario
         */
        void guardar_pre_orden();
        
        /*
         * Pre: -
         * Post: Devuelve rama
         */
        Nodo* devolver_rama();

        /*
         * Pre: -
         * Post: Devuelve TRUE si el edificio exite dentro del diccionario y FALSE en caso contrario
         */
        bool existe(string edificio);

        /*
         * Pre: -
         * Post: Me va a borrar todas ramas
         */
        void borrar_todo();

        /*
         * Destructor
         * Pre: -.
         * Post: Me va a destruir el objeto Diccionario
         */
        ~Diccionario();
    private:
        /*
         * Pre: -.
         * Post: Me va a insertar el edificio en el Diccionario
         */
        Nodo* insertar(Nodo* nodo, Edificio* edificio);

        /*
         * Pre: -
         * Post: Me va a listar en en orden el diccionario
         */
        void listar_en_orden(Nodo * nodo, Mapa* mapa);

        /*
         * Pre: -
         * Post: Me va a guardar en pre orden el diccionario
         */
        void guardar_pre_orden(Nodo * nodo, ofstream &archivo);

        /*
         * Pre: edificio tiene que estar si o si dentro del diccionario.
         * Post: Me va a la receta del edificio
         */
        Nodo* buscar(Nodo* nodo, string edificio);

        /*
         * Pre: -
         * Post: Devuelve TRUE si el edificio exite dentro del diccionario y FALSE en caso contrario
         */
        bool existe(Nodo* nodo, string edificio);

        /*
         * Pre: -
         * Post: Me va a borrar rama por rama
         */
        void borrar_todo(Nodo* nodo);
};


#endif //DICCIONARIO_H
