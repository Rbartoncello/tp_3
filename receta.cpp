//
// Created by rbartoncello on 11/19/21.
//

#include "receta.h"

Receta::Receta() {
    this->piedra = 0;
    this->madera = 0;
    this->metal = 0;
}

Receta::Receta(int piedra, int madera, int metal) {
    this->piedra = piedra;
    this->madera = madera;
    this->metal = metal;
}

void Receta::modificar_piedra(int cantidad) 
{
    this->piedra = cantidad;
}

void Receta::modificar_madera(int cantidad) 
{
    this->madera = cantidad;
}


void Receta::modificar_metal(int cantidad) 
{
    this->metal = cantidad;
}

int Receta::devoler_piedra() 
{
    return this->piedra;
}

int Receta::devoler_madera() 
{
    return this->madera;
}

int Receta::devoler_metal() 
{
    return this->metal;
}
