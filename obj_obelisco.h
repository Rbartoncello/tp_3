#ifndef OBJ_OBELISCO_H
#define OBJ_OBELISCO_H
#include "objetivos.h"
#include "material.h"
#include "lista_edificios.h"
#include "nodo_edificios.h"

class Obelisco_obj : public Objetivos
{

private:
    int cantidad_obelisco;
    Lista_edificios<Edificacion>* edificios_propios;

public:

    //Pre:
    //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
    Obelisco_obj(Lista_edificios<Edificacion> *edificio);

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

    virtual ~Obelisco_obj();
};

#endif