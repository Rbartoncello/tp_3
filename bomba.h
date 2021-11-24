#ifndef BOMBA_H
#define BOMBA_H
#include "material.h"
class Bomba : public Material{
    private:
        string nombre;
        string emoji;
        int cantidad;
    public:
        Bomba();
        Bomba(int cantidad);
        ~Bomba();
};



#endif //BOMBA_H
