#ifndef ANDYCOINS_H
#define ANDYCOINS_H
#include "material.h"

class Andycoins : public Material{
    private:
        string nombre;
        string emoji;
        int cantidad;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Andycoins.
         */
        Andycoins();
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Andycoins con nombre = ANDYCOINS, emoji = EMOJI_ANDYCOINS Y cantidad = cantidad.
         */
        Andycoins(int cantidad);

        virtual ~Andycoins();
};


#endif //ANDYCOINS_H
