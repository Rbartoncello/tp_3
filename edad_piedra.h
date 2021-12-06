#ifndef EDAD_PIEDRA_H
#define EDAD_PIEDRA_H
#include "objetivos.h"
#include "lista.h"

class Edad_piedra : public Objetivos
{
private:

    Lista<Material>* inventario_jugador;

public:

    //Pre:
    //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
    Edad_piedra(Lista<Material>*& inventario_jugador);

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    void agregar_datos(int cantidad);

    //Pre:
    //Post:Muestra por pantalla la descripcion
    void mostrar_descripcion();


    //Pre:
    //Post:valida si el objetivo se ha realizado.
    void verificar_estado_objetivo();


    virtual ~Edad_piedra();
};


#endif 