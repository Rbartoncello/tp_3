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
        void modicar_costo(int costo);

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
};


#endif //BETUN_H
