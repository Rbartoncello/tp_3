#include "escuela.h"
#include "emojis.h"
#include "constantes.h"

Escuela::Escuela(string nombre) : Edificacion (nombre, EMOJI_ESCUELA){
}

Escuela::Escuela(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_ESCUELA, EMOJI_ESCUELA){
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
}

Escuela::~Escuela(){
    delete this->receta;
}

Receta *Escuela::devolver_receta(){
    return this->receta;
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

    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

int Escuela::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}
