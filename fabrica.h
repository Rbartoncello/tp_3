#ifndef FABRICA_H
#define FABRICA_H
#include "edificacion.h"

class Fabrica : public Edificacion
{
private:
    const int CANTIDADMATERIAL = 0;
    const string MATERIAL = "no brinda";
    string emoji;
    Piedra* piedra;
    Madera* madera;
    Metal* metal;
public:

    Fabrica(string nombre, int cant_piedra, int cant_madera, int cant_metal, int max);

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    int cantidadMaterial();

    void imprimirLetra();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    string materialProducido();

    //PRE:
    //POST:Va a decir el tipo de edificio que tiene.
    void hablarSobreMi();

    virtual ~Fabrica();
};

#endif 