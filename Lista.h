#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "Nodo.h"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";

template < typename Tipo >
class Lista_grafo{
/*ATRIBUTOS*/
private:
    int cantidadDeElementos;
    Nodo_grafo<Tipo>* primero;
    Nodo_grafo<Tipo>* ultimo;

/*MÉTODOS*/
public:
    Lista_grafo();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtener_cantidad_elementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtener_posicion(string nombre);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    string obtener_nombre(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(string nuevoElemento);

    ~Lista_grafo();
};

template < typename Tipo >
Lista_grafo<Tipo>::Lista_grafo(){
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista_grafo<Tipo>::obtener_cantidad_elementos(){
    return cantidadDeElementos;
}

template < typename Tipo >
int Lista_grafo<Tipo>::obtener_posicion(string nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo_grafo<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidadDeElementos){
        if(auxiliar -> obtener_nombre() == nombre){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista_grafo<Tipo>::agregar(string nuevoElemento) {
    Nodo_grafo<Tipo>* nuevoNodo = new Nodo_grafo<Tipo>(nuevoElemento);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidadDeElementos++;
}

template<typename Tipo>
Lista_grafo<Tipo>::~Lista_grafo() {
    Nodo_grafo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
string Lista_grafo<Tipo>::obtener_nombre(int posicion) {
    int i = 0;
    Nodo_grafo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return auxiliar -> obtener_nombre();
}

#endif //GRAFOS_LISTA_H
