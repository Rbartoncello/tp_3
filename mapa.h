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
         * Constructor sin parámetros:
         * Pre: -.
         * Post: Me va a crear el objeto Mapa con cantidad_filas = 0, cantidad_columnas = 0 y casilleros = nullptr.
         */
        Mapa();

        /*
         * Pre: la fila y la columna tiene que estar dentro de los parámetros del mapa.
         * Post: Me devolverá el casillero.
         */
        Casillero* devolver_casillero(int fila, int columna);

        /*
         * Pre: 
         * Post: devuelve el puntero casillero
         */
        Casillero*** devolver_puntero_casillero();

        /*
         * Pre: la fila y la columna tiene que estar dentro de los parámetros del mapa.
         * Post: Me devolverá TRUE si el casillero está ocupado FALSE en caso contrario.
         */
        bool casillero_ocupado(int fila, int columna);

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Mapa.
         */
        ~Mapa();

        /*
         * Pre: recibe un nombre que existe.
         * Post: devuelve la cantidad de ese nombre en el mapa.
        */
        int devolver_cantidad_edificio(string nombre_edificio_nuevo, Jugador* jugador);

        /*
         * Pre: recibe un nombre que existe.
         * Post: devuelve la cantidad de ese nombre en el mapa.
         */
        int devolver_cantidad_edificio(string nombre_edificio_nuevo);

        /*
         * Pre:
         * Post:
         */
        void crear_lista_auxiliar_edificios(Lista_primitiva<int>* &cantidad_por_edificio);

        /*
         * Pre:
         * Post:
         */
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
         * Pre: nombre de material, fila y columna en índice de la matriz
         * Post: Agrega al casillero marcado el material pasado por parámetro
         */
        void agregar_material(string nombre, int fila, int columna);

        /*
         * Pre: -
         * Post: Agrega al casillero marcado el jugador pasado por parámetro
         */
        void agregar_jugador(Jugador* jugador);

        /*
         * Pre: -
         * Post: Mueve al jugador a una nueva posición (fila, columna) al jugador pasado por parámetro
         */
        void mover_jugador(Jugador* jugador, int fila , int columna);

        /*
         * Pre: -
         * Post: Mueve el tipo de terreno que se encuentra en la posición (fila, columna)
         */
        char devolver_tipo_terreno(int fila, int columna);

        /*
         * Pre: -
         * Post: Agrega un edificio en (fila, columna) y en la lista de edificios
         */
        void agregar_edificacion(string nombre, int fila, int columna, int duenio, Lista_edificios<Edificacion> *&edificios_jugador);

        /*
         * Pre: El nombre tiene que ser un edificio que exista
         * Post: Me creará un objeto Edifcacion de pediendo del nombre que le paso por parámetro
         */
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

        /*
         * Pre:
         * Post: Me muestra todo los edificios de del jugador
        */
        void mostrar_edificios_construidos2(Jugador* jugador_actual);

        /*
         * Pre: La fila y columna tiene que estar dentro del los parámetros del mapa
         * Post: Me devolverá TRUE si en la posición (fila, columna) hay un edificio y FALSE en caso contrario
        */
        bool hay_edificio(int fila, int columna);

        /*
         * Pre: -
         * Post: válida que una coordenada es de tipo construible
         */
        bool validar_tipo_construible(int fila, int columna);

        /*
         * Pre: -
         * Post: válida que una coordenada es de tipo transitable
         */
        bool validar_tipo_transitable(int fila, int columna);
        
        /*
         * Pre: el casillero tiene un edificio
         * Post: Elimina el edificio del casillero
         */
        void borrar_edificio(int fila, int columna);

        /*
         * Pre: -
         * Post: Guarda los materiales en casilleros transitables de manera aleatoria (con las probabilidades dadas por consigna)
        */
        void lluvia_recursos();

    private:
        /*
         * Pre: El archivo tiene que estar abierto y de formato correcto.
         * Post: Me va a agregar los datos se encuentra en el archivo en un determinado objeto dependiendo lo que lea del archivo.
         */
        void agregar_casillero(ifstream &archivo);

        /*
         * Pre: -
         * Post: Me crea una matriz del tipo casillero de forma dinámica.
         */
        void crear_matriz_casilleros();

        /*
         * Pre: El nombre tiene que ser de un material existente
         * Post: Me devuelve el material buscado.
         */
        Material* buscar_material(string nombre);

        /*
         * Pre: Recibe 2 números
         * Post: Devuelve un numero aleatorio entre esos 2 números
        */
        int numero_aleatorio(int desde, int hasta);
        
        /*
         * Pre: Recibe coordenadas dentro del dominio de la matriz
         * Post: Devuelve true si el casillero es transitable y está vacío, false de lo contrario
        */
        bool se_puede_generar_material(int fila, int columna);

        /*
         * Pre: Recibe un nombre de material y dos números mínimo y maximo
         * Post: Crea una cantidad n ( siendo min < n <max ) de ese material y los agrega al mapa
        */
        void agregar_materiales(string material, int minimo, int maximo);

        /*
         * Pre: -
         * Post: Me devuelve TRUE si el si por lo menos hay como mínimo 7 casilleros transitables no ocupados.
         */
        bool hay_lugar_minimo_material();

};

#endif //MAPA_H
