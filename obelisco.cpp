#include "obelisco.h"    
#include "emojis.h"
    
Obelisco::Obelisco(string nombre) : Edificacion (nombre){
    this->emoji = EMOJI_OBELISCO;
}


void Obelisco::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "O" << END_COLOR;
}

int Obelisco::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Obelisco::materialProducido(){

    return (MATERIAL);
}

void Obelisco::hablarSobreMi(){

    cout << "SOY UN " + devolverNombre() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

Obelisco::~Obelisco(){}