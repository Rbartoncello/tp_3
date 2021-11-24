#include "archivo.h"

/*
 *
 *  Tenemos que discutir si la lectura de Mapa la hacemos en esta unica clase o en cada una
 *
 *
 *  de las clases
 *
 *
 */

Archivo::Archivo(){
}

int Archivo::leer_archivos_edificios(Diccionario* &diccionario)  {
    ifstream archivo(PATH_EDIFICIO);
    string nombre, piedra, madera, metal, max_cant_permitidos, nombre_aux;

    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_EDIFICIO << endl;
        return ERROR;
    } else {
        while ( archivo >> nombre ){
            if (nombre == PLANTA){
                archivo >> nombre_aux;
                nombre += " " + nombre_aux;
            }
            archivo >> piedra;
            archivo >> madera;
            archivo >> metal;
            archivo >> max_cant_permitidos;

            diccionario->insertar(new Edificio (nombre,  stoi(piedra), stoi(madera), stoi(metal), stoi(max_cant_permitidos)));
        }
        archivo.close();
    }

    string nombre_edificio = "fabrica";
    cout << endl << "Piedra: " << diccionario->buscar(nombre_edificio)->devoler_piedra() << " Madera: " << diccionario->buscar(nombre_edificio)->devoler_madera() << " Metal: " << diccionario->buscar(nombre_edificio)->devoler_metal() << endl;


    return 1;
}


int Archivo::leer_archivos_materiales(Inventario *&inventario_jugador_1, Inventario *&inventario_jugador_2)
{

    ifstream archivo(PATH_MATERIALES);

    string nombre, cantidad_jugador_1, cantidad_jugador_2;

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo: " << PATH_MATERIALES << endl;
        return ERROR;
    }
    else
    {
        while (archivo >> nombre)
        {
            archivo >> cantidad_jugador_1;
            archivo >> cantidad_jugador_2;
            inventario_jugador_1->agregar_material(nombre, stoi(cantidad_jugador_1));
            inventario_jugador_2->agregar_material(nombre, stoi(cantidad_jugador_2));
        }
    }
    archivo.close();

    return 0;
}

int Archivo::leer_archivo_ubicaciones(Mapa* &mapa)
{
    string jugador_2 = "2";

    ifstream documento(PATH_UBICACIONES);

    if (!documento.is_open())
    {
        cout << "No se pudo abrir el archivo: " << PATH_MATERIALES << endl;
        return ERROR;
    }

    leer_ubicaciones_materiales(documento,mapa);

    leer_edificios_jugador1(documento, jugador_2,mapa);

    leer_edificios_jugador2(documento,mapa);

    documento.close();

    return 0;
}


void Archivo::leer_ubicaciones_materiales(ifstream &documento,Mapa* &mapa)
{

    bool leyendoMateriales = true;

    string nombre_edificio, segundoNombre, nombreMaterial;
    string coordX, coordY;
/*     int cleanCoordX, cleanCoordY;
 */
    while (leyendoMateriales)
    {
        documento >> nombreMaterial;
        if (nombreMaterial != "1")
        {
            documento >> coordX;
            documento >> coordY;
            /* cleanCoordX = arreglarCoordenadaX(coordX);
            cleanCoordY = arreglarCoordenadaY(coordY); */
            //agregar material a casillero
        }
        else
        {
            documento >> coordX;
            documento >> coordY;
            agregar_posicion_jugador(coordX,coordY,mapa);
            cout << "El jugador 1 estaria en (" << coordX << ", " << coordY << ")" << endl;
            leyendoMateriales = false;
        }
    }
}


void Archivo::agregar_posicion_jugador(string coordX, string coordY,Mapa* &mapa){

    /* int cleanCoordX = arreglarCoordenadaX(coordX);
    int cleanCoordY = arreglarCoordenadaY(coordY); */

}

void Archivo::leer_edificios_jugador2(ifstream &documento,Mapa* &mapa){

    string nombre_edificio;

    while (documento >> nombre_edificio)
    {
        agregar_edificio(documento, nombre_edificio,mapa);
    }
}


void Archivo::leer_edificios_jugador1(ifstream &documento, string jugador, Mapa* &mapa)
{

    bool leyendo_edificios_P1 = true;

    string nombre_edificio, segundoNombre;
    string coordX, coordY;

    while (leyendo_edificios_P1)
    {
        documento >> nombre_edificio;
        if (nombre_edificio != "2")
        {
            agregar_edificio(documento,nombre_edificio,mapa);
        }
        else
        {
            documento >> coordX;
            documento >> coordY;
            agregar_posicion_jugador(coordX,coordY,mapa);
            cout << "El jugador 2 estaria en (" << coordX << ", " << coordY << ")" << endl;
            leyendo_edificios_P1 = false;
        }
    }
}

void Archivo::agregar_edificio(ifstream &documento,string nombre_edificio, Mapa* &mapa)
{
    string segundoNombre, coordX, coordY;
    int cleanCoordX, cleanCoordY;

    if (nombre_edificio == "planta")
    {
        documento >> segundoNombre;
        nombre_edificio = nombre_edificio + " " + segundoNombre;
    }

    documento >> coordX;

    if (coordX == "oro")
    {
        segundoNombre = coordX;
        nombre_edificio = nombre_edificio + " " + segundoNombre;
        documento >> coordX;
        
        cout << "Mina de oro encontrada";
    }

    documento >> coordY;

    cleanCoordX = arreglarCoordenadaX(coordX);
    cleanCoordY = arreglarCoordenadaY(coordY);

    mapa->construirEdificio(cleanCoordX,cleanCoordY,nombre_edificio);
}

int Archivo::arreglarCoordenadaX(string coordX)
{

    coordX = coordX.substr(1);
    coordX.pop_back();

    return (stoi(coordX));
}

int Archivo::arreglarCoordenadaY(string coordY)
{

    coordY.pop_back();
    return (stoi(coordY));
}

Archivo::~Archivo(){
}
