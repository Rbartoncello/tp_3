#ifndef BOMBARDERO_H
#define BOMBARDERO_H
#include "objetivos.h"

const int OBJETIVO_BOMBARDERO = 5;

class Bombardero : public Objetivos
{

private:

    int bombas_usadas;

public:

    //Pre:
    //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
    Bombardero();

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    void agregar_datos(int sumar_bomba_usada);

    //Pre:
    //Post:Muestra por pantalla la descripcion
    void mostrar_descripcion();

    //Pre:
    //Post:valida si el objetivo se ha realizado.
    void verificar_estado_objetivo();


    virtual ~Bombardero();
};


#endif 