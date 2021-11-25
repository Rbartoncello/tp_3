#include <iostream>
#include "juego.h"
#include "interface.h"

Juego::Juego(){
    this->mapa = new Mapa();
    this->lector_archivos = new Archivo();
    this->inventario_p1 = new Inventario();
    this->inventario_p2 = new Inventario();
    this->diccionario = new Diccionario();
}

Juego::~Juego(){
    delete this->mapa;
    delete this->lector_archivos;
    delete this->inventario_p1;
    delete this->inventario_p2;
    delete this->diccionario;
}

int Juego::cargar() {
    int ejecucion = 0;

    if( lector_archivos->leer_archivos_materiales(inventario_p1,inventario_p2)== ERROR || this->mapa->leer_archivo() == ERROR || lector_archivos->leer_archivos_edificios( this->diccionario) == ERROR )
        ejecucion = ERROR;

    return ejecucion;
}

int Juego::archivo_ubicaciones(){
    return lector_archivos->leer_archivo_ubicaciones(mapa);
}

void Juego::nueva_partida(){
    imprimir_menu_nueva_partida();

    bool empezo_juego = false;

    int opcion_elegida = pedir_opcion();

    validar_opcion_ingresada_nueva_partida(opcion_elegida);

    while( (opcion_elegida != GUARDA_SALIR_NUEVA_PARTIDA) && !empezo_juego ){
        procesar_opcion_nueva_partida(opcion_elegida);
        if(opcion_elegida != COMENZAR_PARTIDA){
            imprimir_menu_nueva_partida();

            opcion_elegida = pedir_opcion();
            validar_opcion_ingresada_nueva_partida(opcion_elegida);
        } else
            empezo_juego = true;
    }
    this->diccionario->guardar_pre_orden();
    imprimir_mensaje_guardado();
}

void Juego::validar_opcion_ingresada_nueva_partida(int &opcion_elegida){
    bool es_valida = es_opcion_valida_nueva_partida(opcion_elegida);
    while(!es_valida){
        imprimir_mensaje_error_ingreso();

        cin >> opcion_elegida;
        es_valida = es_opcion_valida_nueva_partida(opcion_elegida);
    }
}

bool Juego::es_opcion_valida_nueva_partida(int opcion){
    return( ( opcion >= MIN_OPCION_NUEVA_PARTIDA ) && ( opcion <= MAX_OPCION_NUEVA_PARTIDA ) );
}

void Juego::procesar_opcion_nueva_partida(int opcion){
    switch (opcion){
        case MODIFICAR_EDIFICIO_POR_NOMBRE:
            modificar_edificio(this->diccionario);
            break;
        case LISTAR_TODOS_EDIFICIOS:
            this->diccionario->listar_en_orden(this->mapa);
            imprimir_mensaje_enter_continuar();
            break;
        case MOSTAR_MAPA:
            this->mapa->mostrar();
            imprimir_mensaje_enter_continuar();
            break;
        case COMENZAR_PARTIDA:
            partida_empezada();
            break;
    }
}

void Juego::mostrar() {
    imprimir_menu_juego();
    imprimir_objetos_mapa();
}

void Juego::modificar_receta(Diccionario* diccionario, string nombre_edificio, string material){
    int opcion;
    imprimir_mensaje_receta_edificio(nombre_edificio, material, diccionario->buscar(nombre_edificio)->devolver_receta(material));
    imprimir_mensaje_afirmativo_negativo();
    cin >> opcion;

    while ( !ingreso_afirmativo_negativo_valido(opcion) ){
        imprimir_mensaje_error_ingreso();
        cin >> opcion;
    }
    if( opcion == AFIRMATIVO ){
        imprimir_mensaje_receta_modificar();
        int cantidad;
        cin >> cantidad;
        while ( !cantidad_valida(cantidad) ){
            imprimir_mensaje_error_ingreso();
            cin >> cantidad;
        }
        diccionario->buscar(nombre_edificio)->modificar_receta(material, cantidad);
    }
}

bool Juego::ingreso_afirmativo_negativo_valido(int ingreso){
    return ( ( ingreso == AFIRMATIVO ) || ( ingreso == NEGATIVO ) );
}

bool Juego::cantidad_valida(int ingreso){
    return ( ( ingreso >= MIN_RECETA_MODIFICAR ) && ( ingreso <= MAX_RECETA_MODIFICAR ) );
}

void Juego::modificar_edificio(Diccionario* diccionario){
    string nombre_edificio;
    imprimir_mensaje_ingresar_edificio();
    cin.ignore();
    getline(cin, nombre_edificio);

    while ( !diccionario->existe(nombre_edificio) ){
        imprimir_mensaje_error_ingresar_edificio();
        cin >> nombre_edificio;
    }
    if (nombre_edificio != EDIFICIO_OBELISCO){
        modificar_receta(diccionario, nombre_edificio, EMOJI_PIEDRA);
        modificar_receta(diccionario, nombre_edificio, EMOJI_MADERA);
        modificar_receta(diccionario, nombre_edificio, EMOJI_METAL);
    } else {
        imprimir_mensaje_error_ingresar_edificio_obelisco();
    }
}

void Juego::partida_empezada(){
    imprimir_menu_juego();

    int opcion_elegida = pedir_opcion();

    validar_opcion_ingresada_partida_empezada(opcion_elegida);

    while(opcion_elegida != GUARDA_SALIR){
        procesar_opcion_partida_empezada(opcion_elegida);
        imprimir_menu_juego();

        opcion_elegida = pedir_opcion();
        validar_opcion_ingresada_partida_empezada(opcion_elegida);
    }
    this->diccionario->guardar_pre_orden();
    imprimir_mensaje_guardado();
}

void Juego::validar_opcion_ingresada_partida_empezada(int &opcion_elegida){
    bool es_valida = es_opcion_valida_partida_empezada(opcion_elegida);
    while(!es_valida){
        imprimir_mensaje_error_ingreso();

        cin >> opcion_elegida;
        es_valida = es_opcion_valida_partida_empezada(opcion_elegida);
    }
}

bool Juego::es_opcion_valida_partida_empezada(int opcion){
    return( ( opcion >= MIN_OPCION_JUEGO ) && ( opcion <= MAX_OPCION_JUEGO ) );
}

void Juego::procesar_opcion_partida_empezada(int opcion){
    switch (opcion){
        case CONSTRUIR_EDIFICIO_NOMBRE:
            this->mapa->mostrar();
            break;
        case LISTAR_MIS_EDIFICIOS_CONSTRUIDOS:
            break;
        case DEMOLER_EDIFICIO_COORDENADA:
            break;
        case ATARCAR_EDIFICIO_COORDENADA:
            break;
        case REPARAR_EDIFICIO_COORDENADA:
            break;
        case COMPRAR_BOMBA:
            break;
        case CONSULTAR_COORDENADA:
            break;
        case MOSTRAR_INVENTARIO:
            this->inventario_p1->mostrar();
            this->inventario_p2->mostrar();
            imprimir_mensaje_enter_continuar();
            break;
        case MOSTRAR_OBJETIVOS:
            break;
        case RECOLECTAR_RECURSOS:
            break;
        case MOVERSE_COORDENAD:
            break;
        case FINALIZAR_TURNO:
            break;
    }
}
