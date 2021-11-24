#ifndef MINA_ORO_H
#define MINA_ORO_H
#include "edificacion.h"
#include "receta.h"

class Mina_oro : public Edificacion{
    private:
        int cantidad_material_brinda;
        bool produce_material;
        string material_producido;
        string emoji;
        Receta* receta;
        int maxima_cantidad_permitidos;
    public:

        Mina_oro(string nombre);

        Mina_oro(int piedra, int madera, int metal, int maxima_cantidad_permitidos);

        ~Mina_oro();
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