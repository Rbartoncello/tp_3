#include <iostream>
#include <fstream>
#include "materiales.h"
#include "constantes.h"

Materiales::Materiales() {
    this->total_materiales = 0;
}

Materiales::~Materiales(){
    for (int i = 0; i < this->total_materiales; i++){
        delete this->materiales[i];
    }
    //delete [] this->materiales;
}

void Materiales::mostrar() {
    for (int i = 0; i < this->total_materiales; i++)
        this->materiales[i]->mostrar();
}
