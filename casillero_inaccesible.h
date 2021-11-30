#ifndef CASALLERO_INACCESIBLE_H
#define CASALLERO_INACCESIBLE_H
#include "casillero.h"

class Casillero_inaccesible : public Casillero {
    private:
        bool ocupado;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero.
         */
        Casillero_inaccesible(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_inaccesible();

        /*
         * 
         * Pre:
         * Post:Esta declarado al tenerlo el padre
         */
        void modificar_terreno(string elemento,int accion);

        /*
         * Pre: -
         * Post: De devuleve TRUE si esta ocupado y FALSE en caso contrario.
         */
        bool esta_ocupado();

        /*
         * Pre: -
         * Post: Me muestra por pantalla.
         */
        virtual void mostrar() = 0;

        virtual int devolver_costo() = 0;

        /*
         * Pre: -
         * Post: Metodo vacio para la clase casillero_construible
        */
        string devolver_nombre_edificio(){return nullptr;};

        /*
         * Pre: -
         * Post: Imprime un resumen escrito del casillero
        */
        void imprimir_resumen();

        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_transitable
        */
        void agregar_material(Material* nombre_material){};

        /*
         * Pre: -
         * Post: Muestra graficamente el casillero por pantalla
        */
        void mostrar_casillero(int jugador, int cantidad_construidos);

        virtual void agregar_jugador(Jugador* jugador) = 0;

        void modificar_ocupado(bool estado);

        virtual void eliminar_jugador() = 0;

        virtual void mover_jugador(Jugador* jugador) = 0;
};

#endif