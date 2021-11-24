#ifndef EDIFICACION_H
#define EDIFICACION_H
#include <iostream>
#include "colors.h"
#include "receta.h"

#include <string>

using namespace std;

class Edificacion
{
private:
    string nombre;
    string emoji;
    int maxima_cantidad_permitidos;
public:
    
    //PRE:necesita el nombre del Edificacion
    //POST: guarda el nombre del edficio en nombre
    Edificacion (string tipoEdificacion, string emoji);

    //PRE:
    //POST: devuelve el nombre del edifico
    string devolver_nombre_edificio();

    /*
    * Pre: -
    * Post: Me devuelve el emoji.
    */
    string devolver_emoji();

    virtual int devolver_maxima_cantidad_permitidos() = 0;

    virtual Receta* devolver_receta() = 0;

    virtual bool brinda_material() = 0;

    //PRE:
    //POST:imprime la letra del tipo de casillero de forma polimorfica o lo que tiene dentro
    virtual void imprimirLetra() =0;

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el Edificacion que este custruido otorgue.
    virtual int devolver_cantidad_material_brinda() = 0;

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el Edificacion que este custruido otorgue.
    virtual string devolver_material_producido() = 0;

    //PRE:
    //POST:Va a decir el tipo de Edificacion que tiene.
    virtual void hablar_sobre_mi() = 0;

    virtual ~Edificacion() = 0;

};


#endif //EDIFICACION_H