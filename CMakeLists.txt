project(tp_3)

set(CMAKE_CXX_STANDARD 14)
set(GCC_ENABLE_WARNINGS "-O1 -Wall -Werror -Wconversions")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_ENABLE_WARNINGS}")
add_executable(tp_3 constantes.h main.cpp
        edificios.cpp edificios.h
        materiales.cpp materiales.h
        mapa.cpp mapa.h
        material.cpp material.h
        edificio.cpp edificio.h
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
        diccionario.cpp diccionario.h
        receta.cpp receta.h
        nodo.cpp nodo.h
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
        bombardero.cpp bombardero.h
        comprar_andypolis.cpp comprar_andypolis.h
        edad_piedra.cpp edad_piedra.h
        gotoxy.h
        mas_alto_que_las_nubes.cpp mas_alto_que_las_nubes.h
        mina_oro.cpp mina_oro.h
        objetivos.cpp objetivos.h
        lista.h
        Grafo.cpp Grafo.h
        Lista.h
        Nodo.h
        nodo.h nodo.cpp
        nodo_lista.h
        Vertice.cpp Vertice.h
        Floyd.cpp Floyd.h
        Camino_minimo.cpp Camino_minimo.h)
