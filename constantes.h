#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <string>

using namespace std;

const string EDIFICIO_MINA = "mina";
const string EDIFICIO_MINA_ORO = "mina oro";
const string EDIFICIO_ASERRADERO = "aserradero";
const string EDIFICIO_FABRICA = "fabrica";
const string EDIFICIO_ESCUELA = "escuela";
const string EDIFICIO_OBELISCO = "obelisco";
const string EDIFICIO_PLANTA_ELECTRICA = "planta electrica";
const string PLANTA = "planta";
const string ORO = "oro";

const string PATH_EDIFICIO = "archivos/edificios.txt";
const string PATH_UBICACIONES = "archivos/ubicaciones.txt";
const string PATH_MAPA = "archivos/mapa.txt";
const string PATH_MATERIALES = "archivos/materiales.txt";

const int OBJETIVOS_SECUNDARIOS_CUMPLIDOS = 3;
const int OBJETIVO_COMPRAR_ANDYCOINS = 100;
const int OBJETIVO_EDAD_PIEDRA = 50000;
const int OBJETIVO_BOMBARDERO = 5;

const string MAS_ALTO_NUBES = "Mas alta que las nubes";
const string COMPRAR_ANDYPOLIS = "Comprar Andypolis";
const string EDAD_PIEDRA = "Edad de piedra";
const string BOMBARDERO = "Bombardero";
const string ENERGETICO = "Energetico";
const string LETRADO = "Letrado";
const string MINERO = "Minero";
const string CANSADO = "Cansado";
const string CONSTRUCTOR = "Constructor";
const string ARMADO = "Armado";
const string EXTREMISTA = "Extremista";

const int MIN_OPCION_NUEVA_PARTIDA = 1;
const int MAX_OPCION_NUEVA_PARTIDA = 5;

const int MIN_OPCION_JUEGO = 1;
const int MAX_OPCION_JUEGO = 13;

const int AFIRMATIVO = 1;
const int NEGATIVO = 2;

const int ERROR = -1;

const int MODIFICAR_EDIFICIO_POR_NOMBRE = 1;
const int LISTAR_TODOS_EDIFICIOS = 2;
const int MOSTAR_MAPA = 3;
const int COMENZAR_PARTIDA = 4;
const int GUARDA_SALIR_NUEVA_PARTIDA = 5;

const int CONSTRUIR_EDIFICIO_NOMBRE = 1;
const int LISTAR_MIS_EDIFICIOS_CONSTRUIDOS = 2;
const int DEMOLER_EDIFICIO_COORDENADA = 3;
const int ATARCAR_EDIFICIO_COORDENADA = 4;
const int REPARAR_EDIFICIO_COORDENADA = 5;
const int COMPRAR_BOMBA = 6;
const int CONSULTAR_COORDENADA = 7;
const int MOSTRAR_INVENTARIO = 8;
const int MOSTRAR_OBJETIVOS = 9;
const int RECOLECTAR_RECURSOS = 10;
const int MOVERSE_COORDENADA = 11;
const int FINALIZAR_TURNO = 12;
const int GUARDA_SALIR = 13;

const char CAMINO = 'C';
const char BETUN = 'B';
const char LAGO = 'L';
const char MUELLE = 'M';
const char TERRENO = 'T';

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";
const string BOMBA = "bombas";
const string ANDYCOINS = "andycoins";
const string ENERGIA = "energia";

const int CONSTRUYENDO = 1;
const int DEMOLIENDO= 0;

/* 
 *  CANTIDAD QUE BRINDA CADA EDIFICIO  
 */
const int BRINDA_MINA = 15;
const int BRINDA_ASERRADERO = 25;
const int BRINDA_FABRICA = 40;
const int BRINDA_ESCUELA = 25;
const int BRINDA_PLANTA_ELECTRICA = 15;
const int BRINDA_MINA_ORO = 50;

/* 
 *  MAXIMOS Y MINIMOS PARA MODIFICAR EDIFICIO  
 */
const int MIN_RECETA_MODIFICAR = 0;
const int MAX_RECETA_MODIFICAR = 50000;

/* 
 *  CANTIDAD QUE SE GENERA CON LA LLUVIA DE RECURSOS  
 */
const int LLUVIA_GENERA_PIEDRA = 100;
const int LLUVIA_GENERA_MADERA = 50;
const int LLUVIA_GENERA_METAL = 50;
const int LLUVIA_GENERA_ANDYCOINS = 250;

/* 
 *  MAXIMOS Y MINIMOS QUE SE GENERA CON LA LLUVIA DE RECURSOS  
 */
const int MIN_GENERAR_PIEDRA = 1;
const int MAX_GENERAR_PIEDRA = 2;

const int MIN_GENERAR_MADERA = 0;
const int MAX_GENERAR_MADERA = 3;

const int MIN_GENERAR_METAL = 2;
const int MAX_GENERAR_METAL = 4;

const int MIN_GENERAR_ANDYCOINS = 0;
const int MAX_GENERAR_ANDYCOINS = 1;

const int JUGADOR_1 = 1;
const int JUGADOR_2 = 2; 

const int ENERGIA_COMIENZO_PARTIDA = 50;
const int ENERGIA_NUEVO_TURNO = 20;
const int ENERGIA_REPARAR = 25;
const int ENERGIA_ATACAR = 30;

const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";

const int COSTO_POR_BOMBA = 100;
const int ENERGIA_COMPRAR_BOMBAS = 5;

#endif