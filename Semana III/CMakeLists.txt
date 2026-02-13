cmake_minimum_required(VERSION 4.1)
project(Semana_III)

set(CMAKE_CXX_STANDARD 20)

add_executable(Semana_III PrimerPuntero.cpp
        PunteroNoInicializado.cpp
        UndefinedBehavior.cpp
        MemoriaDinamica.cpp
        DanglingPointer.cpp)
