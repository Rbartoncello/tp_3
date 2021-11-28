#ifndef CASALLERO_INNACCESIBLE_H
#define CASALLERO_INNACCESIBLE_H
#include "casillero.h"

class Casillero_transitable : public Casillero{
    private:
        bool ocupado;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero.
         */
        Casillero_transitable(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_transitable();

        /*
         * 
         * Pre:Recibe lo que va agregar
         * Post:crea el material.
         */
        virtual void modificar_terreno(string elemento,int accion)=0;

        /*
         * Pre: -
         * Post: De devuleve TRUE si esta ocupado y FALSE en caso contrario.
         */
        bool esta_ocupado();

        void modificar_ocupado(bool estado);

        /*
         * Pre: -
         * Post: Me muestra por pantalla.
         */
        virtual void mostrar() = 0;

        /*
         * Pre: -
         * Post: Metodo vacio para la clase casillero_construible
        */
        string devolver_nombre_edificio(){return nullptr;};

        /*
         * Pre: -
         * Post: Imprime un resumen escrito del casillero
        */
        virtual void imprimir_resumen() = 0;

        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_transitable
        */
        virtual void agregar_material(Material* nombre_material){};

        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_construible
        */
        virtual void agregar_edificio(Edificacion* edificio){};

        /*
         * Pre: -
         * Post: Muestra graficamente el casillero por pantalla
        */
        void mostrar_casillero(int jugador, int cantidad_construidos);
};

#endif