#include <iostream>
#include "jugador.h"
#include "interface.h"

Jugador::Jugador(int numero){
    this->numero = numero;
    this -> energia = 0;
    this -> inventario = new Lista<Material>();
    //objetivo_primario = new Mas_alto_que_las_nubes();
}

Jugador::~Jugador(){
    delete this->inventario;
    //delete this->objetivos_secundarios
}

int Jugador::devolver_numero()
{
    return numero;
}

void Jugador::agregar_material(string nombre, int cantidad){
    //this->inventario->(nombre, cantidad);
}

void Jugador::pedir_nombre(){
    string nombre_ingresado;
    cout << "\tPor favor ingrese el nobre del jugador: ";
    cin >> nombre_ingresado;

    this -> nombre = nombre_ingresado;
}

void Jugador::restar_energia(int cantidad){
    this -> energia -= cantidad;
}

void Jugador::sumar_energia(int cantidad){
    this -> energia += cantidad;
}

void Jugador::recoger_recurso(Material* recurso){
    //this->inventario->sumar_material(recurso)    (me falta hacer el metodo en materiales en el que sume un material al array al recibir un Material*)
}

Lista<Material>*& Jugador::devolver_inventario(){
    return(inventario);
}

void Jugador::modificar_numero(int numero){
    this->numero = numero;
}

void Jugador::modificar_fila(int fila){
    this->fila = fila;
}

void Jugador::modificar_columna(int columna){
    this->columna = columna;
}

void Jugador::mostrar_inventario(){
    imprimir_materiales_jugador(inventario->retornar_primero(),inventario->devolver_cantidad_en_lista());
}