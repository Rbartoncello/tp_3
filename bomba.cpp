#include "bomba.h"
#include "emojis.h"
#include "constantes.h"

Bomba::Bomba() : Material(BOMBA, EMOJI_BOMBA, 0){
    
}

Bomba::Bomba(int cantidad) {
    this->nombre = BOMBA;
    this->emoji = EMOJI_BOMBA;
    this->cantidad = cantidad;
}
