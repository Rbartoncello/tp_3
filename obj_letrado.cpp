#include "obj_letrado.h"
#include <iomanip>
#include "emojis.h"

Letrado::Letrado(Lista_edificios<Edificacion>* edificio, int objetivo) : Objetivos(LETRADO) {
    objetivo_letrado = objetivo;
    descripcion_objetivo = "Debes haber construido " + to_string(objetivo_letrado)+ " escuelas";
    edificios_jugador = edificio;
    cantidad_escuelas = 0;
}

void Letrado::mostrar_descripcion(){
    
    string completado = EMOJI_MAL;

    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;

    cout << "\t║      " << devolver_tipo_objetivo() << "       │ " << descripcion_objetivo << "                             │ "<< setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Letrado::devolver_porcentaje_completado(){
    double porcentaje = ( ( (double) (cantidad_escuelas) / (double) objetivo_letrado )) * 100;

    if (devolver_estado_objetivo())
        porcentaje = 100;

    return porcentaje;
}

void Letrado::verificar_estado_objetivo(){

    verificar_estado();

    if ( !objetivo_realizado ){

        if ((cantidad_escuelas) >= objetivo_letrado )
            objetivo_realizado = true;

    }
}

void Letrado::verificar_estado(){
    Nodo_edificios<Edificacion>* primer_nodo = edificios_jugador->retornar_primero();
    int cantidad = edificios_jugador->devolver_cantidad_en_Lista_edificios();    
    string nombre_edificio;

    for (int i = 0; i < cantidad; i++)
    {
        nombre_edificio = primer_nodo->devolver_dato()->devolver_nombre_edificio();
        if (nombre_edificio == EDIFICIO_ESCUELA)
            cantidad_escuelas++;
        primer_nodo = primer_nodo->direccion_siguiente();
    }
}

void Letrado::agregar_datos(int cantidad){}

Letrado::~Letrado(){}