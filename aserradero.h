#ifndef ASERRADERO_H
#define ASERRADERO_H
#include "edificacion.h"
#include "receta.h"

class Aserradero : public Edificacion{
    private:
        int cantidad_material_brinda;
        bool produce_material;
        string material_producido;
        string emoji;
        Receta* receta;
        bool necesita_reparacion;
        int maxima_cantidad_permitidos;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Aserradero.
         */
        Aserradero();

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Aserradero.
         */
        Aserradero(int piedra, int madera, int metal, int maxima_cantidad_permitidos);

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Aserradero.
         */
        ~Aserradero();

        /*
         * PRE:
         * POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
         */
        int devolver_cantidad_material_brinda();

        /*
         * Pre: -
         * Post: Me devuelve TRUE si produce algun tipo de material o FALSE en caso contrario.
         */
        bool brinda_material();

        /*
         * PRE: -
         * POST: Devolver el material que produce.
         */
        string devolver_material_producido();

        /*
         * Pre: -
         * Post: Me devuelve el piedra.
         */
        Receta* devolver_receta();

        /*
         * Pre: -
         * Post: Me devuelve TRUE si la mina necesita reparacion o FALSE en caso contrario.
         */
        bool devolver_necesita_reparacion();

        /*
         * Pre: -
         * Post: Me devuelve la maxima cantidad pemitida para construir.
         */
        int devolver_maxima_cantidad_permitidos();

        /*
         * PRE:
         * POST:Va a decir el tipo de edificio que tiene.
         */
        void hablar_sobre_mi();
};

#endif //ASERRADERO_H