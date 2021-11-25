#ifndef JUEGO_H
#define JUEGO_H

#include "edificios.h"
#include "mapa.h"
#include "emojis.h"
#include "archivo.h"
#include "diccionario.h"


class Juego{
    private:
        Mapa* mapa;
        Archivo* lector_archivos;
        Inventario* inventario_p1, *inventario_p2; //CAMBIARLO A JUGADOR1 JUGADOR2 (el inventario va dentro de ellos)
        Diccionario* diccionario;

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
         * Pre: -.
         * Post: Devolvera TRUE si exite o ERROR en el caso que no exita o este vacio
         */
        int archivo_ubicaciones();

        /*
        * Pre: -
        * Post: Mostra un menu con las opciones de nueva_partida y cada opcion con si respectiva funcionalidad 
        */
        void nueva_partida();

        /*
        * Pre: -
        * Post: Mostra un menu con las opciones de partida_empezada y cada opcion con si respectiva funcionalidad 
        */
        void partida_empezada();
        
        void mostrar();

    private:
        /*
         * Pre: -
         * Post: Repite el input hasta que se cumpla la condicion pedida (MAX_OPCION_NUEVA_PARTIDA y MIN_OPCION_NUEVA_PARTIDA).
        */
        void validar_opcion_ingresada_nueva_partida(int &opcion_elegida);

        /*        
         * Pre: -
         * Post: Devuelve TRUE si MIN_OPCION_NUEVA_PARTIDA <= opcion <= MAX_OPCION_NUEVA_PARTIDA y FALSE en caso contrario.
        */
        bool es_opcion_valida_nueva_partida(int opcion);

        /*
         * Pre: -
         * Post: Realiza la opcion pedida
        */
        void procesar_opcion_nueva_partida(int opcion);

        /*
         * Pre: -
         * Post: Repite el input hasta que se cumpla la condicion pedida (MAX_OPCION_JUEGO y MIN_OPCION_JUEGO).
        */
        void validar_opcion_ingresada_partida_empezada(int &opcion_elegida);

        /*        
         * Pre: -
         * Post: Devuelve TRUE si MIN_OPCION_JUEGO <= opcion <= MAX_OPCION_JUEGO y FALSE en caso contrario.
        */
        bool es_opcion_valida_partida_empezada(int opcion);

        /*
         * Pre: -
         * Post: Realiza la opcion pedida
        */
        void procesar_opcion_partida_empezada(int opcion);

        /*
         * Pre: Diccionario ya tiene que estar creado y con todos los edificios cargados
         * Post: Me modificara la reseta del edificio ingresado
        */
        void modificar_edificio(Diccionario* diccionario);

        /*
         * Pre: -
         * Post: Me modificara la reseta.
        */
        void modificar_receta(Diccionario* diccionario, string nombre_edificio, string material);

        /*
         * Pre: -
         * Post: Me devuelve TRUE si el ingreso es AFIRMATIVO o NEGATIVO y FLASE en caso contrario.
        */
        bool ingreso_afirmativo_negativo_valido(int ingreso);

        /*
         * Pre: -
         * Post: Me devuelve TRUE si  MIN_RECETA_MODIFICAR <= ingreso <= MAX_RECETA_MODIFICAR y FLASE en caso contrario.
        */
        bool cantidad_valida(int ingreso);

        /*
         * Pre: -
         * Post: Devuelve el entero ingresado por pantalla..
        */
        int pedir_fila();

        /*
         * Pre: -
         * Post: Devuelve el entero ingresado por pantalla..
        */
        int pedir_columna();

        /*
         * Pre: -
         * Post: repite el input hasta que se cumpla la condicion pedida (0 y n_fila).
        */
        void validar_fila(int &fila);

        /*
         * Pre: -
         * Post: repite el input hasta que se cumpla la condicion pedida (0 y n_columna).
        */
        void validar_columna(int &columna);

        /*
         * Pre: -
         * Post: Imprime por pantalla el error.
        */
        void imprimir_mensaje_error_ingreso();

        /*
         * Pre: -
         * Post: Pide al usuario una ubicacion via input y le infroma sobre el contenido del mismo.
        */
        void mostrar_coordenada();
};

#endif //JUEGO_H
