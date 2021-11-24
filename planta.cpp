#include "planta.h"
#include "emojis.h"

Planta::Planta(string nombre, int cant_piedra, int cant_madera, int cant_metal, int max) : Edificacion (nombre){
    this->emoji = EMOJI_PLANTA_ENERGIA;
    this->piedra = new Piedra(cant_piedra);
    this->madera = new Madera(cant_madera);
    this->metal = new Metal(cant_metal);
}

void Planta::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "P" << END_COLOR;
}

int Planta::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Planta::materialProducido(){

    return (MATERIAL);
}

void Planta::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Planta::~Planta(){}