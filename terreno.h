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

using namespace std;

class Terreno : public Casillero_construible{
    private:
        Edificacion* edificacion;
        int costo;
    public:
        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto Terreno.
         */
        Terreno();
        
        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto Terreno.
         */
        Terreno(char tipo_terreno, int pos_x, int pos_y);

        /*
         * PRE:Recibe lo que va agregar
         * POST:verifica que es lo que se realizara en el terreno.
         */
        void modificar_terreno(string elemento, int accion);

        /*
         * PRE:Recibe el nombre del edificio.
         * POST:crear una instancia en el heap de un edificio y lo vincula al edificio.
         */
        void crear_edificio(string nombre_edificio);
        
        /*
         * PRE:
         * POST:Elimina la direccion de memoria del edificio y apunta a nullptr el edificio.
         */
        void remover_edificio();

        /*
         * PRE: costo tiene que ser mayor a 0
         * POST: Me modifica el costo
         */
        void modificar_costo(int costo);

        /*
         * PRE: -
         * POST: Me devuele el costo
         */
        int devolver_costo();

        /*
         * PRE: -
         * POST: Me muestra por pantalla el contenido de este casillero
         */
        void mostrar();

        /*
         * PRE: Tiene que haber un edificio en el casillero
         * POST: Devuelve el nombre del edificio
         */
        string devolver_nombre_edificio();



        int devolver_duenio();

        /*
         * PRE: -
         * POST: Metodo virtual vacio para la clase casillero_construible
         */
        void agregar_edificio(Edificacion* edificio);

        /*
         * Destructor:
         * PRE: -.
         * POST: Me va a destrulle el objeto Terreno.
         */
        virtual ~Terreno();
        
        /*
         * PRE: -
         * POST: Imprime un resumen escrito del casillero
         */
        void imprimir_resumen();

        /*
         * Pre: -
         * Post: Metodo virtual vacio para las clases hijas
        */
        void mostrar_casillero(Jugador* jugador, int cantidad_construidos);

        void agregar_jugador(Jugador* jugador);

        void eliminar_jugador();

        void mover_jugador(Jugador* jugador);
};


#endif //TERRENO_H
