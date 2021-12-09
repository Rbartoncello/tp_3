#ifndef BOMBARDERO_H
#define BOMBARDERO_H
#include "objetivos.h"

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

    //Pre:
    //Post: Me devuelve el porcentaje de completado.
    double devolver_porcentaje_completado();


    virtual ~Bombardero();
};


#endif 