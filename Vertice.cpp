#include "Vertice.h"

Vertice::Vertice(string nombre) {
    this -> nombre = nombre;
}

string Vertice::obtener_nombre() {
    return nombre;
}

Vertice::~Vertice() {

}
