//
// Created by rbartoncello on 11/19/21.
//

#ifndef MUELLE_H
#define MUELLE_H
#include "casillero_transitable.h"

class Muelle : public  Casillero_transitable{
    private:
        int costo;
    public:
        Muelle();

        Muelle(char tipo_terreno, int pos_x, int pos_y);

        /*
        * 
        * Pre:Recibe lo que va agregar
        * Post:crea el material.
        */
        void modificar_terreno(string elemento,int accion);

        void modicar_costo(int costo);

        int devolver_costo();

        ~Muelle();

        void mostrar();
};


#endif //MUELLE_H
