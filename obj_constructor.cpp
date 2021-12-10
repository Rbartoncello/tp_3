#include "obj_constructor.h"
#include <iomanip>
#include "emojis.h"

Constructor::Constructor(Lista_edificios<Edificacion>* edificios_jugador) : Objetivos(CONSTRUCTOR) {
    descripcion_objetivo = "Debes tener un edificio de cada tipo";
    this->edificios_jugador = edificios_jugador;
}

void Constructor::mostrar_descripcion(){
    verificar_estado_objetivo();
    string completado = EMOJI_MAL;
    if(devolver_estado_objetivo())
        completado = EMOJI_HECHO;
    cout << "\t║    " << devolver_tipo_objetivo() << "     │ " << descripcion_objetivo << "                          │ "<< setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Constructor::devolver_porcentaje_completado(){
    double porcentaje = ( ( (double) cantidad_tipos_edificios() / (double) 6 )) * 100;
    if (devolver_estado_objetivo())
        porcentaje = 100;

    return porcentaje;
}

int Constructor::cantidad_tipos_edificios(){
    int contador = 0;

    if (exite_edificio(EDIFICIO_ASERRADERO))
        contador++;
    if (exite_edificio(EDIFICIO_ESCUELA))
        contador++;
    if (exite_edificio(EDIFICIO_FABRICA))
        contador++;
    if (exite_edificio(EDIFICIO_PLANTA_ELECTRICA))
        contador++;
    if (exite_edificio(EDIFICIO_MINA))
        contador++;
    if (exite_edificio(EDIFICIO_MINA_ORO))
        contador++;

    return contador;
}

bool Constructor::exite_edificio(string nombre){
    bool esta = false;
    int i = 1;

    while ( (i < edificios_jugador->devolver_cantidad_en_Lista_edificios()) && !esta){
        if(edificios_jugador->obtener_nombre(i) == nombre)
            esta = true;
        else
            i++;
    }
    return  esta;
}

void Constructor::verificar_estado_objetivo(){
    if ( !objetivo_realizado ){
        if (edificios_jugador->devolver_cantidad_en_Lista_edificios() >= 6){
            if ( exite_edificio(EDIFICIO_ASERRADERO) && exite_edificio(EDIFICIO_ESCUELA) && exite_edificio(EDIFICIO_FABRICA) && exite_edificio(EDIFICIO_PLANTA_ELECTRICA) && exite_edificio(EDIFICIO_MINA) && exite_edificio(EDIFICIO_MINA_ORO) )
                objetivo_realizado = true;                
        }
    }
}

void Constructor::agregar_datos(int cantidad){}

Constructor::~Constructor(){}