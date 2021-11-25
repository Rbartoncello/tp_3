#ifndef MAPA_H
#define MAPA_H
#include <fstream>
#include "casillero.h"

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
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Mapa.
         */
        ~Mapa();

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
        void agregar_material(Material* material, int fila, int columna);

        void agregar_jugador(int coordX, int coordY);


        char devolver_tipo_terreno(int coord1, int columna);

        void construirEdificio(int coordX, int coordY, string nuevo_edificio);

        /*
         * Pre: recibe un nombre.
         * Post: devuelve la cantidad de ese nombre en el mapa.
        */
        int cantidad_edificio_construido(string nombre);

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
         * Pre: -
         * Post: valida que una coordenada es de tipo construible
         */
        bool validar_tipo_construible(int fila, int columna);

        /*
         * Pre: -
         * Post: valida que una coordenada es de tipo transitable
         */
        bool validar_tipo_transitable(int fila, int columna);

        
};

#endif //MAPA_H
