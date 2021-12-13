#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H

#include <string>

using namespace std;

class Vertice {
    private:
        string nombre;
    public:

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Vertice
         */
        Vertice(string nombre);

        /*
         * Pre: -.
         * Post: Obtiene el nombre del vertice
         */
        string devolver_nombre();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Verice
         */
        ~Vertice();
};


#endif //GRAFOS_VERTICE_H
