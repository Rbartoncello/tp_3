//
// Created by rbartoncello on 11/19/21.
//

#ifndef TP_3_TERRENO_H
#define TP_3_TERRENO_H
#include "casillero_construible.h"

class Terreno : public Casillero_construible{
    private:
        int costo;
    public:
        Terreno();
        
        Terreno(char tipo_terreno, int pos_x, int pos_y);

        void modicar_costo(int costo);

        int devolver_costo();

        ~Terreno();

        void mostrar();
};


#endif //TP_3_TERRENO_H
