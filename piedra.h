#ifndef PIEDRA_H
#define PIEDRA_H
#include "material.h"
class Piedra : public Material{
    private:
        string nombre;
        string emoji;
        int cantidad;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Piedra.
         */
        Piedra();
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Piedra con nombre = PIEDRA, emoji = EMOJI_PIEDRA Y cantidad = cantidad.
         */
        Piedra(int cantidad);
};



#endif //PIEDRA_H
