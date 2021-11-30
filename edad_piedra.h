#ifndef EDAD_PIEDRA_H
#define EDAD_PIEDRA_H
#include "objetivos.h"
#include "inventario.h"


const int OBJETIVO_EDAD_PIEDRA = 50000;

class Edad_piedra : public Objetivos
{
private:

    Material** inventario_jugador;

public:

    //Pre:
    //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
    Edad_piedra(Inventario*& inventario_jugador);

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    void agregar_datos();

    //Pre:
    //Post:Muestra por pantalla la descripcion
    void mostrar_descripcion();


    //Pre:
    //Post:valida si el objetivo se ha realizado.
    void verificar_estado_objetivo();


    virtual ~Edad_piedra();
};


#endif 