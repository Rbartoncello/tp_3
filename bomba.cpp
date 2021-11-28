#include "bomba.h"
#include "emojis.h"
#include "constantes.h"

Bomba::Bomba() : Material(BOMBA, EMOJI_BOMBA, 0){
    
}

Bomba::Bomba(int cantidad) : Material(METAL, EMOJI_METAL, cantidad) {
    
}

Bomba::~Bomba(){}