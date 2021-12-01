#include "Floyd.h"
#include <unistd.h>

int ** Floyd::crear_matriz_caminos(){

    int ** caminos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        caminos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++) {
            caminos[i][j] = j;
        }
    }

    return caminos;
}

int ** Floyd::crear_matriz_costos(int ** matriz_adyacencia){

    int ** costos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        costos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++){
            costos[i][j] = matriz_adyacencia[i][j];
        }
    }
    return costos;
}

void Floyd::calcular_matrices() {

    cantidadVertices = vertices -> devolver_cantidad_en_lista();
    matriz_costos = crear_matriz_costos(matriz_adyacencia);
    matriz_caminos = crear_matriz_caminos();

    for (int verticeIntermedio = 0; verticeIntermedio < cantidadVertices; verticeIntermedio++) {

        for (int origen = 0; origen < cantidadVertices; origen++){

            for (int destino = 0; destino < cantidadVertices; destino++) {

                int costo = matriz_costos[origen][verticeIntermedio] + matriz_costos[verticeIntermedio][destino];

                if (matriz_costos[origen][destino] > costo) {
                    matriz_costos[origen][destino] = costo;
                    matriz_caminos[origen][destino] = matriz_caminos[origen][verticeIntermedio];
                } else if (matriz_costos[origen][destino] == INFINITO){
                    matriz_caminos[origen][destino] = POSICION_NO_ENCONTRADA;
                }
            }
        }
    }

}

void Floyd::camino_minimo(int origen, int destino, Mapa* &mapa, Jugador* &jugador) {

    if(matriz_caminos[origen][destino] == POSICION_NO_ENCONTRADA){
        cout << "No hay un camino que conecte " <<  vertices->obtener_nombre(origen + 1) << " con " << vertices->obtener_nombre(destino + 1);
    }else{
        do{
            origen = matriz_caminos[origen][destino];
            string fila = vertices->obtener_nombre(origen + 1);
            fila.pop_back();
            int num_fila = stoi(fila);
            string columna = vertices->obtener_nombre(origen + 1);
            columna = columna.substr(2);
            int num_columna = stoi(columna);
            mapa->mover_jugador(jugador, num_fila, num_columna);
            sleep(1);
            mapa->mostrar();
        }while(origen != destino);
    }
    cout << endl;

}

void Floyd::liberar_matrices() {
    if(matriz_costos != nullptr && matriz_caminos != nullptr){
        for(int i = 0; i < cantidadVertices; i++){
            delete[] matriz_costos[i];
            delete[] matriz_caminos[i];
        }
        delete[] matriz_costos;
        delete[] matriz_caminos;

        matriz_costos = nullptr;
        matriz_caminos = nullptr;
    }
}

Floyd::~Floyd(){
    liberar_matrices();
}

Floyd::Floyd(Lista<Vertice> *vertices, int ** matriz_adyacencia) : Camino_minimo(vertices, matriz_adyacencia){
    calcular_matrices();
}

int Floyd::devolver_costo(int origen, int destino){
    return this->matriz_costos[origen][destino];
}



