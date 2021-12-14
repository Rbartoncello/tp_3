#include "grafo.h"
#include <iostream>

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    vertices = new Lista<Vertice>();
    algoritmo_camino_minimo = nullptr;
}

void Grafo::borrar_vertice() {
    int total = vertices->devolver_cantidad_en_lista();

    if (total > 0) {
        liberar_matriz_adyacencia();
        matriz_adyacencia = nullptr;
    }
    for (int i = 0; i < total; i++) {
        vertices->remover_elemento(1);
    }
}

void Grafo::agregar_vertice(string nuevo_vertice) {
    agrandar_matriz_adyacencia();
    vertices -> agregar(nuevo_vertice);
}

void Grafo::agregar_camino(string origen, string destino, int peso) {
    int posicionOrigen = vertices ->obtener_posicion(origen);
    int posicionDestino = vertices ->obtener_posicion(destino);

    if(!(posicionDestino == POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA))
        matriz_adyacencia[posicionOrigen][posicionDestino] = peso;
    
}

void Grafo::camino_minimo(string origen, string destino, Mapa* &mapa, Jugador* &jugador) {
    int posicionOrigen = vertices ->obtener_posicion(origen);
    int posicionDestino = vertices ->obtener_posicion(destino);

    if(!(posicionDestino == POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA))
        camino_minimo(posicionOrigen, posicionDestino, mapa, jugador);
}

void Grafo::agrandar_matriz_adyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->devolver_cantidad_en_lista() + 1;

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiar_matriz_adyacente(matrizAuxiliar);
    inicializar_muevo_vertice(matrizAuxiliar);
    liberar_matriz_adyacencia();
    matriz_adyacencia = matrizAuxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> devolver_cantidad_en_lista(); i++){
        for(int j = 0; j < vertices -> devolver_cantidad_en_lista(); j++){
            nueva_adyacente[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_muevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> devolver_cantidad_en_lista(); i++){
        nueva_adyacente[vertices -> devolver_cantidad_en_lista()][i] = INFINITO;
        nueva_adyacente[i][vertices -> devolver_cantidad_en_lista()] = INFINITO;
    }
    nueva_adyacente[vertices -> devolver_cantidad_en_lista()][vertices -> devolver_cantidad_en_lista()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices -> devolver_cantidad_en_lista(); i++){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}

Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_adyacencia = nullptr;
    delete vertices;
    delete algoritmo_camino_minimo;
}

void Grafo::camino_minimo(int origen, int destino, Mapa* &mapa, Jugador* &jugador) {
    algoritmo_camino_minimo -> camino_minimo(origen, destino, mapa, jugador);
}

void Grafo::usar_floyd() {
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new Floyd(vertices, matriz_adyacencia);
}

int Grafo::devolver_costo(string origen, string destino){
    int posicionOrigen = vertices ->obtener_posicion(origen);
    int posicionDestino = vertices ->obtener_posicion(destino);
    int costo;
    if ( ( posicionOrigen == POSICION_NO_ENCONTRADA ) || ( posicionDestino == POSICION_NO_ENCONTRADA ) )
        costo = POSICION_NO_ENCONTRADA;
    else
        costo = algoritmo_camino_minimo -> devolver_costo(posicionOrigen, posicionDestino);
    return costo;
}

