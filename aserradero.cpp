#include "aserradero.h"
#include "emojis.h"
#include "constantes.h"

Aserradero::Aserradero() : Edificacion (EDIFICIO_ASERRADERO, EMOJI_ASERRADERO){
    this->produce_material = true;
    this->necesita_reparacion = false;
    this->cantidad_material_brinda = BRINDA_ASERRADERO;
    this->material_producido = MADERA;
    this->reparable = false;
}

Aserradero::Aserradero(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_ASERRADERO, EMOJI_ASERRADERO){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_ASERRADERO;
    this->material_producido = MADERA;
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
    this->reparable = false;
}

Aserradero::~Aserradero(){
    delete this->receta;
}

Receta *Aserradero::devolver_receta(){
    return this->receta;
}

bool Aserradero::devolver_necesita_reparacion() {
    return this->necesita_reparacion;
}

int Aserradero::devolver_maxima_cantidad_permitidos() {
    return this->maxima_cantidad_permitidos;
}

bool Aserradero::brinda_material() {
    return this->produce_material;
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

void Aserradero::atacar(){
    this->necesita_reparacion = true;
}

void Aserradero::reparar(){
    this->necesita_reparacion = false;
}

