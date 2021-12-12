#include <iostream>
#include "diccionario.h"
#include "juego.h"
#include <time.h>

int main() {
    Juego* juego = new Juego();
    srand (( unsigned)time(NULL));


    if (juego->cargar() != ERROR){
        if (juego->archivo_ubicaciones() == ERROR){
            juego->nueva_partida();
        } else {
            juego->partida_empezada();
        }
    }


    delete juego;

    return 0;
}