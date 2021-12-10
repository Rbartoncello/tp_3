#include "constructora.h"
#include "emojis.h"

Constructora::Constructora(Diccionario<Edificacion>* dict_edifcios, Mapa *mapa) {
    this->dict_edificios = dict_edifcios;
    this->mapa = mapa;
}

void Constructora::construir_edificio(Jugador* jugador)
{
    string nombre_nuevo_edificio;

    if(jugador->devolver_energia() >= ENERGIA_CONSTRUIR){
        imprimir_mensaje_construir_edificio();
        cin.ignore();
        getline(cin, nombre_nuevo_edificio);
        while ( !dict_edificios->existe(nombre_nuevo_edificio)){
            imprimir_mensaje_error_ingresar_edificio();
            getline(cin, nombre_nuevo_edificio);
        }
        if(dict_edificios->existe(nombre_nuevo_edificio))
            avanzar_con_construccion(nombre_nuevo_edificio, jugador);
        else
            cout << "\n Oh, no construyes nada?, bueno, vuelve pronto la constructora de Andypolis necesita trabajar\n" << endl;
    } else
        imprimir_mensaje_no_energia_sufuciente(ENERGIA_CONSTRUIR);
}

void Constructora::avanzar_con_construccion(string nombre_nuevo_edificio, Jugador* jugador)
{
    bool coordenadas_validas = false;
    bool ocupado = true, opcion_elegida = false;

    if( !validar_maximo_edificio(nombre_nuevo_edificio, jugador) )
        imprimir_mensaje_max_edificios_alcansado(); 
    else if( validar_materiales(nombre_nuevo_edificio,jugador)) {
        while (ocupado) {
            coordenadas_validas = this->ingreso_de_coordenadas();
            if (coordenadas_validas) {
                ocupado = mapa->hay_edificio(fila_nueva, columna_nueva);
            } else {
                cout << "Ahí ya hay un edificio colocado, ingresa unas coordenadas válidas";
            }
        }
    }



    if (!ocupado) {
        opcion_elegida = validacion_final();
        if (opcion_elegida) {
            mapa->agregar_edificacion(nombre_nuevo_edificio, fila_nueva, columna_nueva, jugador->devolver_numero(),jugador->devolver_mis_edificios());
            this->restar_materiales(nombre_nuevo_edificio, jugador);
            jugador->restar_energia(15);
            cout << "\n EL EDIFICIO SE HA CONSTRUIDO\n" << endl;
        }
    }
}

void Constructora::demoler_edificio(Jugador* jugador){

    string nombre_edificio;

    if(jugador->devolver_energia() >= ENERGIA_DEMOLER){
        imprimir_mensaje_construir_edificio();
        cin.ignore();
        getline(cin, nombre_edificio);
        while ( !dict_edificios->existe(nombre_edificio)){
            imprimir_mensaje_error_ingresar_edificio();
            getline(cin, nombre_edificio);
        }
        if(dict_edificios->existe(nombre_edificio))
            avanzar_con_demolicion(nombre_edificio, jugador);
        else
            cout << "\n Oh, no construyes nada?, bueno, vuelve pronto la constructora de Andypolis necesita trabajar\n" << endl;
    } else
        imprimir_mensaje_no_energia_sufuciente(ENERGIA_CONSTRUIR);
}

void Constructora::avanzar_con_demolicion(string nombre_nuevo_edificio, Jugador *jugador) {

}

bool Constructora::validar_maximo_edificio(string nombre_nuevo_edificio, Jugador* jugador){
    int maxima_cantidad_permitidos = dict_edificios->buscar(nombre_nuevo_edificio)->devolver_maxima_cantidad_permitidos();
    
    int cantidad_actual = mapa->devolver_cantidad_edificio(nombre_nuevo_edificio,jugador);

    return(cantidad_actual<maxima_cantidad_permitidos);
}

bool Constructora::validar_materiales(string nombre_nuevo_edificio, Jugador* &jugador) {
    bool inventario_suficiente = false;

    int cantidad_piedra = jugador->devolver_inventario()->devolver_material(PIEDRA);
    int cantidad_madera = jugador->devolver_inventario()->devolver_material(MADERA);
    int cantidad_metal = jugador->devolver_inventario()->devolver_material(METAL);
    int piedra_necesaria = dict_edificios->buscar(nombre_nuevo_edificio)->devolver_receta()->devoler_piedra();
    int madera_necesaria = dict_edificios->buscar(nombre_nuevo_edificio)->devolver_receta()->devoler_madera();
    int metal_necesario  = dict_edificios->buscar(nombre_nuevo_edificio)->devolver_receta()->devoler_metal();

    if( ( piedra_necesaria <= cantidad_piedra ) && ( madera_necesaria <= cantidad_madera ) && ( metal_necesario <= cantidad_metal ))
        inventario_suficiente = true;
    else
        imprimir_materiales_necesarios(cantidad_piedra, cantidad_madera, cantidad_metal, piedra_necesaria, madera_necesaria, metal_necesario);
    
    return inventario_suficiente;
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

bool Constructora::validacion_final() {
    bool continuar = false;
    string opcion_elegida = " ";

    cout << "Todo esta listo para empezar la construccion, ¿Quieres continuar? [s/n]"<< endl;
    cin.ignore();
    do{
        cin >> opcion_elegida;
    }while(opcion_elegida != "s" && opcion_elegida != "n");
    if(opcion_elegida == "s"){
        continuar = true;
    }
    return continuar;
}

bool Constructora::validar_coords(int coord1, int coord2) {
    bool coords_ok = false;

    if (coord1 < mapa->devolver_cantidad_filas() && coord2 < mapa->devolver_cantidad_columnas() && coord1 >= 0 &&
        coord2 >= 0) {
        coords_ok = true;
    } else {
        cout << "\nEsa no es una coordenada valida - Intentalo de nuevo o sal con un -1 :)" << endl;
        cout << "Filas disponibles: -> (0, " << mapa->devolver_cantidad_filas() << ") \nColumnas disponibles: -> (0, "
             << mapa->devolver_cantidad_columnas() << ")" << endl;
    }

    return coords_ok;
}


void Constructora::restar_materiales(string nombre_nuevo_edificio, Jugador *jugador){
    Edificacion* edificio = dict_edificios->buscar(nombre_nuevo_edificio);

    jugador->restar_material(edificio->devolver_receta()->devoler_piedra(), PIEDRA);
    jugador->restar_material(edificio->devolver_receta()->devoler_piedra(), MADERA);
    jugador->restar_material(edificio->devolver_receta()->devoler_piedra(), METAL);
}

void Constructora::mostrar_aviso_terreno(bool aviso) {

    if(!aviso)
        cout << "\nEste no es un casillero construible,  para salir presione -1" << endl;
}
