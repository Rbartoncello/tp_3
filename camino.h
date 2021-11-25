#ifndef CAMINO_H
#define CAMINO_H
#include "casillero_transitable.h"


class Camino : public Casillero_transitable{
    private:
        Material* material;
        int costo;
    public:
        Camino();

        Camino(char tipo_terreno, int pos_x, int pos_y);

        /*
         * 
         * Pre:Recibe lo que va agregar
         * Post:crea el material.
         */
        void modificar_terreno(string elemento,int accion);

        void modicar_costo(int costo);

        int devolver_costo();

        ~Camino();

        void mostrar();

        /*
         * Pre: -
         * Post: Me va a agregar el material al casillero
        */
        void agregar_material(Material* material);

        /*
         * Pre: -
         * Post: Me va a devolver el material al casillero
        */
        Material* devolver_material();
};


#endif //CAMINO_H
