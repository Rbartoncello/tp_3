#ifndef BOMBA_H
#define BOMBA_H
#include "material.h"
class Bomba : public Material{
    private:

    public:
        Bomba();
        Bomba(int cantidad);
        virtual ~Bomba();
};



#endif //BOMBA_H
