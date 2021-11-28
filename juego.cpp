#include <iostream>
#include "juego.h"
#include "interface.h"

Juego::Juego(){
    this->mapa = new Mapa();
    this->lector_archivos = new Archivo();
    this->jugador_1 = new Jugador(1);
    this->jugador_2 = new Jugador(2);
    this->inventario_jugador1 = jugador_1->devolver_inventario();
    this->inventario_jugador2 = jugador_2->devolver_inventario();
    this->edificios_disponibles = new Diccionario<Edificacion>();

}

Juego::~Juego(){
    delete this->mapa;
    delete this->lector_archivos;
    delete this->edificios_disponibles;
    delete this->jugador_1;
    delete this->jugador_2;
}

int Juego::cargar() {
    int ejecucion = 0;

    if( lector_archivos->leer_archivos_materiales(inventario_jugador1,inventario_jugador2,mapa)== ERROR || this->mapa->leer_archivo() == ERROR || lector_archivos->leer_archivos_edificios( this->edificios_disponibles) == ERROR )
        ejecucion = ERROR;

    return ejecucion;
}

int Juego::archivo_ubicaciones(){
    return lector_archivos->leer_archivo_ubicaciones(mapa, this->edificios_disponibles);
}

void Juego::nueva_partida(){
    imprimir_menu_nueva_partida();

    bool empezo_juego = false;

    int opcion_elegida = pedir_opcion(12, 0);

    validar_opcion_ingresada(opcion_elegida, MAX_OPCION_NUEVA_PARTIDA, MIN_OPCION_NUEVA_PARTIDA);

    while( (opcion_elegida != GUARDA_SALIR_NUEVA_PARTIDA) && !empezo_juego ){
        procesar_opcion_nueva_partida(opcion_elegida);
        if(opcion_elegida != COMENZAR_PARTIDA){
            imprimir_menu_nueva_partida();

            opcion_elegida = pedir_opcion(12, 0);
            validar_opcion_ingresada(opcion_elegida, MAX_OPCION_NUEVA_PARTIDA, MIN_OPCION_NUEVA_PARTIDA);
        } else
            empezo_juego = true;
    }
    this->edificios_disponibles->guardar_pre_orden();
    imprimir_mensaje_guardado();
}

void Juego::procesar_opcion_nueva_partida(int opcion){
    switch (opcion){
        case MODIFICAR_EDIFICIO_POR_NOMBRE:
            modificar_edificio(this->edificios_disponibles);
            break;
        case LISTAR_TODOS_EDIFICIOS:
            this->edificios_disponibles->listar_en_orden(this->mapa);
            imprimir_mensaje_enter_continuar();
            break;
        case MOSTAR_MAPA:
            this->mapa->mostrar();
            imprimir_mensaje_enter_continuar();
            break;
        case COMENZAR_PARTIDA:
            comenzar_partida();
            break;
    }
}

void Juego::mostrar() {
    imprimir_menu_juego(this->mapa, this->jugador_actual);
    imprimir_objetos_mapa();
}

void Juego::modificar_receta(Diccionario<Edificacion>*&edificios_disponibles, string nombre_edificio, string material){
    int opcion;
    int cantidad = edificios_disponibles->buscar(nombre_edificio)->devolver_receta()->devolver_material(material);
    imprimir_mensaje_receta_edificio(nombre_edificio, material, cantidad);
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
        edificios_disponibles->buscar(nombre_edificio)->devolver_receta()->modificar_receta(material, cantidad);
    }
}

bool Juego::ingreso_afirmativo_negativo_valido(int ingreso){
    return ( ( ingreso == AFIRMATIVO ) || ( ingreso == NEGATIVO ) );
}

bool Juego::cantidad_valida(int ingreso){
    return ( ( ingreso >= MIN_RECETA_MODIFICAR ) && ( ingreso <= MAX_RECETA_MODIFICAR ) );
}

void Juego::modificar_edificio(Diccionario<Edificacion>*&edificios_disponibles){
    string nombre_edificio;
    imprimir_mensaje_ingresar_edificio();
    cin.ignore();
    getline(cin, nombre_edificio);

    while ( !edificios_disponibles->existe(nombre_edificio) ){
        imprimir_mensaje_error_ingresar_edificio();
        cin >> nombre_edificio;
    }
    if (nombre_edificio != EDIFICIO_OBELISCO){
        modificar_receta(edificios_disponibles, nombre_edificio, EMOJI_PIEDRA);
        modificar_receta(edificios_disponibles, nombre_edificio, EMOJI_MADERA);
        modificar_receta(edificios_disponibles, nombre_edificio, EMOJI_METAL);
    } else {
        imprimir_mensaje_error_ingresar_edificio_obelisco();
    }
}

void Juego::comenzar_partida(){
    ingresar_primer_jugador();
    
    partida_empezada();
}

void Juego::ingresar_primer_jugador(){
    int numero_jugador = 0;
    imprimir_mensaje_ingrese_jugador();
    cin >> numero_jugador;
    validar_opcion_ingresada(numero_jugador, JUGADOR_2, JUGADOR_1);
    
    if (numero_jugador == JUGADOR_1){
        this->mapa->mostrar();
        cout << "Jugador: "<< JUGADOR_1 << endl;
        posicionar_jugador_mapa(jugador_1);
        cout << "Jugador: "<< JUGADOR_2 << endl;
        posicionar_jugador_mapa(jugador_2);
    } else {
        this->mapa->mostrar();
        cout << "Jugador: " << JUGADOR_2 << endl;
        posicionar_jugador_mapa(jugador_2);
        cout << "Jugador: " << JUGADOR_1 << endl;
        posicionar_jugador_mapa(jugador_1);
    }
}

void Juego::posicionar_jugador_mapa(Jugador *&jugador){
    int fila, columna;
    imprimir_mensaje_ingrese_fila_jugador();
    cin >> fila;
    validar_opcion_ingresada(fila, this->mapa->devolver_cantidad_filas(), 0);
    imprimir_mensaje_ingrese_columna_jugador();
    cin >> columna;
    validar_opcion_ingresada(columna, this->mapa->devolver_cantidad_columnas(), 0);
    /*
    *
    * VALIDAD SI SE PUEDE METER EN EL MAPA
    *
    */
    jugador->modificar_fila(fila);
    jugador->modificar_columna(columna);
}

void Juego::partida_empezada(){
    this->jugador_actual = numero_aleatorio(JUGADOR_1,JUGADOR_2);
    imprimir_menu_juego(this->mapa, this->jugador_actual);

    int opcion_elegida = pedir_opcion(29, 60);

    validar_opcion_ingresada(opcion_elegida, MAX_OPCION_JUEGO, MIN_OPCION_JUEGO);

    while(opcion_elegida != GUARDA_SALIR){
        procesar_opcion_partida_empezada(opcion_elegida);
        imprimir_menu_juego(this->mapa, this->jugador_actual);

        opcion_elegida = pedir_opcion(29, 60);
        validar_opcion_ingresada(opcion_elegida, MAX_OPCION_JUEGO, MIN_OPCION_JUEGO);
    }
    this->edificios_disponibles->guardar_pre_orden();
    imprimir_mensaje_guardado();
}

int Juego::numero_aleatorio(int desde, int hasta){
    srand (( unsigned)time(NULL));
    int numero = ( desde + rand() % hasta );
    
    while (numero > hasta)
        numero = ( desde + rand() % hasta );
    return numero;
}

void Juego::validar_opcion_ingresada(int &opcion_elegida, int max, int min){
    bool es_valida = es_opcion_valida(opcion_elegida, max, min);
    while(!es_valida){
        imprimir_mensaje_error_ingreso();

        cin >> opcion_elegida;
        es_valida = es_opcion_valida(opcion_elegida, max, min);
    }
}

bool Juego::es_opcion_valida(int opcion, int max, int min){
    return( ( opcion >= min ) && ( opcion <= max ) );
}

void Juego::procesar_opcion_partida_empezada(int opcion){
    switch (opcion){
        case CONSTRUIR_EDIFICIO_NOMBRE:
            this->mapa->mostrar();
            break;
        case LISTAR_MIS_EDIFICIOS_CONSTRUIDOS:
            break;
        case DEMOLER_EDIFICIO_COORDENADA:
            this->mapa->mostrar();
            imprimir_mensaje_enter_continuar();
            break;
        case ATARCAR_EDIFICIO_COORDENADA:
            this->mapa->mostrar();
            imprimir_mensaje_enter_continuar();
            break;
        case REPARAR_EDIFICIO_COORDENADA:
            this->mapa->mostrar();
            imprimir_mensaje_enter_continuar();
            break;
        case COMPRAR_BOMBA:
            break;
        case CONSULTAR_COORDENADA:
            this->mostrar_coordenada();
            imprimir_mensaje_enter_continuar();
            break;
        case MOSTRAR_INVENTARIO:
           // this->inventario_jugador1->listar_en_orden(mapa); // Aca deberia mostrar solo uno de estos, dependiendo de quien sea el turno
           // this->inventario_jugador2->listar_en_orden(mapa);
            imprimir_mensaje_enter_continuar();
            break;
        case MOSTRAR_OBJETIVOS:
            cout<<"Mostrar Objetivos"<<endl;
            break;
        case RECOLECTAR_RECURSOS:
            cout<<"Recolectar recursos"<<endl;
            break;
        case MOVERSE_COORDENADA:
            cout<<"Moverse Coordeanada"<<endl;
            break;
        case FINALIZAR_TURNO:
            cout<<"Aqui finalizaría el turno"<<endl;
            break;
    }
}



int Juego::pedir_fila(){
    int opcion_elegida = 0;
    cout << " Por favor ingrese la fila: ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

int Juego::pedir_columna(){
    int opcion_elegida = 0;
    cout << " Por favor ingrese la columna: ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

void Juego::validar_fila(int &fila){
    bool es_valida = (fila >= 0 && fila < (this->mapa->devolver_cantidad_filas()));
    while(!es_valida){
        this->imprimir_mensaje_error_ingreso();

        cin >> fila;
        es_valida = (fila >= 0 && fila < this->mapa->devolver_cantidad_filas());
    }
}

void Juego::validar_columna(int &columna){
    bool es_valida = (columna >= 0 && columna < this->mapa->devolver_cantidad_columnas());
    while(!es_valida){
        this->imprimir_mensaje_error_ingreso();

        cin >> columna;
        es_valida = (columna >= 1 && columna < this->mapa->devolver_cantidad_columnas());
    }
}

void Juego::imprimir_mensaje_error_ingreso(){
    imprimir_mensaje_error();
    cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
}

void Juego::mostrar_coordenada(){
    system("clear");

    int fila = this->pedir_fila();
    this->validar_fila(fila);

    int columna = this->pedir_columna();
    this->validar_columna(columna);

    system("clear");
    this->mapa->imprimir_resumen_casillero(fila, columna);    
}