#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include "mapa.h"
#include "edificacion.h"
#include "material.h"
#include "nodo_lista.h"
#include "jugador.h"

using namespace std;
/*  
* Pre: -
* Post: Imprimira por pantalla el nombre del programa.
*/
void imprimir_mensaje_bienvenida();

/*
 * Pre: -
 * Post: Imprime por pantalla el manu principal.
*/
void imprimir_menu_nueva_partida();

/*
 * Pre: -
 * Post: Imprime por pantalla el manu principal.
*/
void imprimir_menu_juego(Mapa* mapa, Jugador* jugador_acutal);

/*
 * Pre: -
 * Post: Me muestra por pantalla la lista de objetos que parecen en el mapa.
 */
void imprimir_objetos_mapa();

/*
 * Pre: -
 * Post:Imprime el inventario del jugador
 */
void imprimir_materiales_jugador(Nodo_lista<Material>*& primero, int cantidad_en_lista);

/*
* Pre: -
* Post: Imprimira por pantalla solamente "Error!!!".
*/
void imprimir_mensaje_error();

/*
* Pre: -
* Post: Imprimira por pantalla un mensaje con el tiempo en segundos que el usuario tiene que esperar.
*/
void imprimir_mensaje_esperar(int tiempo);


/*
 * Pre: -
 * Post: Imprime por pantalla el encabezado de los edificios del jugador
 */
void encabezado_edificios_jugador();

/*
 * Pre: -
 * Post: Imprime por pantalla la cantidad por edificio del jugador
 */
void imprimir_cantidad_edificios_jugador(Lista_primitiva<string> *nombre_edificios,Lista_primitiva<int> *cantidad_por_edificio);

/*
 * Pre: -
 * Post: Imprime por pantalla los edificios del jugador, uno a uno.
 */
void imprimir_edificios_jugador(Lista_edificios<Edificacion>* edificios_jugador);

/*
 * Pre: -
 * Post: Me imprimira por pantalla la action_realizada.
 */
void imprimir_procesamiento_accion(string action_realizada, string nombre_edificio, string emoji_edificio);

/*
 * Pre: -
 * Post: Imprime por pantalla que se guardo correctamente.
 */ 
void imprimir_mensaje_guardado();

/*
 * Pre: -
 * Post: Devuelve el entero ingresado por pantalla.
 */
int pedir_opcion(int fila, int columna);

/*
 * Pre: -
 * Post: Imprime por pantalla el error.
 */
void imprimir_mensaje_error_ingreso();

/*
 * Pre: -
 * Post: Pausa la pantalla con un cin.
 */
void imprimir_mensaje_enter_continuar();

/*
 * Pre: -
 * Post: Imprime por pantalla que ingrese un edificio.
 */
void imprimir_mensaje_ingresar_edificio();

/*
 * Pre: -
 * Post: Imprime por pantalla que hubo un error y que vuelva a ingresar un edificio.
 */
void imprimir_mensaje_error_ingresar_edificio();

/*
 * Pre: -
 * Post: Imprime por pantalla que hubo un error y que vuelva a ingresar EDICIFIO_OBELISCO.
 */
void imprimir_mensaje_error_ingresar_edificio_obelisco();

/*
 * Pre: -
 * Post: Imprime por pantalla la receta del edificio.
 */
void imprimir_mensaje_receta_edificio(string edificio, string material, int cantidad);

/*
 * Pre: -
 * Post: Imprime por pantalla que el usuario ingrese si o no.
 */
void imprimir_mensaje_afirmativo_negativo();

/*
 * Pre: -
 * Post: Imprime por pantalla que el usuario ingrese la cantidad de receta a modificar.
 */
void imprimir_mensaje_receta_modificar();

/*
 * Pre: -
 * Post: Imprime por pantalla que el encabezado de listar edificios.
 */
void encabezado_edificios_construidos();

/*
 * Pre: -
 * Post: Imprime por pantalla listar edificios.
 */
void imprimir_lista_edificios_construidos(Edificacion* edificio, Mapa* mapa);

/*
 * Pre: -
 * Post: Imprime por pantalla los materiales del jugador;
 */
void imprimir_lista_materiales_jugador(Material* material);

/*
 * Pre: -
 * Post: Imprime por pantalla el encabezado de los materiales del jugador
 */
void encabezado_materiale_jugador();

/*
 * Pre: -
 * Post: Imprime por pantalla que ingrese el numero de jugador
 */
void imprimir_mensaje_ingrese_jugador();

/*
 * Pre: -
 * Post: Imprime por pantalla que ingrese la fila de jugador
 */
void imprimir_mensaje_ingrese_fila_jugador();

/*
 * Pre: -
 * Post: Imprime por pantalla que ingrese la columna de jugador
 */
void imprimir_mensaje_ingrese_columna_jugador();

/*
 * Pre: -
 * Post: Me muestra por pantalla un cuadro del jugador actual.
 */
void imprimir_cuadro_jugador(Jugador* &jugador_actual);

/*
 * Pre: -
 * Post: Me muestra por pantalla un mensaje que no cuanta con energia necesaria.
 */
void imprimir_mensaje_no_energia_sufuciente(int energia);

/*
 * Pre: -
 * Post: Me muestra por pantalla un mensaje que no es posible ir a esa posicion.
 */
void imprimir_mensaje_posicion_no_permitida();

/*
 * Pre: -
 * Post: Me muestra por pantalla un mensaje que cambio de turno.
 */
void imprimir_mensaje_finalizacion_turno_automatico(Jugador* &jugador_actual);

/*
 * Pre: -
 * Post: Me muestra por pantalla un mensaje que el casillero esta ocupado.
 */
void imprimir_mensaje_casillero_ocupado();

/*
 * Pre: -
 * Post: Me muestra por pantalla la tienda de bombas.
 */
void imprimir_tienda_bombas();

/*
 * Pre: -
 * Post: Me muestra por pantalla un mensaje que no cuenta con los andycoins necesarios.
 */
void imprimir_mensaje_sin_andycoins_suficientes(int costo);

/*
 * Pre: -
 * Post: Me muestra por pantalla un mensaje la cantidad de bombas compradas y andycoins actual.
 */
void imprimir_mensaje_bombas_compradas(Lista<Material>* &inventario, int cantidad);

/*
 * Pre: -
 * Post: Me muestra por pantalla el encabezado de los objetivos secundarios.
 */
void encabezado_objetivos_secuncarios();

/*
 * Pre: -
 * Post: Me muestra por pantalla el mensaje que se recolecto recurso con exito.
 */
void imprimir_mensaje_recolectando_recursos_producidos();

/*
 * Pre: -
 * Post: MUestra un mensaje por pantalla de fin del juego
 */
void imprimir_juego_ganado(int ganador);


#endif