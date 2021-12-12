#include "obj_energetico.h"
#include <iomanip>
#include "emojis.h"

Energetico::Energetico(int* energia_jugador) : Objetivos(ENERGETICO) {
    descripcion_objetivo = "Debes tener " + to_string(OBJETIVO_ENERGETICO)+ " de energia";
    energia = energia_jugador;
}

void Energetico::mostrar_descripcion(){
    
    string completado = EMOJI_MAL;

    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;

    cout << "\t║     " << devolver_tipo_objetivo() << "     │ " << descripcion_objetivo << "                                    │ "<< setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Energetico::devolver_porcentaje_completado(){
    
    double porcentaje = ( ( (double) *energia / (double) OBJETIVO_ENERGETICO )) * 100;

    if (devolver_estado_objetivo())
        porcentaje = 100;

    return porcentaje;
}

void Energetico::verificar_estado_objetivo(){
    if ( !objetivo_realizado ){
        if (*energia >= OBJETIVO_ENERGETICO)
            objetivo_realizado = true;
            
    }
}

void Energetico::agregar_datos(int cantidad){}

Energetico::~Energetico(){}