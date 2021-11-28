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
         * Pre: Recibe un nombre de materail que exita.
         * Post: Ingresa el objeto en un vector dinámico.
         */
        void agregar_material(string nombre, int cantidad);

        /*
         * Pre: Recibe un objeto Material que ya existe en el vector dinamico.
         * Post: Suma la cnatidad del objeto ingresado al objeto del mismo tipo que se encuentra en el vector dinámico.
         */
        //void sumar_material(Material* material);


        /*
         * Pre: -
         * Post: Me muestra lista por pantalla toso los objetos del tipo Material.
         */
        void mostrar();
    private:
        /*
         * Pre: Nombre tiene que ser un nombre de material existen
         * Post: Devuelve el tipo de material a buscar.
         */
        Material* buscar_tipo_material(string nombre, int cantidad);
;
};

#endif //MATERIALES_H
