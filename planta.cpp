#include "planta.h"
#include "emojis.h"
Planta::Planta() : Edificacion (EDIFICIO_PLANTA_ELECTRICA, EMOJI_PLANTA_ENERGIA){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_PLANTA_ELECTRICA;
    this->material_producido = ENERGIA;
}

Planta::Planta(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_PLANTA_ELECTRICA, EMOJI_PLANTA_ENERGIA){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_PLANTA_ELECTRICA;
    this->material_producido = ENERGIA;
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
}

Planta::~Planta(){
    delete this->receta;
}

Receta* Planta::devolver_receta() {
    return this->receta;
}

bool Planta::devolver_necesita_reparacion() {
    return this->necesita_reparacion;
}

int Planta::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}

bool Planta::brinda_material() {
    return this->produce_material;
}

int Planta::devolver_cantidad_material_brinda(){
    return this->cantidad_material_brinda;
}

string Planta::devolver_material_producido(){
    return this->material_producido;
}

void Planta::hablar_sobre_mi(){
    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}