#include <iostream>
#include <fstream>
#include "materiales.h"
#include "constantes.h"
#include "piedra.h"
#include "madera.h"
#include "metal.h"
#include "andycoins.h"
#include "bomba.h"
#include "interface.h"

Materiales::Materiales() {
    this->total_materiales = 0;
}

Materiales::~Materiales(){
    for (int i = 0; i < this->total_materiales; i++){
        delete this->materiales[i];
    }
    delete [] this->materiales;
}

void Materiales::agregar_material(string nombre, int cantidad){
    int tope_viejo = this->total_materiales;

    Material** nuevos_materiales = new Material* [ tope_viejo + 1 ];

    for ( int i = 0; i < tope_viejo; i++ )
        nuevos_materiales[i] = this->materiales[i];

    nuevos_materiales[tope_viejo] = buscar_tipo_material(nombre, cantidad);

    if ( this->total_materiales != 0 )
        delete [] this->materiales;

    this->materiales = nuevos_materiales;
    this->total_materiales++;
}

Material* Materiales::buscar_tipo_material(string nombre, int cantidad) {
    Material* material;

    if(nombre == PIEDRA)
        material = new Piedra(cantidad);
    else if(nombre == MADERA)
        material = new Madera(cantidad);
    else if(nombre == METAL)
        material = new Metal(cantidad);
    else if(nombre == ANDYCOINS)
        material = new Andycoins(cantidad);
    else if(nombre == BOMBA)
        material = new Bomba(cantidad);

    return material;
}


void Materiales::mostrar() {
    mostrar_inventario(this->materiales, this->total_materiales);
}
