#include "receta.h"
#include "constantes.h"
#include "emojis.h"

Receta::Receta() {
    this->piedra = new Piedra;
    this->madera = new Madera;
    this->metal = new Metal;
}

Receta::Receta(int piedra, int madera, int metal) {
    this->piedra = new Piedra(piedra);
    this->madera = new Madera(madera);
    this->metal = new Metal(metal);
}

Receta::~Receta() {
    delete this->piedra;
    delete this->madera;
    delete this->metal;
}

void Receta::modificar_piedra(int cantidad) {
    this->piedra->modificar_cantidad(cantidad);
}

void Receta::modificar_madera(int cantidad) {
    this->madera->modificar_cantidad(cantidad);
}


void Receta::modificar_metal(int cantidad) {
    this->metal->modificar_cantidad(cantidad);
}

int Receta::devoler_piedra() {
    return this->piedra->devolver_cantidad();
}

int Receta::devoler_madera() {
    return this->madera->devolver_cantidad();
}

int Receta::devoler_metal() {
    return this->metal->devolver_cantidad();
}

int Receta::devolver_material(string material) {
    int receta = 0;

    if (material == EMOJI_PIEDRA){
        receta = devoler_piedra();
    } else if (material == EMOJI_MADERA){
        receta = devoler_madera();
    } else if (material == EMOJI_METAL){
        receta = devoler_metal();
    }
    
    return receta;
}

void Receta::modificar_receta(string material, int cantidad) {
    if (material == EMOJI_PIEDRA){
        modificar_piedra(cantidad);
    } else if (material == EMOJI_MADERA){
        modificar_madera(cantidad);
    } else if (material == EMOJI_METAL){
        modificar_metal(cantidad);
    }
}
