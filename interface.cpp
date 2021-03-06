#include <iostream>
#include <unistd.h>
#include <iomanip>
#include "interface.h"
#include "colors.h"
#include "constantes.h"
#include "emojis.h"
#include "gotoxy.h"
#include "jugador.h"

void imprimir_mensaje_bienvenida()
{
    system("clear");
    cout << TXT_BOLD << TXT_DARK_YELLOW_3 << "\
\t\t     ___      .__   __.  _______  ____    ____ .______     ______    __       __       _______    \n\
\t\t    /   \\     |  \\ |  | |       \\ \\   \\  /   / |   _  \\   /  __  \\  |  |     |  |     /       | _    \n\
\t\t   /  ^  \\    |   \\|  | |  .--.  | \\   \\/   /  |  |_)  | |  |  |  | |  |     |  |    |   (----`(_)      \n\
\t\t  /  /_\\  \\   |  . `  | |  |  |  |  \\_    _/   |   ___/  |  |  |  | |  |     |  |     \\   \\            \n\
\t\t /  _____  \\  |  |\\   | |  '--'  |    |  |     |  |      |  `--'  | |  `----.|  | .----)   |    _         \n\
\t\t/__/     \\__\\ |__| \\__| |_______/     |__|     |__|       \\______/  |_______||__| |_______/    (_)      \n\
                                                                                                              \n"
         << endl;
    cout << TXT_ORANGE_130 << "\
     _          _             _           _  _                                     _          _            _  _                   \n\
    | |        | |           | |         | || |                                   | |        | |          | |(_)                  \n\
    | |  __ _  | |__    __ _ | |_   __ _ | || |  __ _   _ __    ___   _ __    ___ | |   ___  | |__    ___ | | _  ___   ___   ___  \n\
    | | / _` | | '_ \\  / _` || __| / _` || || | / _` | | '_ \\  / _ \\ | '__|  / _ \\| |  / _ \\ | '_ \\  / _ \\| || |/ __| / __| / _ \\ \n\
    | || (_| | | |_) || (_| || |_ | (_| || || || (_| | | |_) || (_) || |    |  __/| | | (_) || |_) ||  __/| || |\\__ \\| (__ | (_) |\n\
    |_| \\__,_| |_.__/  \\__,_| \\__| \\__,_||_||_| \\__,_| | .__/  \\___/ |_|     \\___||_|  \\___/ |_.__/  \\___||_||_||___/ \\___| \\___/ \n\
                                                       | |                                                                        \n\
                                                       |_|                                                                        \n"
         << endl;
    cout << TXT_WHITE_15;
    cout << "\t\t\t\tLuego de muchos a??os de espera Andy finalmente encontr?? el lugar perfecto para\n\t";
    cout << "\t\tasentarse y comenzar a armar su peque??o para??so. Como primera medida decidi?? nombrar\n\t";
    cout << "\t\tsu nuevo hogar como Andypolis, la maravillosa ciudad de los programadores.\n\t";
    cout << "\t\t\tPoco a poco con el pasar de los d??as el rumor del surgimiento de una ciudad exclusiva para\n\t";
    cout << "\t\tprogramadores se fue difundiendo y la gente comenz?? a llegar a ella y se arm?? un programa\n\t";
    cout << "\t\tque ayude a contabilizar los materiales y edificios de la ciudad.\n\t";
    cout << "\t\t\tFue tanta la popularidad de este programa que llegaron a??n m??s programadores a ayudar y\n\t";
    cout << "\t\tpasar el dise??o de Andypolis al programa, pero algunos de ellos, fan??ticos de los\n\t";
    cout << "\t\tvideojuegos, decidieron darle una peque??a vuelta de tuerca???\n\t";
    cout << "\t\t\tPasaron unas semanas y los habitantes de Andypolis nos pidieron ayuda para generar una\n\t";
    cout << "\t\tnueva versi??n de nuestro programa. Como la dificultad del programa aument?? nos pidieron\n\t";
    cout << "\t\tque dos programadores se unan y desarrollen su programa en conjunto.\t" << endl
         << endl;
    cout << "\t\t\t\t\t    " << BGND_GRAY_243 << "???????????????????????????????????????????????????????????????????????????????????????????????????????????????" << END_COLOR << endl;
    cout << "\t\t\t\t\t    " << BGND_GRAY_243 << "???  Presione [ENTER] para continuar  ???" << END_COLOR << endl;
    cout << "\t\t\t\t\t    " << BGND_GRAY_243 << "???????????????????????????????????????????????????????????????????????????????????????????????????????????????" << END_COLOR << endl;
    cin.get();
    system("clear");
}

void imprimir_menu_nueva_partida()
{
    system("clear");
    cout << TXT_LIGHT_AQUA_43 << TXT_BOLD;
    cout << "\t\t\t\t\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t\t\t\t\t??? " << EMOJI_UNO << " ???" << END_COLOR << TXT_BOLD << " Modificar edificio por nombre " << EMOJI_EDIFICIO_CONSTRUCION << TXT_LIGHT_AQUA_43 << "       ???" << endl;
    cout << "\t\t\t\t\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t\t\t\t\t??? " << EMOJI_DOS << " ???" << END_COLOR << TXT_BOLD << " Listar todos los edificios " << EMOJI_LISTA << TXT_LIGHT_AQUA_43 << "         ???" << endl;
    cout << "\t\t\t\t\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t\t\t\t\t??? " << EMOJI_TRES << " ???" << END_COLOR << TXT_BOLD << " Mostrar mapa " << EMOJI_MAPA << TXT_LIGHT_AQUA_43 << "                        ???" << endl;
    cout << "\t\t\t\t\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t\t\t\t\t??? " << EMOJI_CUATRO << " ???" << END_COLOR << TXT_BOLD << " Comenzar partida " << EMOJI_START << TXT_LIGHT_AQUA_43 << "                   ???" << endl;
    cout << "\t\t\t\t\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t\t\t\t\t??? " << EMOJI_CINCO << " ???" << END_COLOR << TXT_BOLD << " Guarda y salir " << EMOJI_GUARDA_SALIR << TXT_LIGHT_AQUA_43 << "                     ???" << endl;
    cout << "\t\t\t\t\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << END_COLOR;
}

void imprimir_cuadro_jugador(Jugador *&jugador_actual)
{
    Gotoxy gotoxy;
    cout << gotoxy.pos(1, 115) << "????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << gotoxy.pos(2, 115) << "???   Jugador: " << jugador_actual->devolver_numero() << " ( " << jugador_actual->devolver_emoji() << " )          ???" << endl;
    cout << gotoxy.pos(3, 115) << "???   Energia disponible " << EMOJI_PLANTA_ENERGIA << " : " << jugador_actual->devolver_energia() << " ???" << endl;
    cout << gotoxy.pos(4, 115) << "????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
}

void imprimir_menu_juego(Mapa *mapa, Jugador *jugador_actual)
{
    system("clear");
    Gotoxy gotoxy;
    mapa->mostrar();
    imprimir_cuadro_jugador(jugador_actual);
    cout << TXT_LIGHT_AQUA_43 << TXT_BOLD;
    cout << gotoxy.pos(1, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(2, 65) << "??? " << EMOJI_UNO << " ???" << END_COLOR << TXT_BOLD << " Construir edificio por nombre " << EMOJI_EDIFICIO_CONSTRUCION << TXT_LIGHT_AQUA_43 << "       ???" << endl
         << gotoxy.pos(3, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(4, 65) << "??? " << EMOJI_DOS << " ???" << END_COLOR << TXT_BOLD << " Listar mis edificios construidos " << EMOJI_LISTA << TXT_LIGHT_AQUA_43 << "   ???" << endl
         << gotoxy.pos(5, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(6, 65) << "??? " << EMOJI_TRES << " ???" << END_COLOR << TXT_BOLD << " Demoler un edificio por coordenada " << EMOJI_MINA << TXT_LIGHT_AQUA_43 << " ???" << endl
         << gotoxy.pos(7, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(8, 65) << "??? " << EMOJI_CUATRO << " ???" << END_COLOR << TXT_BOLD << " Atacar un edificio por coordenada " << EMOJI_BOMBA << TXT_LIGHT_AQUA_43 << "  ???" << endl
         << gotoxy.pos(9, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(10, 65) << "??? " << EMOJI_CINCO << " ???" << END_COLOR << TXT_BOLD << " Reparar un edificio por coordenada " << EMOJI_EDIFICIO_CONSTRUCION << TXT_LIGHT_AQUA_43 << "  ???" << endl

         << gotoxy.pos(11, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(12, 65) << "??? " << EMOJI_SEIS << " ???" << END_COLOR << TXT_BOLD << " Comprar Bomba " << EMOJI_BOMBA << TXT_LIGHT_AQUA_43 << "                      ???" << endl
         << gotoxy.pos(13, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(14, 65) << "??? " << EMOJI_SIETE << " ???" << END_COLOR << TXT_BOLD << " Consultar coordenada " << EMOJI_BRUJULA << TXT_LIGHT_AQUA_43 << "               ???" << endl
         << gotoxy.pos(15, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(16, 65) << "??? " << EMOJI_OCHO << " ???" << END_COLOR << TXT_BOLD << " Mostrar inventario " << EMOJI_INVENTARIO << TXT_LIGHT_AQUA_43 << "                 ???" << endl
         << gotoxy.pos(17, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(18, 65) << "??? " << EMOJI_NUEVE << " ???" << END_COLOR << TXT_BOLD << " Mostrar objetivos " << EMOJI_LISTA << TXT_LIGHT_AQUA_43 << "                  ???" << endl
         << gotoxy.pos(19, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(20, 65) << "??? " << EMOJI_DIEZ << " ???" << END_COLOR << TXT_BOLD << " Recolectar recursos producidos " << EMOJI_BUSQUEDA << TXT_LIGHT_AQUA_43 << "     ???" << endl
         << gotoxy.pos(21, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(22, 65) << "??? " << EMOJI_ONCE << " ???" << END_COLOR << TXT_BOLD << " Moverse a una coordenada " << EMOJI_MOVERSE << TXT_LIGHT_AQUA_43 << "           ???" << endl
         << gotoxy.pos(23, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(24, 65) << "??? " << EMOJI_DOCE << " ???" << END_COLOR << TXT_BOLD << " Finalizar turno " << EMOJI_START << TXT_LIGHT_AQUA_43 << "                    ???" << endl
         << gotoxy.pos(25, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << gotoxy.pos(26, 65) << "??? " << EMOJI_TRECE << " ???" << END_COLOR << TXT_BOLD << " Guarda y salir " << EMOJI_GUARDA_SALIR << TXT_LIGHT_AQUA_43 << "                     ???" << endl
         << gotoxy.pos(27, 65) << "??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << END_COLOR;
}

void imprimir_objetos_mapa()
{
    cout << endl;
    cout << TXT_LIGHT_PURPLE_104;
    cout << "??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ???" << endl;
    cout << END_COLOR;
    cout << TXT_LIGHT_PURPLE_104 << "???" << END_COLOR << "\t" << TXT_UNDERLINE << TXT_BOLD << "Edificio:\t\t\tMateriales" << END_COLOR << TXT_LIGHT_PURPLE_104 << "\t    ???" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "???" << END_COLOR << "\t-Mina ( " << EMOJI_MINA << " )\t\t\t-Piedra ( " << EMOJI_PIEDRA << " )" << TXT_LIGHT_PURPLE_104 << "\t    ???" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "???" << END_COLOR << "\t-Aserradero ( " << EMOJI_ASERRADERO << " )\t\t-Madera ( " << EMOJI_MADERA << " )" << TXT_LIGHT_PURPLE_104 << "\t    ???" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "???" << END_COLOR << "\t-Fabrica ( " << EMOJI_FABRICA << " )\t\t\t-Metal ( " << EMOJI_METAL << ")" << TXT_LIGHT_PURPLE_104 << "\t    ???" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "???" << END_COLOR << "\t-Escuela ( " << EMOJI_ESCUELA << " )\t\t\t-Andycoins ( " << EMOJI_ANDYCOINS << " )" << TXT_LIGHT_PURPLE_104 << "   ???" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "???" << END_COLOR << "\t-Obelisco ( " << EMOJI_OBELISCO << " )" << TXT_LIGHT_PURPLE_104 << "\t\t\t\t    ???" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "???" << END_COLOR << "\t-Planta el??ctrica ( " << EMOJI_PLANTA_ENERGIA << " )" << TXT_LIGHT_PURPLE_104 << "\t\t\t    ???" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "???" << END_COLOR << "\t" << TXT_UNDERLINE << TXT_BOLD << "Jugadores:\t\t\t\t" << END_COLOR << TXT_LIGHT_PURPLE_104 << "\t    ???" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "???" << END_COLOR << "\t-Jugador 1 ( " << EMOJI_JUGADOR_1 << " )\t-Jugador 2 ( " << EMOJI_JUGADOR_2 << " )" << TXT_LIGHT_PURPLE_104 << "\t    ???" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104;
    cout << "??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ???" << endl;
    cout << END_COLOR;
    cout << endl;
}

void imprimir_mensaje_error()
{
    cout << TXT_BOLD << "\t" << EMOJI_WARNRING << TXT_DARK_RED_1 << TXT_UNDERLINE << " ERROR!! " << END_COLOR << EMOJI_WARNRING << endl;
}

void imprimir_mensaje_esperar(int tiempo)
{
    cout << endl;
    cout << "\t????Por favor espere que volver?? al menu principal en ";
    cout << TXT_BOLD;
    cout << tiempo;
    cout << END_COLOR;
    cout << " segundos..." << EMOJI_RELOJ << endl;
    sleep(tiempo);
    system("clear");
}

void imprimir_procesamiento_accion(string action_realizada, string nombre_edificio)
{
    system("clear");
    cout << "\t" << action_realizada << " " << nombre_edificio << "... " << EMOJI_EDIFICIO_CONSTRUCION << "  " << EMOJI_PARED << "  " << EMOJI_MARTILLO << endl;

    sleep(2);
    system("clear");
    cout << TXT_BOLD;
    cout << "\tSe ha realizado la accion con exito " << EMOJI_HECHO << endl
         << endl;
    cout << END_COLOR;

    sleep(2);
    system("clear");
}

void imprimir_mensaje_guardado()
{
    system("clear");
    cout << "\tCargando... " << EMOJI_LOANDING << endl;

    sleep(2);
    system("clear");

    cout << "\t??Se ha guardado con exito " << EMOJI_HECHO << endl;
    cout << "\t??Adios??" << endl;
}

int pedir_opcion(int fila, int columna)
{
    Gotoxy gotoxy;
    int opcion_elegida = ERROR;
    cout << gotoxy.pos(fila, columna) << "\tPor favor ingrese una de las opciones: ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

void imprimir_mensaje_error_ingreso()
{
    imprimir_mensaje_error();
    cout << "\tLa opci??n elegida no es una opcion v??lida, por favor ingrese otra opci??n: ";
}

void imprimir_mensaje_enter_continuar()
{
    cout << endl
         << "\t\tPresione [ENTER] para continuar" << endl;
    cin.ignore();
    cin.get();
    system("clear");
}

void imprimir_mensaje_enter_continuar2(int contador)
{
    Gotoxy gotozu;
    cout << endl
         << gotozu.pos(contador, 11) << "\t\tPresione [ENTER] para continuar" << endl;
    cin.ignore();
    cin.get();
    system("clear");
}

void imprimir_mensaje_ingresar_edificio()
{
    system("clear");
    cout << "\tIngrese el nombre del edificio que desee modificar: ";
}

void imprimir_mensaje_construir_edificio()
{
    system("clear");
    cout << "\tIngrese el nombre del edificio que desee construir: ";
}

void imprimir_mensaje_max_edificios_alcansado()
{
    system("clear");
    cout << "\nOh, lamento traer malas noticias pero ya has alcanzo el maximo de construidos para este edificio: ";
}

void imprimir_mensaje_edificio_no_duenio()
{
    imprimir_mensaje_error();
    cout << "Ejem... ese edificio no es tuyo..." << endl;
    imprimir_mensaje_esperar(2);
}

void imprimir_mensaje_no_hay_edificio()
{
    imprimir_mensaje_error();
    cout << "Aqu?? no hay un edificio" << endl;
    imprimir_mensaje_esperar(2);
}

void imprimir_mensaje_reembolso(int piedra, int madera, int metal)
{
    system("clear");
    cout << "Se te reembolsaran: " << endl;
    cout << "\tPiedra = " << piedra / 2 << endl;
    cout << "\tMadera = " << madera / 2 << endl;
    cout << "\tMetal = " << metal / 2 << endl;
    cout << "??Quieres continuar? [s/n]" << endl;
}

void imprimir_mensaje_error_ingresar_edificio()
{
    system("clear");
    imprimir_mensaje_error();
    cout << "\tEl nombre de edificio ingresado " << TXT_BOLD << TXT_UNDERLINE << "no" << END_COLOR << " exite, por favor ingrese un nombre de edificio que exista: ";
}

string chequear_status(int cant_material_inventario, int cant_material_necesario)
{
    string status = EMOJI_MAL;

    if (cant_material_inventario >= cant_material_necesario)
        status = EMOJI_HECHO;

    return status;
}

void imprimir_materiales_necesarios(int piedra_inventario, int madera_inventario, int metal_inventario, int piedra_edificio, int madera_edificio, int metal_edificio)
{

    cout << TXT_BOLD;
    cout << "\t?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t???/////////??? Materiales necesarios ??? Materiales en inventario ??? Estado ???" << endl;
    cout << "\t?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << END_COLOR;

    string status = chequear_status(piedra_inventario, piedra_edificio);
    cout << "\t??? " << PIEDRA << "  ???" << setfill(' ') << setw(12) << piedra_edificio << setfill(' ') << setw(14) << "???" << setfill(' ') << setw(14) << piedra_inventario << setfill(' ') << setw(18) << "???   " << status << "   ???" << endl;
    cout << "\t?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;

    status = chequear_status(madera_inventario, madera_edificio);
    cout << "\t??? " << MADERA << "  ???" << setfill(' ') << setw(12) << madera_edificio << setfill(' ') << setw(14) << "???" << setfill(' ') << setw(14) << madera_inventario << setfill(' ') << setw(18) << "???   " << status << "   ???" << endl;
    cout << "\t?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;

    status = chequear_status(metal_inventario, metal_edificio);
    cout << "\t???  " << METAL << "  ???" << setfill(' ') << setw(12) << metal_edificio << setfill(' ') << setw(14) << "???" << setfill(' ') << setw(14) << metal_inventario << setfill(' ') << setw(18) << "???   " << status << "   ???" << endl;
    cout << "\t?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;

    imprimir_mensaje_esperar(4);
}

void imprimir_materiales_gastados_construir(Receta *receta)
{
    system("clear");
    cout << "\tTodo esta listo para empezar la construccion, usted va a gastar: " << endl;
    cout << TXT_BOLD;
    cout << "\t???????????????????????????????????????????????????" << endl;
    cout << "\t??? " << setfill(' ') << setw(5) << receta->devoler_piedra() << setfill(' ') << setw(8) << " ??? " << EMOJI_PIEDRA << " ???" << endl;
    cout << "\t???????????????????????????????????????????????????" << endl;
    cout << "\t??? " << setfill(' ') << setw(5) << receta->devoler_madera() << setfill(' ') << setw(8) << " ??? " << EMOJI_MADERA << " ???" << endl;
    cout << "\t???????????????????????????????????????????????????" << endl;
    cout << "\t??? " << setfill(' ') << setw(5) << receta->devoler_metal() << setfill(' ') << setw(8) << " ??? " << EMOJI_METAL << " ???" << endl;
    cout << "\t???????????????????????????????????????????????????" << endl;
    cout << END_COLOR;
    cout << "\t??Quieres continuar? [s/n]" << endl;
}

void imprimir_mensaje_receta_edificio(string edificio, string material, int cantidad)
{
    system("clear");
    cout << "\tEl edificio " << edificio << " necesita " << cantidad << " de " << material << "  desea modificarlo" << endl;
}

void imprimir_mensaje_afirmativo_negativo()
{
    cout << endl
         << "\t ";
    cout << TXT_BOLD << TXT_GREEN_118 << AFIRMATIVO << ") SI " << END_COLOR << endl;
    cout << "\t ";
    cout << TXT_BOLD << TXT_LIGHT_RED_9 << NEGATIVO << ") NO " << END_COLOR << endl;
}

void imprimir_mensaje_receta_modificar()
{
    system("clear");
    cout << "\tIngrese la cantidad entre [ " << MIN_RECETA_MODIFICAR << ", " << MAX_RECETA_MODIFICAR << " ] que decee modificar: ";
}

void imprimir_mensaje_error_ingresar_edificio_obelisco()
{
    system("clear");
    imprimir_mensaje_error();
    cout << TXT_BOLD << TXT_UNDERLINE << "No" << END_COLOR << " se puede modificar el " << EDIFICIO_OBELISCO << endl;

    imprimir_mensaje_esperar(2);
}

void encabezado_edificios_construidos()
{
    system("clear");

    cout << TXT_BOLD;
    cout << "\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t???                      ??? Materiales necesarios para construirlos ???             ???             ???                 ???" << endl;
    cout << "\t???  Nombre de edificio  ????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????? Construidos ??? Disponibles ??? Brinda material ???" << endl;
    cout << "\t???                      ??? Piedra (" << EMOJI_PIEDRA << ") ??? Madera (" << EMOJI_MADERA << ") ???  Metal (" << EMOJI_METAL << ") ???             ???             ???                 ???" << endl;
    cout << "\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << END_COLOR;
}

void imprimir_lista_edificios_construidos(Edificacion *edificio, Mapa *mapa)
{
    string brinda = EMOJI_MAL;
    if (edificio->brinda_material())
        brinda = EMOJI_HECHO;
    cout << "\t???" << setfill(' ') << setw(16) << edificio->devolver_nombre_edificio() << "( " << edificio->devolver_emoji() << " )" << setfill(' ') << setw(3);
    cout << "???" << setfill(' ') << setw(8) << edificio->devolver_receta()->devoler_piedra() << setfill(' ') << setw(8);
    cout << "???" << setfill(' ') << setw(8) << edificio->devolver_receta()->devoler_madera() << setfill(' ') << setw(8);
    cout << "???" << setfill(' ') << setw(8) << edificio->devolver_receta()->devoler_metal() << setfill(' ') << setw(8);
    cout << "???" << setfill(' ') << setw(7) << mapa->devolver_cantidad_edificio(edificio->devolver_nombre_edificio()) << setfill(' ') << setw(9);
    cout << "???" << setfill(' ') << setw(7) << edificio->devolver_maxima_cantidad_permitidos() - mapa->devolver_cantidad_edificio(edificio->devolver_nombre_edificio()) << setfill(' ') << setw(9);
    cout << "???" << setfill(' ') << setw(10) << brinda << setw(11) << "???" << endl;
    cout << "\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
}

void imprimir_materiales_jugador(Nodo_lista<Material> *&primero, int cantidad_en_lista)
{

    Nodo_lista<Material> *auxiliar = primero;

    encabezado_materiale_jugador();

    for (int i = 0; i < cantidad_en_lista; i++)
    {
        imprimir_lista_materiales_jugador(auxiliar->devolver_dato());
        auxiliar = auxiliar->direccion_siguiente();
    }
}

void encabezado_edificios_jugador_secundario()
{
    Gotoxy gotoxy;
    cout << TXT_BOLD;
    cout << gotoxy.pos(8, 42) << "\t\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????"
         << gotoxy.pos(9, 42) << "\t\t??? Edificios construidos ??? Fila ??? Columna ??? Necesita reparacion ???"
         << gotoxy.pos(10, 42) << "\t\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????";
    cout << END_COLOR;
}

void sin_edificios_en_lista()
{
    Gotoxy gotoxy;
    int contador = 10;

    cout << TXT_BOLD;
    cout << gotoxy.pos(8, 22) << "\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????"
         << gotoxy.pos(9, 22) << "\t??? Edificios construidos ??? Fila ??? Columna ??? Necesita reparacion ???"
         << gotoxy.pos(10, 22) << "\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????";
    cout << END_COLOR;

    contador++;
    cout << TXT_BOLD;
    cout << gotoxy.pos(contador, 22) << "\t??? " << TXT_RED_196 << setfill(' ') << setw(49) << "NO HAY NINGUN EDIFICIO CONSTRUIDO" << setfill(' ') << setw(16) << END_COLOR << "???" << endl;
    contador++;
    cout << gotoxy.pos(contador, 22) << "\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    imprimir_mensaje_enter_continuar2(contador+1);
}

void imprimir_edificios_jugador(Lista_edificios<Edificacion> *edificios_jugador)
{

    encabezado_edificios_jugador_secundario();
    Gotoxy gotoxy;

    string necesita_reparacion = EMOJI_MAL, nombre_edificio;
    int cantidad_en_lista = edificios_jugador->devolver_cantidad_en_Lista_edificios();
    Nodo_edificios<Edificacion> *primer_nodo_edificios = edificios_jugador->retornar_primero();
    Edificacion *edificio;
    int contador = 10, contador_auxiliar = 0;

    for (int i = 0; i < cantidad_en_lista; i++)
    {
        edificio = primer_nodo_edificios->devolver_dato();
        nombre_edificio = edificio->devolver_nombre_edificio();
        if (nombre_edificio == EDIFICIO_FABRICA || nombre_edificio == EDIFICIO_MINA)
        {
            if (edificio->devolver_necesita_reparacion())
                necesita_reparacion = EMOJI_HECHO;
        }
        contador++;
        contador_auxiliar = contador + 1;
        cout << gotoxy.pos(contador, 42) << "\t\t???" << setfill(' ') << setw(16) << nombre_edificio << "( " << edificio->devolver_emoji() << " )" << setfill(' ') << setw(4)
             << "???" << setfill(' ') << setw(4) << edificio->devolver_fila() << setfill(' ') << setw(5)
             << "???" << setfill(' ') << setw(5) << edificio->devolver_columna() << setfill(' ') << setw(7)
             << "???" << setfill(' ') << setw(12) << necesita_reparacion << setfill(' ') << setw(13) << "???" << endl
             << gotoxy.pos(contador_auxiliar, 42) << "\t\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;

        contador++;

        primer_nodo_edificios = primer_nodo_edificios->direccion_siguiente();
    }
    cout << gotoxy.pos(contador, 42) << "\t\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
}

void encabezado_edificios_jugador()
{
    Gotoxy gotoxy;
    cout << TXT_BOLD;
    cout << gotoxy.pos(8, 11) << "\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????"
         << gotoxy.pos(9, 11) << "\t???        Edificio      ???  Cantidad   ???"
         << gotoxy.pos(10, 11) << "\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????";
    cout << END_COLOR;
}

int imprimir_cantidad_edificios_jugador(Lista_primitiva<string> *nombre_edificios, Lista_primitiva<int> *cantidad_por_edificio)
{
    string nombre_de_edificio;
    int cantidad = 0, contador = 10, contador_auxiliar = 0;
    Gotoxy gotoxy;

    encabezado_edificios_jugador();

    for (int i = 0; i < nombre_edificios->devolver_cantidad_en_Lista_primitiva(); i++)
    {
        nombre_de_edificio = nombre_edificios->devolver_elemento_en_posicion(i + 1);
        cantidad = cantidad_por_edificio->devolver_elemento_en_posicion(i + 1);
        contador++;
        contador_auxiliar = contador + 1;
        cout << gotoxy.pos(contador, 11) << "\t???" << setfill(' ') << setw(16) << nombre_de_edificio << ""
             << "      "
             << setfill(' ') << setw(3)
             << "???" << setfill(' ') << setw(7) << cantidad << setfill(' ') << setw(9) << "???" << endl
             << gotoxy.pos(contador_auxiliar, 11) << "\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
        contador++;
    }

    cout << gotoxy.pos(contador, 11) << "\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    contador++;

    return contador;
}

void encabezado_materiale_jugador()
{
    system("clear");

    cout << TXT_BOLD;
    cout << "\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t???                      ???             ???" << endl;
    cout << "\t???  Nombre de material  ??? Disponibles ???" << endl;
    cout << "\t???                      ???             ???" << endl;
    cout << "\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << END_COLOR;
}

void imprimir_lista_materiales_jugador(Material *material)
{

    cout << "\t???" << setfill(' ') << setw(16) << material->devolver_nombre() << "( " << material->devolver_emoji() << " )" << setfill(' ') << setw(3);
    cout << "???" << setfill(' ') << setw(7) << material->devolver_cantidad() << setfill(' ') << setw(9) << "???";
    cout << "\n\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
}

void imprimir_mensaje_ingrese_jugador()
{
    system("clear");
    cout << "Por favor ingrese el numero de jugador que desee ser [1 o 2]: ";
}

void imprimir_mensaje_ingrese_fila_jugador()
{
    cout << "Por favor ingrese la fila con la que desee empezar: ";
}

void imprimir_mensaje_ingrese_columna_jugador()
{
    cout << "Por favor ingrese la columna con la que desee empezar: ";
}

void imprimir_mensaje_no_energia_sufuciente(int energia)
{
    system("clear");
    imprimir_mensaje_error();
    cout << "\tNo cuentas con la energia necesaria: " << energia << endl;
    imprimir_mensaje_esperar(2);
}

void imprimir_mensaje_posicion_no_permitida()
{
    imprimir_mensaje_error();
    cout << "No es posible ir a la posicion ingresada" << endl;
    imprimir_mensaje_esperar(2);
}

void imprimir_mensaje_finalizacion_turno_automatico(Jugador *&jugador)
{
    system("clear");
    cout << TXT_BOLD;
    cout << "\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t??? El jugador " << jugador->devolver_numero() << " se a quedado con energia " << jugador->devolver_energia() << " se finalizara el turno automaticamente ???" << endl;
    cout << "\t????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << END_COLOR;
    sleep(3);
}

void imprimir_mensaje_casillero_ocupado()
{
    cout << "La posicion elegida se encuentra ocupada" << endl;
}

void imprimir_tienda_bombas()
{
    system("clear");

    cout << TXT_BOLD;
    cout << "\t?????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t???   Bienvenido al mercado negro   ???" << endl;
    cout << "\t?????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << END_COLOR;
    cout << "\t???          " << EMOJI_BOMBA << "           ??? " << COSTO_POR_BOMBA << " c/u ???" << endl;
    cout << "\t?????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl
         << endl;

    cout << "\t Ingrese la cantidad de bombas que desee comprar: ";
}

void imprimir_mensaje_sin_andycoins_suficientes(int costo)
{
    system("clear");
    imprimir_mensaje_error();
    cout << "\tNo cuenta con los suficientes " << ANDYCOINS << " = " << costo << " " << EMOJI_ANDYCOINS << " para realizar la compra" << endl;
    imprimir_mensaje_esperar(2);
}

void imprimir_mensaje_bombas_compradas(Lista<Material> *&inventario, int cantidad)
{
    system("clear");
    cout << "\tComprando bombas ... " << EMOJI_BOMBA << EMOJI_COMPRANDO << endl;

    sleep(2);
    system("clear");

    cout << "\tHa comprado " << cantidad << "  " << EMOJI_BOMBA << endl;

    int posicion = inventario->obtener_posicion(ANDYCOINS);

    int andycoins = inventario->obtener_direccion_nodo(posicion)->devolver_dato()->devolver_cantidad();

    cout << "\tLe quedan en el inventario " << andycoins << "  " << ANDYCOINS << endl;

    imprimir_mensaje_esperar(3);
}

void encabezado_objetivos_secuncarios()
{
    system("clear");
    cout << TXT_BOLD;
    cout << "\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << "\t??? Nombre de objetivo ???                          Descripcion                          ??? Porcentaje de completado ??? Completado ???" << endl;
    cout << "\t??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????" << endl;
    cout << END_COLOR;
}

void imprimir_mensaje_recolectando_recursos_producidos()
{
    system("clear");
    cout << "\tRecolectando recursos producidos... " << EMOJI_BUSQUEDA << endl;

    sleep(2);
    system("clear");

    cout << TXT_BOLD;
    cout << "\t??Se han recolectado los recursos producidos con exito" << EMOJI_HECHO << endl;
    cout << END_COLOR;

    sleep(2);
    system("clear");
}

void imprimir_juego_ganado(int ganador)
{

    system("clear");
    Gotoxy gotoxy;

    

    cout << TXT_BOLD << TXT_DARK_YELLOW_3;
    cout << gotoxy.pos(10, 35) <<  "  _______      ___      .___  ___.  _______ \n ";
    cout << gotoxy.pos(11, 35) <<  " /  _____|    /   \\     |   \\/   | |   ____|\n";
    cout << gotoxy.pos(12, 35) <<  "|  |  __     /  ^  \\    |  \\  /  | |  |__   \n";
    cout << gotoxy.pos(13, 35) <<  "|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|  \n";
    cout << gotoxy.pos(14, 35) <<  "|  |__| |  /  _____  \\  |  |  |  | |  |____ \n";
    cout << gotoxy.pos(15, 35) <<  " \\______| /__/     \\__\\ |__|  |__| |_______|\n";

    cout << gotoxy.pos(17, 35) << "  ______   ____    ____  _______ .______      \n";
    cout << gotoxy.pos(18, 35) << " /  __  \\  \\   \\  /   / |   ____||   _  \\     \n";
    cout << gotoxy.pos(19, 35) << "|  |  |  |  \\   \\/   /  |  |__   |  |_)  |    \n";
    cout << gotoxy.pos(20, 35) << "|  |  |  |   \\      /   |   __|  |      /     \n";
    cout << gotoxy.pos(21, 35) << "|  `--'  |    \\    /    |  |____ |  |\\  \\----.\n";
    cout << gotoxy.pos(22, 35) << " \\______/      \\__/     |_______|| _| `._____|\n";

    sleep(2);
    system("clear");
    cout << END_COLOR;

    cout << gotoxy.pos(15, 35) << "\t\t EL JUGADOR " << ganador << " HA GANADO EL JUEGO" << endl;
    sleep(2);
    imprimir_mensaje_enter_continuar();

}