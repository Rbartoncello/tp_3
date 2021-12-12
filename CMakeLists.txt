project(tp_3)

set(CMAKE_CXX_STANDARD 14)
set(GCC_ENABLE_WARNINGS "-O1 -Wall -Werror -Wconversions")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_ENABLE_WARNINGS}")
add_executable(tp_3 constantes.h main.cpp
        materiales.cpp materiales.h
        mapa.cpp mapa.h
        material.cpp material.h
        juego.cpp juego.h
        jugador.cpp jugador.h
        casillero.cpp casillero.h
        casillero_transitable.cpp casillero_transitable.h
        casillero_construible.cpp casillero_construible.h
        casillero_inaccesible.cpp casillero_inaccesible.h
        lago.cpp lago.h
        camino.cpp camino.h
        terreno.cpp terreno.h
        betun.cpp betun.h
        muelle.cpp muelle.h
        interface.cpp interface.h
        diccionario.h
        receta.cpp receta.h
        edificacion.cpp edificacion.h
        escuela.h escuela.cpp
        fabrica.cpp fabrica.h
        mina.h mina.cpp
        obelisco.h obelisco.cpp
        planta.cpp planta.h
        archivo.cpp archivo.h
        inventario.cpp inventario.h
        aserradero.h aserradero.cpp
        mina_oro.cpp mina_oro.h
        piedra.cpp piedra.h
        madera.cpp madera.h
        metal.cpp metal.h
        bomba.cpp bomba.h
        andycoins.cpp andycoins.h
        gotoxy.h
        mina_oro.cpp mina_oro.h
        objetivos.cpp objetivos.h
        lista.h
        Grafo.cpp Grafo.h
        nodo.h
        nodo_lista.h
        Vertice.cpp Vertice.h
        Floyd.cpp Floyd.h
        Camino_minimo.cpp Camino_minimo.h
        constructora.cpp constructora.h
        obj_armado.cpp obj_armado.h
        obj_bombardero.cpp obj_bombardero.cpp
        obj_cansado.h obj_cansado.cpp
        obj_comprar_andypolis.cpp obj_comprar_andypolis.h
        obj_constructor.cpp obj_constructor.h
        obj_edad_piedra.cpp obj_edad_piedra.h
        obj_extremista.cpp obj_extremista.h
        obj_letrado.h obj_letrado.cpp
        obj_obelisco.cpp obj_obelisco.h
        obj_minero.cpp obj_minero.h
        obj_energetico.cpp obj_energetico.h
        )
