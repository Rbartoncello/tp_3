#ifndef MAPA_H
#define MAPA_H
#include <fstream>
#include "casillero.h"
#include "andycoins.h"
#include "constantes.h"
#include "jugador.h"
#include "emojis.h"

using namespace std;
class Mapa{
    private:
        int cantidad_filas;
        int cantidad_columnas;
        Casillero*** casilleros;

    public:
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Mapa con cantidad_filas = 0, cantidad_columnas = 0 y casilleros = nullptr.
         */
        Mapa();

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Mapa.
         */
        Mapa(int filas, int columnas);

        /*
         * Pre: la fila y la columna tiene que estar dentro de los parametro del mapa.
         * Post: Me devolvera el casillero.
         */
        Casillero* devolver_casillero(int fila, int columna);

                /*
         * Pre: 
         * Post: devuelve el puntero casillero
         */
        Casillero*** devolver_puntero_casillero();

        void construir_edifcio(Jugador* jugador);

        int cantidad_edificio_construido(string nombre);

        /*
         * Pre: la fila y la columna tiene que estar dentro de los parametro del mapa.
         * Post: Me devolvera TRUE si el casillero esta ocupado FALSE en caso contrario.
         */
        bool casillero_ocupado(int fila, int columna);

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Mapa.
         */
        ~Mapa();

        /*
         * Pre: recibe un nombre.
         * Post: devuelve la cantidad de ese nombre en el mapa.
        */
        int devolver_cantidad_edificio(string nombre_edificio_nuevo, Jugador* jugador);

        int devolver_cantidad_edificio(string nombre_edificio_nuevo);

        void crear_lista_auxiliar_edificios(Lista_primitiva<int>* &cantidad_por_edificio);

        void crear_lista(Lista_primitiva<string>* &objetivos);

        /*
         * Pre: -
         * Post: Guarda todos los datos del archivo en un objeto Mapa
         */
        int leer_archivo();

        /*
         * Pre: -
         * Post: Me muestra por pantalla el mapa.
         */
        void mostrar();

        /*
         * Pre: nombre de material,fila y columna en indice de la matriz
         * Post: Agrega al casillero marcado el material pasado por parametro
         */
        void agregar_material(string nombre, int fila, int columna);

        void agregar_jugador(Jugador* jugador);

        void mover_jugador(Jugador* jugador, int fila , int columna);

        char devolver_tipo_terreno(int coord1, int columna);

        void agregar_edificacion(string nombre, int fila, int columna, int duenio, Lista_edificios<Edificacion> *&edificios_jugador);

        Edificacion* crear_edificio(string nombre, int piedra, int madera, int metal, int max_cant_permitidos);

        /*
         * Pre: -
         * Post: Devuelve la cantidad de filas que tiene la matriz de casilleros
        */
        int devolver_cantidad_filas();

        /*
         * Pre: -
         * Post: Devuelve la cantidad de columnas que tiene la matriz de casilleros
        */
        int devolver_cantidad_columnas();

        /*
         * Pre: Recibe coordenadas dentro del dominio de la matriz
         * Post: Imprime por pantalla un resumen del casillero pedido
        */
        void imprimir_resumen_casillero(int fila, int columna);

        void mostrar_edificios_construidos(Jugador* jugador_actual);

        /*
      * Pre: -
      * Post: valida que una coordenada es de tipo construible
      */
        bool validar_tipo_construible(int fila, int columna);

        /*
         * Pre: -
         * Post: valida que una coordenada es de tipo transitable
         */
        bool validar_tipo_transitable(int fila, int columna);
        
        /*
         * Pre: el casillero tiene un edificio
         * Post: Elimina el edificio del casillero
         */
        void borrar_edificio(int fila, int columna);

        /*
         * Pre: Fila y columna dentro de los parametros del mapa
         * Post: Me devuelve TRUE si en esa posicion exite un edificio
         */
        bool hay_edificio(int fila, int columna);

        /*
         * Pre: -
         * Post: Guarda materiales en casilleros transitables de manera aleatoria (con las probabilidades dadas por consigna)
        */
        void lluvia_recursos();

        /*
         * Pre: -
         * Post: Me devuelve TRUE si hay como minimo un edificio construido y FALSE en caso contrario.
        */
        bool hay_algun_edificio_construido();

    private:
        /*
         * Pre: El archivo tiene que estar abierto y de formato correcto.
         * Post: Me va agregar los datos de encuentra en el archivo en un determinado objeto dependiendo lo que lea del archivo.
         */
        void agregar_casillero(ifstream &archivo);

        /*
         * Pre: -
         * Post: Me crea una matriz del tipo casillero de forma dinamica.
         */
        void crear_matriz_casilleros();


        

        /*
         * Pre: El nombre tiene que ser de un material exitente
         * Post: Me devolver el material buscado.
         */
        Material* buscar_material(string nombre);

        //Pre:
        //Post:Agrega lo lloviddo a la coordenada correspondiente
        void agregar_a_coordenada(int cantidad, string material);

        void agregar_material(int cantidad, string material);

        /*
         * Pre: Recibe 2 numeros
         * Post: Devuelve un numero aleatorio entre esos 2 numeros
        */
        int numero_aleatorio(int desde, int hasta);
        
        /*
         * Pre: Recibe coordenadas dentro del dominio de la matriz
         * Post: Devuelve true si el casillero es transitable y esta vacio, false de lo contrario
        */
        bool se_puede_generar_material(int fila, int columna);

        /*
         * Pre: Recibe un nombre de material y dos numeros minimo y maximo
         * Post: Crea una cantidad n ( siendo min < n <max ) de ese material y los agrega al mapa
        */
        void agregar_materiales(string material, int minimo, int maximo);


        /*
         * Pre: -
         * Post: Me devuleve TRUE si el si por lo menos hay como minimo 7 casilleros transitables no ocupados.
         */
        bool hay_lugar_minimo_material();

};

#endif //MAPA_H
