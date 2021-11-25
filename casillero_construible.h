#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H
#include "casillero.h"

class Casillero_construible : public Casillero{
    private:
        bool ocupado;
        Edificacion* edificio;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero.
         */
        Casillero_construible(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
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
        void imprimir_resumen();
};

#endif