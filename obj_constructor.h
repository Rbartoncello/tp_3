#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H
#include "objetivos.h"
#include "lista_edificios.h"

class Constructor : public Objetivos{
    private:
        Lista_edificios<Edificacion>* edificios_jugador;

    public:

        //Pre:
        //Post: inicializa su nombre y coloca la cantidad de andycoins en cero
        Constructor(Lista_edificios<Edificacion>* edificios_jugador);

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

        bool exite_edificio(string nombre);

        int cantidad_tipos_edificios();


    virtual ~Constructor();
};


#endif 