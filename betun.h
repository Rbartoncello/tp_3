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
         * POST: Me devuelve el costo
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
        void agregar_material(Material* material_nuevo);

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
        
        /*
        * PRE: -
        * POST: Me agregará el jugador al casillero Betun
        */
        void agregar_jugador(Jugador* jugador);
        
        /*
        * PRE: -
        * POST: Me eliminará el jugador del casillero Betun
        */
        void eliminar_jugador();
        
        /*
        * PRE: -
        * POST: Me moverá el jugador al casillero Betun
        */
        void mover_jugador(Jugador* jugador);
};


#endif //BETUN_H
