#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "mapa.h"
#include "constantes.h"
#include "camino.h"
#include "betun.h"
#include "lago.h"
#include "muelle.h"
#include "terreno.h"
 #include "interface.h"

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

int Mapa::devolver_cantidad_edificio(string nombre_edificio_nuevo)
{
    int cantidad = 0;
    for (int i = 0; i < this->cantidad_filas; i++)
    {
        for (int j = 0; j < this->cantidad_columnas; j++)
        {
            if (this->casilleros[i][j]->devolver_tipo_terreno() == TERRENO && this->casilleros[i][j]->esta_ocupado() && this->casilleros[i][j]->devolver_nombre_edificio() == nombre_edificio_nuevo)
            {
                cantidad++;
            }
        }
    }
    return cantidad;
}

int Mapa::devolver_cantidad_edificio(string nombre_edificio_nuevo, Jugador *jugador)
{
    int cantidad = 0;
    for (int i = 0; i < this->cantidad_filas; i++)
    {
        for (int j = 0; j < this->cantidad_columnas; j++)
        {
            if (this->casilleros[i][j]->devolver_tipo_terreno() == TERRENO && this->casilleros[i][j]->esta_ocupado() && this->casilleros[i][j]->devolver_nombre_edificio() == nombre_edificio_nuevo)
            {
                if (jugador->devolver_numero() == this->devolver_casillero(i, j)->devolver_duenio())
                {
                    cantidad++;
                }
            }
        }
    }
    return cantidad;
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

void Mapa::agregar_material(string nombre, int fila, int columna)
{
    this->casilleros[fila][columna]->agregar_material(buscar_material(nombre));
}

Material *Mapa::buscar_material(string nombre)
{
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

void Mapa::agregar_jugador(Jugador *jugador)
{
    casilleros[jugador->devolver_fila()][jugador->devolver_columna()]->agregar_jugador(jugador);
}

void Mapa::mover_jugador(Jugador *jugador, int fila, int columna)
{
    casilleros[jugador->devolver_fila()][jugador->devolver_columna()]->eliminar_jugador();
    jugador->modificar_fila(fila);
    jugador->modificar_columna(columna);
    casilleros[fila][columna]->mover_jugador(jugador);
}

Casillero *Mapa::devolver_casillero(int fila, int columna)
{
    return casilleros[fila][columna];
}

bool Mapa::casillero_ocupado(int fila, int columna)
{
    return casilleros[fila][columna]->esta_ocupado();
}

int Mapa::cantidad_edificio_construido(string nombre)
{
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

bool Mapa::validar_tipo_construible(int fila, int columna)
{
    return ( casilleros[fila][columna]->devolver_tipo_terreno() == TERRENO ) ;
}

bool Mapa::validar_tipo_transitable(int fila, int columna)
{
    return ( ( casilleros[fila][columna]->devolver_tipo_terreno() != LAGO ) && ( casilleros[fila][columna]->devolver_tipo_terreno() != TERRENO ) );
}

bool Mapa::hay_edificio(int fila, int columna)
{
    return (devolver_casillero(fila, columna)->devolver_tipo_terreno() == TERRENO && devolver_casillero(fila, columna)->esta_ocupado());
}

char Mapa::devolver_tipo_terreno(int fila, int columna)
{
    return casilleros[fila][columna]->devolver_tipo_terreno();
}

void Mapa::agregar_edificacion(string nombre, int fila, int columna, int duenio, Lista_edificios<Edificacion> *&edificios_jugador)
{
    Edificacion *edificio = crear_edificio(nombre, 0, 0, 0, 0);

    edificio->modificar_duenio(duenio);
    edificio->agregar_direccion(fila, columna);
    casilleros[fila][columna]->agregar_edificio(edificio);
    edificios_jugador->agregar_elemento(edificio, 1);
}

Edificacion *Mapa::crear_edificio(string nombre, int piedra, int madera, int metal, int max_cant_permitidos)
{
    Edificacion *edificio = nullptr;

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

void Mapa::construir_edifcio(Jugador *jugador)
{
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

void Mapa::crear_lista(Lista_primitiva<string> *&nombre_edificios)
{
    nombre_edificios->agregar(EDIFICIO_ASERRADERO);
    nombre_edificios->agregar(EDIFICIO_ESCUELA);
    nombre_edificios->agregar(EDIFICIO_FABRICA);
    nombre_edificios->agregar(EDIFICIO_MINA);
    nombre_edificios->agregar(EDIFICIO_MINA_ORO);
    nombre_edificios->agregar(EDIFICIO_OBELISCO);
    nombre_edificios->agregar(EDIFICIO_PLANTA_ELECTRICA);
}

void Mapa::crear_lista_auxiliar_edificios(Lista_primitiva<int> *&cantidad_por_edificio)
{
    for (int i = 0; i < 7; i++)
        cantidad_por_edificio->agregar(0);
}

void Mapa::mostrar_edificios_construidos(Jugador *jugador_actual)
{
    system("clear");

    int cantidad, posicion_edificio_en_lista, cantidad_en_lista = jugador_actual->devolver_mis_edificios()->devolver_cantidad_en_Lista_edificios(), contador = 0;
    Nodo_edificios<Edificacion> *primero = jugador_actual->devolver_mis_edificios()->retornar_primero();
    Lista_primitiva<string> *nombre_edificios = new Lista_primitiva<string>();
    Lista_primitiva<int> *cantidad_por_edificio = new Lista_primitiva<int>();
    string nombre_de_edificio;

    crear_lista_auxiliar_edificios(cantidad_por_edificio);
    crear_lista(nombre_edificios);

    for (int i = 0; i < cantidad_en_lista; i++)
    {
        nombre_de_edificio = primero->devolver_dato()->devolver_nombre_edificio();
        posicion_edificio_en_lista = nombre_edificios->obtener_posicion_con_nombre(nombre_de_edificio);
        cantidad = cantidad_por_edificio->devolver_elemento_en_posicion(posicion_edificio_en_lista) + 1;
        cantidad_por_edificio->cambiar_dato(cantidad, posicion_edificio_en_lista);
        primero = primero->direccion_siguiente();
    }

    contador = imprimir_cantidad_edificios_jugador(nombre_edificios,cantidad_por_edificio);

    imprimir_edificios_jugador(jugador_actual->devolver_mis_edificios());

    imprimir_mensaje_enter_continuar2(contador);

    delete nombre_edificios;
    delete cantidad_por_edificio;
}

void Mapa::borrar_edificio(int fila, int columna)
{
    casilleros[fila][columna]->eliminar_edificio();
}

bool Mapa::hay_edicicio(int fila, int columna)
{
    return (devolver_casillero(fila, columna)->devolver_tipo_terreno() == TERRENO && devolver_casillero(fila, columna)->devolver_edificacion() != nullptr);
}


int Mapa::numero_aleatorio(int desde, int hasta){
    //srand((unsigned int)time(NULL));
    int numero = ( desde + rand() % hasta );
    
    while (numero > hasta)
        numero = ( desde + rand() % hasta );
    return numero;
}

bool Mapa::se_puede_generar_material(int fila, int columna){
    return ( !( casillero_ocupado(fila, columna) ) && ( this->casilleros[fila][columna]->devolver_tipo_terreno() != LAGO) && ( this->casilleros[fila][columna]->devolver_tipo_terreno() != TERRENO ) );
}

void Mapa::agregar_materiales(std::string material, int minimo, int maximo){
    int maximos_materiales = numero_aleatorio(minimo, maximo);

    for (int i = 0; i < maximos_materiales; i++){
        int fila_aleatoria = numero_aleatorio(0 , this->cantidad_filas);
        usleep(1000);
        int columna_aleatoria = numero_aleatorio(0 , this->cantidad_columnas);

        while ( !( se_puede_generar_material(fila_aleatoria, columna_aleatoria) ) ){
            fila_aleatoria = numero_aleatorio(0 , this->cantidad_filas);
            sleep(1);
            columna_aleatoria = numero_aleatorio(0 , this->cantidad_columnas);
        }
        this->agregar_material(material, fila_aleatoria, columna_aleatoria);
    }
}
bool Mapa::hay_lugar_minimo_material(){
    bool hay_lugar = false;
    int sumatoria_lugares = 0;
    int i = 0;
    int j = 0;

    while( ( i < this->devolver_cantidad_filas() ) && !(hay_lugar) ){
        while( ( j < this->devolver_cantidad_columnas() ) && !(hay_lugar) ){
            if(se_puede_generar_material(i, j))
                sumatoria_lugares++;
            if (sumatoria_lugares == 10)
                hay_lugar = true;
            else
                j++;
            
        }
        j = 0;
        i++;
    }

    return hay_lugar;
}

void Mapa::lluvia_recursos(){
    system("clear");
    if (hay_lugar_minimo_material()){
        
        cout << "\tLluvia de recursos ... " << EMOJI_LLUVIA << " " << EMOJI_LLUVIA_CON_TRUENOS << " " << EMOJI_LLUVIA << endl;
        cout << "\t[Por favor espere]" << endl;

        agregar_materiales(PIEDRA, MIN_GENERAR_PIEDRA, MAX_GENERAR_PIEDRA+1);
        agregar_materiales(MADERA, MIN_GENERAR_MADERA, MAX_GENERAR_MADERA+1);
        agregar_materiales(METAL, MIN_GENERAR_METAL, MAX_GENERAR_METAL+1);
        agregar_materiales(ANDYCOINS, MIN_GENERAR_ANDYCOINS, MAX_GENERAR_ANDYCOINS+1);

        system("clear");
        cout << TXT_BOLD;
        cout << "\tSe ha agregado recursos al mapa con exito " << EMOJI_HECHO << endl << endl;
        cout << END_COLOR;
    } else {
        cout << "No es posible agregar materiales en el mapa ya que no hay más lugar" << endl;
    }
    system("clear");
}

Casillero*** Mapa::devolver_puntero_casillero(){
    return casilleros;
}

bool Mapa::hay_algun_edificio_construido(){
    bool hay_edificio = false;
    int i = 0;

    while ( ( i < this->devolver_cantidad_filas() ) && !(hay_edificio) ){
        int j = 0;
        while( ( j < this->devolver_cantidad_filas() ) && !(hay_edificio) ){
            if( this->devolver_casillero(i,j)->esta_ocupado() )
                hay_edificio = true;
            else{
                j++;
            }
        }
        i++;
    }

    return hay_edificio;
}

