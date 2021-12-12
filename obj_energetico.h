#ifndef OBJ_ENERGETICO_H
#define OBJ_ENERGETICO_H
#include "objetivos.h"

class Energetico : public Objetivos
{

private:
    int* energia;

public:

    //Pre:
    //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
    Energetico(int* energia_jugador);

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    void agregar_datos(int sumar_andycoins);

    //Pre:
    //Post:Muestra por pantalla la descripcion
    void mostrar_descripcion();

    //Pre:
    //Post: Me devuelve el porcentaje de completado.
    double devolver_porcentaje_completado();

    //Pre:
    //Post:valida si el objetivo se ha realizado.
    void verificar_estado_objetivo();

    virtual ~Energetico();
};

#endif