#ifndef Lista_edificios_EDIFICIOS_H
#define Lista_edificios_EDIFICIOS_H
#include <iostream>
#include "nodo_edificios.h"
#include "constantes.h"
#include "edificacion.h"


template<typename T>
class Lista_edificios{
    private:
        int cantidad_en_Lista_edificios;
        Nodo_edificios<T>* primero;
        Nodo_edificios<T>* ultimo;    
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Lista_edificios.
         */
        Lista_edificios();

        /*
         * Pre: posicion >= cantidad Lista_edificios.
         * Post: Me agrega un nuevo elemento a la Lista_edificios en la posicion ingresada.
         */
        void agregar_elemento(T* elemento, int posicion);

        /*
         * Pre: -.
         * Post: Me agrega un nuevo elemento a la Lista_edificios.
         */
        void agregar(string nuevo_elemento);

        /*
         * Pre: -.
         * Post: Me devuelve el primer elemento de la Lista_edificios.
         */
        Nodo_edificios<T>*& retornar_primero();

        /*
         * Pre: -.
         * Post: Me devuelve la cantidad de elementos de la Lista_edificios.
         */
        int devolver_cantidad_en_Lista_edificios();
        /*
        * PRE:
        * POST:
        */
        bool eliminar_por_direccion(int fila, int columna);

        /*
        * PRE:
        * POST:
        */
        int obtener_cantidad(int posicion);

        /*
         * Pre: -.
         * Post: Me devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra.
         */
        int obtener_posicion(string nombre);

                /*
         * Pre: -.
         * Post: Devuelve el nodo siguiente.
         */
       T* devolver_objeto_material(string material);

        /*
         * Pre: -.
         * Post: Me devuelve el nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra.
         */
        string obtener_nombre(int posicion);

        /*
         * Pre: posicion >= cantidad Lista_edificios.
         * Post: Me devuelve la direccion del nodo de esa posicion.
         */
        Nodo_edificios<T>* obtener_direccion_nodo(int posicion);

        /*
         * Pre: la posicion del elemento a eliminar
         * Post: elimina el elemento de la Lista_edificioss
         */
        void remover_elemento(int posicion);
        
        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Lista_edificios.
         */
        ~Lista_edificios();
};

template<typename T>
Lista_edificios<T>::Lista_edificios(){
    cantidad_en_Lista_edificios = 0;
    primero = nullptr;
    ultimo = nullptr;
}

template<typename T>
void Lista_edificios<T>::agregar_elemento(T* elemento, int posicion){
    Nodo_edificios<T>* nuevo = new Nodo_edificios<T>(elemento);
    Nodo_edificios<T>* auxiliar;

    if (posicion==1){
        auxiliar = primero;
        primero = nuevo;
    }
    else{
        Nodo_edificios<T>* nodo_anterior_a_posicion;
        nodo_anterior_a_posicion = obtener_direccion_nodo(posicion-1);
        auxiliar = nodo_anterior_a_posicion->direccion_siguiente();
        nodo_anterior_a_posicion->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(auxiliar);
    cantidad_en_Lista_edificios++;
}

template <typename T>
void Lista_edificios<T>::remover_elemento(int posicion){
    
    Nodo_edificios<T> *posicion_siguiente_nodo;

    if (posicion == 0)
    {
        posicion_siguiente_nodo = primero->direccion_siguiente();
        delete primero;
        primero = posicion_siguiente_nodo;
    }
    else
    {
        Nodo_edificios<T> *nodo_anterior_a_posicion;
        Nodo_edificios<T> *posicion_nodo_a_eliminar;
        nodo_anterior_a_posicion = obtener_direccion_nodo(posicion-1);
        posicion_nodo_a_eliminar = nodo_anterior_a_posicion->direccion_siguiente();
        posicion_siguiente_nodo = obtener_direccion_nodo(posicion)->direccion_siguiente();
        delete posicion_nodo_a_eliminar;
        nodo_anterior_a_posicion->cambiar_siguiente(posicion_siguiente_nodo);
    }
    cantidad_en_Lista_edificios--;
}

template < typename T >
void Lista_edificios<T>::agregar(string nuevo_elemento) {
    Nodo_edificios<T>* nuevo_nodo = new Nodo_edificios<T>(nuevo_elemento);
    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo -> cambiar_siguiente(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
    cantidad_en_Lista_edificios++;
}

template<typename T>
Nodo_edificios<T>* Lista_edificios<T>::obtener_direccion_nodo(int posicion){
    Nodo_edificios<T>* auxiliar = primero;
   
    for (int i = 0; i < posicion; i++)
    {
        auxiliar = auxiliar->direccion_siguiente();
    }
    return (auxiliar);
}

template<typename T>
Nodo_edificios<T>*& Lista_edificios<T>::retornar_primero(){
    return primero;
}

template<typename T>
int Lista_edificios<T>::devolver_cantidad_en_Lista_edificios(){
    return cantidad_en_Lista_edificios;
}

template<typename T>
int Lista_edificios<T>::obtener_posicion(string nombre) {
    bool elemento_encontrado = false;
    int i = 1;
    Nodo_edificios<T>* auxiliar = primero;

    while(!elemento_encontrado && i!= cantidad_en_Lista_edificios){
        if(auxiliar->devolver_dato()->devolver_nombre_edificio() == nombre){
            elemento_encontrado = true;
        }
        i++;
        auxiliar = auxiliar->direccion_siguiente();
    }

    if(!elemento_encontrado)
        return ERROR;
    
    return i - 1;
}
template<typename T>
int Lista_edificios<T>::obtener_cantidad(int posicion) {
    int i = 0;
    Nodo_edificios<T>* auxiliar = primero;

    if(posicion > cantidad_en_Lista_edificios){
        return ERROR;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> direccion_siguiente();
        i++;
    }
    return auxiliar -> obtener_cantidad();
}

template<typename T>
Lista_edificios<T>::~Lista_edificios(){   
    Nodo_edificios<T>* auxiliar;

    if (cantidad_en_Lista_edificios != 0){
        auxiliar = primero->direccion_siguiente();

        for (int i = 0; i < cantidad_en_Lista_edificios; i++)
        {
            delete primero;
            primero = auxiliar;
            if (auxiliar!= nullptr)
                auxiliar = primero->direccion_siguiente();
        }
    }
}

template<typename T>
string Lista_edificios<T>::obtener_nombre(int posicion) {
    int i = 0;
    Nodo_edificios<T>* auxiliar = primero;

    if(posicion > cantidad_en_Lista_edificios){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> direccion_siguiente();
        i++;
    }
    return auxiliar -> obtener_nombre();
}

template<typename T>
bool Lista_edificios<T>::eliminar_por_direccion(int fila, int columna){

    string direccion_buscada = to_string(fila) + to_string(columna);
    Nodo_edificios<T>* auxiliar = primero;
    bool bandera = false;
    int posicion = 0;
    
    for (int i = 0; i < cantidad_en_Lista_edificios; ++i) {
        cout << auxiliar->obtener_direccion() << endl;
        if(auxiliar->obtener_direccion() == direccion_buscada){
            auxiliar->anular_dato();
            bandera = true;
            posicion = i;
        }
        auxiliar = auxiliar->direccion_siguiente();
    }

    remover_elemento(posicion);

    return bandera;
}


#endif