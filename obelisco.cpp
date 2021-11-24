#include "obelisco.h"    
#include "emojis.h"
#include "constantes.h"

Obelisco::Obelisco(string nombre) : Edificacion (nombre, EMOJI_OBELISCO){
}

Obelisco::Obelisco(int piedra, int madera, int metal, int maxima_cantidad_permitidos) : Edificacion (EDIFICIO_OBELISCO, EMOJI_OBELISCO){
    this->receta = new Receta(piedra, madera, metal);
    this->maxima_cantidad_permitidos = maxima_cantidad_permitidos;
}

Obelisco::~Obelisco(){
    delete this->receta;
}

Receta* Obelisco::devolver_receta() {
    return this->receta;
}

int Obelisco::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}

void Obelisco::imprimirLetra()
{
    cout<< BGND_LIGHT_GREEN_77 <<TXT_BLACK_16<< "O" << END_COLOR;
}

int Obelisco::cantidadMaterial(){

    return (CANTIDADMATERIAL);
}

string Obelisco::materialProducido(){

    return (MATERIAL);
}

void Obelisco::hablarSobreMi(){

    cout << "SOY UN " + devolver_nombre_edificio() + " Y ME ENCUENTRO EN EL CASILLERO CONSULTADO" << endl;
}

