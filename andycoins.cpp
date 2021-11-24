#include "andycoins.h"
#include "emojis.h"
#include "constantes.h"

Andycoins::Andycoins() : Material(ANDYCOINS, EMOJI_ANDYCOINS, 0){
    
}

Andycoins::Andycoins(int cantidad) {
    this->nombre = ANDYCOINS;
    this->emoji = EMOJI_ANDYCOINS;
    this->cantidad = cantidad;
}
