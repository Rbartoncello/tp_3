#include "metal.h"
#include "emojis.h"
#include "constantes.h"

Metal::Metal() : Material(METAL, EMOJI_METAL, 0){
    
}

Metal::Metal(int cantidad) : Material(METAL, EMOJI_METAL, cantidad) {
    
}

Metal::~Metal(){}