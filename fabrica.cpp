#include "fabrica.h"
#include "emojis.h"
#include "constantes.h"

Fabrica::Fabrica(string nombre) : Edificacion (nombre, EMOJI_FABRICA){
}

Fabrica::Fabrica(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_FABRICA, EMOJI_FABRICA){
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
}

Fabrica::~Fabrica(){
    delete this->receta;
}

Receta *Fabrica::devolver_receta(){
    return this->receta;
}

int Fabrica::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
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

    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

