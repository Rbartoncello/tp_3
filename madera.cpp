#include "madera.h"
#include "emojis.h"
#include "constantes.h"

Madera::Madera() : Material(MADERA, EMOJI_MADERA, 0){
    
}

Madera::Madera(int cantidad) {
    this->nombre = MADERA;
    this->emoji = EMOJI_MADERA;
    this->cantidad = cantidad;
}
