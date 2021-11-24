#include "fabrica.h"
#include "emojis.h"

Fabrica::Fabrica(string nombre, int cant_piedra, int cant_madera, int cant_metal, int max) : Edificacion (nombre){
    this->emoji = EMOJI_FABRICA;
    this->piedra = new Piedra(cant_piedra);
    this->madera = new Madera(cant_madera);
    this->metal = new Metal(cant_metal);
}


void Fabrica::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "F" << END_COLOR;
}

int Fabrica::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Fabrica::materialProducido(){

    return (MATERIAL);
}

void Fabrica::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Fabrica::~Fabrica(){}