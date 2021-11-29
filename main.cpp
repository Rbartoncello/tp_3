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
        if (juego->archivo_ubicaciones() == ERROR){
            juego->nueva_partida();
        } else {
            juego->cargar_grafo();
        }
    }


    delete juego;

    return 0;
}