#include "escuela.h"
#include "emojis.h"
#include "constantes.h"

Escuela::Escuela() : Edificacion (EDIFICIO_ESCUELA, EMOJI_ESCUELA){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_ESCUELA;
    this->material_producido = ANDYCOINS;
    this->reparable = false;
}

Escuela::Escuela(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_ESCUELA, EMOJI_ESCUELA){
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_ESCUELA;
    this->material_producido = ANDYCOINS;
    this->reparable = false;
}

Escuela::~Escuela(){
    delete this->receta;
}

Receta *Escuela::devolver_receta(){
    return this->receta;
}

bool Escuela::devolver_necesita_reparacion() {
    return this->necesita_reparacion;
}

bool Escuela::brinda_material() {
    return this->produce_material;
}


int Escuela::devolver_cantidad_material_brinda(){
    return this->cantidad_material_brinda;
}

string Escuela::devolver_material_producido(){
    return this->material_producido;
}

void Escuela::hablar_sobre_mi(){
    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

int Escuela::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}

void Escuela::atacar(){
    this->necesita_reparacion = true;
}

void Escuela::reparar(){
    this->necesita_reparacion = false;
}
