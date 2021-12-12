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

        //Pre:-
        //Post:devuelve el estado del la variable existeciaArchivo, tiene almacenada si el archivo se leyo correctamente.
        bool getArchivoValido();

        //Pre:
        //Post:
        int leer_archivos_materiales(Jugador* &jugador_1, Jugador* &jugador_2);

        Material* generar_material(string nombre,int cantidad);

        //Pre:
        //Post:
        int leer_archivo_ubicaciones(Mapa* &mapa, Diccionario<Edificacion>* &diccionario, Jugador* &jugador_1, Jugador* &jugador_2);

        //Pre:
        //Post:retorna el nombre del archivo.
        string devolverNombre();

        //Pre:
        //Post:
        int leer_archivos_edificios(Diccionario<Edificacion>*&diccionario,Mapa* mapa);

        //Pre:
        //Post:
        //  void leerArchivoMapa(string nombre);

        void escribir_archivos(Jugador *&jugador_1, Jugador *&jugador_2, Mapa* mapa);

        ~Archivo() ;

    private:

        //Pre:Debe recibir el nombre del Archivo.
        //Post:valida si existe el Archivo.
        void validarArchivo();

        int leer_ubicaciones_materiales(ifstream &documento,Mapa* &mapa, Jugador* &jugador);

        void escribir_archivo_ubicaciones(Mapa* mapa,Jugador *jugador_1, Jugador *jugador_2);

        void agregar_edificio(ifstream &documento,string nombre_edificio,Mapa* &mapa, Diccionario<Edificacion>*&diccionario, int duenio,Lista_edificios<Edificacion>*& edificios_jugador);

        void agregar_posicion_jugador(Mapa* &mapa, Jugador* &jugador);
        
        void leer_edificios_jugador_1(ifstream &documento, Mapa* &mapa, Diccionario<Edificacion>*&diccionario, Jugador* &jugador,Lista_edificios<Edificacion>*& edificios_jugador);

        void leer_edificios_jugador_2(ifstream &documento,Mapa* &mapa, Diccionario<Edificacion>*&diccionario,Lista_edificios<Edificacion>*& edificios_jugador);

        int arreglarCoordenadaX(string coordX);

        int arreglarCoordenadaY(string coordY);

        void escribir_archivo_materiales(Jugador *&jugador_1, Jugador *&jugador_2);

        void guardar_edificios_jugador(Lista_edificios<Edificacion>* edificio_jugador, fstream &documento);

        void guardar_materiales_en_mapa(Mapa *mapa, fstream &documento);

        Edificacion* buscar_edificacion(string nombre, int piedra, int madera, int metal, int max_cant_permitidos);

        Material* buscar_material(string nombre);
};

#endif //ARCHIVO_H
