#ifndef OBJETIVOS_H
#define OBJETIVOS_H
#include <string>
#include <iostream>
#include "constantes.h"

using namespace std;

class Objetivos
{
protected:

    bool objetivo_realizado;
    string descripcion_objetivo;

private:

    string nombre_objetivo;

public:

    //Pre:
    //Post: coloca al objetivo_realizo como valor falso.
    Objetivos(string nombre_de_objetivo);

    //Pre:
    //Post:Debbera devolver el tipo de objetivo, preguntara al hijo polimorficamente.
    string devolver_tipo_objetivo();

    //Pre:
    //Post:Muestra por pantalla la descripcion
    virtual void mostrar_descripcion() = 0;

    //Pre:
    //Post:Agrega datos al conteo para alcanzar el objetivo
    virtual void agregar_datos(int cantidad) = 0;

    //Pre:
    //Post:valida si el objetivo se ha realizado.
    virtual void verificar_estado_objetivo() = 0;

    //Pre:
    //Post:Devuelve un true si el objetivo se ha cumplido
    bool devolver_estado_objetivo();

    virtual ~Objetivos() = 0;
};


#endif 