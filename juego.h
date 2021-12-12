#ifndef JUEGO_H
#define JUEGO_H
#include "edificios.h"
#include "mapa.h"
#include "emojis.h"
#include "archivo.h"
#include "diccionario.h"
#include "jugador.h"
#include "Grafo.h"
#include "constructora.h"

class Juego
{
private:
    Mapa *mapa;
    Grafo *grafo;
    Archivo *lector_archivos;
    Diccionario<Edificacion> *diccionario;
    Jugador *jugador_1;
    Jugador *jugador_2;
    Jugador *jugador_actual;
    Constructora *constructora;

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
    void modificar_edificio(Diccionario<Edificacion> *&edificios_disponibles);

    /*
         * Pre: -
         * Post: Me modificara la reseta.
        */
    void modificar_receta(Diccionario<Edificacion> *&edificios_disponibles, string nombre_edificio, string material);

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
    void posicionar_jugador_mapa(Jugador *&jugador);

    /*
         * Pre: Recibe 2 numeros
         * Post: Devuelve un numero aleatorio entre esos 2 numeros
        */
    int numero_aleatorio(int desde, int hasta);

    /*
         * Pre: -
         * Post: Devuelve devuelve el turno del jugador actual
         */
    Jugador *devolver_jugador_turno();

    /*
         * Pre: -
         * Post: Me muestra el inventario del jugador_actual
         */
    void mostrar_inventario(Jugador *jugador_turno);

    /*
         * Pre: -
         * Post: El jugador_actual se va a mover a una codenada ingresado por pantalla
         */
    void moverse_coordenada();

    /*
         * Pre: -
         * Post: Se van a cargar los costos del mapa
         */
    void cargar_costos();

    /*
         * Pre: -
         * Post: Se van a cargar los costos del mapa
         */
    void cargar_costos_filas();

    /*
         * Pre: -
         * Post: Se van a cargar los costos del mapa
         */
    void cargar_costos_columnas();

    /*
         * Pre: -
         * Post: Me agrega ENERGIA_COMIENZO_PARTIDA a cada jugador
         */
    void agregar_energia_comienza_partida();

    /*
         * Pre: -
         * Post: Me modifica el costo del casillero
         */
    void modificar_costo_casillero(Casillero *&casillero);

    /*
         * Pre: -
         * Post: Le preguntara a usuario que si decea moverse a otra coordenada
         */
    void sin_energia_desplazarse(int costo);

    /*
         * Pre: -
         * Post: Pone en 0 todo los materieles del inventario
         */
    void vaciar_inventario();

    /*
        * Pre: -
        * Post: Me creara el grafo 
        */
    void cargar_grafo();

    /*
         * Pre: -
         * Post: Repara un edificio por input
         */
    void reparar_edificio();

    /*
         * Pre: -
         * Post: Ataca un edificio por input
         */
    void atacar_edificio();

    /*
         * Pre: -
         * Post: Acumula recurso producidos
         */
    void acumular_recursos();

    /*
         * Pre: -
         * Post: valida si se puede reparar una coordenada
         */
    bool validar_reparar_edificio(int fila, int columna);

    /*
         * Pre: -
         * Post: restablece todos los atributos fue_atacado a false de los edificios
         */
     void restablecer_fue_atacado();

     void restar_atacar();

     bool validar_atacar_edificio(int fila, int columna);

     bool validar_bombas_energia();


    /*
         * Pre: -
         * Post: genera el jugador primero en turno
         */
    void jugador_inicial();

    /*
           * Pre: 
           * Post:valida si hay ganador
           */
    int validar_ganador(int opcion_elegida);

    /*
           * Pre: 
           * Post:pide la opcion y muestra el menu.
           */
    int mostrar_opciones();
};

#endif //JUEGO_H
