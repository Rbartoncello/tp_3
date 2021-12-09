#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H
#include "casillero.h"

class Casillero_construible : public Casillero{
    private:
        bool ocupado;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero_construible.
         */
        Casillero_construible(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero_construible con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_construible();

        /*
         * 
         * Pre:Recibe lo que va agregar
         * Post:Llama al hijo respectivo.
         */
        virtual void modificar_terreno(string elemento,int accion) = 0;

        /*
         * Pre: -
         * Post: De devuleve TRUE si esta ocupado y FALSE en caso contrario.
         */
        bool esta_ocupado();

        void modificar_ocupado(bool estado);

        virtual int devolver_duenio() = 0;

        virtual Edificacion* devolver_edificacion(){return nullptr;};

        virtual void eliminar_edificio(){};

        /*
         * Pre: -
         * Post: Me muestra por pantalla.
         */
        virtual void mostrar() = 0;

        virtual ~Casillero_construible() = 0; 

        /*
         * Pre: -
         * Post: Metodo virtual vacio para los hijos
        */
        virtual string devolver_nombre_edificio(){return nullptr;};

        /*
         * Pre: -
         * Post: Imprime un resumen escrito del casillero
        */
        virtual void imprimir_resumen() = 0;

        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_transitable
        */
        void agregar_material(Material* nombre_material){};

        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_construible
        */
        virtual void agregar_edificio(Edificacion* edificio){};

        virtual int devolver_costo() = 0;

        virtual void agregar_jugador(Jugador* jugador) = 0;

        virtual void eliminar_jugador() = 0;

        virtual void mover_jugador(Jugador* jugador) = 0;

        /*
         * PRE: -
         * POST: Me modifica el costo
         */
        virtual void modificar_costo(int costo) = 0;
};

#endif