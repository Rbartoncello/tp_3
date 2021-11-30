#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "material.h"
#include <string>

using namespace std;

class Inventario{
    private:
        Material** materiales;
        int total_materiales;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Inventario con total_materiales = 0.
         */
        Inventario();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a descruir el objeto Materiales.
         */
        ~Inventario();
        /*
         * Pre: Recibe un objeto Material.
         * Post: Ingresa el objeto en un vector dinámico.
         */
        void agregar_material(string nombre, int cantidad);

        /*
         * Pre: -
         * Post: Me muestra lista por pantalla toso los objetos del tipo Material.
         */
        void mostrar();

        /*
         * Pre: -
         * Post: Me muestra lista por pantalla toso los objetos del tipo Material.
         */
        Material** devolver_acceso_materiales();
    private:
        /*
         * Pre: Nombre tiene que ser un nombre de material existen
         * Post: Devuelve el tipo de material a buscar.
         */
        Material* buscar_tipo_material(string nombre);
};


#endif //INVENTARIO_H
