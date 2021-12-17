#ifndef CAMINO_MINIMO_H
#define CAMINO_MINIMO_H
#include <string>
#include "lista.h"
#include "vertice.h"
#include "mapa.h"
#include "jugador.h"
#include <iostream>
#include "constantes.h"



class Camino_minimo {
    protected:
        int ** matriz_adyacencia;
        Lista<Vertice> * vertices;
        int cantidad_vertices;

    public: 
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Camino_minimo
         */
        Camino_minimo(Lista<Vertice> * vertices, int** matriz_adyacencia);

        /*
         * PRE:  - 
         * POST: Método virtual de la clase hija Floyd
         */
        virtual void camino_minimo(int origen, int destino, Mapa* &mapa, Jugador* &jugador) = 0;
        
        /*
         * PRE:  - 
         * POST: Método virtual de la clase hija Floyd
         */
        virtual int devolver_costo(int origen, int destino) = 0;
        
        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Camino_minimo
         */
        virtual ~Camino_minimo() = default;
};


#endif //GRAFOS_CAMINO_MINIMO_H
