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
         * POST:
         */
        bool validar_materiales(string nombre_nuevo_edificio, Jugador* &jugador);

        /*
         * PRE:
         * POST:
         */
        void avanzar_con_demolicion(Jugador* jugador);

        /*
         * PRE:
         * POST:
         */
        bool ingreso_de_coordenadas();

        /*
         * PRE:
         * POST:
         */
        bool validar_coords(int coord1, int coord2);

        /*
         * PRE:
         * POST:
         */
        void mostrar_aviso_terreno(bool aviso);

        /*
         * PRE:
         * POST:
         */
        void restar_materiales(string nombre_nuevo_edificio,Jugador* jugador);

        /*
         * PRE:
         * POST:
         */
        bool validacion_final();

    public:
        /*
        * PRE:
        * POST:
        */
        Constructora(Diccionario<Edificacion>* dict_edifcios, Mapa* mapa);
            /*
        * PRE:
        * POST:
        */
        void demoler_edificio(Jugador* jugador);
            /*
        * PRE:
        * POST:
        */
        void construir_edificio(Jugador* jugador);



};

#endif //TP_3_CONSTRUCTORA_H
