#ifndef MAS_ALTO_QUE_LAS_NUBES_H
#define MAS_ALTO_QUE_LAS_NUBES_H
#include "objetivos.h"
#include "edificacion.h"
const int OBJETIVO_PRINCIPAL_COMPLETADO = 1;

class Mas_alto_que_las_nubes : public Objetivos
{

private:

    int cantidad_obelisco;
    string descripcion_objetivo;
    Edificacion* edificios_jugador;

public:

    //Pre:
    //Post: coloca al objetivo_realizo como valor falso.
    Mas_alto_que_las_nubes(Edificacion* &edificios_jugador);

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    void agregar_datos();

    //Pre:
    //Post:Muestra por pantalla la descripcion
    void mostrar_descripcion();

    //Pre:
    //Post:valida si el objetivo se ha realizado.
    void verificar_estado_objetivo();


    virtual ~Mas_alto_que_las_nubes();
};


#endif 