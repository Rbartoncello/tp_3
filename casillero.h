#ifndef CASILLERO_H
#define CASILLERO_H
#include "colors.h"
#include <string>
#include <iostream>
#include "material.h"

using namespace std;

class Casillero{
    protected:
        char tipo_terreno;
        
    private:
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
         * Constructor sin parametros:
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
         * 
         * Pre:Recibe lo que va agregar
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
         * Post: Metodo virtual vacio para las clases hijas
        */
        virtual bool esta_ocupado() = 0;

        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_construible
        */
        virtual string devolver_nombre_edificio(){return nullptr;};

        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_transitable
        */
        virtual void agregar_material(Material* nombre_material){};
};


#endif //CASILLERO_H
