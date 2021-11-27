#ifndef MAS_ALTO_QUE_LAS_NUBES_H
#define MAS_ALTO_QUE_LAS_NUBES_H
#include "objetivos.h"
#include "edificacion.h"
const int OBJETIVO_PRINCIPAL_COMPLETADO = 1;

class Mas_alto_que_las_nubes : public Objetivos
{

private:

    int cantidad_obelisco;

public:

    //Pre:
    //Post: coloca al objetivo_realizo como valor falso.
    Mas_alto_que_las_nubes();

    //Pre:
    //Post:Debbera devolver el tipo de objetivo, preguntara al hijo polimorficamente.
    string devolver_tipo_objetivo();

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    void agregar_datos(Edificacion* &cantidad_Obelisco);

    //Pre:
    //Post:valida si el objetivo se ha realizado.
    void verificar_estado_objetivo();


    ~Mas_alto_que_las_nubes();
};


#endif 