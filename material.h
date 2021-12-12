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
         * Pre:
         * Post: Modifica la cantidad de Material.
         */
        void modificar_cantidad(int cantidad);

        /*
         * Pre: -
         * Post: Imprime un resumen escrito del material
        */
        void imprimir_resumen();

        /*
         * Pre: Cantidad mayor a 0
         * Post: Aumenta la cantidad del material
        */
        void aumentar_cantidad(int cantidad);

        /*
         * Pre: Cantidad mayor a 0
         * Post: Reduce la cantidad del material
        */
        void reducir_cantidad(int cantidad);
        /*
        * PRE:
        * POST:
        */
        virtual ~Material() = 0;
};

#endif //MATERIAL_H