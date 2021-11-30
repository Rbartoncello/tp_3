#include "mina_oro.h"
#include "emojis.h"
#include "constantes.h"

Mina_oro::Mina_oro() : Edificacion (EDIFICIO_MINA_ORO, EMOJI_MINA_ORO){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_MINA_ORO;
    this->material_producido = ANDYCOINS;
}

Mina_oro::Mina_oro(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_MINA_ORO, EMOJI_MINA_ORO){
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_MINA_ORO;
    this->material_producido = ANDYCOINS;
}

Mina_oro::~Mina_oro(){
    delete this->receta;
}

Receta *Mina_oro::devolver_receta(){
    return this->receta;
}

bool Mina_oro::devolver_necesita_reparacion() {
    return this->necesita_reparacion;
}

int Mina_oro::devolver_cantidad_material_brinda(){
    return this->cantidad_material_brinda;
}

string Mina_oro::devolver_material_producido(){
    return this->material_producido;
}

bool Mina_oro::brinda_material() {
    return this->produce_material;
}

void Mina_oro::hablar_sobre_mi(){
    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

int Mina_oro::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}
