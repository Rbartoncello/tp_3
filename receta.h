#ifndef RECETA_H
#define RECETA_H
#include <string>
#include "piedra.h"
#include "madera.h"
#include "metal.h"

using namespace std;

class Receta {
    private:
        Piedra* piedra;
        Madera* madera;
        Metal* metal;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Receta.
         */
        Receta();

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Receta.
         */
        Receta(int piedra, int madera, int metal);

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a detruir el objeto Receta.
         */
        ~Receta();
        /*
         * Pre: -
         * Post: Me devuelve el cantidad de material PIEDRA, MADERA o METAL y 0 en el caso que no sea ninguno de los anteriores.
         */
        int devolver_receta(string material);

        /*
         * Pre: material tiene que ser si o si PIEDRA, MADERA o METAL
         * Post: Me modificar el cantidad de material PIEDRA, MADERA o METAL.
         */
        void modificar_receta(string material, int cantidad);
    //private:
        /*
         * Pre: -
         * Post: Me modificar el cantidad de material piedra
         */
        void modificar_piedra(int cantidad);

        /*
         * Pre: -
         * Post: Me modificar el cantidad de material madera
         */
        void modificar_madera(int cantidad);

        /*
         * Pre: -
         * Post: Me modificar el cantidad de material metal
         */
        void modificar_metal(int cantidad);

        /*
         * Pre: -
         * Post: Me devuelve el cantidad de piedra.
         */
        int devoler_piedra();

        /*
         * Pre: -
         * Post: Me devuelve el cantidad de madera.
         */
        int devoler_madera();

        /*
         * Pre: -
         * Post: Me devuelve el cantidad de metal.
         */
        int devoler_metal();
};


#endif //RECETA_H
