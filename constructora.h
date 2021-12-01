#ifndef TP_3_CONSTRUCTORA_H
#define TP_3_CONSTRUCTORA_H

#include "diccionario.h"
#include "mapa.h"

const int OBJETIVO_COMPRAR_ANDYCOINS = 100000;

class Constructora
{

private:
    Mapa*   mapa;
    Diccionario<Edificacion>* dict_edificios;

    void mostrar_aviso();

    void avanzar_con_construccion(string nombre_nuevo_edifcio)

public:
    Constructora(Diccionario<Edificacion>* dict_edifcios, Mapa* mapa);

    void construir_edificio(Jugador* jugador);



};

#endif //TP_3_CONSTRUCTORA_H
