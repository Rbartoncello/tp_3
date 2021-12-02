#include "archivo.h"
#include "obelisco.h"
#include "mina.h"
#include "escuela.h"
#include "planta.h"
#include "constantes.h"
#include "fabrica.h"
#include "aserradero.h"
#include "mina_oro.h"
#include "andycoins.h"
#include "bomba.h"

Archivo::Archivo(){
}

int Archivo::leer_archivos_edificios(Diccionario<Edificacion>* &diccionario){
    int ejecucion = 1;

    ifstream archivo(PATH_EDIFICIO);
    string nombre, piedra, madera, metal, max_cant_permitidos, nombre_aux;
    Edificacion* edificio;


    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_EDIFICIO << endl;
        ejecucion = ERROR;
    } else {
        while ( archivo >> nombre ){
            if (nombre == PLANTA){
                archivo >> nombre_aux;
                nombre += " " + nombre_aux;
            }
            archivo >> piedra;
            if (piedra == "oro"){
                nombre += " " + piedra;
                archivo >> piedra;
            }
            archivo >> madera;
            archivo >> metal;
            archivo >> max_cant_permitidos;
            edificio = buscar_edificacion(nombre,  stoi(piedra), stoi(madera), stoi(metal), stoi(max_cant_permitidos));
            diccionario->insertar(nombre,edificio);
        }
        archivo.close();
    }
    return ejecucion;
}

Edificacion* Archivo::buscar_edificacion(string nombre, int piedra, int madera, int metal, int max_cant_permitidos){
    Edificacion* edificio;
    
    if (nombre == EDIFICIO_ASERRADERO)
        edificio = new Aserradero(piedra, madera, metal, max_cant_permitidos);
    else if (nombre == EDIFICIO_ESCUELA)
        edificio = new Escuela(piedra, madera, metal, max_cant_permitidos);
    else if (nombre == EDIFICIO_FABRICA)
        edificio = new Fabrica(piedra, madera, metal, max_cant_permitidos);
    else if (nombre == EDIFICIO_MINA)
        edificio = new Mina(piedra, madera, metal, max_cant_permitidos);
    else if (nombre == EDIFICIO_MINA_ORO)
        edificio = new Mina_oro(piedra, madera, metal, max_cant_permitidos);
    else if (nombre == EDIFICIO_OBELISCO)
        edificio = new Obelisco(piedra, madera, metal, max_cant_permitidos);
    else if (nombre == EDIFICIO_PLANTA_ELECTRICA)
        edificio = new Planta(piedra, madera, metal, max_cant_permitidos);
    
    return edificio;
}

int Archivo::leer_archivos_materiales(Lista<Material> *&inventario_jugador_1, Lista<Material> *&inventario_jugador_2){
    int ejecucion = 1;

    ifstream archivo(PATH_MATERIALES);

    string nombre, cantidad_jugador_1, cantidad_jugador_2;

    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_MATERIALES << endl;
        ejecucion = ERROR;
    } else {
        Material* material;
        while (archivo >> nombre){
            archivo >> cantidad_jugador_1;
            archivo >> cantidad_jugador_2;
            material = generar_material(nombre,stoi(cantidad_jugador_1));
            inventario_jugador_1->agregar_elemento(material,1);
            material = generar_material(nombre, stoi(cantidad_jugador_2));
            inventario_jugador_2->agregar_elemento(material, 1);   
        }
    }

    archivo.close();
    return ejecucion;
}

Material* Archivo::generar_material(string nombre, int cantidad){
    Material *material;

    if (nombre == PIEDRA)
        material = new Piedra(cantidad);
    else if (nombre == MADERA)
        material = new Madera(cantidad);
    else if (nombre == METAL)
        material = new Metal(cantidad);
    else if (nombre == ANDYCOINS)
        material = new Andycoins(cantidad);
    else if (nombre == BOMBA)
        material = new Bomba(cantidad);

    return material;
}

int Archivo::leer_archivo_ubicaciones(Mapa* &mapa, Diccionario<Edificacion>* &diccionario, Jugador* &jugador_1, Jugador* &jugador_2){
    int ejecucion = 1;

    ifstream documento(PATH_UBICACIONES);

    if (!documento.is_open()){
        ejecucion = ERROR;
    } else {
        ejecucion = leer_ubicaciones_materiales(documento,mapa, jugador_1);
        if (ejecucion != ERROR){
            leer_edificios_jugador_1(documento,mapa, diccionario, jugador_2);     
            leer_edificios_jugador_2(documento,mapa, diccionario);
        }
        documento.close();
    }
    return ejecucion;
}


int Archivo::leer_ubicaciones_materiales(ifstream &documento,Mapa* &mapa, Jugador* &jugador){
    int ejecucion = 1;

    bool leyendo_materiales = true;

    string nombre_material;
    string fila, columna;
    int clean_fila, clean_columna;

    while (leyendo_materiales){

        if (documento >> nombre_material){
            if (nombre_material != "1"){
            documento >> fila;
            documento >> columna;
            clean_fila = arreglarCoordenadaX(fila);
            clean_columna = arreglarCoordenadaY(columna);
            
            mapa->agregar_material(nombre_material,clean_fila, clean_columna);
            } else {
                documento >> fila;
                documento >> columna;
                jugador->modificar_fila(arreglarCoordenadaX(fila));
                jugador->modificar_columna(arreglarCoordenadaY(columna));

                agregar_posicion_jugador(mapa, jugador);
                leyendo_materiales = false;
            }
        } else {
            leyendo_materiales = false;
            ejecucion = ERROR;
        }
    }
    return ejecucion;
}


void Archivo::leer_edificios_jugador_2(ifstream &documento,Mapa* &mapa, Diccionario<Edificacion>*&diccionario){
    string nombre_edificio;

    while (documento >> nombre_edificio)
        agregar_edificio(documento, nombre_edificio,mapa, diccionario, JUGADOR_2);

}

void Archivo::leer_edificios_jugador_1(ifstream &documento, Mapa* &mapa, Diccionario<Edificacion>*&diccionario, Jugador* &jugador){

    bool leyendo_edificios_P1 = true;

    string nombre_edificio, segundo_nombre;
    string fila, columna;

    while (leyendo_edificios_P1){
        documento >> nombre_edificio;
        if (nombre_edificio != "2")
            agregar_edificio(documento,nombre_edificio,mapa, diccionario, JUGADOR_1);
        else{
            documento >> fila;
            documento >> columna;
            jugador->modificar_fila(arreglarCoordenadaX(fila));
            jugador->modificar_columna(arreglarCoordenadaY(columna));

            agregar_posicion_jugador(mapa, jugador);
            leyendo_edificios_P1 = false;
        }
    }
}

void Archivo::agregar_edificio(ifstream &documento,string nombre_edificio, Mapa* &mapa, Diccionario<Edificacion>*&diccionario, int propietario){
    string segundo_nombre, fila, columna;
    int clean_fila, clean_columna;

    if (nombre_edificio == PLANTA){
        documento >> segundo_nombre;
        nombre_edificio = nombre_edificio + " " + segundo_nombre;
    }

    documento >> fila;

    if (fila == ORO){
        segundo_nombre = fila;
        nombre_edificio = nombre_edificio + " " + segundo_nombre;
        documento >> fila;
    }

    documento >> columna;

    clean_fila = arreglarCoordenadaX(fila);
    clean_columna = arreglarCoordenadaY(columna);
    
    int piedra = diccionario->buscar(nombre_edificio)->devolver_receta()->devoler_piedra();
    int madera = diccionario->buscar(nombre_edificio)->devolver_receta()->devoler_madera();
    int metal = diccionario->buscar(nombre_edificio)->devolver_receta()->devoler_metal();
    int max_cant_permitidos = diccionario->buscar(nombre_edificio)->devolver_maxima_cantidad_permitidos();
    
    mapa->agregar_edificacion(buscar_edificacion(nombre_edificio,  piedra, madera, metal, max_cant_permitidos), clean_fila,clean_columna, propietario);
}

int Archivo::arreglarCoordenadaX(string fila){
    fila = fila.substr(1);
    fila.pop_back();


    return (stoi(fila));
}

int Archivo::arreglarCoordenadaY(string columna){
    columna.pop_back();
    return (stoi(columna));
}

void Archivo::agregar_posicion_jugador(Mapa *&mapa, Jugador* &jugador) {
    mapa->agregar_jugador(jugador);
}

Archivo::~Archivo(){}

