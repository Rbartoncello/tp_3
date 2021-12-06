#ifndef COMPRAR_ANDYPOLIS_H
#define COMPRAR_ANDYPOLIS_H
#include "objetivos.h"
#include "material.h"
#include "lista.h"

class Comprar_andypolis : public Objetivos
{

private:

    int andycoins_recolectados;
    string descripcion_objetivo;

public:

    //Pre:
    //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
    Comprar_andypolis(int andycoins_iniciales);

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    void agregar_datos(int sumar_andycoins);

    //Pre:
    //Post:Muestra por pantalla la descripcion
    void mostrar_descripcion();

    //Pre:
    //Post:valida si el objetivo se ha realizado.
    void verificar_estado_objetivo();


    virtual ~Comprar_andypolis();
};


#endif 