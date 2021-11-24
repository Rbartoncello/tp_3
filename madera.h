#ifndef MADERA_H
#define MADERA_H
#include "material.h"
class Madera : public Material{
    private:
        string nombre;
        string emoji;
        int cantidad;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Madera.
         */
        Madera();
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Madera con nombre = MADERA, emoji = EMOJI_MADERA Y cantidad = cantidad.
         */
        Madera(int cantidad);
};



#endif //MADERA_H