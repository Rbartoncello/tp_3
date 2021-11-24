#include "mina.h"
#include "emojis.h"

Mina::Mina(string nombre, int cant_piedra, int cant_madera, int cant_metal, int max) : Edificacion (nombre){
    this->emoji = EMOJI_MINA;
    this->piedra = new Piedra(cant_piedra);
    this->madera = new Madera(cant_madera);
    this->metal = new Metal(cant_metal);
}


void Mina::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "M" << END_COLOR;
}

int Mina::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Mina::materialProducido(){

    return (MATERIAL);
}

void Mina::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Mina::~Mina(){}