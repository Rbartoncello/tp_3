#include "edificio.h"
#include "constantes.h"
#include <iostream>
#include <string>

using namespace std;

Edificio::Edificio(string nombre, string emoji, int piedra, int madera, int metal, int max_cant_permitidos){
    this->nombre_edificio = nombre;
    this->emoji = emoji;
    this->receta.modificar_piedra(piedra);
    this->receta.modificar_madera(madera);
    this->receta.modificar_metal(metal);
    this->maxima_cantidad_permitidos = max_cant_permitidos;
}

string Edificio::devolver_nombre_edificio(){
    return this->nombre_edificio;
}

string Edificio::devolver_emoji(){
    return this->emoji;
}

Receta Edificio::devolver_receta(){
    return this->receta;
}

int Edificio::devolver_cantidad_material(string material){
    int cantidad_material = 0;

    if (material == PIEDRA)
        cantidad_material = this->receta.devoler_piedra();
    else if (material == MADERA)
        cantidad_material = this->receta.devoler_madera();
    else if (material == METAL)
        cantidad_material = this->receta.devoler_metal();

    return cantidad_material;
}

int Edificio::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}