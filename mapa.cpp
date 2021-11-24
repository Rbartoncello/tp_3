#include <iostream>
#include "mapa.h"
#include "constantes.h"
#include "camino.h"
#include "betun.h"
#include "lago.h"
#include "muelle.h"
#include "terreno.h"

Mapa::Mapa(){
    this->cantidad_filas = 0;
    this->cantidad_columnas = 0;
    this->casilleros = nullptr;
}

Mapa::~Mapa(){
    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            delete this->casilleros[i][j];
        }
        delete [] this->casilleros[i];
    }
    delete[] this->casilleros;
    this->casilleros = nullptr;
}

void Mapa::crear_matriz_casilleros(){
    this->casilleros = new Casillero**[this->cantidad_filas];
    for (int i = 0; i < this->cantidad_filas; i++){
        casilleros[i] = new Casillero*[this->cantidad_columnas];
        for (int j = 0; j < this->cantidad_columnas; j++){
            casilleros[i][j] = nullptr;
        }
    }
}

void Mapa::agregar_casillero(ifstream &archivo){
    char tipo_terreno;
    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            if(archivo >> tipo_terreno){
                switch (tipo_terreno){
                    case LAGO:
                        this->casilleros[i][j] = new Lago(tipo_terreno, j, i);
                        break;
                    case CAMINO:
                        this->casilleros[i][j] = new Camino(tipo_terreno, j, i);
                        break;
                    case BETUN:
                        this->casilleros[i][j] = new Betun(tipo_terreno, j, i);
                        break;
                    case MUELLE:
                        this->casilleros[i][j] = new Muelle(tipo_terreno, j, i);
                        break;
                    case TERRENO:
                        this->casilleros[i][j] = new Terreno(tipo_terreno, j, i);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

int Mapa::leer_archivo() {
    ifstream archivo(PATH_MAPA);
    
    if (!(archivo.is_open())){
        cout << "No se puedo abrir el archivo: " << PATH_MAPA << endl;
        return ERROR;
    } else {
        string fila, columna;

        if(archivo >> fila){
            archivo >> columna;

            this->cantidad_filas = stoi(fila);
            this->cantidad_columnas = stoi(columna);

            crear_matriz_casilleros();

            agregar_casillero(archivo);
        }
        archivo.close();
    }
    return 0;
}

void Mapa::mostrar(){
    system("clear");

    for (int i = 0; i <= this->cantidad_columnas + 1; i++){
        if (i == 0)
            cout << "\t";
        cout << BGND_BROWN_137 << "  " << END_COLOR;
    }
    cout << endl;

    for (int i = 0; i < this->cantidad_filas; i++){
        cout << "\t" << BGND_BROWN_137 << "  " << END_COLOR;
        for (int j = 0; j < this->cantidad_columnas; j++){
            this->casilleros[i][j]->mostrar();
        }
        if ( i < 10 )
            cout << BGND_BROWN_137 << TXT_UNDERLINE << TXT_LIGHT_BLUE_33 << TXT_BOLD << i << " " << END_COLOR;
        else
            cout << BGND_BROWN_137 << TXT_UNDERLINE << TXT_LIGHT_BLUE_33 << TXT_BOLD << i << END_COLOR;
        cout << endl;
    }

    for (int i = 0; i <= this->cantidad_columnas; i++){
        if (i == 0)
            cout << "\t" << BGND_BROWN_137 << "  " << END_COLOR;
        if ( ( i < this->cantidad_columnas ) && ( i < 10 ) )
            cout << BGND_BROWN_137 << i << " " << END_COLOR;
        else if ( ( i < this->cantidad_columnas ))
            cout << BGND_BROWN_137 << i << END_COLOR;
        else if ( i == this->cantidad_columnas )
            cout << BGND_BROWN_137 << "  " << END_COLOR;
    }

    cout << endl;
}

void Mapa::construirEdificio(int coordX, int coordY, string nuevo_edificio,Diccionario* dict)
{
    if (validar_tipo_construible(coordX, coordY))
    {
        casilleros[coordX][coordY]->modificar_terreno(nuevo_edificio, CONSTRUYENDO, dict);
    }

    cout << "Por aqui paso: " + nuevo_edificio << endl;
}

void Mapa::agregar_jugador(int coordX, int coordY)
{
    //casilleros[coordX][coordY]->modificar_terreno();

}


int Mapa::cantidad_edificio_construido(string nombre){
    int cantidad = 0;
    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            if ( this->casilleros[i][j]->devolver_tipo_terreno() == TERRENO && this->casilleros[i][j]->esta_ocupado() && this->casilleros[i][j]->devolver_nombre_edificio()==nombre){
                cantidad ++;
            }
        }
    }
    return cantidad;
}

bool Mapa::validar_tipo_construible(int coord1, int coord2){

    return ((devolver_tipo_terreno(coord1, coord2) == TERRENO));
}

char Mapa::devolver_tipo_terreno(int coord1, int coord2)
{
    return casilleros[coord1][coord2]->devolver_tipo_terreno();
}
