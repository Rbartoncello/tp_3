#include "escuela.h"
#include "emojis.h"

Escuela::Escuela(string nombre, int cant_piedra, int cant_madera, int cant_metal, int max) : Edificacion (nombre){
    this->emoji = EMOJI_ESCUELA;
    this->piedra = new Piedra(cant_piedra);
    this->madera = new Madera(cant_madera);
    this->metal = new Metal(cant_metal);
}

void Escuela::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "E" << END_COLOR;
}

int Escuela::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Escuela::materialProducido(){

    return (MATERIAL);
}

void Escuela::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Escuela::~Escuela(){}