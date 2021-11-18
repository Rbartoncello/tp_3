#include "juego.h"
#include "constantes.h"

int main() {
    Juego juego;

    if(juego.se_abrieron_archivos())
        juego.mostrar();

    return 0;
}