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
private:
    int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    Camino_minimo * algoritmo_camino_minimo;
    
    /*
     *Pre: tienen que existir tanto el origen como el destino. Además se deben haber calculado las matrices de Floyd
     *Post: muestra el camino mínimo entre el origen y el destino
     */
    void camino_minimo(int origen, int destino, Mapa* &mapa, Jugador* &jugador);

    /*
     *Pre: -
     *Post: Agranda dinámicamente la matriz de adyacencia
     */
    void agrandar_matriz_adyacencia();

    /*
     *Pre: la matriz que se le envíe ya debe tener memoria reservada
     *Post:  copia la matriz de adyacencia en la nueva matriz
     */
    void copiar_matriz_adyacente(int** nueva_adyacente);

    /*
     *Pre: -
     *Post: Inicializa un nuevo vertices en la matriz de adyacencia con un valor de infinito
     */
    void inicializar_muevo_vertice(int** nueva_adyacente);

    /*
     *Pre: -
     *Post: Libera la memoria de la matriz de adyacencia
     */
    void liberar_matriz_adyacencia();

public:
    /*
     * Constructor sin parametros:
     * Pre: -.
     * Post: Me va a crear el objeto Grafo
     */
    Grafo();
    
    /*
     *Pre: No hay vertices repetidos en nombre
     *Post: agrega un nuevo vertices al grafo
     */
    void agregar_vertice(string nuevo_vertice);

    /*
     *Pre: Se debe tener un algoritmo para calcular el camino mínimo previamente elegido
     *Post: Muestra por terminal el camino mínimo desde un origen a un destino
     */
    void camino_minimo(string origen, string destino, Mapa* &mapa, Jugador* &jugador);


    /*
     *Pre: El peso es un valor positivo
     *Post: Ajusta la matriz de adyacencia con el peso ingresado
     */
    void agregar_camino(string origen, string destino, int peso);

    /*
     *Pre: -
     *Post: Selecciona el algoritmo de Floyd para calcular el camino mínimo
     */
    //post: 
    void usar_floyd();
    
    /*
    * PRE:
    * POST: Devuelve el costo que necesita para ir de origen a destino
    */
    int devolver_costo(string origen, string destino);

    /*
     * Destructor
     * Pre: -.
     * Post: Me va a eliminar el objeto Grafo
     */
    ~Grafo();
};


#endif // __GRAFO_H__