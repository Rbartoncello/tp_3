#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include <string>
#include "edificio.h"

using namespace std;

class Edificios{
    private:
        Edificio** edificios;
        int total_edificios;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto edificios con total_edificios = 0.
         */
        Edificios();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a descruir el objeto edificios.
         */
        ~Edificios();

        /*
         * Pre: -
         * Post: Guarda cada linea en un objeto Edificio
         */
        int procesar_archivo();
   
    private:

        /*
         * Pre: Recibe un objeto Edificio.
         * Post: Ingresa el objeto en un vector dinámico.
         */
        void agregar_edificio(Edificio* edificio);

        /*
         * Pre: Recibe un nombre_edificio existente
         * Post: devuelve el emoji de ese edificio
        */
        string buscar_tipo_emoji(string nombre_edificio);

};

#endif