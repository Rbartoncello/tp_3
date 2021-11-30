#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>

using namespace std;

template < typename Tipo >
class Nodo_grafo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo_grafo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo_grafo(string nombre);

    //post: devuelve el nodo siguiente.
    Nodo_grafo<Tipo>* obtener_siguiente();

    //post: devuelve el nombre del nodo
    string obtener_nombre();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(Nodo_grafo<Tipo>* siguiente);

    ~Nodo_grafo();
};

template<typename Tipo>
Nodo_grafo<Tipo>::Nodo_grafo(string nombre) {
    elemento = new Tipo(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo_grafo<Tipo> *Nodo_grafo<Tipo>::obtener_siguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo_grafo<Tipo>::obtener_nombre() {
    return elemento -> obtener_nombre();
}

template<typename Tipo>
void Nodo_grafo<Tipo>::asignarSiguiente(Nodo_grafo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo_grafo<Tipo>::~Nodo_grafo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
