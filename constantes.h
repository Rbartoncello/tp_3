#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <string>

using namespace std;

const string EDIFICIO_MINA = "mina";
const string EDIFICIO_ASERRADERO = "aserradero";
const string EDIFICIO_FABRICA = "fabrica";
const string EDIFICIO_ESCUELA = "escuela";
const string EDIFICIO_OBELISCO = "obelisco";
const string EDIFICIO_PLANTA_ELECTRICA = "planta electrica";
const string PLANTA = "planta";

const string PATH_EDIFICIO = "edificios.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const string PATH_MAPA = "mapa.txt";
const string PATH_MATERIALES = "materiales.txt";

const int MIN_OPCION = 1;
const int MAX_OPCION = 10;

const int AFIRMATIVO = 1;
const int NEGATIVO = 2;

const int ERROR = -1;

const int CONSTRUIR_EDIFICIO_NOMBRE = 1;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int LISTAR_TODOS_EDIFICIOS = 3;
const int DEMOLER_EDIFICIO_COORDENADA = 4;
const int MOSTAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR_RECURSOS = 8;
const int LLUVIA_RECURSOS = 9;
const int GUARDA_SALIR = 10;

const string VERSION_PGM = "2.0";

const int MIN_GENERAR_PIEDRA = 1;
const int MAX_GENERAR_PIEDRA = 2;

const int MIN_GENERAR_MADERA = 0;
const int MAX_GENERAR_MADERA = 2;

const int MIN_GENERAR_METAL = 2;
const int MAX_GENERAR_METAL = 4;

const char CAMINO = 'C';
const char TERRENO = 'T';
const char LAGO = 'L';

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";

const string CONSTRUYENDO = "Construyendo";
const string DEMOLIENDO= "Demoliendo";

const int AUMENTAR_CANTIDAD_PIEDRA = 15;
const int AUMENTAR_CANTIDAD_MADERA = 25;
const int AUMENTAR_CANTIDAD_METAL = 40;

#endif