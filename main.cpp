#include <iostream>
#include <fstream>
#include "diccionario.h"
#include "emojis.h"
#include "constantes.h"
#include "edificio.h"
#include "juego.h"
#include "archivo.h"
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