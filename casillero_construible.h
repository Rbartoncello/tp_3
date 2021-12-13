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
         * Constructor sin parámetros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero_construible con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_construible();

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual void modificar_terreno(string elemento,int accion) = 0;

        /*
         * Pre: -
         * Post: Devuelve TRUE si está ocupado y FALSE en caso contrario.
         */
        bool esta_ocupado();
        
        /*
        * PRE: -
        * POST: Me modificara ocupado
        */
        void modificar_ocupado(bool estado);
        
        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual int devolver_duenio() = 0;
        
        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual Edificacion* devolver_edificacion(){return nullptr;};
        
        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual void eliminar_edificio(){};

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual void mostrar() = 0;
        
        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Casillero_construible.
         */
        virtual ~Casillero_construible() = 0;

        /*
         * PRE: -
         * POST: Devolverá el material que se encuentra en el casillero
         */
        Material* devolver_material();

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual string devolver_nombre_edificio(){return nullptr;};

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual void imprimir_resumen() = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para la clase casillero_transitable
        */
        void agregar_material(Material* nombre_material){};

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual void agregar_edificio(Edificacion* edificio){};
        
        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual int devolver_costo() = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual void agregar_jugador(Jugador* jugador) = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual void eliminar_jugador() = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual void mover_jugador(Jugador* jugador) = 0;

        /*
         * Pre: -
         * Post: Método virtual vació para la clase Terreno
         */
        virtual void modificar_costo(int costo) = 0;
};

#endif