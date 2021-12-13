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
         * Post: Me va a crear el objeto Casillero_transitable.
         */
        Casillero_transitable(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero_transitable con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
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
        
        /*
        * PRE: -
        * POST: Me modificara ocupado
        */
        void modificar_ocupado(bool estado);
        
        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
         */
        virtual int devolver_costo() = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
         */
        virtual void mostrar() = 0;

        /*
         * Pre: -
         * Post: Me retornara 0
        */
        string devolver_nombre_edificio(){return "0";};

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
         */
        virtual void imprimir_resumen() = 0;

        /*
         * Pre: -
         * Post: Me retornara 0
         */
        int devolver_duenio(){{return 0;}};

        /*
         * Pre: -
         * Post: Me retornara nullptr
         */
        Edificacion* devolver_edificacion(){return nullptr;};

        void eliminar_edificio(){};

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
         */
        virtual Material* devolver_material() = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
         */
        virtual void agregar_material(Material* nombre_material){};

        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_construible
        */
        void agregar_edificio(Edificacion* edificio){};

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
         */
        virtual void agregar_jugador(Jugador* jugador) = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
         */
        virtual void eliminar_jugador() = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
         */
        virtual void mover_jugador(Jugador* jugador) = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
         */
        virtual void modificar_costo(int costo) = 0;
};

#endif