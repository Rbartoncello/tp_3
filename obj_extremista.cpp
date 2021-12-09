#include <iomanip>
#include  "obj_extremista.h"
#include "emojis.h"

Extremista::Extremista() : Objetivos(EXTREMISTA) {
    bombas_compradas = 0;
    descripcion_objetivo = "Debes haber comprado " + to_string(OBJETIVO_EXTREMISTA) + " bombas durante la partida";
}

void Extremista::agregar_datos(int sumar_bombas){
    bombas_compradas = bombas_compradas + sumar_bombas;
    verificar_estado_objetivo();
}

void Extremista::verificar_estado_objetivo(){
    if ( !objetivo_realizado ){
        if (bombas_compradas >= OBJETIVO_EXTREMISTA)
            objetivo_realizado = true;
    }
}

void Extremista::mostrar_descripcion(){
    string completado = EMOJI_MAL;
    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;
    cout << "\t║     " << devolver_tipo_objetivo() << "     │ " << descripcion_objetivo << "            │ " << setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Extremista::devolver_porcentaje_completado(){
    double porcentaje = ( ( (double ) bombas_compradas / (double ) OBJETIVO_EXTREMISTA )) * 100;
    if (devolver_estado_objetivo())
        porcentaje = 100;
    
    return porcentaje;
}

Extremista::~Extremista(){}