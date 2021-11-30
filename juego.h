#ifndef JUEGO_H
#define JUEGO_H

#include "edificios.h"
#include "mapa.h"
#include "emojis.h"
#include "archivo.h"
#include "diccionario.h"
#include "jugador.h"
#include "Grafo.h"

class Juego{
    private:
        Mapa* mapa;
        Grafo* grafo;
        Archivo* lector_archivos;
        Diccionario<Edificacion>* diccionario;
        Jugador* jugador_1;
        Jugador* jugador_2;
        Jugador* jugador_actual;
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

        void cargar_grafo();

    private:

        

        /*
         * Pre: -
         * Post: Realiza la opcion pedida
        */
        void procesar_opcion_nueva_partida(int opcion);

        /*
         * Pre: -
         * Post: Repite el input hasta que se cumpla la condicion pedida (max y min).
        */
        void validar_opcion_ingresada(int &opcion_elegida, int max, int min);

        /*        
         * Pre: -
         * Post: Devuelve TRUE si min <= opcion <= max y FALSE en caso contrario.
        */
        bool es_opcion_valida(int opcion, int max, int min);

        /*
         * Pre: -
         * Post: Realiza la opcion pedida
        */
        void procesar_opcion_partida_empezada(int opcion);

        /*
         * Pre: Diccionario ya tiene que estar creado y con todos los edificios cargados
         * Post: Me modificara la reseta del edificio ingresado
        */
        void modificar_edificio(Diccionario<Edificacion>*&edificios_disponibles);

        /*
         * Pre: -
         * Post: Me modificara la reseta.
        */
        void modificar_receta(Diccionario<Edificacion>*&edificios_disponibles, string nombre_edificio, string material);

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

        /*
         * Pre: -
         * Post: Comienza la partida
         */
        void comenzar_partida();

        /*
         * Pre: -
         * Post: Ingresara el primer jugador
         */
        void ingresar_primer_jugador();

        /*
         * Pre: -
         * Post: Me posicionara el jugador en el mapa
         */
        void posicionar_jugador_mapa(Jugador* &jugador);

        /*
         * Pre: Recibe 2 numeros
         * Post: Devuelve un numero aleatorio entre esos 2 numeros
        */
        int numero_aleatorio(int desde, int hasta);

        Jugador* devolver_jugador_turno();

        void mostrar_inventario(Jugador* jugador_turno);

        void moverse_coordenada();

        void cargar_costos();

        void cargar_costos_filas();
        void cargar_costos_columnas();

        void agregar_energia_comienza_partida();

        void modificar_costo_casillero(Casillero* &casillero);
};

#endif //JUEGO_H
