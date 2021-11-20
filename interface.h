#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>

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
void imprimir_menu_principal();

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

#endif