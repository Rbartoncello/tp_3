#ifndef MATERIALES_H
#define MATERIALES_H
#include "material.h"
#include <string>

using namespace std;

class Materiales{
    private:
        Material** materiales;
        int total_materiales;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Materiales con total_materiales = 0.
         */
        Materiales();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a descruir el objeto Materiales.
         */
        ~Materiales();

        /*
         * Pre: -
         * Post: Guarda cada linea en un objeto Material
         */
        //int leer_archivo();

        /*
         * Pre: Recibe un objeto Material.
         * Post: Ingresa el objeto en un vector dinámico.
         */
        //void agregar_material(Material* material);

        /*
         * Pre: -
         * Post: Me muestra lista por pantalla toso los objetos del tipo Material.
         */
        void mostrar();
;
};

#endif //MATERIALES_H
