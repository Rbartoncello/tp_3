#include "obj_minero.h"
#include <iomanip>
#include "emojis.h"

Minero::Minero(Lista_edificios<Edificacion>* edificio) : Objetivos(MINERO) {
    descripcion_objetivo = "Debes haber construido " + to_string(OBJETIVO_MINERO)+ " mina de cada tipo";
    edificios_jugador = edificio;
    minas_totales = 0;
}

void Minero::mostrar_descripcion(){
    
    string completado = EMOJI_MAL;

    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;

    cout << "\t║   " << devolver_tipo_objetivo() << "             │ " << descripcion_objetivo << "                    │ "<< setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Minero::devolver_porcentaje_completado(){

    double porcentaje = ( ( (double) (minas_totales) / (double) (OBJETIVO_MINERO+OBJETIVO_MINERO) )) * 100;

    if (devolver_estado_objetivo())
        porcentaje = 100;

    return porcentaje;
}

void Minero::verificar_estado_objetivo(){

    verificar_estado();

    if ( !objetivo_realizado ){

        if ((minas_totales) >= (OBJETIVO_MINERO+OBJETIVO_MINERO))
            objetivo_realizado = true;

    }
}

void Minero::verificar_estado(){
    Nodo_edificios<Edificacion>* primer_nodo = edificios_jugador->retornar_primero();
    int cantidad = edificios_jugador->devolver_cantidad_en_Lista_edificios(), minas_comunes = 0, minas_oro = 0;
    string nombre_edificio;
    

    for (int i = 0; i < cantidad; i++)
    {
        nombre_edificio = primer_nodo->devolver_dato()->devolver_nombre_edificio();
        if (nombre_edificio == EDIFICIO_MINA && minas_comunes == 0)
            minas_comunes++;
        else if (nombre_edificio == EDIFICIO_MINA_ORO && minas_oro== 0)
            minas_oro++;
        primer_nodo = primer_nodo->direccion_siguiente();
    }

    minas_totales =  minas_comunes + minas_oro;
}

void Minero::agregar_datos(int cantidad){}

Minero::~Minero(){}