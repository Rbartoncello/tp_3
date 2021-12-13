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
    int fila, columna;

protected:
    bool reparable;
public:
    
    //PRE:necesita el nombre del Edificacion
    //POST: guarda el nombre del edficio en nombre
    Edificacion (string tipoEdificacion, string emoji);
        /*
    * PRE: Necesita un int
    * POST: Cambia el duenio (el atributo de edificacion)
    */
    void modificar_duenio(int duenio);

    //PRE:
    //POST: devuelve el nombre del edifico
    string devolver_nombre_edificio();
        /*
    * PRE:
    * POST: Devuelve el duenio
    */
    int devolver_duenio();

    /*
    * Pre: -
    * Post: Me devuelve el emoji.
    */
    string devolver_emoji();
    /*
    * PRE:
    * POST: devuelve un string con la fila y columna: ->  "12" -> fila = 1 columna = 2
    */
    string devolver_direccion();
    /*
    * PRE:
    * POST: devuelve un int fila
    */
    int devolver_fila();
    /*
    * PRE:
    * POST: devuelve un int columna
    */
    int devolver_columna();
    /*
    * PRE:
    * POST: se cambia el atributo direccion del edificio
    */
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
    /*
    * PRE: Metodo virtual de las clases hijas
    * POST:
    */
    virtual void reparar() = 0;
    /*
    * PRE:  Metodo virtual de las clases hijas
    * POST:
    */
    virtual void atacar() = 0;
    /*
    * PRE:  Metodo virtual de las clases hijas
    * POST:
    */
    virtual int devolver_maxima_cantidad_permitidos() = 0;
    /*
    * PRE:  Metodo virtual de las clases hijas
    * POST:
    */
    virtual Receta* devolver_receta() = 0;
    /*
    * PRE:  Metodo virtual de las clases hijas
    * POST:
    */
    virtual bool brinda_material() = 0;
    /*
    * PRE:
    * POST: Devuelve si el edificio fue atacado o no (solo para los edificios de mas de uno de vida)
    */
    bool devolver_fue_atacado();
    /*
    * PRE:
    * POST:
    */
    void fue_atacado_true();
    /*
    * PRE:
    * POST:
    */
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
    /*
    * PRE: -
    * POST: -
    */
    virtual ~Edificacion() = 0;
    /*
     * Pre: -
     * Post: Imprime un resumen escrito del edificio.
    */
    void imprimir_resumen();

};


#endif //EDIFICACION_H