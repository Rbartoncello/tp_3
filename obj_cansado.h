#ifndef CANSADO_H
#define CANSADO_H
#include "objetivos.h"

class Cansado : public Objetivos{
    private:
        int energia;
    public:

        //Pre:
        //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
        Cansado(int energia);

        //Pre:
        //Post:Muestra por pantalla la descripcion
        void mostrar_descripcion();

        //Pre:
        //Post:Agrega datos al conteo para alcanzar el objetivo
        void agregar_datos(int cantidad);

        //Pre:
        //Post:valida si el objetivo se ha realizado.
        void verificar_estado_objetivo();

        //Pre:
        //Post: Me devuelve el porcentaje de completado.
        double devolver_porcentaje_completado();

        virtual ~Cansado();
};


#endif 