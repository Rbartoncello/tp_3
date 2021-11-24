#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include "mapa.h"
#include "edificacion.h"

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
void imprimir_menu_juego();

/*
 * Pre: -
 * Post: Me muestra por pantalla la lista de objetos que parecen en el mapa.
 */
void imprimir_objetos_mapa();

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
 * Post: Imprimira un mensaje por pantalla
 */
void imprimir_mensaje_recolectando_recursos_producidos();

/*
 * Pre: -
 * Post: Devuelve el entero ingresado por pantalla.
 */
int pedir_opcion();

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

#endif