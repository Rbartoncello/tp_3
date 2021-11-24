#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
#include "constantes.h"

using namespace std;

class Material{
    private:
        string nombre;
        string emoji;
        int cantidad;
    public:
        /*
        * Constructor:
        * Pre: -.
        * Post: Me va a crear el objeto Material.
        */
        Material(string nombre, string emoji, int cantidad);

        /*
        * Constructor:
        * Pre: -.
        * Post: Me va a crear el objeto Material con nombre_material "NULL", emoji = "NULL" y cantidad = 0.
        */
        Material();

        /*
        * Pre: -.
        * Post: Me va agregar un emoji en el atributo emoji dependiendo si es piedra, madera o metal.
        */
        string agregar_emoji(string nombre_matertial);

        /*
        * Pre: -
        * Post: Me muestra por pantalla el objeto tipo Material.
        */
        void mostrar();

        /*
        * Pre: -
        * Post: Me devuelve el nombre
        */
        string devolver_nombre();

        /*
        * Pre: -
        * Post: Me devuelve el emoji.
        */
        string devolver_emoji();

        /*
        * Pre: -
        * Post: Me devuelve el cantidad.
        */
        int devolver_cantidad();

        /*
         * Pre: cantidad > 0.
         * Post: Modifica la cantidad de Material.
         */
        void modificar_cantidad(int cantidad);
};

#endif //MATERIAL_H