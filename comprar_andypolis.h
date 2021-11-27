#ifndef COMPRAR_ANDYPOLIS_H
#define COMPRAR_ANDYPOLIS_H
#include "objetivos.h"

const int OBJETIVO_COMPRAR_ANDYCOINS = 100000;

class Comprar_andypolis : public Objetivos
{

private:

    int andycoins_recolectados;
    string descripcion_objetivo;

public:

    //Pre:
    //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
    Comprar_andypolis();

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    void agregar_datos(int sumar_andycoins);

    //Pre:
    //Post:Muestra por pantalla la descripcion
    void mostrar_descripcion();

    //Pre:
    //Post:valida si el objetivo se ha realizado.
    void verificar_estado_objetivo();


    ~Comprar_andypolis();
};


#endif 