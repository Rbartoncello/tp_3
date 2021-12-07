#include "constructora.h"

Constructora::Constructora(Diccionario<Edificacion>* dict_edifcios, Mapa *mapa) {
    this->dict_edificios = dict_edifcios;
    this->mapa = mapa;
}



void Constructora::construir_edificio(Jugador* jugador)
{
    string nombre_nuevo_edifcio;
    bool entrada_valida = false;

    do
    {
        cout << "Ingrese el nombre del nuevo edificio: ";
        cin >> nombre_nuevo_edifcio;
        entrada_valida = dict_edificios->existe(nombre_nuevo_edifcio);

        if (!entrada_valida && (nombre_nuevo_edifcio!="1"))
            mostrar_aviso();

    } while (!entrada_valida && nombre_nuevo_edifcio != "1");

    if(entrada_valida)
        avanzar_con_construccion(nombre_nuevo_edifcio, jugador);
    else{
        cout << "\n Oh, no construyes nada?, bueno, vuelve pronto la constructora de Andypolis necesita trabajar\n" << endl;
    }
}

void Constructora::avanzar_con_construccion(string nombre_nuevo_edifcio, Jugador* jugador){

    bool coordenadas_validas = false, materiales_validos = false, cantidad_construida = false;
    bool ocupado = false;

    cantidad_construida = validar_maximo_edificio(nombre_nuevo_edifcio, jugador); //FUNCIONA, falta que los edificios sepan de quien son para validar cuantos hay de un juegador en particualar

    if(cantidad_construida)
        materiales_validos = validar_materiales(nombre_nuevo_edifcio,jugador);
    else{
        cout << "\nOh, lamento traer malas noticias pero ya has alcanzo el maximo de construidos para este edificio: ";
    }
    if(materiales_validos)
        coordenadas_validas = this->ingreso_de_coordenadas();

    if(coordenadas_validas){
        ocupado = mapa->hay_edificio(fila_nueva,columna_nueva);
    }

    if (!ocupado){
        //mapa->construir_edifcio(fila_nueva,columna_nueva,nombre_nuevo_edifcio);
        this->restar_materiales(nombre_nuevo_edifcio,jugador);
        cout << "\n EL EDIFICIO SE HA CONSTRUIDO\n" << endl;
    }
    else if (materiales_validos){
        cout << "\nAcaso has perdido la cabeza?, aqui ya hay un edificio: ";
    }
}

bool Constructora::validar_maximo_edificio(string nombre_nuevo_edificio, Jugador* jugador){
    int maxima_cantidad_permitidos = 0, cantidad_actual = 0;

    maxima_cantidad_permitidos = dict_edificios->buscar(nombre_nuevo_edificio)->devolver_maxima_cantidad_permitidos();

    cantidad_actual = mapa->devolver_cantidad_edificio(nombre_nuevo_edificio,jugador);

    return(cantidad_actual<maxima_cantidad_permitidos);
}

bool Constructora::validar_materiales(string nombre_nuevo_edificio, Jugador* &jugador) {
    int cantidad_piedra = 0, cantidad_madera = 0, cantidad_metal = 0, piedra_necesaria = 0, madera_necesaria = 0, metal_necesario = 0;

    cantidad_piedra = jugador->devolver_inventario()->devolver_material(PIEDRA);
    cantidad_madera = jugador->devolver_inventario()->devolver_material(MADERA);
    cantidad_metal = jugador->devolver_inventario()->devolver_material(METAL);
    piedra_necesaria = dict_edificios->buscar(nombre_nuevo_edificio)->devolver_receta()->devoler_piedra();
    madera_necesaria = dict_edificios->buscar(nombre_nuevo_edificio)->devolver_receta()->devoler_madera();
    metal_necesario  = dict_edificios->buscar(nombre_nuevo_edificio)->devolver_receta()->devoler_metal();

    if(piedra_necesaria <= cantidad_piedra && madera_necesaria <= cantidad_madera && metal_necesario <= cantidad_metal) {
        return true;
    }
    mostrar_materiales_faltantes(cantidad_piedra, cantidad_madera, cantidad_metal, piedra_necesaria, madera_necesaria, metal_necesario);
    return false;
}

void Constructora::mostrar_materiales_faltantes(int cantidad_piedra, int cantidad_madera, int cantidad_metal, int piedra_necesaria, int madera_necesaria, int metal_necesario){
    if(piedra_necesaria > cantidad_piedra)
        cout << "Falto " << piedra_necesaria - cantidad_piedra << " de piedra" << endl;
    if(madera_necesaria > cantidad_madera)
        cout << "Falto " << madera_necesaria - cantidad_madera << " de madera" << endl;
    if(metal_necesario > cantidad_metal)
        cout << "Falto " << metal_necesario - cantidad_metal << " de metal" << endl;
}

void Constructora::mostrar_aviso(){
    cout << "\n EL edificio que intenta crear no existe, para salir presione 1" << endl;
}

bool Constructora::ingreso_de_coordenadas()
{
    bool salida_sin_coordenadas = false, coord_ok = false;
    mapa->mostrar();
    do
    {
        cout << "Ingrese la coordenada fila: ";
        cin >> fila_nueva;

        if(fila_nueva == -2){
            salida_sin_coordenadas =  true;
            cout << "\nFinalizando Construccion" << endl;
        }
        else{
            cout << "Ingrese la coordenada columna: ";
            cin >> columna_nueva;
            coord_ok = validar_coords(fila_nueva,columna_nueva);
        }

        if(coord_ok){
            coord_ok = mapa->validar_tipo_construible(fila_nueva,columna_nueva);
            mostrar_aviso_terreno(coord_ok);
        }

    } while (!coord_ok && !salida_sin_coordenadas);

    return (coord_ok);
}

bool Constructora::validar_coords(int coord1, int coord2) {
    bool coords_ok = false;

    if (coord1 < mapa->devolver_cantidad_filas() && coord2 < mapa->devolver_cantidad_columnas() && coord1 >= 0 &&
        coord2 >= 0) {
        coords_ok = true;
    } else {
        cout << "\nEsa no es una coordenada valida - Intentalo de nuevo o sal con un -1 :)" << endl;
        cout << "Filas disponibles: -> (1, " << mapa->devolver_cantidad_filas() << ") \nColumnas disponibles: -> (1, "
             << mapa->devolver_cantidad_columnas() << ")" << endl;
    }

    return coords_ok;
}


void Constructora::restar_materiales(string nombre_nuevo_edificio, Jugador *jugador){

    Edificacion* edificio = dict_edificios->buscar(nombre_nuevo_edificio);

    jugador->restar_piedra(edificio->devolver_receta()->devoler_piedra());
    jugador->restar_madera(edificio->devolver_receta()->devoler_madera());
    jugador->restar_metal(edificio->devolver_receta()->devoler_metal());
}

void Constructora::mostrar_aviso_terreno(bool aviso) {

    if(!aviso)
        cout << "\nEste no es un casillero construible,  para salir presione -1" << endl;
}
