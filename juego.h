#ifndef JUEGO_H
#define JUEGO_H

#include "edificios.h"
#include "materiales.h"
#include "mapa.h"

class Juego{
    private:
        Materiales* materiales;
        Mapa* mapa;
    public:
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el Juego vacio
         */
        Juego();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Mapa.
         */
        ~Juego();

        /*
         * Pre: -.
         * Post: Devolvera TRUE si todos los archivos fueron abiertos correctamente.
         */
        int cargar();

        
        void mostrar();
};

#endif //JUEGO_H
