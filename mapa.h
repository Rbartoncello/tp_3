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


        char devolver_tipo_terreno(int coord1, int coord2);

        void construirEdificio(int coordX, int coordY, string nuevo_edificio);
        
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
        bool validar_tipo_construible(int coord1, int coord2);

        
};

#endif //MAPA_H
