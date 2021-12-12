#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H

#include <string>

using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    string nombre;

/*MÉTODOS*/
public:
        /*
    * PRE:
    * POST:
    */
    Vertice(string nombre);

    //post: obtiene el nombre del vertice
    string devolver_nombre();

    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
