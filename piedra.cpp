#include "piedra.h"
#include "emojis.h"
#include "constantes.h"

Piedra::Piedra() : Material(PIEDRA, EMOJI_PIEDRA, 0){
    
}

Piedra::Piedra(int cantidad) : Material(PIEDRA, EMOJI_PIEDRA, cantidad) {
}

Piedra::~Piedra(){}