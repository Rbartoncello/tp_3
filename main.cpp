#include "juego.h"
#include "constantes.h"

int main() {
    Juego juego;

    if(juego.cargar() != ERROR)
        juego.mostrar();

    return 0;
}