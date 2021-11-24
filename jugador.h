#ifndef JUEGADOR_H
#define JUEGADOR_H

#include "materiales.h"
#include "archivo.h"

class Jugador{
    private:
        string nombre;
        int energia;
        Materiales* inventario;
        //Objetivo_secundario** objetivos_secundarios
        //Objetivo_primario* objetivo_primario
    public:
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el Jugador vacio
         */
        Jugador();


        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el arreglo de objetivos
         */
        ~Jugador();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a definir como nombre el string ingresado por input (con ese nombre se va a referir al jugador por el resto del juego)
         */
        void pedir_nombre();

        /*
         * Destructor:
         * Pre: es un numero entero positivo
         * Post: Me va a restar la cantidad de energia pasada por parametro
         */
        void restar_energia(int cantidad);
        
        /*
         * Destructor:
         * Pre: es un numero entero positivo
         * Post: Me va a sumar la cantidad de energia pasada por parametro
         */
        void sumar_energia(int cantidad);

        /*
         * Destructor:
         * Pre: recibe un material bien creado
         * Post: Suma ese material a su contraparte en el inventario
         */
        void recoger_recurso(Material* recurso);


        
};


#endif //JUEGADOR_H