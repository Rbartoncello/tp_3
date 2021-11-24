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
    int maxima_cantidad_permitidos;

public:

    Edificacion(string nombre_edificio);
    
    //PRE:necesita el nombre del Edificacion
    //POST: guarda el nombre del edficio en nombre
    Edificacion(string nombre_edificio, int piedra, int madera, int metal, int   maxima_cantidad_permitidos);

    //PRE:
    //POST: devuelve el nombre del edifico
    string devolverNombre();

    //PRE:
    //POST:imprime la letra del tipo de casillero de forma polimorfica o lo que tiene dentro
    virtual void imprimirLetra() =0;

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el Edificacion que este custruido otorgue.
    virtual int cantidadMaterial() = 0;
    /*
    * Pre: -
    * Post: Me devuelve el piedra.
    */
    Receta* devolver_receta();

    /*
 * Pre: -
 * Post: Me devuelve el maxima_cantidad_permitidos.
 */
    int devolver_maxima_cantidad_permitidos();

    /*
    * Pre: -
    * Post: Me devuelve el nombre_edificio.
    */
    string devolver_nombre_edificio();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el Edificacion que este custruido otorgue.
    virtual string materialProducido() = 0;

    //PRE:
    //POST:Va a decir el tipo de Edificacion que tiene.
    virtual void hablarSobreMi() = 0;

    virtual ~Edificacion() = 0;

};


#endif //EDIFICACION_H