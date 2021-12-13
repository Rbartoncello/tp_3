#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "diccionario.h"
#include "constantes.h"
#include <fstream>
#include <iostream>
#include "emojis.h"
#include "jugador.h"
#include "mapa.h"
#include "edificacion.h"

class Archivo {
    public:

        //Pre:Debe recibir el nombre del Archivo.
        //Post: crea la Lista.
        Archivo();

        //Pre: Necesita un puntero a ambos jugadores
        //Post: Carga los materiales de los jugadores del archivo
        int leer_archivos_materiales(Jugador* &jugador_1, Jugador* &jugador_2);
        /*
         * PRE: NEcesita un nombre valido y una cantidad > 0
         * POST:  Crea un objeto del tipo material específico dependiendo de sus parametros
         */
        Material* generar_material(string nombre,int cantidad);

        //Pre:
        //Post:lee archivo ubicaciones
        int leer_archivo_ubicaciones(Mapa* &mapa, Diccionario<Edificacion>* &diccionario, Jugador* &jugador_1, Jugador* &jugador_2);

        //Pre:
        //Post:lee el archivo edificios
        int leer_archivos_edificios(Diccionario<Edificacion>*&diccionario,Mapa* mapa);

        //Pre:
        //Post:escribe el archivo ubicaciones y materiales
        void escribir_archivos(Jugador *&jugador_1, Jugador *&jugador_2, Mapa* mapa);

        //Pre:
        //Post:escribe el archivo ubicaciones vacio
        void escribir_archivos();

        ~Archivo() ;

    private:
        /*
         * PRE:
         * POST: Lee las ubicaciones de los materiales
         */
        int leer_ubicaciones_materiales(ifstream &documento,Mapa* &mapa, Jugador* &jugador);
        /*
         * PRE:
         * POST:  Guarda la info cambiada en el archivo ubicaciones
         */
        void escribir_archivo_ubicaciones(Mapa* mapa,Jugador *jugador_1, Jugador *jugador_2);
        /*
         * PRE: Necesita un diccionario de edificios valido y una lista de edificios valida
         * POST:  Crea edificios nuevos a medida que lee
         */
        void agregar_edificio(ifstream &documento,string nombre_edificio,Mapa* &mapa, Diccionario<Edificacion>*&diccionario, int duenio,Lista_edificios<Edificacion>*& edificios_jugador);
        /*
         * PRE:
         * POST:  Lee la pósicion de jugador en ubicaciones y lo agrega al mapa
         */
        void agregar_posicion_jugador(Mapa* &mapa, Jugador* &jugador);
        /*
        * PRE:
        * POST: Lee los edificos del primer jugador
        */
        void leer_edificios_jugador_1(ifstream &documento, Mapa* &mapa, Diccionario<Edificacion>*&diccionario, Jugador* &jugador,Lista_edificios<Edificacion>*& edificios_jugador);
        /*
        * PRE:
        * POST: Lee los edificos del segundo jugador
        */
        void leer_edificios_jugador_2(ifstream &documento,Mapa* &mapa, Diccionario<Edificacion>*&diccionario,Lista_edificios<Edificacion>*& edificios_jugador);
        /*
         * PRE: Requiere un string con un formato específico
         * POST:  Limpia la coordenada que se lee de ubicaciones.txt
         */
        int arreglar_coordenada_x(string coordX);
        /*
         * PRE: Requiere un string con un formato específico
         * POST:  Limpia la coordenada que se lee de ubicaciones.txt
         */
        int arreglar_coordenada_y(string coordY);
        /*
         * PRE:
         * POST:  Guarda la info de los materiales de los jugadores en materiales.txt
         */
        void escribir_archivo_materiales(Jugador *&jugador_1, Jugador *&jugador_2);
        /*
         * PRE: Necesita una lista de edificios bien construida
         * POST: Guarda los edificios de cada jugador en ubicaciones.txt
         */
        void guardar_edificios_jugador(Lista_edificios<Edificacion>* edificio_jugador, fstream &documento);
        /*
         * PRE: Necesita un mapa bien generado
         * POST:
         */
        void guardar_materiales_en_mapa(Mapa *mapa, fstream &documento);
};

#endif //ARCHIVO_H
