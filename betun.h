#ifndef BETUN_H
#define BETUN_H
#include "casillero_transitable.h"

class Betun : public Casillero_transitable{
    private:
        Material* material;
        int costo;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Betun.
         */
        Betun();

        virtual Edificacion* devolver_edificacion(){return nullptr;};

        virtual void eliminar_edificio(){};

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Betun.
         */
        Betun(char tipo_terreno, int pos_x, int pos_y);

        /*
         * Pre: Recibe lo que va agregar
         * Post: crea el material.
         */
        void modificar_terreno(string elemento,int accion);

        /*
         * PRE: -
         * POST: Me modifica el costo
         */
        void modificar_costo(int costo);

        /*
         * PRE: -
         * POST: Me devuele el costo
         */
        int devolver_costo();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Betun.
         */
        ~Betun();

        /*
         * Pre: -
         * Post: Me muestra por pantalla.
         */
        void mostrar();

        /*
         * Pre: -
         * Post: Me va a agregar el material al casillero
        */
        void agregar_material(Material* material);

        /*
         * Pre: -
         * Post: Me va a devolver el material al casillero
        */
        Material* devolver_material();

        /*
         * Pre: -
         * Post: Imprime un resumen escrito del casillero
        */
        void imprimir_resumen();

        void agregar_jugador(Jugador* jugador);

        void eliminar_jugador();

        void mover_jugador(Jugador* jugador);
};


#endif //BETUN_H
