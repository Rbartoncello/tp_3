cmake_minimum_required(VERSION 3.20)
project(tp_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(tp_3 constantes.h edificios.txt mapa.txt main.cpp edificios.cpp edificios.h materiales.cpp materiales.h
        mapa.cpp mapa.h material.cpp material.h edificio.cpp edificio.h juego.cpp juego.h archivo.cpp archivo.h)
