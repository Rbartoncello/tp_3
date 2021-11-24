#ifndef ESCUELA_H
#define ESCUELA_H
#include "edificacion.h"
#include "receta.h"

class Escuela : public Edificacion{
    private:
        int cantidad_material_brinda;
        bool produce_material;
        string material_producido;
        string emoji;
        Receta* receta;
        int maxima_cantidad_permitidos;
    public:

        Escuela(string nombre);

        Escuela(int piedra, int madera, int metal, int maxima_cantidad_permitidos);

        ~Escuela();
        /*
         * Pre: -
         * Post: Me devuelve el piedra.
         */
        Receta* devolver_receta();

        int devolver_maxima_cantidad_permitidos();

        bool brinda_material();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    int devolver_cantidad_material_brinda();

    void imprimirLetra();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    string devolver_material_producido();

    //PRE:
    //POST:Va a decir el tipo de edificio que tiene.
    void hablar_sobre_mi();
};

#endif 