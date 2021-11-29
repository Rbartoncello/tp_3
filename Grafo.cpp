#include "Grafo.h"
#include <iostream>

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    vertices = new Lista_grafo<Vertice>();
    algoritmo_camino_minimo = nullptr;
}

void Grafo::agregarVertice(string nuevoVertice) {
    agrandar_matriz_adyacencia();
    vertices -> agregar(nuevoVertice);
}

void Grafo::agregar_camino(string origen, string destino, int peso) {
    int posicionOrigen = vertices ->obtener_posicion(origen);
    int posicionDestino = vertices ->obtener_posicion(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicionDestino == POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA)) {
        matriz_adyacencia[posicionOrigen][posicionDestino] = peso;
    }
}

void Grafo::camino_minimo(string origen, string destino) {
    int posicionOrigen = vertices ->obtener_posicion(origen);
    int posicionDestino = vertices ->obtener_posicion(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    camino_minimo(posicionOrigen, posicionDestino);
}

void Grafo::agrandar_matriz_adyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->obtener_cantidad_elementos() + 1;

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
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        for(int j = 0; j < vertices -> obtener_cantidad_elementos(); j++){
            nueva_adyacente[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_muevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        nueva_adyacente[vertices -> obtener_cantidad_elementos()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_cantidad_elementos()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_cantidad_elementos()][vertices -> obtener_cantidad_elementos()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
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

void Grafo::camino_minimo(int origen, int destino) {
    algoritmo_camino_minimo -> camino_minimo(origen, destino);
}

void Grafo::usar_floyd() {
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new Floyd(vertices, matriz_adyacencia);
}

int Grafo::devolver_costo(string origen, string destino){
    int posicionOrigen = vertices ->obtener_posicion(origen);
    int posicionDestino = vertices ->obtener_posicion(destino);

    return algoritmo_camino_minimo -> devolver_costo(posicionOrigen, posicionDestino);
}

