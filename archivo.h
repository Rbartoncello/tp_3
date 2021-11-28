#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "diccionario.h"
#include "constantes.h"
#include <fstream>
#include <iostream>
#include "emojis.h"
#include "inventario.h"
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
        int leer_archivos_materiales(Diccionario<Material>* &inventario_jugador_1, Diccionario<Material>* &inventario_jugador_2,Mapa* &mapa);


        //Pre:
        //Post:
        int leer_archivo_ubicaciones(Mapa* &mapa, Diccionario<Edificacion>* &diccionario);

        //Pre:
        //Post:retorna el nombre del archivo.
        string devolverNombre();

        //Pre:
        //Post:
        int leer_archivos_edificios(Diccionario<Edificacion>*&diccionario);

        //Pre:
        //Post:
        //  void leerArchivoMapa(string nombre);

        ~Archivo() ;

    private:

        //Pre:Debe recibir el nombre del Archivo.
        //Post:valida si existe el Archivo.
        void validarArchivo();

        int leer_ubicaciones_materiales(ifstream &documento,Mapa* &mapa);

        void agregar_edificio(ifstream &documento,string nombre_edificio,Mapa* &mapa, Diccionario<Edificacion>*&diccionario);

        void agregar_posicion_jugador(int coordX, int coordY,Mapa* &mapa);
        
        void leer_edificios_jugador_1(ifstream &documento, string jugador,Mapa* &mapa, Diccionario<Edificacion>*&diccionario);

        void leer_edificios_jugador_2(ifstream &documento,Mapa* &mapa, Diccionario<Edificacion>*&diccionario);

        int arreglarCoordenadaX(string coordX);

        int arreglarCoordenadaY(string coordY);

        Edificacion* buscar_edificacion(string nombre, int piedra, int madera, int metal, int max_cant_permitidos);

        Material* buscar_material(string nombre);
};

#endif //ARCHIVO_H
