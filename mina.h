#ifndef MINA_H
#define MINA_H
#include "edificacion.h"
#include "receta.h"

class Mina : public Edificacion{
    private:
        const int CANTIDADMATERIAL = 0;
        const string MATERIAL = "no brinda"; //Porque const?
        string emoji;
        Receta* receta;
        int maxima_cantidad_permitidos;
    public:

        Mina(string nombre);

        Mina(int piedra, int madera, int metal, int maxima_cantidad_permitidos);

        ~Mina();
        /*
         * Pre: -
         * Post: Me devuelve el piedra.
         */
        Receta* devolver_receta();

        int devolver_maxima_cantidad_permitidos();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    int cantidadMaterial();

    void devolverPosicion();

    void imprimirLetra();

    //PRE:
    //POST:Va a sumar a la lista de materiales lo que el edificio que este custruido otorgue.
    string materialProducido();

    //PRE:
    //POST:Va a decir el tipo de edificio que tiene.
    void hablarSobreMi();
};

#endif //MINA_H