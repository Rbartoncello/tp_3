#include "edificios.h"
#include "emojis.h"
#include "constantes.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

Edificios::Edificios(){
    this->total_edificios = 0;
}

Edificios::~Edificios(){
    for (int i = 0; i < this->total_edificios; i++){
        delete this->edificios[i];
    }
    delete [] this->edificios;
}

void Edificios::agregar_edificio(Edificio* edificio){
    int tope_viejo = this->total_edificios;

    Edificio** nuevos_edificios = new Edificio* [ tope_viejo + 1 ];

    for ( int i = 0; i < tope_viejo; i++ )
        nuevos_edificios[i] = this->edificios[i];

    nuevos_edificios[tope_viejo] = edificio;

    if ( this->total_edificios != 0 )
        delete [] this->edificios;

    this->edificios = nuevos_edificios;
    this->total_edificios++;
}

int Edificios::procesar_archivo(){

    ifstream archivo(PATH_EDIFICIO);
    string nombre, piedra, madera, metal, max_cant_permitidos, nombre_aux;

    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_EDIFICIO << endl;
        return ERROR;
    } else {
        while ( archivo >> nombre ){
            if (nombre == PLANTA){
                archivo >> nombre_aux;
                nombre += " " + nombre_aux; 
            }
            
            string emoji = buscar_tipo_emoji(nombre);
            archivo >> piedra;
            archivo >> madera;
            archivo >> metal;
            archivo >> max_cant_permitidos;

            agregar_edificio(new Edificio (nombre, emoji, stoi(piedra), stoi(madera), stoi(metal), stoi(max_cant_permitidos)));
        }
        archivo.close();
    }

    return 0;
}

string Edificios::buscar_tipo_emoji(string nombre_edificio){
    string emoji;

    if (nombre_edificio == EDIFICIO_MINA){
        emoji = EMOJI_MINA;
    } else if (nombre_edificio == EDIFICIO_ASERRADERO){
        emoji = EMOJI_ASERRADERO;
    } else if (nombre_edificio == EDIFICIO_FABRICA){
        emoji = EMOJI_FABRICA;
    } else if (nombre_edificio == EDIFICIO_ESCUELA){
        emoji = EMOJI_ESCUELA;
    } else if (nombre_edificio == EDIFICIO_OBELISCO){
        emoji = EMOJI_OBELISCO;
    } else if (nombre_edificio == EDIFICIO_PLANTA_ELECTRICA){
        emoji = EMOJI_PLANTA_ENERGIA;
    }
    
    return emoji;  
}
