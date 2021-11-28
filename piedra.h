#ifndef PIEDRA_H
#define PIEDRA_H
#include "material.h"


class Piedra : public Material{
    private:
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

        virtual ~Piedra();
};



#endif //PIEDRA_H
