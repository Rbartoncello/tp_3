#include "aserradero.h"
#include "emojis.h"
#include "constantes.h"

Aserradero::Aserradero(string nombre) : Edificacion (nombre, EMOJI_ASERRADERO){
}

Aserradero::Aserradero(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_ASERRADERO, EMOJI_ASERRADERO){
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
}

Aserradero::~Aserradero(){
    delete this->receta;
}

Receta *Aserradero::devolver_receta(){
    return this->receta;
}

int Aserradero::devolver_maxima_cantidad_permitidos() {
    return this->maxima_cantidad_permitidos;
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

    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

