#include "fabrica.h"
#include "emojis.h"
#include "constantes.h"

Fabrica::Fabrica(string nombre) : Edificacion (nombre, EMOJI_FABRICA){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_ESCUELA;
    this->material_producido = METAL;
}

Fabrica::Fabrica(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_FABRICA, EMOJI_FABRICA){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_FABRICA;
    this->material_producido = METAL;
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

bool Fabrica::brinda_material(){
    return this->produce_material;
}

void Fabrica::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "F" << END_COLOR;
}

int Fabrica::devolver_cantidad_material_brinda(){

    return this->cantidad_material_brinda;
}

string Fabrica::devolver_material_producido(){

    return this->material_producido;
}

void Fabrica::hablar_sobre_mi(){

    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

