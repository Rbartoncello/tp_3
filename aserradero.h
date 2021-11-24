#ifndef ASERRADERO_H
#define ASERRADERO_H
#include "edificacion.h"
#include "receta.h"

class Aserradero : public Edificacion{
    private:
        const int CANTIDADMATERIAL = 0;
        const string MATERIAL = "no brinda"; //Porque const?
        string emoji;
        Receta* receta;
        int maxima_cantidad_permitidos;
    public:

        Aserradero(string nombre);

        Aserradero(int piedra, int madera, int metal, int maxima_cantidad_permitidos);

        ~Aserradero();
        /*
         * Pre: -
         * Post: Me devuelve el piedra.
         */
        Receta* devolver_receta();

        int devolver_maxima_cantidad_permitidos();

        //PRE:
        //POST:Imprime la letra "A"
        void imprimirLetra();

        //PRE:
        //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
        int cantidadMaterial();

        //PRE:
        //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
        string materialProducido();

        //PRE:
        //POST:Va a decir el tipo de edificio que tiene.
        void hablarSobreMi();
};

#endif 