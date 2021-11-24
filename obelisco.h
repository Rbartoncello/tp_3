#ifndef OBELISCO_H
#define OBELISCO_H
#include "edificacion.h"
#include "receta.h"
class Obelisco : public Edificacion{
    private:
        const int CANTIDADMATERIAL = 0;
        const string MATERIAL = "no brinda"; //Porque const?
        string emoji;
        Receta* receta;
        int maxima_cantidad_permitidos;
    public:

        Obelisco(string nombre);

        Obelisco(int piedra, int madera, int metal, int maxima_cantidad_permitidos);

        ~Obelisco();
        /*
         * Pre: -
         * Post: Me devuelve el piedra.
         */
        Receta* devolver_receta();

        int devolver_maxima_cantidad_permitidos();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    int cantidadMaterial();

    void imprimirLetra();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    string materialProducido();

    //PRE:
    //POST:Va a decir el tipo de edificio que tiene.
    void hablarSobreMi();
};

#endif 