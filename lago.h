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

        void modificar_costo(int costo);

        int devolver_costo();

        int devolver_duenio();

        Edificacion* devolver_edificacion(){return nullptr;};

        virtual void eliminar_edificio(){};

        ~Lago();

        void mostrar();

        void agregar_jugador(Jugador* jugador);

        void eliminar_jugador();

        void mover_jugador(Jugador* jugador);
};


#endif //LAGO_H
