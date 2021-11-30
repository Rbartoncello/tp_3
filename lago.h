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
        Lago();

        Lago(char tipo_terreno, int pos_x, int pos_y);

        void modicar_costo(int costo);

        int devolver_costo();

        ~Lago();

        void mostrar();

        void agregar_jugador(Jugador* jugador);

        void eliminar_jugador();

        void mover_jugador(Jugador* jugador);
};


#endif //LAGO_H
