#ifndef OBELISCO_H
#define OBELISCO_H
#include "edificacion.h"
#include "receta.h"

class Obelisco : public Edificacion{
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
         * Post: Me va a crear el objeto Obelisco.
         */
        Obelisco();

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Obelisco.
         */
        Obelisco(int piedra, int madera, int metal, int maxima_cantidad_permitidos);

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Obelisco.
         */
        ~Obelisco();

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
         * Post: Me devuelve TRUE si la Fabrica necesita reparacion o FALSE en caso contrario.
         */
        bool devolver_necesita_reparacion();
            /*
        * PRE:
        * POST: cambia necesita_reparacion a true
        */
        void atacar();
            /*
        * PRE:
        * POST: cambia necesita_reparacion a false
        */
        void reparar();

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

#endif //OBELISCO_H