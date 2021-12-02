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
        avanzar_con_construccion(nombre_nuevo_edifcio);
    else{
        cout << "\n Oh, no construyes nada?, bueno, vuelve pronto la constructora de Andypolis necesita trabajar\n" << endl;
    }
}

void Constructora::avanzar_con_construccion(string nombre_nuevo_edifcio){

    bool coordenadas_validas = false, materiales_validos = false, validar_terreno_vacio = false, cantidad_construida = false;
    string edificio;

    cantidad_construida = validar_maximo_edificio(nombre_nuevo_edifcio); //FUNCIONA, falta que los edificios sepan de quien son para validar cuantos hay de un juegador en particualar
    if(cantidad_construida)
    {
        cout<<"ANASHE"<<endl;
    }
    else{
        cout<<"ANASHEN´t"<<endl;
    }
/*
    if(cantidad_construida)
        materiales_validos = validar_materiales(nombre_nuevo_edifcio);
    else{
        cout << "\nOh, lamento traer malas noticias pero ya has alcanzo el maximo de construidos para este edificio: ";
    }

    if(materiales_validos)
        coordenadas_validas = ingreso_de_coordenadas();

    if(coordenadas_validas){
        edificio = mapa->devolverTipoEdificio(fila_para_trabajar,columna_para_trabajar);
        validar_terreno_vacio = terreno_vacio(edificio);
    }

    if (validar_terreno_vacio){
        mapa->construirEdificio(filaParaTrabajar,columnaParaTrabajar,nombreNuevoEdificio);
        restarMateriales(nombreNuevoEdificio);
        cout << "\n EL EDIFICIO SE HA CONSTRUIDO\n" << endl;
    }
    else if (materiales_validos && (!validar_terreno_vacio)){
        cout << "\nAcaso has perdido la cabeza?, aqui ya hay un edificio: ";
    }*/
}

bool Constructora::validar_maximo_edificio(string nombre_nuevo_edificio){
    int maxima_cantidad_permitidos = 0, cantidad_actual = 0;

    maxima_cantidad_permitidos = dict_edificios->buscar(nombre_nuevo_edificio)->devolver_maxima_cantidad_permitidos();

    cantidad_actual = mapa->devolver_cantidad_edificio(nombre_nuevo_edificio);

    return(cantidad_actual<maxima_cantidad_permitidos);
}


void Constructora::mostrar_aviso(){
    cout << "\n EL edificio que intenta crear no existe, para salir presione 1" << endl;
}