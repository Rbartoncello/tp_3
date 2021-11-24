#ifndef METAL_H
#define METAL_H
#include "material.h"
class Metal : public Material{
    private:
        string nombre;
        string emoji;
        int cantidad;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Metal.
         */
        Metal();
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Metal con nombre = METAL, emoji = EMOJI_METAL Y cantidad = cantidad.
         */
        Metal(int cantidad);
};



#endif //METAL_H