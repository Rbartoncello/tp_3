#ifndef MINA_ORO_H
#define MINA_ORO_H
#include "edificacion.h"

class Mina_oro : public Edificacion{
    private:
        int cantidad_material;
        bool produce_material;
        string material_producido;
        string emoji;
    public:
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Mina_oro con emoji = EMOJI_MINA_ORO produce_material = true cantidad_material = 50 y material_producido = ANDYCOINS.
         */
        Mina_oro(string nombre);

        /*
         * Pre: -.
         * Post: Devuelve cantidad_material.
         */
        int devolver_cantidad_material();

        /*
         * Pre: -.
         * Post: Devuelve emoji.
         */
        string devolver_emoji();

        /*
         * Pre: -.
         * Post: Devuelve la posicion del objeto Mina_oro.
         */
        void devolver_posicion();

        /*
         * Pre: -.
         * Post: Imprime por pantalla el EMOJI_MINA_ORO que representa al objeto MIna_oro
         */
        void imprimir_edificio();

        /*
         * Pre: -.
         * Post: Devuelve devuelve TRUE si produce_material o FALSE en caso contrario
         */
        bool brinda_material();

        /*
         * Pre: -.
         * Post: Devuelve la cantidad de material_producido.
         */
        string devolver_material_producido();

        /*
         * Pre: -.
         * Post: Devuelve un mensaje diciendo que objeto es.
         */
        void hablar_sobre_mi();
};

#endif //MINA_ORO_H