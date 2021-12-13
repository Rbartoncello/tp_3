#ifndef LAGO_H
#define LAGO_H
#include "casillero_inaccesible.h"

class Lago : public Casillero_inaccesible {
    private:
        int costo;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Lago.
         */
        Lago();
        
        /*
         * Constructor sin parámetros:
         * Pre: -.
         * Post: Me va a crear el objeto Lago con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Lago(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Pre: costo >= 0.
         * Post: Me va a modificar el costo.
         */
        void modificar_costo(int costo);
        
        /*
         * PRE:
         * POST: Me va a devolver el costo
         */
        int devolver_costo();

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Lago.
         */
        ~Lago();

        /*
        * PRE:
        * POST: Me mostrará el casillero Lago
        */
        void mostrar();

        /*
        * PRE: -
        * POST: Me agregará el jugador al casillero Lago
        */
        void agregar_jugador(Jugador* jugador);
        
        /*
        * PRE: -
        * POST: Me eliminará el jugador del casillero Lago
        */
        void eliminar_jugador();
        
        /*
        * PRE: -
        * POST: Me moverá el jugador al casillero Lago
        */
        void mover_jugador(Jugador* jugador);
};


#endif //LAGO_H
