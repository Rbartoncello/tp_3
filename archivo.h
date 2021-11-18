#ifndef ARCVHIVO_H
#define ARCVHIVO_H
#include<string>
#include<fstream>

using namespace std;

class Archivo{
    private:
        string nombre_txt;
        bool existe_archivo;
    public:
        //Pre: Debe recibir el nombre del Archivo.
        //Post: crea la Lista.
        Archivo(string nombreArchivo);

        //Pre:
        //Post: Recorre el txt de forma polimorfica.
        virtual void leer_archivo() = 0;

        //Pre:
        //Post:Retorna el nombre del archivo.
        string devolver_nombre_txt();

        //Pre:-
        //Post: Devuelve el estado del la variable existe_archivo, tiene almacenada si el archivo se leyo correctamente.
        bool devolver_existe_archivo(); 

        virtual ~Archivo() = 0;   
    private:
        //Pre:Debe recibir el nombre del Archivo.
        //Post:valida si existe el Archivo.
        void validar_archivo();

};

#endif