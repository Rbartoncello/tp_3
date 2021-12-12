#ifndef CASILLERO_H
#define CASILLERO_H
#include <string>
#include <iostream>
#include "colors.h"
#include "material.h"
#include "edificacion.h"
#include "jugador.h"

using namespace std;

class Casillero{
    protected:
        char tipo_terreno;
        
    private:
        Jugador* jugador;
        int pos_x;
        int pos_y;

    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero.
         */
        Casillero(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parámetros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0 y pos_y = 0.
         */
        Casillero();
        
        /*
         * 
         * Pre: -.
         * Post: devuelve el tipo de terreno.
         */
        char devolver_tipo_terreno();

        /*
         * Pre:Recibe lo que va a agregar
         * Post:Llama al hijo respectivo.
         */
        virtual void modificar_terreno(string elemento,int accion) = 0;
        
        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Casillero.
         */
        virtual ~Casillero(){};

        /*
         * Pre: -
         * Post: Me muestra por pantalla.
         */
        virtual void mostrar() = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
        */
        virtual bool esta_ocupado() = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para la clase casillero_construible
        */
        virtual string devolver_nombre_edificio() = 0;

        virtual int devolver_duenio() = 0;

        virtual Edificacion* devolver_edificacion(){return nullptr;};

        virtual Material* devolver_material() = 0;

        virtual void eliminar_edificio(){};

        /*
         * Pre: -
         * Post: Método virtual vació para las clases hijas
        */
        virtual void imprimir_resumen(){};

        /*
         * Pre: -
         * Post: Método virtual vació para la clase casillero_transitable
        */
        virtual void agregar_material(Material* nombre_material){};

        /*
         * Pre: -
         * Post: Método virtual vació para la clase casillero_construible
        */
        virtual void agregar_edificio(Edificacion* edificio){};

        string devolver_posicion();

        virtual int devolver_costo() = 0;

        virtual void agregar_jugador(Jugador* jugador) = 0;

        void modificar_jugador(Jugador* jugador);

        Jugador* devolver_jugador();

        virtual void eliminar_jugador() = 0;

        virtual void mover_jugador(Jugador* jugador) = 0;

        virtual void modificar_costo(int costo) = 0;
};


#endif //CASILLERO_H



























































































































