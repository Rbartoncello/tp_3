#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <string>
#include "receta.h"

using namespace std;

class Edificio {
private:
    string nombre_edificio;
    string emoji;
    Receta receta;
    int maxima_cantidad_permitidos;
public:
    Edificio();
    /*
     * Constructor:
     * Pre: -.
     * Post: Me va a crear el objeto edificio.
     */
    Edificio(string nombre_edificio, string emoji, int piedra, int madera, int metal, int   maxima_cantidad_permitidos);

    /*
     * Pre: -
     * Post: Me devuelve el nombre_edificio.
     */
    string devolver_nombre_edificio();

    /*
    * Pre: -
    * Post: Me devuelve el emoji.
    */
    string devolver_emoji();

    /*
     * Pre: -
     * Post: Me devuelve el piedra.
     */
    Receta devolver_receta();

    /*
     * Pre: Recibe un nombre de un material
     * Post: Devuelve la cantidad de ese material que necesita el edificio para construirse
    */
    int devolver_cantidad_material(string material);

    /*
     * Pre: -
     * Post: Me devuelve el maxima_cantidad_permitidos.
     */
    int devolver_maxima_cantidad_permitidos();
};

#endif //EDIFICIO_H

