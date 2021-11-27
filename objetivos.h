#ifndef OBJETIVOS_H
#define OBJETIVOS_H
#include <string>

using namespace std;

class Objetivos
{
private:
    bool objetivo_realizado;

public:

    //Pre:
    //Post: coloca al objetivo_realizo como valor falso.
    Objetivos();

    //Pre:
    //Post:Debbera devolver el tipo de objetivo, preguntara al hijo polimorficamente.
    virtual string devolver_tipo_objetivo() = 0;

    //Pre:Necesita datos utilizados en partida
    //Post:Agrega datos a sus hijos de acuerdo al tipo de objetivo.
    void sumar_datos();

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    virtual void agregar_datos() = 0;

    //Pre:
    //Post:valida si el objetivo se ha realizado.
    virtual void verificar_estado_objetivo() = 0;

    //Pre:
    //Post:Devuelve un true si el objetivo se ha cumplido
    bool devolver_estado_objetivo();

    virtual ~Objetivos() = 0;
};


#endif 