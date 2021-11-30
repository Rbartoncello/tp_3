#ifndef GRAFOS_CAMINO_MINIMO_H
#define GRAFOS_CAMINO_MINIMO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "mapa.h"
#include "jugador.h"
#include <iostream>

const int INFINITO = 99999999;

class Camino_minimo {
//Atributos
protected:
    int ** matriz_adyacencia;
    Lista_grafo<Vertice> * vertices;
    int cantidadVertices;

//Métodos
public:
    Camino_minimo(Lista_grafo<Vertice> * vertices, int** matriz_adyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual void camino_minimo(int origen, int destino, Mapa* &mapa, Jugador* &jugador) = 0;

    virtual int devolver_costo(int origen, int destino) = 0;

    virtual ~Camino_minimo() = default;
};


#endif //GRAFOS_CAMINO_MINIMO_H
