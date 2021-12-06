#include "obelisco.h"    
#include "emojis.h"
#include "constantes.h"

Obelisco::Obelisco() : Edificacion (EDIFICIO_OBELISCO, EMOJI_OBELISCO){
    this->produce_material = false;
    this->cantidad_material_brinda = 0;
    this->material_producido = "niguno";
    this->reparable = false;
}

Obelisco::Obelisco(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_OBELISCO, EMOJI_OBELISCO){
    this->produce_material = false;
    this->cantidad_material_brinda = 0;
    this->material_producido = "niguno";
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
    this->reparable = false;
}

Obelisco::~Obelisco(){
    delete this->receta;
}

Receta* Obelisco::devolver_receta() {
    return this->receta;
}

bool Obelisco::devolver_necesita_reparacion() {
    return this->necesita_reparacion;
}

int Obelisco::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}

bool Obelisco::brinda_material() {
    return this->produce_material;
}

int Obelisco::devolver_cantidad_material_brinda(){
    return this->cantidad_material_brinda;
}

string Obelisco::devolver_material_producido(){
    return this->material_producido;
}

void Obelisco::hablar_sobre_mi(){
    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

void Obelisco::atacar(){
    this->necesita_reparacion = true;
}

void Obelisco::reparar(){
    this->necesita_reparacion = false;
}
