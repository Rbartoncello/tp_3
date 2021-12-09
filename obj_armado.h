#ifndef ARMADO_H
#define ARMADO_H
#include "objetivos.h"
#include "lista.h"

class Armado : public Objetivos{
    private:
        string nombre;
        Lista<Material>* inventario_jugador;

    public:

        //Pre:
        //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
        Armado(Lista<Material>*& inventario_jugador);

        //Pre:
        //Post:Agrega datos al conteo para alcanzar el objetivo
        void agregar_datos(int cantidad);

        //Pre:
        //Post:Muestra por pantalla la descripcion
        void mostrar_descripcion();


        //Pre:
        //Post:valida si el objetivo se ha realizado.
        void verificar_estado_objetivo();

        //Pre:
        //Post: Me devuelve el porcentaje de completado.
        double devolver_porcentaje_completado();

        virtual ~Armado();
};


#endif 