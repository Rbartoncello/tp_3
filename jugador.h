#ifndef JUGADOR_H
#define JUGADOR_H
#include "materiales.h"
#include "lista.h"
#include "objetivos.h"
#include "constantes.h"
#include "lista_primitiva.h"
#include "obj_comprar_andypolis.h"
#include "obj_armado.h"
#include "obj_bombardero.h"
#include "obj_cansado.h"
#include "obj_constructor.h"
#include "obj_edad_piedra.h"
#include "obj_extremista.h"
#include "lista_edificios.h"
#include "edificacion.h"
#include "obj_minero.h"
#include "obj_energetico.h"
#include "obj_letrado.h"
#include "obj_obelisco.h"

class Jugador {
     private:
          string nombre;
          string emoji;
          int energia, numero, fila, columna, objetivos_completados;
          Lista<Material> *inventario;
          Lista<Material> *recursos_acumulados;
          Lista<Objetivos> *objetivos_secundarios;
          Lista_edificios<Edificacion>* edificios_jugador;
          int energia_acumulada;
          Objetivos* objetivo_principal;

     public:
          /*
           * Pre: -.
           * Post: Me va a crear el Jugador vacio
           */
          Jugador(int numero, string emoji);

          /*
           * Pre: Necesita un punto de inicio y uno de final
           * Post: Va a generar un numero random.
           */
          int numero_aleatorio(int desde, int hasta);

          /*
           * Pre: 
           * Post: Devuelve el numero asignado al jugador.
           */
          int devolver_numero();

          /*
           * Pre: 
           * Post: muestra por pantalla los objetivos del jugador
           */
          void mostrar_objetivos();

          /*
           * Pre: necesita un valor a sumar y el nombre del objetivo
           * Post: si el objetivo es del usuario suma
           */
          void sumar_a_objetivo(int cantidad, string nombre_objetivo);

          /*
           * Pre: -
           * Post: Me devuelve la energia del jugador
           */
          int devolver_energia();
          
          /*
           * Destructor:
           * Pre: -.
           * Post: Me va a destruir el arreglo de objetivos
           */
          ~Jugador();

          /*
           * Pre: -.
           * Post: Me va a definir como nombre el string ingresado por input (con ese nombre se va a  referir al jugador por el resto del juego)
           */    
          void pedir_nombre(); 

          /*
           * Pre:
           * Post: Agrega a la lista de inventario un nuevo material
           */
          void agregar_inventario(Material *elemento);
            /*
        * PRE:
        * POST:
        */
          Material* generar_material(string nombre);
            /*
        * PRE:
        * POST:
        */
          Lista_edificios<Edificacion>*& devolver_mis_edificios();

          /*
           * Pre: cantidad tiene que ser mayor a 0
           * Post: Me restara el cantidad del material del inventario.
           */
          void restar_material(int cantidad, string material);

          /*
           * Pre: Recibe un nombre de un material que exita.
           * Post: Ingresa el objeto en un vector dinámico.
           */
          void aumentar_material(Material *material);

          /*
           * Pre: cantidad tiene que ser mayor a 0
           * Post: Me restara el cantidad de energia.
           */
          void restar_energia(int cantidad);

          /*
           * Pre: cantidad tiene que ser mayor a 0
           * Post: Me sumara el cantidad de energia.
           */
          void sumar_energia(int cantidad);

          /*
           * Pre:
           * Post: Me suma los materiales recolectados en el inventario
           */
          void recoger_recurso();
          
          /*
           * Pre: -
           * Post: Me devuelve el inventario del jugador
           */
          Lista<Material> *&devolver_inventario();

          /*
           * Pre: -
           * Post: Me modificara el numero del jugador
           */
          void modificar_numero(int numero);

          /*
           * Pre: Fila tiene que estar dentro del mapa
           * Post: Me modifca la fila del jugador
           */
          void modificar_fila(int fila);

          /*
           * Pre: Columna tiene que estar dentro del mapa
           * Post: Me modifca la columna del jugador
           */
          void modificar_columna(int columna);

          /*
           * Pre: -
           * Post: Me muestra lista por pantalla el inventario.
           */
          void mostrar_inventario();

          /*
           * Pre: -
           * Post: Me devuelve la fila del jugador
           */
          int devolver_fila();

          /*
           * Pre: -
           * Post: Me devuelve la columna del jugador
           */
          int devolver_columna();

          /*
           * Pre: -
           * Post: Me devuelve el emoji del jugador
           */
          string devolver_emoji();

          /*
           * Pre: -
           * Post: Me pone en 0 todos los materiales del inventario del jugador
           */
          void vaciar_inventario();

          /*
           * Pre: -
           * Post: Realizara el procedimiento de compra de bombas.
           */
          void comprar_bombas();

          /*
           * Pre: -
           * Post: Me va a devovler TRUE si se completarios los tres objetivos secundarios o FALSE en caso contrario.
           */
          bool validar_objetivos();

          /*
           * Pre: 
           * Post:termina con 3 objetivos en la lista objetivos secundarios
           */
          void generar_objetivos(int cantidad_escuelas);

          /*
           * Pre: 
           * Post: Me ira acumulando los recursos de los edificios que encuentre en el mapa.
           */
          void acumular_recursos(string material, int cantidad);

          /*
           * Pre: 
           * Post: Me ira acumulando los recursos de los edificios que encuentre en el mapa.
           */
          void borrar_edificio(int fila, int columna);
     private:

          /*
           * Pre: Necesita una lista de objetivos de tipo string
           * Post: Agrega el nombre de los objetivos a esta lista
           */
         void crear_lista(Lista_primitiva<string> *&objetivos);

          /*
           * Pre: Necesita el nombre del objetivo a crear
           * Post: Agrega a la lista de objetivos secundarios un nuevo objetivo
           */
          void agregar_objetivo(string nombre_objetivo, int cantidad_escuelas);


          /*
           * Pre:
           * Post: Me contarar la cantidad de objetivos completados y los devolvera.
           */
          int contar_objetivos_completados(int contador);

          /*
           * Pre: costo tiene que ser mayor a 0
           * Post: Me devuelve TRUE si costo >= andycoins y FALSE en caso contrario.
           */
          bool andycoins_sufuciente(int costo);

          /*
           * Pre: Cantidad tiene que ser mayor a 0
           * Post: Comprar la cantidad de bombas ingresadas.
           */
          void comprar_bombas(int cantidad);

          /*
           * Pre: -
           * Post: Me devuelve la energia_acumulada del jugador
           */
          int devolver_energia_acumulada();

          /*
           * Pre:
           * Post: Me pondra en 0 el cantidad de energia_acumulada.
           */
          void vaciar_energia_acumulada();

          /*
           * Pre: cantidad tiene que ser mayor a 0
           * Post: Me sumara el cantidad de energia_acumulada.
           */
          void sumar_energia_acumulada(int cantidad);
          
};

#endif //JUGADOR_H