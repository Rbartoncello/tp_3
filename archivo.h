#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "diccionario.h"
#include "constantes.h"
#include <fstream>
#include <iostream>
#include "emojis.h"
#include "inventario.h"
#include "mapa.h"

class Archivo {
    public:

        //Pre:Debe recibir el nombre del Archivo.
        //Post: crea la Lista.
        Archivo();

        //Pre:-
        //Post:devuelve el estado del la variable existeciaArchivo, tiene almacenada si el archivo se leyo correctamente.
        bool getArchivoValido();

        Edificacion* elegir_edificios(string nombre,  int piedra,  int madera,  int metal, int max_permitidos);

        //Pre:
        //Post:
        int leer_archivos_materiales(Inventario* &inventario_jugador_1,Inventario* &inventario_jugador_2);


        //Pre:
        //Post:
        int leer_archivo_ubicaciones(Mapa* &mapa);

        //Pre:
        //Post:retorna el nombre del archivo.
        string devolverNombre();

        //Pre:
        //Post:
        int leer_archivos_edificios(Diccionario* &diccionario);

        //Pre:
        //Post:
        //  void leerArchivoMapa(string nombre);

        ~Archivo() ;

    private:

        //Pre:Debe recibir el nombre del Archivo.
        //Post:valida si existe el Archivo.
        void validarArchivo();

        void leer_ubicaciones_materiales(ifstream &documento,Mapa* &mapa);

        void agregar_edificio(ifstream &documento,string nombre_edificio,Mapa* &mapa,Diccionario* dict);

        void agregar_posicion_jugador(int coordX, int coordY,Mapa* &mapa);
        
        void leer_edificios_jugador1(ifstream &documento, string jugador,Mapa* &mapa,Diccionario* dict);

        void leer_edificios_jugador2(ifstream &documento,Mapa* &mapa,Diccionario* dict);

        int arreglarCoordenadaX(string coordX);

        int arreglarCoordenadaY(string coordY);

};

#endif //ARCHIVO_H
