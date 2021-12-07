#include <iostream>
#include "jugador.h"
#include "interface.h"

Jugador::Jugador(int numero, string emoji){
    this->numero = numero;
    this->emoji = emoji;
    energia = 0;
    inventario = new Lista<Material>();
    objetivos_secundarios = new Lista<Objetivos>();
    //objetivo_primario = new Mas_alto_que_las_nubes();
    //generar_objetivos_secundarios();
}

Jugador::~Jugador(){
    delete this->inventario;
    delete this->objetivos_secundarios;
}

void Jugador::crear_lista(Lista_primitiva<string>* &objetivos){
     
    objetivos->agregar(COMPRAR_ANDYPOLIS);
    objetivos->agregar(EDAD_PIEDRA);
    objetivos->agregar(BOMBARDERO);
    //objetivos->agregar(ENERGETICO);
    //objetivos->agregar(LETRADO);
    //objetivos->agregar(MINERO);
    //objetivos->agregar(CANSADO);
    //objetivos->agregar(ARMADO);
    //objetivos->agregar(EXTREMISTA);    
    
}

void Jugador::generar_objetivos_secundarios(){
    Lista_primitiva<string>* objetivos = new Lista_primitiva<string>();
    string nombre_objetivo;
    int posicion = 0, hasta = 3;

    crear_lista(objetivos);

    for (int i = 0; i < 3; i++)
    {
        posicion = numero_aleatorio(1,hasta);
        nombre_objetivo = objetivos->devolver_elemento_en_posicion(posicion);
        agregar_objetivo(nombre_objetivo);
        objetivos->remover_elemento(posicion);
        hasta--;
    }    

    delete objetivos;
}

void Jugador::agregar_objetivo(string nombre_objetivo){

    Objetivos* objetivo;

    if (nombre_objetivo == COMPRAR_ANDYPOLIS)
       objetivo = new Comprar_andypolis(inventario->devolver_material(ANDYCOINS));
    else if (nombre_objetivo == BOMBARDERO)
       objetivo = new Bombardero();
    else if (nombre_objetivo == EDAD_PIEDRA)
       objetivo = new Edad_piedra(inventario);
    
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

void Jugador::restar_piedra(int cantidad){
    int posicion = devolver_inventario()->obtener_posicion(PIEDRA);
    devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->reducir_cantidad(cantidad);
}

void Jugador::restar_madera(int cantidad){
    int posicion = devolver_inventario()->obtener_posicion(MADERA);
    devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->reducir_cantidad(cantidad);
}

void Jugador::restar_metal(int cantidad){
    int posicion = devolver_inventario()->obtener_posicion(METAL);
    devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->reducir_cantidad(cantidad);
}

void Jugador::sumar_energia(int cantidad){
    this -> energia += cantidad;
}

void Jugador::recoger_recurso(Material* recurso){
    //this->inventario->sumar_material(recurso)    (me falta hacer el metodo en materiales en el que sume un material al array al recibir un Material*)
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
    gastar_andycoins( cantidad * COSTO_POR_BOMBA );

    int posicion = devolver_inventario()->obtener_posicion(BOMBA);

    devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->aumentar_cantidad(cantidad);
}

void Jugador::gastar_andycoins(int precio){
    int posicion = devolver_inventario()->obtener_posicion(ANDYCOINS);
    devolver_inventario()->obtener_direccion_nodo(posicion)->devolver_dato()->reducir_cantidad(precio);
}

void Jugador::mostrar_objetivos(){
    int cantidad_lista =  objetivos_secundarios->devolver_cantidad_en_lista();
    Nodo_lista<Objetivos>* auxiliar = objetivos_secundarios->retornar_primero();


    for (int i = 0; i < cantidad_lista; i++)
    {
        cout << i+1 << ": ";
        auxiliar->devolver_dato()->mostrar_descripcion();
        cout << "\n";
        auxiliar = auxiliar->direccion_siguiente();
    }
}

void Jugador::sumar_a_objetivo(int cantidad, string nombre_objetivo){

    int contador = 0;
    Nodo_lista<Objetivos>* objetivo;
    string nombre_objetivo_auxiliar;
    bool encontrado = true;

    while (encontrado && contador<3)
    {
        contador++;
        objetivo = objetivos_secundarios->obtener_direccion_nodo(contador);    
        nombre_objetivo_auxiliar = objetivo->devolver_dato()->devolver_tipo_objetivo();

        if (nombre_objetivo == nombre_objetivo_auxiliar)
            encontrado = false;        
    }

    if (!encontrado)
        objetivo->devolver_dato()->agregar_datos(cantidad);    
}

bool Jugador::validar_objetivos(){

    return(false);
}

int Jugador::contar_objetivos_completados(int contador){

    //int objetivos_realizados = 0;
    //Nodo_lista<Objetivos>* objetivo_verificacion;
    //objetivo_verificacion = objetivos_secundarios->obtener_direccion_nodo(contador);

   /* if (objetivo_verificacion->devolver_dato()->devolver_estado_objetivo())
        objetivos_realizados++;

    if (contador < 3)
        objetivos_realizados = objetivos_realizados + contar_objetivos_completados(contador+1);*/

    return 0;
}