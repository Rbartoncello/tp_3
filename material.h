#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
#include "constantes.h"

using namespace std;

class Material{
    private:
        string nombre_material;
        string emoji;
        int cantidad_material_jugador_1;
        int cantidad_material_jugador_2;
    public:
        /*
        * Constructor:
        * Pre: -.
        * Post: Me va a crear el objeto Material.
        */
        Material(string nombre_material, int cantidad_material_jugador_1, int cantidad_material_jugador_2);

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
        * Post: Me devuelve el nombre_material.
        */
        string devolver_nombre_material();

        /*
        * Pre: -
        * Post: Me devuelve el emoji.
        */
        string devolver_emoji();

        /*
        * Pre: -
        * Post: Me devuelve el cantidad_material_jugador_1.
        */
        int devolver_cantidad_material_jugador_1();

        /*
        * Pre: -
        * Post: Me devuelve el cantidad_material_jugador_2.
        */
        int devolver_cantidad_material_jugador_2();
};

#endif //MATERIAL_H