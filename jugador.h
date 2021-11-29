#ifndef JUEGADOR_H
#define JUEGADOR_H
#include "materiales.h"
#include "lista.h"
#include "objetivos.h"
#include "mas_alto_que_las_nubes.h"

class Jugador{
    private:
        string nombre;
        string emoji;
        int energia, numero, fila, columna;
        Lista* inventario;
        Objetivos** objetivos_secundarios;
        //Mas_alto_que_las_nubes* objetivo_primario;
        

    public:
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el Jugador vacio
         */
        Jugador(int numero, string emoji);
        

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el arreglo de objetivos
         */
        ~Jugador();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a definir como nombre el string ingresado por input (con ese nombre se va a referir al jugador por el resto del juego)
         */
        void pedir_nombre();

        /*
         * Pre: Recibe un nombre de un material que exita.
         * Post: Ingresa el objeto en un vector dinámico.
         */
        void agregar_material(string nombre, int cantidad);

        /*
         * Destructor:
         * Pre: es un numero entero positivo
         * Post: Me va a restar la cantidad de energia pasada por parametro
         */
        void restar_energia(int cantidad);
        
        /*
         * Destructor:
         * Pre: es un numero entero positivo
         * Post: Me va a sumar la cantidad de energia pasada por parametro
         */
        void sumar_energia(int cantidad);

        /*
         * Destructor:
         * Pre: recibe un material bien creado
         * Post: Suma ese material a su contraparte en el inventario
         */
        void recoger_recurso(Material* recurso);

        Lista*& devolver_inventario();

        void modificar_numero(int numero);

        void modificar_fila(int fila);

        void modificar_columna(int columna);

        /*
         * Pre: -
         * Post: Me muestra lista por pantalla el inventario.
         */
        void mostrar_inventario();

        int devolver_fila();

        int devolver_columna();

        int devolver_numero();

        string devolver_emoji();
};


#endif //JUEGADOR_H