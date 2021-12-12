#include <iomanip>
#include "obj_obelisco.h"
#include "emojis.h"

Obelisco_obj::Obelisco_obj(Lista_edificios<Edificacion> *edificio) : Objetivos(MAS_ALTO_NUBES)
{
    edificios_propios = edificio;
    descripcion_objetivo = "Debes haber construido " + to_string(OBJETIVO_PRIMARIO) + " obelisco";
    cantidad_obelisco = 0;
}

void Obelisco_obj::agregar_datos(int cantidad) {}

void Obelisco_obj::verificar_estado_objetivo()
{

    if (!objetivo_realizado)
    {

        if (edificios_propios->obtener_posicion(EDIFICIO_OBELISCO) != ERROR)
        {
            objetivo_realizado = true;
            cantidad_obelisco = 1;
        }
    }
}

void Obelisco_obj::mostrar_descripcion()
{
    string completado = EMOJI_MAL;

    if (devolver_estado_objetivo())
        completado = EMOJI_HECHO;

    cout << "\t║     " << devolver_tipo_objetivo() << "     │ " << descripcion_objetivo << "            │ " << setfill(' ') << setw(14) << devolver_porcentaje_completado() << " %" << setfill(' ') << setw(13) << " │ " << setfill(' ') << setw(6) << completado << setfill(' ') << setw(10) << " ║ " << endl;
}

double Obelisco_obj::devolver_porcentaje_completado()
{
    double porcentaje = (((double)cantidad_obelisco / (double)OBJETIVO_PRIMARIO)) * 100;

    if (devolver_estado_objetivo())
        porcentaje = 100;

    return porcentaje;
}

Obelisco_obj::~Obelisco_obj() {}