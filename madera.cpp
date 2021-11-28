#include "madera.h"
#include "emojis.h"
#include "constantes.h"

Madera::Madera() : Material(MADERA, EMOJI_MADERA, 1){
    
}

Madera::Madera(int cantidad) : Material(MADERA, EMOJI_MADERA, cantidad){
}

Madera::~Madera(){}