//
// Created by rbartoncello on 11/19/21.
//

#ifndef TP_3_MUELLE_H
#define TP_3_MUELLE_H
#include "casillero_transitable.h"

class Muelle : public  Casillero_transitable{
    private:
        int costo;
    public:
        Muelle();

        Muelle(char tipo_terreno, int pos_x, int pos_y);

        void modicar_costo(int costo);

        int devolver_costo();

        ~Muelle();

        void mostrar();
};


#endif //TP_3_MUELLE_H
