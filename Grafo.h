#ifndef __GRAFO_H__
#define __GRAFO_H__
#include <string>
#include "lista.h"
#include "Vertice.h"
#include "Floyd.h"
#include "mapa.h"
#include "jugador.h"

using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
    int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    Camino_minimo * algoritmo_camino_minimo;

/*MÉTODOS*/

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void camino_minimo(int origen, int destino, Mapa* &mapa, Jugador* &jugador);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_adyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacente(int** nueva_adyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_muevo_vertice(int** nueva_adyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

public:
    Grafo();
    
    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregarVertice(string nuevoVertice);

    //pre: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //post: muestra por terminal el camino mínimo desde un origen a un destino
    void camino_minimo(string origen, string destino, Mapa* &mapa, Jugador* &jugador);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregar_camino(string origen, string destino, int peso);

    //post: selecciona el algortimo de Floyd para calcular el camino mínimo
    void usar_floyd();
    /*
    * PRE:
    * POST:
    */
    int devolver_costo(string origen, string destino);

    ~Grafo();
};


#endif // __GRAFO_H__