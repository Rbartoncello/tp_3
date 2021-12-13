#include "archivo.h"
#include "bomba.h"

Archivo::Archivo()
{
}

int Archivo::leer_archivos_edificios(Diccionario<Edificacion> *&diccionario, Mapa *mapa)
{
    int ejecucion = 1;

    ifstream archivo(PATH_EDIFICIO);
    string nombre, piedra, madera, metal, max_cant_permitidos, nombre_aux;
    Edificacion *edificio;

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo: " << PATH_EDIFICIO << endl;
        ejecucion = ERROR;
    }
    else
    {
        while (archivo >> nombre)
        {
            if (nombre == PLANTA)
            {
                archivo >> nombre_aux;
                nombre += " " + nombre_aux;
            }
            archivo >> piedra;
            if (piedra == "oro")
            {
                nombre += " " + piedra;
                archivo >> piedra;
            }
            archivo >> madera;
            archivo >> metal;
            archivo >> max_cant_permitidos;
            edificio = mapa->crear_edificio(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(max_cant_permitidos));
            diccionario->insertar(nombre, edificio);
        }
        archivo.close();
    }
    return ejecucion;
}

int Archivo::leer_archivos_materiales(Jugador *&jugador_1, Jugador *&jugador_2)
{
    int ejecucion = 1;

    ifstream archivo(PATH_MATERIALES);

    string nombre, cantidad_jugador_1, cantidad_jugador_2;

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo: " << PATH_MATERIALES << endl;
        ejecucion = ERROR;
    }
    else
    {
        Material *material;
        while (archivo >> nombre)
        {
            archivo >> cantidad_jugador_1;
            archivo >> cantidad_jugador_2;
            material = generar_material(nombre, stoi(cantidad_jugador_1));
            jugador_1->agregar_inventario(material);
            material = generar_material(nombre, stoi(cantidad_jugador_2));
            jugador_2->agregar_inventario(material);
        }
    }

    archivo.close();
    return ejecucion;
}

Material *Archivo::generar_material(string nombre, int cantidad)
{
    Material *material;

    if (nombre == PIEDRA)
        material = new Piedra(cantidad);
    else if (nombre == MADERA)
        material = new Madera(cantidad);
    else if (nombre == METAL)
        material = new Metal(cantidad);
    else if (nombre == ANDYCOINS)
        material = new Andycoins(cantidad);
    else
        material = new Bomba(cantidad);

    return material;
}

int Archivo::leer_archivo_ubicaciones(Mapa *&mapa, Diccionario<Edificacion> *&diccionario, Jugador *&jugador_1, Jugador *&jugador_2)
{
    int ejecucion = 1;

    ifstream documento(PATH_UBICACIONES);

    if (!documento.is_open())
    {
        ejecucion = ERROR;
    }
    else
    {
        ejecucion = leer_ubicaciones_materiales(documento, mapa, jugador_1);
        if (ejecucion != ERROR)
        {
            leer_edificios_jugador_1(documento, mapa, diccionario, jugador_2, jugador_1->devolver_mis_edificios());
            leer_edificios_jugador_2(documento, mapa, diccionario, jugador_2->devolver_mis_edificios());
        }
        documento.close();
    }
    return ejecucion;
}

int Archivo::leer_ubicaciones_materiales(ifstream &documento, Mapa *&mapa, Jugador *&jugador)
{
    int ejecucion = 1;

    bool leyendo_materiales = true;

    string nombre_material;
    string fila, columna;
    int clean_fila, clean_columna;

    while (leyendo_materiales)
    {

        if (documento >> nombre_material)
        {
            if (nombre_material != "1")
            {
                documento >> fila;
                documento >> columna;
                clean_fila = arreglarCoordenadaX(fila);
                clean_columna = arreglarCoordenadaY(columna);

                mapa->agregar_material(nombre_material, clean_fila, clean_columna);
            }
            else
            {
                documento >> fila;
                documento >> columna;
                jugador->modificar_fila(arreglarCoordenadaX(fila));
                jugador->modificar_columna(arreglarCoordenadaY(columna));
                agregar_posicion_jugador(mapa, jugador);
                leyendo_materiales = false;
            }
        }
        else
        {
            leyendo_materiales = false;
            ejecucion = ERROR;
        }
    }
    return ejecucion;
}

void Archivo::leer_edificios_jugador_1(ifstream &documento, Mapa *&mapa, Diccionario<Edificacion> *&diccionario, Jugador *&jugador, Lista_edificios<Edificacion> *&edificios_jugador)
{

    bool leyendo_edificios_P1 = true;

    string nombre_edificio, segundo_nombre;
    string fila, columna;

    while (leyendo_edificios_P1)
    {
        documento >> nombre_edificio;
        if (nombre_edificio != "2")
            agregar_edificio(documento, nombre_edificio, mapa, diccionario, JUGADOR_1, edificios_jugador);
        else
        {
            documento >> fila;
            documento >> columna;
            jugador->modificar_fila(arreglarCoordenadaX(fila));
            jugador->modificar_columna(arreglarCoordenadaY(columna));
            agregar_posicion_jugador(mapa, jugador);
            leyendo_edificios_P1 = false;
        }
    }
}

void Archivo::leer_edificios_jugador_2(ifstream &documento, Mapa *&mapa, Diccionario<Edificacion> *&diccionario, Lista_edificios<Edificacion> *&edificios_jugador)
{
    string nombre_edificio;

    while (documento >> nombre_edificio)
        agregar_edificio(documento, nombre_edificio, mapa, diccionario, JUGADOR_2, edificios_jugador);
}

void Archivo::agregar_edificio(ifstream &documento, string nombre_edificio, Mapa *&mapa, Diccionario<Edificacion> *&diccionario, int propietario, Lista_edificios<Edificacion> *&edificios_jugador)
{
    string segundo_nombre, fila, columna;
    int clean_fila, clean_columna;

    if (nombre_edificio == PLANTA)
    {
        documento >> segundo_nombre;
        nombre_edificio = nombre_edificio + " " + segundo_nombre;
    }

    documento >> fila;

    if (fila == ORO)
    {
        segundo_nombre = fila;
        nombre_edificio = nombre_edificio + " " + segundo_nombre;
        documento >> fila;
    }

    documento >> columna;

    clean_fila = arreglarCoordenadaX(fila);
    clean_columna = arreglarCoordenadaY(columna);

    mapa->agregar_edificacion(nombre_edificio, clean_fila, clean_columna, propietario, edificios_jugador);
}

int Archivo::arreglarCoordenadaX(string fila)
{
    fila = fila.substr(1);
    fila.pop_back();

    return (stoi(fila));
}

int Archivo::arreglarCoordenadaY(string columna)
{
    columna.pop_back();
    return (stoi(columna));
}

void Archivo::agregar_posicion_jugador(Mapa *&mapa, Jugador *&jugador)
{
    mapa->agregar_jugador(jugador);
}

void Archivo::escribir_archivos(Jugador *&jugador_1, Jugador *&jugador_2, Mapa *mapa)
{
    escribir_archivo_materiales(jugador_1, jugador_2);
    escribir_archivo_ubicaciones(mapa, jugador_1, jugador_2);
}

void Archivo::escribir_archivo_materiales(Jugador *&jugador_1, Jugador *&jugador_2)
{
    Nodo_lista<Material> *materiales_jugador_1 = jugador_1->devolver_inventario()->retornar_primero();
    Nodo_lista<Material> *materiales_jugador_2 = jugador_2->devolver_inventario()->retornar_primero();

    int cantidad_en_lista = jugador_1->devolver_inventario()->devolver_cantidad_en_lista(), cantidad_1 = 0, cantidad_2 = 0;
    string nombre_material;

    fstream documento(PATH_MATERIALES, ios::out);

    for (int i = 0; i < cantidad_en_lista; i++)
    {
        nombre_material = materiales_jugador_1->devolver_dato()->devolver_nombre();
        cantidad_1 = materiales_jugador_1->devolver_dato()->devolver_cantidad();
        cantidad_2 = materiales_jugador_2->devolver_dato()->devolver_cantidad();
        documento << nombre_material << " " << cantidad_1 << " " << cantidad_2 << endl;
        materiales_jugador_1 = materiales_jugador_1->direccion_siguiente();
        materiales_jugador_2 =  materiales_jugador_2->direccion_siguiente();
    }

    documento.close();
}

void Archivo::escribir_archivo_ubicaciones(Mapa *mapa, Jugador *jugador_1, Jugador *jugador_2)
{
    Lista_edificios<Edificacion> *edificio_jugador_1 = jugador_1->devolver_mis_edificios();
    Lista_edificios<Edificacion> *edificio_jugador_2 = jugador_2->devolver_mis_edificios();

    fstream documento(PATH_UBICACIONES, ios::out);

    guardar_materiales_en_mapa(mapa, documento);

    documento << 1 << " (" << jugador_1->devolver_fila() << ", " << jugador_1->devolver_columna() << ")" << endl;

    guardar_edificios_jugador(edificio_jugador_1, documento);

    documento << 2 << " (" << jugador_2->devolver_fila() << ", " << jugador_2->devolver_columna() << ")" << endl;

    guardar_edificios_jugador(edificio_jugador_2, documento);

    documento.close();
}

void Archivo::guardar_edificios_jugador(Lista_edificios<Edificacion> *edificio_jugador, fstream &documento)
{
    Nodo_edificios<Edificacion> *primero = edificio_jugador->retornar_primero();
    int cantidad_en_lista = edificio_jugador->devolver_cantidad_en_Lista_edificios(), fila = 0, columna = 0;
    Edificacion *edificio;
    string nombre_edificio;

    for (int i = 0; i < cantidad_en_lista; i++)
    {
        edificio = primero->devolver_dato();
        nombre_edificio = edificio->devolver_nombre_edificio();
        fila = edificio->devolver_fila();
        columna = edificio->devolver_columna();
        documento << nombre_edificio << " (" << fila << ", " << columna << ")" << endl;
        primero = primero->direccion_siguiente();
    }
}

void Archivo::guardar_materiales_en_mapa(Mapa *mapa, fstream &documento)
{

    Casillero ***casillero = mapa->devolver_puntero_casillero();
    int filas = mapa->devolver_cantidad_filas(), columnas = mapa->devolver_cantidad_columnas();

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (casillero[i][j]->esta_ocupado() && mapa->validar_tipo_transitable(i,j) )
            {
                if (casillero[i][j]->devolver_material() != nullptr)
                    documento << casillero[i][j]->devolver_material()->devolver_nombre() << " (" << i << ", " << j << ")" << endl;
            }
        }
    }
}

Archivo::~Archivo() {}
