//
// Created by rbartoncello on 11/19/21.
//

#ifndef TP_3_LAGO_H
#define TP_3_LAGO_H
#include "casillero_inaccesible.h"

class Lago : public Casillero_inaccesible {
    private:
        int costo;
    public:
        Lago();

        Lago(char tipo_terreno, int pos_x, int pos_y);

        void modicar_costo(int costo);

        int devolver_costo();

        ~Lago();

        void mostrar();
};


#endif //TP_3_LAGO_H
