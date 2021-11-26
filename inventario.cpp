#include <iostream>
#include <fstream>
#include "inventario.h"
#include "constantes.h"
#include "piedra.h"
#include "madera.h"
#include "metal.h"
#include "andycoins.h"
#include "bomba.h"

Inventario::Inventario() {
    this->total_materiales = 0;
}

void Inventario::agregar_material(string nombre, int cantidad){
    int tope_viejo = this->total_materiales;

    Material** nuevos_materiales = new Material* [ tope_viejo + 1 ];

    for ( int i = 0; i < tope_viejo; i++ )
        nuevos_materiales[i] = this->materiales[i];

    nuevos_materiales[tope_viejo] = buscar_tipo_material(nombre);
    
    nuevos_materiales[tope_viejo]->modificar_cantidad(cantidad);

    if ( this->total_materiales != 0 )
        delete [] this->materiales;

    this->materiales = nuevos_materiales;
    this->total_materiales++;
}

void Inventario::mostrar() {
    for (int i = 0; i < this->total_materiales; i++){
        this->materiales[i]->mostrar();
    }
    
}

Material* Inventario::buscar_tipo_material(string nombre) {
    Material* material;

    if(nombre == PIEDRA)
        material = new Piedra;
    else if(nombre == MADERA)
        material = new Madera;
    else if(nombre == METAL)
        material = new Metal;
    else if(nombre == BOMBA)
        material = new Bomba;
    else
        material = new Andycoins;

    return material;
}

Inventario::~Inventario(){
    for (int i = 0; i < this->total_materiales; i++){
        delete this->materiales[i];
    }
    delete [] this->materiales;
}