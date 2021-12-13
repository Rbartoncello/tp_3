#include "vertice.h"

Vertice::Vertice(string nombre) {
    this -> nombre = nombre;
}

string Vertice::devolver_nombre() {
    return nombre;
}

Vertice::~Vertice() {

}
