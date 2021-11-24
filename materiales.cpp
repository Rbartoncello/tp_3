#include <iostream>
#include <fstream>
#include "materiales.h"
#include "constantes.h"

Materiales::Materiales() {
    this->total_materiales = 0;
}

Materiales::~Materiales(){
    for (int i = 0; i < this->total_materiales; i++){
        delete this->materiales[i];
    }
    delete [] this->materiales;
}

/* int Materiales::leer_archivo() {

    ifstream archivo(PATH_MATERIALES);

    string nombre, cantidad_jugador_1, cantidad_jugador_2;

    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_MATERIALES << endl;
        return ERROR;
        
    } else {
        while ( archivo >> nombre ){
            archivo >> cantidad_jugador_1;
            archivo >> cantidad_jugador_2;
            agregar_material(new Material(nombre, stoi(cantidad_jugador_1), stoi(cantidad_jugador_2)));
        }
    }

    archivo.close();
    
    return 0;
} */

/* void Materiales::agregar_material(Material* material){

    int tope_viejo = this->total_materiales;

    Material** nuevos_materiales = new Material* [ tope_viejo + 1 ];

    for ( int i = 0; i < tope_viejo; i++ )
        nuevos_materiales[i] = this->materiales[i];

    nuevos_materiales[tope_viejo] = material;

    if ( this->total_materiales != 0 )
        delete [] this->materiales;

    this->materiales = nuevos_materiales;
    this->total_materiales++;
} */

void Materiales::mostrar() {
    for (int i = 0; i < this->total_materiales; i++)
        this->materiales[i]->mostrar();
}
