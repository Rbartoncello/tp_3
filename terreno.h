#ifndef TERRENO_H
#define TERRENO_H
#include <string>
#include "casillero_construible.h"
#include "edificacion.h"
#include "casillero.h"
#include "obelisco.h"
#include "mina.h"
#include "mina_oro.h"
#include "escuela.h"
#include "planta.h"
#include "constantes.h"
#include "fabrica.h"
#include "aserradero.h"
#include "diccionario.h"

using namespace std;

class Terreno : public Casillero_construible{
    private:
        int costo;
        Edificacion* puntero_edificio;

    public:
        Terreno();
        
        Terreno(char tipo_terreno, int pos_x, int pos_y);

        /*
        * 
        * Pre:Recibe lo que va agregar
        * Post:verifica que es lo que se realizara en el terreno.
        */
        void modificar_terreno(string elemento,int accion,Diccionario* dict);

        //Pre:Recibe el nombre del edificio.
        //Post:crear una instancia en el heap de un edificio y lo vincula al punteroEdificio.
        void crear_edificio(string nombreEdificio, Diccionario* diccionario);

        //Pre:
        //Post:Elimina la direccion de memoria del edificio y apunta a nullptr el punteroEdificio.
        void remover_edificio();

        void modicar_costo(int costo);

        int devolver_costo();

        void mostrar();

        /*
         * Pre: Tiene que haber un edificio en el casillero
         * Post: Devuelve el nombre del edificio
        */
        string devolver_nombre_edificio();

        virtual ~Terreno();
};


#endif //TERRENO_H
