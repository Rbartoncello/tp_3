#include "aserradero.h"
#include "emojis.h"
#include "constantes.h"

Aserradero::Aserradero(string nombre) : Edificacion (nombre, EMOJI_ASERRADERO){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_ASERRADERO;
    this->material_producido = MADERA;
}

Aserradero::Aserradero(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_ASERRADERO, EMOJI_ASERRADERO){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_ASERRADERO;
    this->material_producido = MADERA;
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

bool Aserradero::brinda_material() {
    return this->produce_material;
}

void Aserradero::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "A" << END_COLOR;
}

int Aserradero::devolver_cantidad_material_brinda(){

    return this->cantidad_material_brinda;
}

string Aserradero::devolver_material_producido(){

    return this->material_producido;
}

void Aserradero::hablar_sobre_mi(){

    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

