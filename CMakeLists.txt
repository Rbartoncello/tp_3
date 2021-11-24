project(tp_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(tp_3 constantes.h main.cpp edificios.cpp edificios.h materiales.cpp materiales.h
        mapa.cpp mapa.h material.cpp material.h edificio.cpp edificio.h juego.cpp juego.h  casillero.cpp
        casillero.h casillero_transitable.cpp casillero_transitable.h casillero_construible.cpp casillero_construible.h
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
        planta.cpp planta.h archivo.cpp archivo.h inventario.cpp inventario.h
        aserradero.h aserradero.cpp mina_oro.cpp mina_oro.h piedra.cpp piedra.h madera.cpp madera.h metal.cpp metal.h
        bomba.cpp bomba.h andycoins.cpp andycoins.h)
