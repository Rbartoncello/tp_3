#include <iostream>
#include "juego.h"

Juego::Juego()
{
    this->mapa = new Mapa();
    this->grafo = new Grafo;
    this->lector_archivos = new Archivo();
    this->diccionario = new Diccionario<Edificacion>();
    this->jugador_1 = new Jugador(JUGADOR_1, EMOJI_JUGADOR_1);
    this->jugador_2 = new Jugador(JUGADOR_2, EMOJI_JUGADOR_2);
    this->constructora = new Constructora(diccionario, mapa);
}

Juego::~Juego()
{
    delete this->mapa;
    delete this->grafo;
    delete this->lector_archivos;
    delete this->diccionario;
    delete this->jugador_1;
    delete this->jugador_2;
    delete this->constructora;
}

int Juego::cargar()
{
    int ejecucion = 0;

    if (lector_archivos->leer_archivos_materiales(jugador_1, jugador_2) == ERROR || this->mapa->leer_archivo() == ERROR || lector_archivos->leer_archivos_edificios(this->diccionario, mapa) == ERROR)
        ejecucion = ERROR;

    return ejecucion;
}

int Juego::archivo_ubicaciones()
{
    return lector_archivos->leer_archivo_ubicaciones(mapa, this->diccionario, jugador_1, jugador_2);
}

void Juego::nueva_partida()
{
    vaciar_inventario();

    imprimir_menu_nueva_partida();

    bool empezo_juego = false;

    int opcion_elegida = pedir_opcion(12, 0);

    validar_opcion_ingresada(opcion_elegida, MAX_OPCION_NUEVA_PARTIDA, MIN_OPCION_NUEVA_PARTIDA);

    while ((opcion_elegida != GUARDA_SALIR_NUEVA_PARTIDA) && !empezo_juego)
    {
        procesar_opcion_nueva_partida(opcion_elegida);
        if (opcion_elegida != COMENZAR_PARTIDA)
        {
            imprimir_menu_nueva_partida();

            opcion_elegida = pedir_opcion(12, 0);
            validar_opcion_ingresada(opcion_elegida, MAX_OPCION_NUEVA_PARTIDA, MIN_OPCION_NUEVA_PARTIDA);
        }
        else
            empezo_juego = true;
    }
    this->diccionario->guardar_pre_orden();
    imprimir_mensaje_guardado();
}

void Juego::vaciar_inventario()
{
    jugador_1->vaciar_inventario();
    jugador_2->vaciar_inventario();
}

void Juego::procesar_opcion_nueva_partida(int opcion)
{
    switch (opcion)
    {
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
        comenzar_partida();
        break;
    }
}

void Juego::modificar_receta(Diccionario<Edificacion> *&diccionario, string nombre_edificio, string material)
{
    int opcion;
    int cantidad = diccionario->buscar(nombre_edificio)->devolver_receta()->devolver_material(material);
    imprimir_mensaje_receta_edificio(nombre_edificio, material, cantidad);
    imprimir_mensaje_afirmativo_negativo();
    cin >> opcion;

    while (!ingreso_afirmativo_negativo_valido(opcion))
    {
        imprimir_mensaje_error_ingreso();
        cin >> opcion;
    }
    if (opcion == AFIRMATIVO)
    {
        imprimir_mensaje_receta_modificar();
        int cantidad;
        cin >> cantidad;
        while (!cantidad_valida(cantidad))
        {
            imprimir_mensaje_error_ingreso();
            cin >> cantidad;
        }
        diccionario->buscar(nombre_edificio)->devolver_receta()->modificar_receta(material, cantidad);
    }
}

bool Juego::ingreso_afirmativo_negativo_valido(int ingreso)
{
    return ((ingreso == AFIRMATIVO) || (ingreso == NEGATIVO));
}

bool Juego::cantidad_valida(int ingreso)
{
    return ((ingreso >= MIN_RECETA_MODIFICAR) && (ingreso <= MAX_RECETA_MODIFICAR));
}

void Juego::modificar_edificio(Diccionario<Edificacion> *&diccionario)
{
    string nombre_edificio;
    imprimir_mensaje_ingresar_edificio();
    cin.ignore();
    getline(cin, nombre_edificio);

    while (!diccionario->existe(nombre_edificio))
    {
        imprimir_mensaje_error_ingresar_edificio();
        cin >> nombre_edificio;
    }
    if (nombre_edificio != EDIFICIO_OBELISCO)
    {
        modificar_receta(diccionario, nombre_edificio, EMOJI_PIEDRA);
        modificar_receta(diccionario, nombre_edificio, EMOJI_MADERA);
        modificar_receta(diccionario, nombre_edificio, EMOJI_METAL);
    }
    else
    {
        imprimir_mensaje_error_ingresar_edificio_obelisco();
    }
}

void Juego::comenzar_partida()
{
    ingresar_primer_jugador();
    this->mapa->lluvia_recursos();
    this->toca_lluvia = false;
    partida_empezada();
}

void Juego::ingresar_primer_jugador()
{
    int numero_jugador = 0;
    imprimir_mensaje_ingrese_jugador();
    cin >> numero_jugador;
    validar_opcion_ingresada(numero_jugador, JUGADOR_2, JUGADOR_1);

    if (numero_jugador == JUGADOR_1)
    {
        this->mapa->mostrar();
        cout << "Jugador: " << JUGADOR_1 << endl;
        posicionar_jugador_mapa(jugador_1);
        cout << "Jugador: " << JUGADOR_2 << endl;
        posicionar_jugador_mapa(jugador_2);
    }
    else
    {
        this->mapa->mostrar();
        cout << "Jugador: " << JUGADOR_2 << endl;
        posicionar_jugador_mapa(jugador_2);
        cout << "Jugador: " << JUGADOR_1 << endl;
        posicionar_jugador_mapa(jugador_1);
    }
}

void Juego::posicionar_jugador_mapa(Jugador *&jugador)
{
    int fila = pedir_fila();
    int columna = pedir_columna();

    jugador->modificar_fila(fila);
    jugador->modificar_columna(columna);

    mapa->agregar_jugador(jugador);
}

void Juego::jugador_inicial()
{
    int primer_jugador = numero_aleatorio(JUGADOR_1, JUGADOR_2);

    if (primer_jugador == 1)
        jugador_actual = jugador_1;
    else
        jugador_actual = jugador_2;
}

int Juego::validar_ganador(int opcion_elegida, bool* partida_ganada)
{
    *partida_ganada = jugador_actual->validar_objetivos();

    if (opcion_elegida != GUARDA_SALIR && *partida_ganada)
    {
        opcion_elegida = GUARDA_SALIR;
        imprimir_juego_ganado(jugador_actual->devolver_numero());
    }

    return opcion_elegida;
}

int Juego::mostrar_opciones()
{
    int opcion_elegida = 0;

    if (jugador_actual->devolver_energia() == 0)
    {
        imprimir_mensaje_finalizacion_turno_automatico(jugador_actual);
        opcion_elegida = FINALIZAR_TURNO;
    }
    else
    {
        imprimir_menu_juego(mapa, jugador_actual);

        opcion_elegida = pedir_opcion(29, 60);
        validar_opcion_ingresada(opcion_elegida, MAX_OPCION_JUEGO, MIN_OPCION_JUEGO);
    }
    procesar_opcion_partida_empezada(opcion_elegida);

    return opcion_elegida;
}

void Juego::crear_todo_objetivos()
{

    int cantidad_escuelas = diccionario->buscar(EDIFICIO_ESCUELA)->devolver_maxima_cantidad_permitidos();

    jugador_1->generar_objetivos(cantidad_escuelas);
    jugador_2->generar_objetivos(cantidad_escuelas);
}

void Juego::partida_empezada()
{
    int opcion_elegida = 0;
    bool partida_ganada = false;

    crear_todo_objetivos();
    agregar_energia_comienza_partida();

    jugador_inicial();

    while (opcion_elegida != GUARDA_SALIR)
    {

        opcion_elegida = validar_ganador(opcion_elegida,&partida_ganada);

        if (opcion_elegida != GUARDA_SALIR)
            opcion_elegida = mostrar_opciones();

        opcion_elegida = validar_ganador(opcion_elegida,&partida_ganada);
    };

    diccionario->guardar_pre_orden();
    if (!partida_ganada)
        lector_archivos->escribir_archivos(jugador_1, jugador_2, mapa);
    else
        lector_archivos->escribir_archivos();
    imprimir_mensaje_guardado();
}

void Juego::agregar_energia_comienza_partida()
{
    jugador_1->sumar_energia(ENERGIA_COMIENZO_PARTIDA);
    jugador_2->sumar_energia(ENERGIA_COMIENZO_PARTIDA);
}

int Juego::numero_aleatorio(int desde, int hasta)
{
    int numero = (desde + rand() % hasta);

    while (numero > hasta)
        numero = (desde + rand() % hasta);
    return numero;
}

Jugador *Juego::devolver_jugador_turno()
{
    Jugador *jugador;

    if (jugador_actual == jugador_2)
        jugador = this->jugador_1;
    else
        jugador = this->jugador_2;

    return jugador;
}

void Juego::validar_opcion_ingresada(int &opcion_elegida, int max, int min)
{
    bool es_valida = es_opcion_valida(opcion_elegida, max, min);
    while (!es_valida)
    {
        imprimir_mensaje_error_ingreso();

        cin >> opcion_elegida;
        es_valida = es_opcion_valida(opcion_elegida, max, min);
    }
}

bool Juego::es_opcion_valida(int opcion, int max, int min)
{
    return ((opcion >= min) && (opcion <= max));
}

void Juego::procesar_opcion_partida_empezada(int opcion)
{

    switch (opcion)
    {
    case CONSTRUIR_EDIFICIO_NOMBRE:
        constructora->construir_edificio(jugador_actual);
        break;
    case LISTAR_MIS_EDIFICIOS_CONSTRUIDOS:
        mapa->mostrar_edificios_construidos(jugador_actual);
        break;
    case DEMOLER_EDIFICIO_COORDENADA:
        constructora->demoler_edificio(jugador_actual);
        break;
    case ATARCAR_EDIFICIO_COORDENADA:
        this->atacar_edificio();
        imprimir_mensaje_enter_continuar();
        break;
    case REPARAR_EDIFICIO_COORDENADA:
        this->reparar_edificio();
        imprimir_mensaje_enter_continuar();
        break;
    case COMPRAR_BOMBA:
        jugador_actual->comprar_bombas();
        break;
    case CONSULTAR_COORDENADA:
        this->mostrar_coordenada();
        imprimir_mensaje_enter_continuar();
        break;
    case MOSTRAR_INVENTARIO:
        mostrar_inventario(jugador_actual);
        imprimir_mensaje_enter_continuar();
        break;
    case MOSTRAR_OBJETIVOS:
        jugador_actual->mostrar_objetivos();
        imprimir_mensaje_enter_continuar();
        break;
    case RECOLECTAR_RECURSOS:
        jugador_actual->recoger_recurso();
        break;
    case MOVERSE_COORDENADA:
        moverse_coordenada();
        break;
    case FINALIZAR_TURNO:
        acumular_recursos();
        jugador_actual->sumar_a_objetivo(jugador_actual->devolver_energia(), CANSADO);
        jugador_actual->sumar_energia(ENERGIA_NUEVO_TURNO);
        jugador_actual = devolver_jugador_turno();
        this->restablecer_fue_atacado();
        this->lluvia();
        if (jugador_actual->devolver_energia() <= 0)
        {
            jugador_actual = devolver_jugador_turno();
        }
        break;
    }
}

void Juego::mostrar_inventario(Jugador *jugador_turno)
{
    jugador_turno->mostrar_inventario();
}

void Juego::moverse_coordenada()
{
    mapa->mostrar();
    int fila = pedir_fila();
    int columna = pedir_columna();

    cargar_grafo();

    int fila_actual = jugador_actual->devolver_fila();
    int columna_actual = jugador_actual->devolver_columna();

    string posicion_actual = to_string(fila_actual) + " " + to_string(columna_actual);
    string posicion_ingresada = to_string(fila) + " " + to_string(columna);

    int costo = grafo->devolver_costo(posicion_actual, posicion_ingresada);
    if (costo != POSICION_NO_ENCONTRADA)
    {
        if (jugador_actual->devolver_energia() >= costo)
        {
            grafo->camino_minimo(posicion_actual, posicion_ingresada, mapa, jugador_actual);
            jugador_actual->restar_energia(costo);
        }
        else
            sin_energia_desplazarse(costo);
    }
    else
        imprimir_mensaje_posicion_no_permitida();
}

void Juego::sin_energia_desplazarse(int costo)
{
    system("clear");
    imprimir_mensaje_no_energia_sufuciente(costo);
    cout << "\tDesea ingresar una nueva posicion: " << endl;
    int opcion;
    imprimir_mensaje_afirmativo_negativo();
    cin >> opcion;

    while (!ingreso_afirmativo_negativo_valido(opcion))
    {
        imprimir_mensaje_error_ingreso();
        cin >> opcion;
    }
    if (opcion == AFIRMATIVO)
        moverse_coordenada();
}

void Juego::cargar_grafo()
{
    Jugador *jugador_sig = devolver_jugador_turno();

    for (int i = 0; i < mapa->devolver_cantidad_filas(); i++)
    {
        for (int j = 0; j < mapa->devolver_cantidad_columnas(); j++)
        {
            Casillero *casillero = mapa->devolver_casillero(i, j);
            if (!mapa->hay_edicicio(i, j))
            {
                if ((i != jugador_sig->devolver_fila()) || (j != jugador_sig->devolver_columna()))
                    this->grafo->agregar_vertice(casillero->devolver_posicion());
            }
        }
    }
    cargar_costos();
    grafo->usar_floyd();
}

void Juego::cargar_costos()
{
    cargar_costos_filas();
    cargar_costos_columnas();
}

void Juego::modificar_costo_casillero(Casillero *&casillero)
{
    if (casillero->devolver_tipo_terreno() == LAGO)
    {
        if (jugador_actual->devolver_numero() == JUGADOR_1)
            casillero->modificar_costo(2);
        else
            casillero->modificar_costo(5);
    }
    else if (casillero->devolver_tipo_terreno() == MUELLE)
    {
        if (jugador_actual->devolver_numero() == JUGADOR_1)
            casillero->modificar_costo(5);
        else
            casillero->modificar_costo(2);
    }
}

void Juego::cargar_costos_filas()
{
    for (int i = 0; i < mapa->devolver_cantidad_filas(); i++)
    {
        for (int j = 0; j < mapa->devolver_cantidad_columnas(); j++)
        {
            if (j < mapa->devolver_cantidad_columnas() - 1)
            {
                Casillero *casillero_1 = mapa->devolver_casillero(i, j);
                Casillero *casillero_2 = mapa->devolver_casillero(i, j + 1);
                modificar_costo_casillero(casillero_1);
                modificar_costo_casillero(casillero_2);
                this->grafo->agregar_camino(casillero_1->devolver_posicion(), casillero_2->devolver_posicion(), casillero_2->devolver_costo());
                this->grafo->agregar_camino(casillero_2->devolver_posicion(), casillero_1->devolver_posicion(), casillero_1->devolver_costo());
            }
        }
    }
}

void Juego::cargar_costos_columnas()
{
    for (int j = 0; j < mapa->devolver_cantidad_columnas(); j++)
    {
        for (int i = 0; i < mapa->devolver_cantidad_filas(); i++)
        {
            if (i < mapa->devolver_cantidad_filas() - 1)
            {
                Casillero *casillero_1 = mapa->devolver_casillero(i, j);
                Casillero *casillero_2 = mapa->devolver_casillero(i + 1, j);
                modificar_costo_casillero(casillero_1);
                modificar_costo_casillero(casillero_2);
                this->grafo->agregar_camino(casillero_1->devolver_posicion(), casillero_2->devolver_posicion(), casillero_2->devolver_costo());
                this->grafo->agregar_camino(casillero_2->devolver_posicion(), casillero_1->devolver_posicion(), casillero_1->devolver_costo());
            }
        }
    }
}

int Juego::pedir_fila()
{
    int opcion_elegida = 0;
    cout << " Por favor ingrese la fila: ";
    cin >> opcion_elegida;
    validar_opcion_ingresada(opcion_elegida, this->mapa->devolver_cantidad_filas(), 0);

    return opcion_elegida;
}

int Juego::pedir_columna()
{
    int opcion_elegida = 0;
    cout << " Por favor ingrese la columna: ";
    cin >> opcion_elegida;
    validar_opcion_ingresada(opcion_elegida, this->mapa->devolver_cantidad_columnas(), 0);

    return opcion_elegida;
}

void Juego::mostrar_coordenada()
{
    system("clear");

    int fila = this->pedir_fila();
    int columna = this->pedir_columna();

    system("clear");
    this->mapa->imprimir_resumen_casillero(fila, columna);
}

void Juego::reparar_edificio()
{
    if (jugador_actual->devolver_energia() <= ENERGIA_REPARAR)
        imprimir_mensaje_no_energia_sufuciente(ENERGIA_REPARAR);
    else
    {
        int fila = this->pedir_fila();
        int columna = this->pedir_columna();

        if (validar_reparar_edificio(fila, columna))
        {
            mapa->devolver_casillero(fila, columna)->devolver_edificacion()->reparar();
            jugador_actual->restar_energia(ENERGIA_REPARAR);
        }
    }
}

void Juego::atacar_edificio()
{
    if (validar_bombas_energia())
    {
        int fila = this->pedir_fila();
        int columna = this->pedir_columna();

        if (validar_atacar_edificio(fila, columna))
        {
            if (mapa->devolver_casillero(fila, columna)->devolver_edificacion()->devolver_fue_atacado())
            {
                cout << "Este edificio ya fue atacado en este turno!!!" << endl;
            }
            else
            {
                if (mapa->devolver_casillero(fila, columna)->devolver_edificacion()->devolver_necesita_reparacion())
                {
                    devolver_jugador_turno()->borrar_edificio(fila, columna);
                    mapa->borrar_edificio(fila, columna);
                }
                else
                {
                    mapa->devolver_casillero(fila, columna)->devolver_edificacion()->atacar();
                    mapa->devolver_casillero(fila, columna)->devolver_edificacion()->fue_atacado_true();
                    if (mapa->devolver_casillero(fila, columna)->devolver_edificacion()->devolver_nombre_edificio() != EDIFICIO_MINA && mapa->devolver_casillero(fila, columna)->devolver_edificacion()->devolver_nombre_edificio() != EDIFICIO_FABRICA)
                    {
                        devolver_jugador_turno()->borrar_edificio(fila, columna);
                        mapa->borrar_edificio(fila, columna);
                    }
                    restar_atacar();
                }
            }
        }
    }
}

bool Juego::validar_reparar_edificio(int fila, int columna)
{
    bool se_puede = false;

    string nombre_edificio = mapa->devolver_casillero(fila, columna)->devolver_edificacion()->devolver_nombre_edificio();

    int cantidad_piedra = jugador_actual->devolver_inventario()->devolver_material(PIEDRA);
    int cantidad_madera = jugador_actual->devolver_inventario()->devolver_material(MADERA);
    int cantidad_metal = jugador_actual->devolver_inventario()->devolver_material(METAL);
    int piedra_necesaria = diccionario->buscar(nombre_edificio)->devolver_receta()->devoler_piedra() / 4;
    int madera_necesaria = diccionario->buscar(nombre_edificio)->devolver_receta()->devoler_madera() / 4;
    int metal_necesario = diccionario->buscar(nombre_edificio)->devolver_receta()->devoler_metal() / 4;

    if (mapa->hay_edicicio(fila, columna))
    {
        if (mapa->devolver_casillero(fila, columna)->devolver_duenio() != jugador_actual->devolver_numero())
        {
            cout << "No se puede reparar un edificio que no te pertenece" << endl;
        }
        else
        {
            if (!mapa->devolver_casillero(fila, columna)->devolver_edificacion()->devolver_reparable())
            {
                cout << "El edificio no es ni una mina ni una fabrica asi que no se puede reparar." << endl;
            }
            else
            {
                if (!mapa->devolver_casillero(fila, columna)->devolver_edificacion()->devolver_necesita_reparacion())
                {
                    cout << "El edificio no necesita reparacion." << endl;
                }
                else
                {
                    if (cantidad_piedra >= piedra_necesaria && cantidad_metal >= metal_necesario && cantidad_madera >= madera_necesaria)
                    {
                        se_puede = true;
                    }
                }
            }
        }
    }
    return se_puede;
}

void Juego::acumular_recursos()
{
    Edificacion *edificio;
    for (int i = 0; i < jugador_actual->devolver_mis_edificios()->devolver_cantidad_en_Lista_edificios(); i++)
    {
        edificio = jugador_actual->devolver_mis_edificios()->obtener_direccion_nodo(i)->devolver_dato();
        if (edificio->brinda_material())
        {
            jugador_actual->acumular_recursos(edificio->devolver_material_producido(), edificio->devolver_cantidad_material_brinda());
        }
    }
}

void Juego::restablecer_fue_atacado()
{
    for (int i = 0; i < mapa->devolver_cantidad_filas(); i++)
    {
        for (int j = 0; j < mapa->devolver_cantidad_columnas(); j++)
        {
            if ((mapa->hay_edicicio(i, j)))
            {
                mapa->devolver_casillero(i, j)->devolver_edificacion()->fue_atacado_false();
            }
        }
    }
}

void Juego::restar_atacar()
{
    jugador_actual->restar_material(1, BOMBA);
    jugador_actual->restar_energia(ENERGIA_ATACAR);
    jugador_actual->sumar_a_objetivo(1, BOMBARDERO);
}

bool Juego::validar_atacar_edificio(int fila, int columna)
{
    bool se_puede = false;
    if (mapa->hay_edicicio(fila, columna))
    {
        if (mapa->devolver_casillero(fila, columna)->devolver_duenio() == jugador_actual->devolver_numero())
            cout << "No se puede atacar un edificio propio " << endl;
        else
            se_puede = true;
    }
    return se_puede;
}

bool Juego::validar_bombas_energia()
{
    bool se_puede = false;
    if (jugador_actual->devolver_energia() < ENERGIA_ATACAR)
        imprimir_mensaje_no_energia_sufuciente(ENERGIA_ATACAR);
    else
    {
        if (jugador_actual->devolver_inventario()->devolver_material(BOMBA) < 1)
            cout << "Debe tener por lo menos una bomba para atacar un edificio" << endl;
        else
            se_puede = true;
    }
    return se_puede;
}

void Juego::lluvia()
{
    if (toca_lluvia)
    {
        mapa->lluvia_recursos();
        toca_lluvia = false;
    }
    else
    {
        toca_lluvia = true;
    }
}