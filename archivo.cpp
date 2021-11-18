#include <fstream>
#include <iostream>
#include "archivo.h"

using namespace std;

Archivo::Archivo(string nombreArchivo){
    this->nombre_txt = nombreArchivo;
    validar_archivo();
}

void Archivo::validar_archivo(){
    ifstream archivo(nombre_txt);

    this->existe_archivo = archivo.is_open();

    if ( !existe_archivo )
        cout << "No se encontro un archivo con nombre \"" << nombre_txt << endl;
    archivo.close();
}

bool Archivo::devolver_existe_archivo(){
    return this->existe_archivo;
}

string Archivo::devolver_nombre_txt(){
    return this->nombre_txt;
}

Archivo::~Archivo(){}


