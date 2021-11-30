/*#include <iostream>
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

Diccionario::Diccionario() {
    this->rama = NULL;
}

void Diccionario::insertar(Edificacion* edificio) {
    this->rama = insertar(this->rama, edificio);
}

Nodo* Diccionario::insertar(Nodo* nodo, Edificacion* edificio) {
    if (nodo == NULL)
        nodo = new Nodo(edificio);
    else if (edificio->devolver_nombre_edificio() > nodo->devolver_edificio()->devolver_nombre_edificio())
        nodo->modificar_derecha(insertar(nodo->devolver_derecha(), edificio), nodo);//esta linea como esta implementada no es muy clara
    else
        nodo->modificar_izquierda(insertar(nodo->devolver_izquierda(), edificio), nodo);
    return nodo;
}

Receta* Diccionario::buscar(string edificio) {
    return buscar(this->rama, edificio)->devolver_edificio()->devolver_receta();
}

Nodo* Diccionario::buscar(Nodo* nodo, string edificio) {
    if (nodo->devolver_edificio()->devolver_nombre_edificio() == edificio)
        return nodo;
    else if (edificio > nodo->devolver_edificio()->devolver_nombre_edificio())
        return buscar(nodo->devolver_derecha(), edificio);
    else 
        return buscar(nodo->devolver_izquierda(), edificio);
    
}

void Diccionario::listar_en_orden(Mapa* mapa) {
    encabezado_edificios_construidos();
    listar_en_orden(this->rama, mapa);
}

void Diccionario::listar_en_orden(Nodo * nodo, Mapa* mapa) {
    if (nodo != NULL){
        listar_en_orden(nodo->devolver_izquierda(), mapa);
        imprimir_lista_edificios_construidos(nodo->devolver_edificio(), mapa);
        listar_en_orden(nodo->devolver_derecha(), mapa);
    }
}

void Diccionario::guardar_pre_orden(Nodo * nodo, ofstream &documento) {
    if (nodo != NULL){
        documento << nodo->devolver_edificio()->devolver_nombre_edificio() << " " << nodo->devolver_edificio()->devolver_receta()->devoler_piedra() << " " << nodo->devolver_edificio()->devolver_receta()->devoler_madera() << " " << nodo->devolver_edificio()->devolver_receta()->devoler_metal() << " " << nodo->devolver_edificio()->devolver_maxima_cantidad_permitidos() << endl;
        
        guardar_pre_orden(nodo->devolver_izquierda(), documento);
        guardar_pre_orden(nodo->devolver_derecha(), documento);
    }
}

void Diccionario::guardar_pre_orden() {
    ofstream documento(PATH_EDIFICIO);
    guardar_pre_orden(this->rama, documento);
    documento.close();
}

Nodo* Diccionario::devolver_rama() {
    return this->rama;
}

bool Diccionario::existe(string edificio) {
    return existe(this->rama, edificio);
}

bool Diccionario::existe(Nodo* nodo, string edificio) {
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


Diccionario::~Diccionario() {
    borrar_todo();
}

void Diccionario::borrar_todo() {
    borrar_todo(this->rama);
}

void Diccionario::borrar_todo(Nodo* nodo) {
    if (nodo == NULL)
        return;

    borrar_todo(nodo->devolver_izquierda());
    borrar_todo(nodo->devolver_derecha());
    
    delete nodo;
}
*/









