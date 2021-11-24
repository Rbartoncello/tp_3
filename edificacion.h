#ifndef EDIFICACION_H
#define EDIFICACION_H
#include <iostream>
#include "colors.h"

#include <string>

using namespace std;

class Edificacion
{
private:

    string nombre;

public:
    
    //PRE:necesita el nombre del Edificacion
    //POST: guarda el nombre del edficio en nombre
    Edificacion (string tipoEdificacion);

    //PRE:
    //POST: devuelve el nombre del edifico
    string devolverNombre();

    //PRE:
    //POST:imprime la letra del tipo de casillero de forma polimorfica o lo que tiene dentro
    virtual void imprimirLetra() =0;

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el Edificacion que este custruido otorgue.
    virtual int cantidadMaterial() = 0;

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el Edificacion que este custruido otorgue.
    virtual string materialProducido() = 0;

    //PRE:
    //POST:Va a decir el tipo de Edificacion que tiene.
    virtual void hablarSobreMi() = 0;

    virtual ~Edificacion() = 0;

};


#endif //EDIFICACION_H