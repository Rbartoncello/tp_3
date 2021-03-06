#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H
#include "casillero.h"

class Casillero_inaccesible : public Casillero {
    private:
        bool ocupado;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero_inaccesible.
         */
        Casillero_inaccesible(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parámetros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero_inaccesible con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_inaccesible();

        /*
         * 
         * Pre:
         * Post:Está declarado al tenerlo el padre
         */
        void modificar_terreno(string elemento,int accion);

        /*
         * Pre: -
         * Post: Se devuelve TRUE si está ocupado y FALSE en caso contrario.
         */
        bool esta_ocupado();

        /*
         * Pre: -
         * Post: Me muestra por pantalla.
         */
        virtual void mostrar() = 0;
        
        /*
         * Pre: -
         * Post: Método virtual vació para la clase Lago
         */
        virtual int devolver_costo() = 0;

        /*
         * Pre: -
         * Post: Método vació para la clase casillero_construible
        */
        string devolver_nombre_edificio(){return "l";};
        
        /*
         * Pre: -
         * Post: Devolverá 0
         */
        int devolver_duenio(){return 0;};
        
        /*
         * Pre: -
         * Post: Retornara nullptr
         */
        Edificacion* devolver_edificacion(){return nullptr;};
        
        /*
         * Pre: -
         * Post: -
         */
        void eliminar_edificio(){};
        
        /*
         * Pre: -
         * Post: Imprime un resumen escrito del casillero
        */
        void imprimir_resumen();
        
        /*
         * Pre: Recibe un objeto hijo de la clase Material (el casillero debe estar vacio)
         * Post: Lo agrega al casillero en cuestion
         */
        void agregar_material(Material* nombre_material){};

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Lago
         */
        virtual void agregar_jugador(Jugador* jugador) = 0;
        
        /*
        * PRE: -
        * POST: Me modificara ocupado
        */
        void modificar_ocupado(bool estado);
        
        /*
         * Pre: -
         * Post: Método virtual vació para la clase Lago
         */
        virtual void eliminar_jugador() = 0;
        
        /*
         * PRE: -
         * POST: Devolverá el material que se encuentra en el casillero
         */
        Material* devolver_material();
        
        /*
         * Pre: -
         * Post: Método virtual vació para la clase Lago
         */
        virtual void mover_jugador(Jugador* jugador) = 0;
        
        /*
         * Pre: -
         * Post: Método virtual vació para la clase Lago
         */
        virtual void modificar_costo(int costo) = 0;
};

#endif