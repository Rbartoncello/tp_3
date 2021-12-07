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
    int fila_nueva;
    int columna_nueva;

    void mostrar_aviso();

    void avanzar_con_construccion(string nombre_nuevo_edifcio, Jugador* jugador);

    bool validar_maximo_edificio(string nombre_nuevo_edificio, Jugador* jugador);

    bool validar_materiales(string nombre_nuevo_edificio, Jugador* &jugador);

    void mostrar_materiales_faltantes(int cantidad_piedra, int cantidad_madera, int cantidad_metal, int piedra_necesaria, int madera_necesaria, int metal_necesario);

    bool ingreso_de_coordenadas();

    bool validar_coords(int coord1, int coord2);

    void mostrar_aviso_terreno(bool aviso);

public:
    Constructora(Diccionario<Edificacion>* dict_edifcios, Mapa* mapa);

    void construir_edificio(Jugador* jugador);



};

#endif //TP_3_CONSTRUCTORA_H
