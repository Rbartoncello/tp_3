#include "aserradero.h"
#include "emojis.h"



Aserradero::Aserradero(string nombre, int cant_piedra, int cant_madera, int cant_metal, int max) : Edificacion (nombre){
    this->emoji = EMOJI_ASERRADERO;
    this->piedra = new Piedra(cant_piedra);
    this->madera = new Madera(cant_madera);
    this->metal = new Metal(cant_metal);
}

void Aserradero::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "A" << END_COLOR;
}

int Aserradero::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Aserradero::materialProducido(){

    return (MATERIAL);
}

void Aserradero::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Aserradero::~Aserradero(){}