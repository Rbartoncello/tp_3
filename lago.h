//
// Created by rbartoncello on 11/19/21.
//

#ifndef LAGO_H
#define LAGO_H
#include "casillero_inaccesible.h"

class Lago : public Casillero_inaccesible {
    private:
        int costo;
    public:
            /*
        * PRE:
        * POST:
        */
        Lago();
        /*
        * PRE:
        * POST:
        */
        Lago(char tipo_terreno, int pos_x, int pos_y);
        /*
        * PRE:
        * POST:
        */
        void modificar_costo(int costo);
        /*
        * PRE:
        * POST:
        */
        int devolver_costo();
        /*
        * PRE:
        * POST:
        */
        Edificacion* devolver_edificacion(){return nullptr;};
        /*
        * PRE:
        * POST:
        */
        virtual void eliminar_edificio(){};
        /*
        * PRE:
        * POST:
        */
        ~Lago();
        /*
        * PRE:
        * POST:
        */
        void mostrar();
        /*
        * PRE:
        * POST:
        */
        void agregar_jugador(Jugador* jugador);
        /*
        * PRE:
        * POST:
        */
        void eliminar_jugador();
        /*
        * PRE:
        * POST:
        */
        void mover_jugador(Jugador* jugador);
};


#endif //LAGO_H
