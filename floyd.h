#ifndef FLOYD_H
#define FLOYD_H
#include "camino_minimo.h"

using namespace std;

class Floyd : public Camino_minimo{
    private:
        int ** matriz_costos;
        int ** matriz_caminos;
        
        /*
         *Pre: requiere una matriz de adyacencia bien cargada
         *Post: crea la matriz costo inicializándola con los valores de la matriz de adyacencia
         */
        int ** crear_matriz_costos(int ** matriz_adyacencia);

        /*
         *Pre: -
         *Post: crea una matriz de caminos
         */
        int ** crear_matriz_caminos();

        /*
         *Pre: -
         *Post: libera la memoria de las matrices de costos y caminos
         */
        void liberar_matrices();

        /*
         *Pre: -
         *Post: calcula las matrices de costos y caminos.
         */
        void calcular_matrices();
        
        /*
         * PRE: Origen y destino tienen que existir en la matriz_caminos
         * POST: Devuelve el costo que cuesta ir de origen a destino
         */
        int devolver_costo(int origen, int destino);
    public:
        /*
         * Constructor :
         * Pre: -.
         * Post: Me va a crear el objeto Floyd
         */
        Floyd(Lista<Vertice> *vertices, int ** matriz_adyacencia);

        /*
         * Pre: -.
         * Post: Muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
         */
        void camino_minimo(int origen, int destino, Mapa* &mapa, Jugador* &jugador);

        /*
         * Destructor :
         * Pre: -.
         * Post: Me va a detruir el objeto Floyd
         */
        ~Floyd();
};


#endif //GRAFOS_FLOYD_H
