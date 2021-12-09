#ifndef LISTA_PRIMITIVA_H
#define LISTA_PRIMITIVA_H
#include <iostream>
#include <cstring>
#include "nodo_primitivo.h"

template <typename T>
class Lista_primitiva
{
private:
    int cantidad_en_Lista_primitiva;
    Nodo_primitivo<T> *primero;
    Nodo_primitivo<T> *ultimo;

public:
    /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Lista_primitiva.
         */
    Lista_primitiva();

    /*
         * Pre: posicion >= cantidad Lista_primitiva.
         * Post: Me agrega un nuevo elemento a la Lista_primitiva en la posicion ingresada.
         */
    void agregar_elemento(T elemento, int posicion);

    /*
         * Pre: -.
         * Post: Me agrega un nuevo elemento a la Lista_primitiva.
         */
    void agregar(T nuevo_elemento);

    /*
         * Pre: -.
         * Post: Me devuelve el primer elemento de la Lista_primitiva.
         */
    Nodo_primitivo<T> *&retornar_primero();

    /*
         * Pre: -.
         * Post: Me devuelve la cantidad de elementos de la Lista_primitiva.
         */
    int devolver_cantidad_en_Lista_primitiva();

    /*
         * Pre: -.
         * Post: Me devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra.
         */
    int obtener_posicion(T nombre);

    /*
         * Pre: la posicion del elemento a eliminar
         * Post: elimina el elemento de la Lista_primitivas
         */
    void remover_elemento(int posicion);

    /*
         * Pre: la posicion del elemento a eliminar
         * Post: elimina el elemento de la Lista_primitivas
         */
    T devolver_elemento_en_posicion(int posicion);

    /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Lista_primitiva.
         */
    ~Lista_primitiva();

    void cambiar_dato(T dato, int posicion);

    int obtener_posicion_con_nombre(string nombre_buscado);

private:
    /*
         * Pre: posicion >= cantidad Lista_primitiva.
         * Post: Me devuelve la direccion del nodo de esa posicion.
         */
    Nodo_primitivo<T> *obtener_direccion_nodo(int posicion);
};

template <typename T>
Lista_primitiva<T>::Lista_primitiva()
{
    cantidad_en_Lista_primitiva = 0;
    primero = nullptr;
    ultimo = nullptr;
}

template <typename T>
void Lista_primitiva<T>::agregar_elemento(T elemento, int posicion)
{
    Nodo_primitivo<T> *nuevo = new Nodo_primitivo<T>(elemento);
    Nodo_primitivo<T> *auxiliar;

    if (posicion == 1)
    {
        auxiliar = primero;
        primero = nuevo;
    }
    else
    {
        Nodo_primitivo<T> *nodo_anterior_a_posicion;
        nodo_anterior_a_posicion = obtener_direccion_nodo(posicion - 1);
        auxiliar = nodo_anterior_a_posicion->direccion_siguiente();
        nodo_anterior_a_posicion->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(auxiliar);
    cantidad_en_Lista_primitiva++;
}

template <typename T>
void Lista_primitiva<T>::remover_elemento(int posicion)
{

    Nodo_primitivo<T> *posicion_siguiente_nodo;

    if (posicion == 1)
    {
        posicion_siguiente_nodo = primero->direccion_siguiente();
        delete primero;
        primero = posicion_siguiente_nodo;
    }
    else
    {
        Nodo_primitivo<T> *nodo_anterior_a_posicion;
        Nodo_primitivo<T> *posicion_nodo_a_eliminar;
        nodo_anterior_a_posicion = obtener_direccion_nodo(posicion - 1);
        posicion_nodo_a_eliminar = nodo_anterior_a_posicion->direccion_siguiente();
        posicion_siguiente_nodo = posicion_nodo_a_eliminar->direccion_siguiente();
        delete posicion_nodo_a_eliminar;
        nodo_anterior_a_posicion->cambiar_siguiente(posicion_siguiente_nodo);
    }
    cantidad_en_Lista_primitiva--;
}

template <typename T>
void Lista_primitiva<T>::agregar(T nuevo_elemento)
{
    Nodo_primitivo<T> *nuevo_nodo = new Nodo_primitivo<T>(nuevo_elemento);
    if (primero == nullptr)
    {
        primero = nuevo_nodo;
        ultimo = primero;
    }
    else
    {
        ultimo->cambiar_siguiente(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
    cantidad_en_Lista_primitiva++;
}

template <typename T>
Nodo_primitivo<T> *Lista_primitiva<T>::obtener_direccion_nodo(int posicion)
{
    Nodo_primitivo<T> *auxiliar = primero;

    for (int i = 1; i != posicion; i++)
    {
        auxiliar = auxiliar->direccion_siguiente();
    }
    return (auxiliar);
}

template <typename T>
T Lista_primitiva<T>::devolver_elemento_en_posicion(int posicion)
{
    Nodo_primitivo<T> *auxiliar = nullptr;

    auxiliar = obtener_direccion_nodo(posicion);

    return (auxiliar->devolver_dato());
}

template <typename T>
Nodo_primitivo<T> *&Lista_primitiva<T>::retornar_primero()
{
    return primero;
}

template <typename T>
int Lista_primitiva<T>::devolver_cantidad_en_Lista_primitiva()
{
    return cantidad_en_Lista_primitiva;
}

template <typename T>
int Lista_primitiva<T>::obtener_posicion(T nombre)
{
    bool elemento_encontrado = false;
    int i = 0;
    Nodo_primitivo<T> *auxiliar = primero;

    while (!elemento_encontrado && i < cantidad_en_Lista_primitiva)
    {
        if (auxiliar->devolver_dato()->devolver_nombre() == nombre)
        {
            elemento_encontrado = true;
        }
        i++;
        auxiliar = auxiliar->direccion_siguiente();
    }

    if (!elemento_encontrado)
        return -1;

    return i - 1;
}

template <typename T>
Lista_primitiva<T>::~Lista_primitiva()
{
    Nodo_primitivo<T> *auxiliar;

    if (cantidad_en_Lista_primitiva != 0)
    {
        auxiliar = primero->direccion_siguiente();

        for (int i = 0; i < cantidad_en_Lista_primitiva; i++)
        {
            delete primero;
            primero = auxiliar;
            if (auxiliar != nullptr)
                auxiliar = primero->direccion_siguiente();
        }
    }
}

template <typename T>
void Lista_primitiva<T>::cambiar_dato(T dato, int posicion)
{

    Nodo_primitivo<T> *auxiliar = primero;

    for (int i = 1; i < posicion + 1; ++i)
    {
        if (i == posicion)
        {
            auxiliar->cambiar_dato(dato);
        }
        auxiliar = auxiliar->direccion_siguiente();
    }
}

template <typename T>
int Lista_primitiva<T>::obtener_posicion_con_nombre(string nombre_buscado)
{

    Nodo_primitivo<T> *auxiliar = primero;
    string nombre =  primero->devolver_dato();
    int contador = 1;

    while (nombre != nombre_buscado)
    {
        auxiliar = auxiliar->direccion_siguiente();
        nombre =  auxiliar->devolver_dato();
        contador++;
    }

    return contador;
}

#endif