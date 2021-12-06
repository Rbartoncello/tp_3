#ifndef TP_3_CONSTRUCTORA_H
#define TP_3_CONSTRUCTORA_H

#include "diccionario.h"
#include "mapa.h"
#include "constantes.h"

class Constructora
{

private:
    Mapa*   mapa;
    Diccionario<Edificacion>* dict_edificios;

    void mostrar_aviso();

    void avanzar_con_construccion(string nombre_nuevo_edifcio, Jugador* jugador);

    bool validar_maximo_edificio(string nombre_nuevo_edificio, Jugador* jugador);

    bool validar_materiales(string nombre_nuevo_edificio, Jugador* &jugador);

    void mostrar_materiales_faltantes(int cantidad_piedra, int cantidad_madera, int cantidad_metal, int piedra_necesaria, int madera_necesaria, int metal_necesario);

public:
    Constructora(Diccionario<Edificacion>* dict_edifcios, Mapa* mapa);

    void construir_edificio(Jugador* jugador);



};

#endif //TP_3_CONSTRUCTORA_H
