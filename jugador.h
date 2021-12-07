#ifndef JUEGADOR_H
#define JUEGADOR_H
#include "materiales.h"
#include "lista.h"
#include "objetivos.h"
#include "constantes.h"
#include "lista_primitiva.h"
#include "comprar_andypolis.h"
#include "bombardero.h"
#include "edad_piedra.h"
//#include "mas_alto_que_las_nubes.h"

class Jugador
{
private:
    string nombre;
    string emoji;
    int energia, numero, fila, columna, objetivos_completados;
    Lista<Material> *inventario;
    Lista<Objetivos> *objetivos_secundarios;
    //Mas_alto_que_las_nubes* objetivo_primario;

public:
    /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el Jugador vacio
         */
    Jugador(int numero, string emoji);

    /*
         * Pre: Necesita un punto de inicio y uno de final
         * Post: Va a generar un numero random.
         */
    int numero_aleatorio(int desde, int hasta);

    /*
         * Pre: 
         * Post: Devuelve el numero asignado al jugador.
         */
    int devolver_numero();

    /*
         * Pre: 
         * Post: muestra por pantalla los objetivos del jugador
         */
    void mostrar_objetivos();

    /*
         * Pre: necesita un valor a sumar y el nombre del objetivo
         * Post: si el objetivo es del usuario suma
         */
    void sumar_a_objetivo(int cantidad, string nombre_objetivo);

    int devolver_energia();
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
    void aumentar_material(Material *material);

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
    void recoger_recurso(Material *recurso);

    Lista<Material> *&devolver_inventario();

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

    string devolver_emoji();

    void vaciar_inventario();

    /*
         * Pre: -
         * Post: Realizara el procedimiento de compra de bombas.
         */
    void comprar_bombas();

    /*
         * Pre: costo tiene que ser mayor a 0
         * Post: Me devuelve TRUE si costo >= andycoins y FALSE en caso contrario.
         */
    bool andycoins_sufuciente(int costo);

    /*
         * Pre: Cantidad tiene que ser mayor a 0
         * Post: Comprar la cantidad de bombas ingresadas.
         */
    void comprar_bombas(int cantidad);

    /*
         * Pre: Precio tiene que ser mayor a 0
         * Post:Me restara el cantidad (precio) de andycoins del inventario.
         */
     void gastar_andycoins(int precio);

     bool validar_objetivos();

     /*
         * Pre: 
         * Post:termina con 3 objetivos en la lista objetivos secundarios
         */
    void generar_objetivos_secundarios();
private:

    /*
         * Pre: Necesita una lista de objetivos de tipo string
         * Post: Agrega el nombre de los objetivos a esta lista
         */
    void crear_lista(Lista_primitiva<string> *&objetivos);

    /*
         * Pre: Necesita el nombre del objetivo a crear
         * Post: Agrega a la lista de objetivos secundarios un nuevo objetivo
         */
    void agregar_objetivo(string nombre_objetivo);

    

    int contar_objetivos_completados(int contador);
};

#endif //JUEGADOR_H