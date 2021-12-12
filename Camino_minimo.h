#ifndef GRAFOS_CAMINO_MINIMO_H
#define GRAFOS_CAMINO_MINIMO_H
#include <string>
#include "lista.h"
#include "Vertice.h"
#include "mapa.h"
#include "jugador.h"
#include <iostream>

const int INFINITO = 99999999;

class Camino_minimo {
    //Atributos
    protected:
        int ** matriz_adyacencia;
        Lista<Vertice> * vertices;
        int cantidadVertices;

    //Métodos
    public:
        /*
        * PRE:
        * POST:
        */
        Camino_minimo(Lista<Vertice> * vertices, int** matriz_adyacencia);

        //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
        virtual void camino_minimo(int origen, int destino, Mapa* &mapa, Jugador* &jugador) = 0;
            /*
        * PRE:
        * POST:
        */
        virtual int devolver_costo(int origen, int destino) = 0;
            /*
        * PRE:
        * POST:
        */
        virtual ~Camino_minimo() = default;
};


#endif //GRAFOS_CAMINO_MINIMO_H
