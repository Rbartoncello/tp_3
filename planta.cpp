#include "planta.h"
#include "emojis.h"
Planta::Planta(string nombre) : Edificacion (nombre, EMOJI_PLANTA_ENERGIA){
}

Planta::Planta(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_PLANTA_ELECTRICA, EMOJI_PLANTA_ENERGIA){
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
}

Planta::~Planta(){
    delete this->receta;
}

Receta* Planta::devolver_receta() {
    return this->receta;
}

int Planta::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
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

    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}