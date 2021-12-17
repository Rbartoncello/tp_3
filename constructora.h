#ifndef TP_3_CONSTRUCTORA_H
#define TP_3_CONSTRUCTORA_H

#include "diccionario.h"
#include "mapa.h"
#include "constantes.h"

class Constructora{
    private:
        Mapa*   mapa;
        Diccionario<Edificacion>* dict_edificios;
        int fila_nueva;
        int columna_nueva;

        /*
         * PRE: Se necesita un nombre valido y un jugador
         * POST: Termina la construccion (crea el edificio)
         */
        void avanzar_con_construccion(string nombre_nuevo_edifcio, Jugador* jugador);

        /*
         * PRE: Se necesita un nombre valido y un jugador
         * POST: Devuelve un TRUE si este jugador puede seguir construyendo edificios de ese tipo
         */
        bool validar_maximo_edificio(string nombre_nuevo_edificio, Jugador* jugador);

        /*
         * PRE: Se necesita un nombre valido y un jugador
         * POST: Devuelve TRUE si el jugador tiene los materiales necesarios para el edificio
         */
        bool validar_materiales(string nombre_nuevo_edificio, Jugador* &jugador);

        /*
         * PRE: Requiere un jugador actual
         * POST: termina la demolicion del edificio
         */
        void avanzar_con_demolicion(Jugador* jugador);

        /*
         * PRE: -
         * POST: Devuelve TRUE si se elegió una coordenada diferente a -1 o si las coordenadas son validas
         */
        bool ingreso_de_coordenadas();

        /*
         * PRE: requiere dos ints como coordenadas 1 y 2
         * POST: devuelve TRUE si las coordenadas estan dentro de la matriz
         */
        bool validar_coords(int coord1, int coord2);

        /*
         * PRE: recibe un bool aviso
         * POST: -
         */
        void mostrar_aviso_terreno(bool aviso);

        /*
         * PRE: Se necesita un nombre valido y un jugador
         * POST: resta los materiales que se usaron en la construccion del inventario del jugador
         */
        void restar_materiales(string nombre_nuevo_edificio,Jugador* jugador);

        /*
         * PRE: Se necesita un nombre valido y un jugador
         * POST: Suma los materiales que se usaron en la construccion del inventario del jugador
         */
        void sumar_materiales(string nombre_nuevo_edificio,Jugador* jugador);

        /*
         * PRE: -
         * POST: Hace la ultima confirmación (devuelve TRUE si se puso "s")
         */
        bool validacion_final(string nombre_nuevo_edificio);

    public:
        /*
        constructor
        * PRE:
        * POST:
        */
        Constructora(Diccionario<Edificacion>* dict_edifcios, Mapa* mapa);
            /*
        * PRE:  Necesita el jugador actual
        * POST: Empieza la demolicion del edificio
        */
        void demoler_edificio(Jugador* jugador);
            /*
        * PRE:  Necesita el jugador actual
        * POST: Empieza la construccion del edificio
        */
        void construir_edificio(Jugador* jugador);



};

#endif //TP_3_CONSTRUCTORA_H
