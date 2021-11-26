#include "andycoins.h"
#include "emojis.h"
#include "constantes.h"

Andycoins::Andycoins() : Material(ANDYCOINS, EMOJI_ANDYCOINS, 0){
    
}

Andycoins::Andycoins(int cantidad) : Material(METAL, EMOJI_ANDYCOINS, cantidad) {
    
}
