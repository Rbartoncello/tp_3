#include "andycoins.h"
#include "emojis.h"

Andycoins::Andycoins() : Material(ANDYCOINS, EMOJI_ANDYCOINS, 0){
    
}

Andycoins::Andycoins(int cantidad) : Material(ANDYCOINS, EMOJI_ANDYCOINS, cantidad) {
    
}

Andycoins::~Andycoins(){}