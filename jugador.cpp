#include <iostream>
#include "jugador.h"
#include "interface.h"

Jugador::Jugador(int numero, string emoji){
    this->numero = numero;
    this->emoji = emoji;
    this -> energia = 0;
    this -> inventario = new Lista<Material>();
    //objetivo_primario = new Mas_alto_que_las_nubes();
}

Jugador::~Jugador(){
    delete this->inventario;
    //delete this->objetivos_secundarios
}

void Jugador::aumentar_material(Material* material){
    inventario->obtener_direccion_nodo(inventario->obtener_posicion(material->devolver_nombre()))->devolver_dato()->aumentar_cantidad(material->devolver_cantidad());
}

void Jugador::vaciar_inventario(){

    Nodo_lista<Material>* auxiliar = inventario->retornar_primero();

    for (int i = 0; i < inventario->devolver_cantidad_en_lista(); i++){
        auxiliar->devolver_dato()->modificar_cantidad(0);
        auxiliar = auxiliar->direccion_siguiente();
    }
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

int Jugador::devolver_fila(){
    return fila;
}

int Jugador::devolver_columna(){
    return columna;
}

int Jugador::devolver_numero(){
    return numero;
}

int Jugador::devolver_energia(){
    return energia;
}

string Jugador::devolver_emoji(){
    return emoji;
}

void Jugador::comprar_bombas(){
    if (devolver_energia() >= ENERGIA_COMPRAR_BOMBAS){
        imprimir_tienda_bombas();
        int cantidad;
        cin >> cantidad;
        while (cantidad <= 0){
            imprimir_mensaje_error_ingreso();
            cin >> cantidad;
        }
        if (andycoins_sufuciente(cantidad * COSTO_POR_BOMBA)){
            comprar_bombas(cantidad);
            restar_energia(ENERGIA_COMPRAR_BOMBAS);
            imprimir_mensaje_bombas_compradas(inventario, cantidad);
        }
        else 
            imprimir_mensaje_sin_andycoins_suficientes(cantidad * COSTO_POR_BOMBA);

    } else
        imprimir_mensaje_no_energia_sufuciente(ENERGIA_COMPRAR_BOMBAS);
}

bool Jugador::andycoins_sufuciente(int costo){
    int posicion = devolver_inventario()->obtener_posicion(ANDYCOINS);

    int cantidad = devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->devolver_cantidad();

    return ( costo <= cantidad );
}

void Jugador::comprar_bombas(int cantidad){
    gastar_andycoins( cantidad * COSTO_POR_BOMBA );

    int posicion = devolver_inventario()->obtener_posicion(BOMBA);

    devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->aumentar_cantidad(cantidad);
}

void Jugador::gastar_andycoins(int precio){
    int posicion = devolver_inventario()->obtener_posicion(ANDYCOINS);
    devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->reducir_cantidad(precio);
}