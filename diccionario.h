#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "nodo.h"
#include "mapa.h"
#include <iostream>
#include <iomanip>
#include "obelisco.h"
#include "mina.h"
#include "escuela.h"
#include "planta.h"
#include "constantes.h"
#include "fabrica.h"
#include "aserradero.h"
#include "interface.h"

using namespace std;

template<typename T>
class Diccionario {

    public:
        Nodo* rama;
    public:
        /*
         * Constructor
         * Pre: -.
         * Post: Me va a crear el objeto Diccionario con rama = NULL
         */
        Diccionario();

        /*
         * Pre: -.
         * Post: Me va a insertar el edificio en el Diccionario
         */
        void insertar(T* edificio);

        /*
         * Pre: edificio tiene que estar si o si dentro del diccionario.
         * Post: Me va a la receta del edificio
         */
        Receta* buscar(string edificio);

        /*
         * Pre: -
         * Post: Me va a listar en en orden el diccionario
         */
        void listar_en_orden(Mapa* mapa);

        /*
         * Pre: -
         * Post: Me va a guardar en pre orden el diccionario
         */
        void guardar_pre_orden();
        
        /*
         * Pre: -
         * Post: Devuelve rama
         */
        Nodo* devolver_rama();

        /*
         * Pre: -
         * Post: Devuelve TRUE si el edificio exite dentro del diccionario y FALSE en caso contrario
         */
        bool existe(string edificio);

        /*
         * Pre: -
         * Post: Me va a borrar todas ramas
         */
        void borrar_todo();

        /*
         * Destructor
         * Pre: -.
         * Post: Me va a destruir el objeto Diccionario
         */
        ~Diccionario();
    private:
        /*
         * Pre: -.
         * Post: Me va a insertar el edificio en el Diccionario
         */
        Nodo* insertar(Nodo* nodo, T* edificio);

        /*
         * Pre: -
         * Post: Me va a listar en en orden el diccionario
         */
        void listar_en_orden(Nodo * nodo, Mapa* mapa);

        /*
         * Pre: -
         * Post: Me va a guardar en pre orden el diccionario
         */
        void guardar_pre_orden(Nodo * nodo, ofstream &archivo);

        /*
         * Pre: edificio tiene que estar si o si dentro del diccionario.
         * Post: Me va a la receta del edificio
         */
        Nodo* buscar(Nodo* nodo, string edificio);

        /*
         * Pre: -
         * Post: Devuelve TRUE si el edificio exite dentro del diccionario y FALSE en caso contrario
         */
        bool existe(Nodo* nodo, string edificio);

        /*
         * Pre: -
         * Post: Me va a borrar rama por rama
         */
        void borrar_todo(Nodo* nodo);
};

template<typename T>
Diccionario<T>::Diccionario() {
    this->rama = NULL;
}

template<typename T>
void Diccionario<T>::insertar(T* edificio) {
    this->rama = insertar(this->rama, edificio);
}

template<typename T>
Nodo* Diccionario<T>::insertar(Nodo* nodo, T* edificio) {
    if (nodo == NULL)
        nodo = new Nodo(edificio);
    else if (edificio->devolver_nombre_edificio() > nodo->devolver_edificio()->devolver_nombre_edificio())
        nodo->modificar_derecha(insertar(nodo->devolver_derecha(), edificio), nodo);//esta linea como esta implementada no es muy clara
    else
        nodo->modificar_izquierda(insertar(nodo->devolver_izquierda(), edificio), nodo);
    return nodo;
}

template<typename T>
Receta* Diccionario<T>::buscar(string edificio) {
    return buscar(this->rama, edificio)->devolver_edificio()->devolver_receta();
}

template<typename T>
Nodo* Diccionario<T>::buscar(Nodo* nodo, string edificio) {
    if (nodo->devolver_edificio()->devolver_nombre_edificio() == edificio)
        return nodo;
    else if (edificio > nodo->devolver_edificio()->devolver_nombre_edificio())
        return buscar(nodo->devolver_derecha(), edificio);
    else 
        return buscar(nodo->devolver_izquierda(), edificio);
    
}

template<typename T>
void Diccionario<T>::listar_en_orden(Mapa* mapa) {
    encabezado_edificios_construidos();
    listar_en_orden(this->rama, mapa);
}

template<typename T>
void Diccionario<T>::listar_en_orden(Nodo * nodo, Mapa* mapa) {
    if (nodo != NULL){
        listar_en_orden(nodo->devolver_izquierda(), mapa);
        imprimir_lista_edificios_construidos(nodo->devolver_edificio(), mapa);
        listar_en_orden(nodo->devolver_derecha(), mapa);
    }
}

template<typename T>
void Diccionario<T>::guardar_pre_orden(Nodo * nodo, ofstream &documento) {
    if (nodo != NULL){
        documento << nodo->devolver_edificio()->devolver_nombre_edificio() << " " << nodo->devolver_edificio()->devolver_receta()->devoler_piedra() << " " << nodo->devolver_edificio()->devolver_receta()->devoler_madera() << " " << nodo->devolver_edificio()->devolver_receta()->devoler_metal() << " " << nodo->devolver_edificio()->devolver_maxima_cantidad_permitidos() << endl;
        
        guardar_pre_orden(nodo->devolver_izquierda(), documento);
        guardar_pre_orden(nodo->devolver_derecha(), documento);
    }
}

template<typename T>
void Diccionario<T>::guardar_pre_orden() {
    ofstream documento(PATH_EDIFICIO);
    guardar_pre_orden(this->rama, documento);
    documento.close();
}

template<typename T>
Nodo* Diccionario<T>::devolver_rama() {
    return this->rama;
}

template<typename T>
bool Diccionario<T>::existe(string edificio) {
    return existe(this->rama, edificio);
}

template<typename T>
bool Diccionario<T>::existe(Nodo* nodo, string edificio) {
    bool exite = false;
    if(nodo != NULL){
        if (nodo->devolver_edificio()->devolver_nombre_edificio() == edificio)
            exite = true;
        else if (edificio > nodo->devolver_edificio()->devolver_nombre_edificio())
            return existe(nodo->devolver_derecha(), edificio);
        else 
            return existe(nodo->devolver_izquierda(), edificio);
    }
    return exite;
}


template<typename T>
Diccionario<T>::~Diccionario() {
    borrar_todo();
}

template<typename T>
void Diccionario<T>::borrar_todo() {
    borrar_todo(this->rama);
}

template<typename T>
void Diccionario<T>::borrar_todo(Nodo* nodo) {
    if (nodo == NULL)
        return;

    borrar_todo(nodo->devolver_izquierda());
    borrar_todo(nodo->devolver_derecha());
    
    delete nodo;
}


#endif //DICCIONARIO_H
