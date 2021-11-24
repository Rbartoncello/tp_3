#include <iostream>
#include "juego.h"
#include "interface.h"

Juego::Juego(){
    this->mapa = new Mapa();
    this->lector_archivos = new Archivo();
    this->inventario_p1 = new Inventario();
    this->inventario_p2 = new Inventario();
}

Juego::~Juego(){
    delete this->mapa;
    delete this->lector_archivos;
    delete this->inventario_p1;
    delete this->inventario_p2;

}

int Juego::cargar() {
    int ejecucion = 0;

    if( lector_archivos->leer_archivos_materiales(inventario_p1,inventario_p2)== ERROR || this->mapa->leer_archivo() == ERROR )
        ejecucion = ERROR;
    
    lector_archivos->leer_archivo_ubicaciones(mapa);
    inventario_p1->mostrar();
    inventario_p2->mostrar();

    return ejecucion;
}

void Juego::nueva_partida(){
    imprimir_menu_nueva_partida();

    int opcion_elegida = pedir_opcion();

    validar_opcion_ingresada(opcion_elegida);

    while(opcion_elegida != GUARDA_SALIR_NUEVA_PARTIDA){
        procesar_opcion_nueva_partida(opcion_elegida);
        imprimir_menu_nueva_partida();

        opcion_elegida = pedir_opcion();
        validar_opcion_ingresada(opcion_elegida);
    }

    imprimir_mensaje_guardado();
}

void Juego::validar_opcion_ingresada(int &opcion_elegida){
    bool es_valida = es_opcion_valida(opcion_elegida);
    while(!es_valida){
        imprimir_mensaje_error_ingreso();

        cin >> opcion_elegida;
        es_valida = es_opcion_valida(opcion_elegida);
    }
}

bool Juego::es_opcion_valida(int opcion){
    return( ( opcion >= MIN_OPCION_NUEVA_PARTIDA ) && ( opcion <= MAX_OPCION_NUEVA_PARTIDA ) );
}

void Juego::procesar_opcion_nueva_partida(int opcion){
    switch (opcion){
        case MODIFICAR_EDIFICIO_POR_NOMBRE:
            cout<<"Modificar Edificio por Nombre"<<endl;
            break;
        case LISTAR_TODOS_EDIFICIOS:
            cout<<"Listar todos los edificios"<<endl;
            break;
        case MOSTAR_MAPA:
            this->mapa->mostrar();
            imprimir_mensaje_enter_continuar();
            break;
        case COMENZAR_PARTIDA:
            cout<<"Comenzar Partida"<<endl;
            break;
        default:
            break;
    }
}

void Juego::mostrar() {
    imprimir_menu_juego();
    imprimir_objetos_mapa();
}

//Pongo esto temporalmente ak pq no puedo usarlo sino
string Juego::buscar_tipo_emoji(string nombre_edificio){
    string emoji;

    if (nombre_edificio == EDIFICIO_MINA){
        emoji = EMOJI_MINA;
    } else if (nombre_edificio == EDIFICIO_ASERRADERO){
        emoji = EMOJI_ASERRADERO;
    } else if (nombre_edificio == EDIFICIO_FABRICA){
        emoji = EMOJI_FABRICA;
    } else if (nombre_edificio == EDIFICIO_ESCUELA){
        emoji = EMOJI_ESCUELA;
    } else if (nombre_edificio == EDIFICIO_OBELISCO){
        emoji = EMOJI_OBELISCO;
    } else if (nombre_edificio == EDIFICIO_PLANTA_ELECTRICA){
        emoji = EMOJI_PLANTA_ENERGIA;
    }

    return emoji;
}

