//
// Created by rbartoncello on 11/19/21.
//

#ifndef TP_3_CAMINO_H
#define TP_3_CAMINO_H
#include "casillero_transitable.h"


class Camino : public Casillero_transitable{
    private:
        int costo;
    public:
        Camino();

        Camino(char tipo_terreno, int pos_x, int pos_y);

        void modicar_costo(int costo);

        int devolver_costo();

        ~Camino();

        void mostrar();
};


#endif //TP_3_CAMINO_H
