#include "obj_cansado.h"
#include <iomanip>
#include "emojis.h"

Cansado::Cansado(int energia) : Objetivos(CANSADO) {
    descripcion_objetivo = "Debes haber terminado con " + to_string(OBJETIVO_CANSADO)+ " de energia en un turno";
    this->energia = energia+1;
}

void Cansado::mostrar_descripcion(){
    verificar_estado_objetivo();
    string completado = EMOJI_MAL;
    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;
    cout << "\t║      " << devolver_tipo_objetivo() << "       │ " << descripcion_objetivo << "            │ "<< setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Cansado::devolver_porcentaje_completado(){
    double porcentaje = 0;
    if (devolver_estado_objetivo())
        porcentaje = 100;

    return porcentaje;
}

void Cansado::verificar_estado_objetivo(){
    if ( !objetivo_realizado ){
        if (energia == OBJETIVO_CANSADO)
            objetivo_realizado = true;
    }
}

void Cansado::agregar_datos(int cantidad){
    energia = cantidad;
    verificar_estado_objetivo();
}

Cansado::~Cansado(){}