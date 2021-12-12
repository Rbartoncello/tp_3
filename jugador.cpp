#include <iostream>
#include "jugador.h"
#include "interface.h"
#include "bomba.h"

Jugador::Jugador(int numero, string emoji){
    this->numero = numero;
    this->emoji = emoji;
    energia = 0;
    inventario = new Lista<Material>();
    recursos_acumulados = new Lista<Material>();
    objetivos_secundarios = new Lista<Objetivos>();
    edificios_jugador = new Lista_edificios<Edificacion>();
    energia_acumulada = 0;
}

Jugador::~Jugador(){
    delete inventario;
    delete recursos_acumulados;
    delete objetivos_secundarios;
    delete edificios_jugador;
    delete objetivo_principal;
}

void Jugador::crear_lista(Lista_primitiva<string>* &objetivos){
    objetivos->agregar(COMPRAR_ANDYPOLIS);
    objetivos->agregar(EDAD_PIEDRA);
    objetivos->agregar(BOMBARDERO);
    objetivos->agregar(ENERGETICO);
    objetivos->agregar(LETRADO);
    objetivos->agregar(MINERO);
    objetivos->agregar(CANSADO);
    objetivos->agregar(ARMADO);
    objetivos->agregar(EXTREMISTA);    
}

void Jugador::generar_objetivos(int cantidad_escuelas){
    objetivo_principal = new Obelisco_obj(edificios_jugador);
    Lista_primitiva<string>* objetivos = new Lista_primitiva<string>();
    string nombre_objetivo;
    int posicion = 0, hasta = 9;

    crear_lista(objetivos);

    for (int i = 0; i < 3; i++)
    {
        posicion = numero_aleatorio(1,hasta);
        nombre_objetivo = objetivos->devolver_elemento_en_posicion(posicion);
        agregar_objetivo(nombre_objetivo, cantidad_escuelas);
        objetivos->remover_elemento(posicion);
        hasta--;
    }    

    delete objetivos;
}

void Jugador::agregar_inventario(Material *material){
    inventario->agregar_elemento(material,1);
    if (material->devolver_nombre() != BOMBA)
        recursos_acumulados->agregar_elemento(generar_material(material->devolver_nombre()),1);
}

Material* Jugador::generar_material(string nombre){
    Material *material;

    if (nombre == PIEDRA)
        material = new Piedra;
    else if (nombre == MADERA)
        material = new Madera;
    else if (nombre == METAL)
        material = new Metal;
    else if (nombre == ANDYCOINS)
        material = new Andycoins;

    return material;
}

void Jugador::agregar_objetivo(string nombre_objetivo, int cantidad_escuelas){

    Objetivos* objetivo;

    if (nombre_objetivo == COMPRAR_ANDYPOLIS)
       objetivo = new Comprar_andypolis(inventario->devolver_material(ANDYCOINS));
    else if (nombre_objetivo == BOMBARDERO)
       objetivo = new Bombardero();
    else if (nombre_objetivo == EDAD_PIEDRA)
       objetivo = new Edad_piedra(inventario);
    else if (nombre_objetivo == ARMADO)
        objetivo = new Armado(inventario);
    else if (nombre_objetivo == CANSADO)
        objetivo = new Cansado(energia);
    else if (nombre_objetivo == EXTREMISTA)
        objetivo = new Extremista;
     else if (nombre_objetivo == LETRADO)
        objetivo = new Letrado(edificios_jugador,cantidad_escuelas);
     else if (nombre_objetivo == MINERO)
        objetivo = new Minero(edificios_jugador);
     else if (nombre_objetivo == ENERGETICO)
        objetivo = new Energetico(&energia);
    
    objetivos_secundarios->agregar_elemento(objetivo,1);
}

int Jugador::numero_aleatorio(int desde, int hasta){
    int numero = ( desde + rand() % hasta );
    
    while (numero > hasta)
        numero = ( desde + rand() % hasta );
    return numero;
}

void Jugador::aumentar_material(Material* material){
    inventario->obtener_direccion_nodo(inventario->obtener_posicion(material->devolver_nombre()))->devolver_dato()->aumentar_cantidad(material->devolver_cantidad());    
}

void Jugador::vaciar_inventario(){

    Nodo_lista<Material>* auxiliar = inventario->retornar_primero();

    for (int i = 0; i < inventario->devolver_cantidad_en_lista(); i++){
        auxiliar->devolver_dato()->modificar_cantidad(0);
        auxiliar = auxiliar->direccion_siguiente();
    }
}

void Jugador::pedir_nombre(){
    string nombre_ingresado;
    cout << "\tPor favor ingrese el nobre del jugador: ";
    cin >> nombre_ingresado;

    this -> nombre = nombre_ingresado;
}

void Jugador::restar_energia(int cantidad){
    this -> energia -= cantidad;
}

void Jugador::restar_material(int cantidad, string material){
    int posicion = inventario->obtener_posicion(material);
    inventario->obtener_direccion_nodo(posicion)->devolver_dato()->reducir_cantidad(cantidad);
}

void Jugador::sumar_energia(int cantidad){
    this -> energia += cantidad;
}

void Jugador::recoger_recurso(){
    if (energia >= ENERGIA_RECOLECTAR_RECURSOS){
        sumar_energia(energia_acumulada);
        vaciar_energia_acumulada();
        int cantidad_material = 0;
        int posicion;
        Nodo_lista<Material>* aux = recursos_acumulados->retornar_primero();

        for (int i = 0; i < recursos_acumulados->devolver_cantidad_en_lista(); i++){
            cantidad_material = aux->devolver_dato()->devolver_cantidad();

            posicion = inventario->obtener_posicion(aux->devolver_dato()->devolver_nombre());
            inventario->obtener_direccion_nodo(posicion)->devolver_dato()->aumentar_cantidad(cantidad_material);

            if (aux->devolver_dato()->devolver_nombre() == ANDYCOINS)
                sumar_a_objetivo(cantidad_material,COMPRAR_ANDYPOLIS);

            aux->devolver_dato()->modificar_cantidad(0);
            aux = aux->direccion_siguiente();
            }
        imprimir_mensaje_recolectando_recursos_producidos();
        restar_energia(ENERGIA_RECOLECTAR_RECURSOS);
    } else
        imprimir_mensaje_no_energia_sufuciente(ENERGIA_RECOLECTAR_RECURSOS);
}

Lista<Material>*& Jugador::devolver_inventario(){
    return(inventario);
}

void Jugador::modificar_numero(int numero){
    this->numero = numero;
}

void Jugador::modificar_fila(int fila){
    this->fila = fila;
}

void Jugador::modificar_columna(int columna){
    this->columna = columna;
}

void Jugador::mostrar_inventario(){
    imprimir_materiales_jugador(inventario->retornar_primero(),inventario->devolver_cantidad_en_lista());
}

int Jugador::devolver_fila(){
    return fila;
}

int Jugador::devolver_columna(){
    return columna;
}

int Jugador::devolver_numero(){
    return numero;
}

int Jugador::devolver_energia(){
    return energia;
}

string Jugador::devolver_emoji(){
    return emoji;
}

void Jugador::comprar_bombas(){
    if (devolver_energia() >= ENERGIA_COMPRAR_BOMBAS){
        imprimir_tienda_bombas();
        int cantidad;
        cin >> cantidad;
        while (cantidad <= 0){
            imprimir_mensaje_error_ingreso();
            cin >> cantidad;
        }
        if (andycoins_sufuciente(cantidad * COSTO_POR_BOMBA)){
            comprar_bombas(cantidad);
            restar_energia(ENERGIA_COMPRAR_BOMBAS);
            imprimir_mensaje_bombas_compradas(inventario, cantidad);
            sumar_a_objetivo(cantidad,EXTREMISTA);
        }
        else 
            imprimir_mensaje_sin_andycoins_suficientes(cantidad * COSTO_POR_BOMBA);

    } else
        imprimir_mensaje_no_energia_sufuciente(ENERGIA_COMPRAR_BOMBAS);
}

bool Jugador::andycoins_sufuciente(int costo){
    int posicion = devolver_inventario()->obtener_posicion(ANDYCOINS);

    int cantidad = devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->devolver_cantidad();

    return ( costo <= cantidad );
}

void Jugador::comprar_bombas(int cantidad){
    restar_material( ( cantidad * COSTO_POR_BOMBA ), ANDYCOINS);

    int posicion = devolver_inventario()->obtener_posicion(BOMBA);

    devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->aumentar_cantidad(cantidad);
}

void Jugador::mostrar_objetivos(){
    int cantidad_lista =  objetivos_secundarios->devolver_cantidad_en_lista();
    Nodo_lista<Objetivos>* auxiliar = objetivos_secundarios->retornar_primero();
    
    encabezado_objetivos_secuncarios();

    for (int i = 0; i < cantidad_lista; i++){
        auxiliar->devolver_dato()->mostrar_descripcion();
        if (i < cantidad_lista - 1)
                cout << "\t╠────────────────────┼───────────────────────────────────────────────────────────────┼──────────────────────────┼────────────╣" << endl;
        auxiliar = auxiliar->direccion_siguiente();
    }
    cout << "\t╚════════════════════╩═══════════════════════════════════════════════════════════════╩══════════════════════════╩════════════╝" << endl;
}

void Jugador::sumar_a_objetivo(int cantidad, string nombre_objetivo){

    int contador = 0;
    Nodo_lista<Objetivos>* objetivo;
    string nombre_objetivo_auxiliar;
    bool encontrado = true;

    while (encontrado && contador<3)
    {
        objetivo = objetivos_secundarios->obtener_direccion_nodo(contador);    
        nombre_objetivo_auxiliar = objetivo->devolver_dato()->devolver_tipo_objetivo();
        contador++;
        if (nombre_objetivo == nombre_objetivo_auxiliar)
            encontrado = false;        
    }

    if (!encontrado)
        objetivo->devolver_dato()->agregar_datos(cantidad);    
}

bool Jugador::validar_objetivos(){
    objetivo_principal->verificar_estado_objetivo();

    if (!objetivo_principal->devolver_estado_objetivo())

        return(contar_objetivos_completados(0) == OBJETIVOS_SECUNDARIOS_CUMPLIDOS);

    return true;
}

int Jugador::contar_objetivos_completados(int contador){

    int objetivos_realizados = 0;
    Nodo_lista<Objetivos>* objetivo_verificacion = objetivos_secundarios->obtener_direccion_nodo(contador);
    objetivo_verificacion->devolver_dato()->verificar_estado_objetivo();

    if (objetivo_verificacion->devolver_dato()->devolver_estado_objetivo())
        objetivos_realizados++;

    if (contador < 2)
        objetivos_realizados = objetivos_realizados + contar_objetivos_completados(contador+1);

    return objetivos_realizados;
}

void Jugador::acumular_recursos(string material, int cantidad){
    if(material != ENERGIA){
        int posicion = recursos_acumulados->obtener_posicion(material);
        recursos_acumulados->obtener_direccion_nodo(posicion)->devolver_dato()->aumentar_cantidad(cantidad);
    } else
        sumar_energia_acumulada(cantidad);
}

int Jugador::devolver_energia_acumulada(){
    return energia_acumulada;
}

void Jugador::vaciar_energia_acumulada(){
    energia_acumulada = 0;
}

void Jugador::sumar_energia_acumulada(int cantidad){
    energia_acumulada += cantidad;
}

Lista_edificios<Edificacion>*& Jugador::devolver_mis_edificios(){
    return edificios_jugador;
}