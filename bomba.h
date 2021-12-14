#ifndef BOMBA_H
#define BOMBA_H
#include "material.h"
class Bomba : public Material{
    private:

    public:
            /*
            constructor
        * PRE:
        * POST: Crea una bomba sin parametros
        */
        Bomba();
            /*
            constructor
        * PRE:
        * POST: Crea un objeto bomba con una cantidad determinada
        */
        Bomba(int cantidad);
            /*
        * PRE:
        * POST:
        */
        virtual ~Bomba();
};



#endif //BOMBA_H
