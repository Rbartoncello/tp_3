#include "mina.h"
#include "emojis.h"
#include "constantes.h"

Mina::Mina(string nombre) : Edificacion (nombre, EMOJI_MINA){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_MINA;
    this->material_producido = PIEDRA;
}

Mina::Mina(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_MINA, EMOJI_MINA){
    this->produce_material = true;
    this->cantidad_material_brinda = BRINDA_MINA;
    this->material_producido = PIEDRA;
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
}

Mina::~Mina(){
    delete this->receta;
}

Receta *Mina::devolver_receta(){
    return this->receta;
}

int Mina::devolver_maxima_cantidad_permitidos() {
    return this->maxima_cantidad_permitidos;
}

bool Mina::brinda_material() {
    return this->produce_material;
}

void Mina::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "M" << END_COLOR;
}

int Mina::devolver_cantidad_material_brinda(){

    return this->cantidad_material_brinda;
}

string Mina::devolver_material_producido(){

    return this->material_producido;
}

void Mina::hablar_sobre_mi(){

    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}