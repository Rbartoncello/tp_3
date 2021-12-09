#ifndef EDIFICACION_H
#define EDIFICACION_H
#include <iostream>
#include "colors.h"
#include "receta.h"

#include <string>

using namespace std;

class Edificacion
{
private:
    string nombre;
    string emoji;
    int duenio;
    int maxima_cantidad_permitidos;
    bool fue_atacado;
    string direccion;

protected:
    bool reparable;
public:
    
    //PRE:necesita el nombre del Edificacion
    //POST: guarda el nombre del edficio en nombre
    Edificacion (string tipoEdificacion, string emoji);

    void modificar_duenio(int duenio);

    //PRE:
    //POST: devuelve el nombre del edifico
    string devolver_nombre_edificio();

    int devolver_duenio();

    /*
    * Pre: -
    * Post: Me devuelve el emoji.
    */
    string devolver_emoji();

    string devolver_direccion();

    void agregar_direccion(int fila, int columna);

    /*
    * Pre: -
    * Post: Me devuelve si el edificio es reparable.
    */
    bool devolver_reparable();

    /*
     * Pre: -
     * Post: Me devuelve TRUE si la Fabrica necesita reparacion o FALSE en caso contrario.
     */
    virtual bool devolver_necesita_reparacion() = 0;

    virtual void reparar() = 0;

    virtual void atacar() = 0;    

    virtual int devolver_maxima_cantidad_permitidos() = 0;

    virtual Receta* devolver_receta() = 0;

    virtual bool brinda_material() = 0;

    bool devolver_fue_atacado();

    void fue_atacado_true();

    void fue_atacado_false();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el Edificacion que este custruido otorgue.
    virtual int devolver_cantidad_material_brinda() = 0;

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el Edificacion que este custruido otorgue.
    virtual string devolver_material_producido() = 0;

    //PRE:
    //POST:Va a decir el tipo de Edificacion que tiene.
    virtual void hablar_sobre_mi() = 0;

    virtual ~Edificacion() = 0;

    /*
     * Pre: -
     * Post: Imprime un resumen escrito del edificio.
    */
    void imprimir_resumen();

};


#endif //EDIFICACION_H