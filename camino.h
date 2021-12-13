#ifndef CAMINO_H
#define CAMINO_H
#include "casillero_transitable.h"


class Camino : public Casillero_transitable{
    private:
        Material* material;
        int costo;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Camino.
         */
        Camino();
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Camino.
         */
        Camino(char tipo_terreno, int pos_x, int pos_y);

        /*
         * 
         * Pre:Recibe lo que va agregar
         * Post:crea el material.
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
         * Post: Me va a destruir el objeto Camino.
         */
        ~Camino();

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
        
        /*
        * PRE: -
        * POST: Me agregará el jugador al casillero Camino
        */
        void agregar_jugador(Jugador* jugador);
        
        /*
        * PRE: -
        * POST: Me eliminará el jugador del casillero Camino
        */
        void eliminar_jugador();
        
        /*
        * PRE: -
        * POST: Me moverá el jugador al casillero Camino
        */
        void mover_jugador(Jugador* jugador);
};


#endif //CAMINO_H
