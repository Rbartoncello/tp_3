#include <iostream>

#include <iomanip>
#include "mapa.h"
#include "interface.h"
#include "constantes.h"
#include "camino.h"
#include "betun.h"
#include "lago.h"
#include "muelle.h"
#include "terreno.h"

Mapa::Mapa()
{
    this->cantidad_filas = 0;
    this->cantidad_columnas = 0;
    this->casilleros = nullptr;
}

Mapa::~Mapa()
{
    for (int i = 0; i < this->cantidad_filas; i++)
    {
        for (int j = 0; j < this->cantidad_columnas; j++)
        {
            delete this->casilleros[i][j];
        }
        delete[] this->casilleros[i];
    }
    delete[] this->casilleros;
    this->casilleros = nullptr;
}

void Mapa::crear_matriz_casilleros()
{
    this->casilleros = new Casillero **[this->cantidad_filas];
    for (int i = 0; i < this->cantidad_filas; i++)
    {
        casilleros[i] = new Casillero *[this->cantidad_columnas];
        for (int j = 0; j < this->cantidad_columnas; j++)
        {
            casilleros[i][j] = nullptr;
        }
    }
}


void Mapa::agregar_casillero(ifstream &archivo)
{
    char tipo_terreno;
    for (int i = 0; i < this->cantidad_filas; i++)
    {
        for (int j = 0; j < this->cantidad_columnas; j++)
        {
            if (archivo >> tipo_terreno)
            {
                switch (tipo_terreno)
                {
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

int Mapa::leer_archivo()
{
    ifstream archivo(PATH_MAPA);

    if (!(archivo.is_open()))
    {
        cout << "No se puedo abrir el archivo: " << PATH_MAPA << endl;
        return ERROR;
    }
    else
    {
        string fila, columna;

        if (archivo >> fila)
        {
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

void Mapa::mostrar()
{
    system("clear");

    for (int i = 0; i <= this->cantidad_columnas + 1; i++)
    {
        if (i == 0)
            cout << "\t";
        cout << BGND_BROWN_137 << "  " << END_COLOR;
    }
    cout << endl;

    for (int i = 0; i < this->cantidad_filas; i++)
    {
        cout << "\t" << BGND_BROWN_137 << "  " << END_COLOR;
        for (int j = 0; j < this->cantidad_columnas; j++)
        {
            this->casilleros[i][j]->mostrar();
        }
        if (i < 10)
            cout << BGND_BROWN_137 << TXT_UNDERLINE << TXT_LIGHT_BLUE_33 << TXT_BOLD << i << " " << END_COLOR;
        else
            cout << BGND_BROWN_137 << TXT_UNDERLINE << TXT_LIGHT_BLUE_33 << TXT_BOLD << i << END_COLOR;
        cout << endl;
    }

    for (int i = 0; i <= this->cantidad_columnas; i++)
    {
        if (i == 0)
            cout << "\t" << BGND_BROWN_137 << "  " << END_COLOR;
        if ((i < this->cantidad_columnas) && (i < 10))
            cout << BGND_BROWN_137 << i << " " << END_COLOR;
        else if ((i < this->cantidad_columnas))
            cout << BGND_BROWN_137 << i << END_COLOR;
        else if (i == this->cantidad_columnas)
            cout << BGND_BROWN_137 << "  " << END_COLOR;
    }

    imprimir_objetos_mapa();

    cout << endl;
}

void Mapa::agregar_material(string nombre, int fila, int columna){
    this->casilleros[fila][columna]->agregar_material( buscar_material(nombre) );
}

Material* Mapa::buscar_material(string nombre) {
    Material *material;

    if (nombre == PIEDRA)
        material = new Piedra(LLUVIA_GENERA_PIEDRA);
    else if (nombre == MADERA)
        material = new Madera(LLUVIA_GENERA_MADERA);
    else if (nombre == METAL)
        material = new Metal(LLUVIA_GENERA_METAL);
    else if (nombre == ANDYCOINS)
        material = new Andycoins(LLUVIA_GENERA_ANDYCOINS);

    return material;
}

void Mapa::agregar_jugador(Jugador* jugador){
    casilleros[jugador->devolver_fila()][jugador->devolver_columna()]->agregar_jugador(jugador);
}

void Mapa::mover_jugador(Jugador* jugador, int fila , int columna){
    casilleros[jugador->devolver_fila()][jugador->devolver_columna()]->eliminar_jugador();
    jugador->modificar_fila(fila);
    jugador->modificar_columna(columna);
    casilleros[fila][columna]->mover_jugador(jugador);
}

Casillero* Mapa::devolver_casillero(int fila, int columna)
{
    return casilleros[fila][columna];
}

int Mapa::cantidad_edificio_construido(string nombre){
    int cantidad = 0;
    for (int i = 0; i < this->cantidad_filas; i++)
    {
        for (int j = 0; j < this->cantidad_columnas; j++)
        {
            if (this->casilleros[i][j]->devolver_tipo_terreno() == TERRENO && this->casilleros[i][j]->esta_ocupado() && this->casilleros[i][j]->devolver_nombre_edificio() == nombre)
            {
                cantidad++;
            }
        }
    }
    return cantidad;
}

bool Mapa::validar_tipo_construible(int fila, int columna){
    return ( ( devolver_tipo_terreno(fila, columna) == TERRENO ) );
}

bool Mapa::validar_tipo_transitable(int fila, int columna){
    return ( ( devolver_tipo_terreno(fila, columna) == CAMINO ) );
}



char Mapa::devolver_tipo_terreno(int fila, int columna){
    return casilleros[fila][columna]->devolver_tipo_terreno();
}

void Mapa::agregar_edificacion(Edificacion* edificacion, int fila, int columna, int duenio) {
    if ( validar_tipo_construible(fila, columna) ){
        edificacion->modificar_duenio(duenio);
        this->casilleros[fila][columna]->agregar_edificio(edificacion);
    }
}

int Mapa::devolver_cantidad_columnas()
{
    return this->cantidad_columnas;
}

int Mapa::devolver_cantidad_filas()
{
    return this->cantidad_filas;
}

void Mapa::imprimir_resumen_casillero(int fila, int columna)
{
    this->casilleros[fila][columna]->imprimir_resumen();
}

void Mapa::mostrar_edificios_construidos(Jugador* jugador_actual){
    system("clear");

    cout << TXT_BOLD;
    cout << "\t\t╔═══════════════════════╦══════╦═════════╦══════════════════════╦═════════════════════╗" << endl;
    cout << "\t\t║ Edificios construidos ║ Fila ║ Columna ║ Cantidad construidos ║ Necesita reparacion ║" << endl;
    cout << "\t\t╠═══════════════════════╬══════╬═════════╬══════════════════════╬═════════════════════╣" << endl;
    cout << END_COLOR;

    bool hay_edificios = false;

    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            if ( ( this->casilleros[i][j]->devolver_tipo_terreno() == TERRENO ) && ( this->casilleros[i][j]->esta_ocupado() ) ){
                hay_edificios = true;

                this->casilleros[i][j]->mostrar_casillero(jugador_actual, this->cantidad_edificio_construido(this->casilleros[i][j]->devolver_nombre_edificio()));
                if( ( i == this->cantidad_filas - 1 ) && ( j == this->cantidad_columnas - 1 ) )
                    cout << "\t\t╚═══════════════════════╩══════╩═════════╩══════════════════════╩═════════════════════╝" << endl;
            }
        }
    }

    if (!hay_edificios){
        cout << TXT_BOLD;
        cout << "\t\t║ " << TXT_RED_196 << setfill(' ') << setw(49) << "NO HAY NINGUN EDIFICIO CONSTRUIDO" << setfill(' ') << setw(16) << END_COLOR << " ║" << endl;
        cout << "\t\t╚═══════════════════════════════════════════════════════════════╝" << endl;
    }
    
}
