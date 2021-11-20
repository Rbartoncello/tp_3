cmake_minimum_required(VERSION 3.20)
project(tp_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(tp_3 constantes.h edificios.txt mapa.txt main.cpp edificios.cpp edificios.h materiales.cpp materiales.h
        mapa.cpp mapa.h material.cpp material.h edificio.cpp edificio.h juego.cpp juego.h  casillero.cpp
        casillero.h casillero_transitable.cpp casillero_transitable.h casillero_construible.cpp casillero_construible.h
        casillero_inaccesible.cpp casillero_inaccesible.h lago.cpp lago.h camino.cpp camino.h terreno.cpp terreno.h
        betun.cpp betun.h muelle.cpp muelle.h)
