#include <iostream>
#include "emojis.h"
#include "material.h"

Material::Material(string nombre, int cantidad_material_jugador_1, int cantidad_material_jugador_2){
    this->nombre_material = nombre;
    this->emoji = agregar_emoji(nombre_material);
    this->cantidad_material_jugador_1 = cantidad_material_jugador_1;
    this->cantidad_material_jugador_2 = cantidad_material_jugador_2;
}

Material::Material(){
    this->nombre_material = "NULL";
    this->emoji = "NULL";
    this->cantidad_material_jugador_1 = 0;
    this->cantidad_material_jugador_2 = 0;
}

string Material::agregar_emoji(string nombre_material){
    string emoji;

    if (nombre_material == PIEDRA)
        emoji = EMOJI_PIEDRA;
    else if (nombre_material == MADERA)
        emoji = EMOJI_MADERA;
    else if (nombre_material == METAL)
        emoji = EMOJI_METAL;
    else if (nombre_material == BOMBA)
        emoji = EMOJI_BOMBA;
    else if (nombre_material == ANDYCOINS)
        emoji = EMOJI_ANDYCOINS;

    return emoji;
}

void Material::mostrar(){
    cout << devolver_nombre_material() << "( " << devolver_emoji() << " ) " << devolver_cantidad_material_jugador_1() << " " << devolver_cantidad_material_jugador_2() <<  endl;
}

string Material::devolver_nombre_material(){
    return this->nombre_material;
}

string Material::devolver_emoji(){
    return this->emoji;
}

int Material::devolver_cantidad_material_jugador_1() {
    return this->cantidad_material_jugador_1;
}

int Material::devolver_cantidad_material_jugador_2() {
    return this->cantidad_material_jugador_2;
}
