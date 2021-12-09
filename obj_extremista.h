#ifndef EXTREMISTA_H
#define EXTREMISTA_H
#include "objetivos.h"

class Extremista : public Objetivos{
    private:
        int bombas_compradas;
    public:

        //Pre:
        //Post: inicializa su nombre y coloca la cantidad de bombas_compradas en cero
        Extremista();

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


        virtual ~Extremista();
};

#endif