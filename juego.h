#ifndef JUEGO_H
#define JUEGO_H

#include "edificios.h"
#include "mapa.h"
#include "emojis.h"
#include "archivo.h"

class Juego{
    private:
        Mapa* mapa;
        Archivo* lector_archivos;
        Inventario* inventario_p1, *inventario_p2; //CAMBIARLO A JUGADOR1 JUGADOR2 (el inventario va dentro de ellos)

    public:
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el Juego vacio
         */
        Juego();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Mapa.
         */
        ~Juego();

        /*
         * Pre: -.
         * Post: Devolvera TRUE si todos los archivos fueron abiertos correctamente.
         */
        int cargar();

        /*
        * Pre: -
        * Post: Mostra un menu con las opciones de nueva_partida y cada opcion con si respectiva funcionalidad 
        */
        void nueva_partida();

        string buscar_tipo_emoji(string nombre_edificio);
        
        void mostrar();

    private:
        /*
         * Pre: -
         * Post: Repite el input hasta que se cumpla la condicion pedida (MAX_OPCION_NUEVA_PARTIDA y MIN_OPCION_NUEVA_PARTIDA).
        */
        void validar_opcion_ingresada(int &opcion_elegida);

        /*        
         * Pre: -
         * Post: Devuelve TRUE si MIN_OPCION_NUEVA_PARTIDA <= opcion <= MAX_OPCION_NUEVA_PARTIDA y FALSE en caso contrario.
        */
        bool es_opcion_valida(int opcion);

        /*
         * Pre: -
         * Post: Realiza la opcion pedida
        */
        void procesar_opcion_nueva_partida(int opcion);
};

#endif //JUEGO_H
