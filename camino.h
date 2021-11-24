#ifndef CAMINO_H
#define CAMINO_H
#include "casillero_transitable.h"


class Camino : public Casillero_transitable{
    private:
    
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
};


#endif //CAMINO_H
