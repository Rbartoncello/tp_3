#include <iostream>
#include <fstream>
#include "diccionario.h"
#include "emojis.h"
#include "constantes.h"
#include "edificio.h"
#include "juego.h"
#include "archivo.h"

int main() {
    Juego* juego = new Juego();


    if (juego->cargar() != ERROR){
        juego->nueva_partida();
    }


    delete juego;

    return 0;
}