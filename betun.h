//
// Created by rbartoncello on 11/19/21.
//

#ifndef TP_3_BETUN_H
#define TP_3_BETUN_H
#include "casillero_transitable.h"

class Betun : public Casillero_transitable{
    private:
        int costo;
    public:
        Betun();

        Betun(char tipo_terreno, int pos_x, int pos_y);

        void modicar_costo(int costo);

        int devolver_costo();

        ~Betun();

        /*
         * Pre: -
         * Post: Me muestra por pantalla.
         */
        void mostrar();
};


#endif //TP_3_BETUN_H
