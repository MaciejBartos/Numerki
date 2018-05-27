cmake_minimum_required(VERSION 3.10)
project(aproksymacja)

set(CMAKE_CXX_STANDARD 11)

add_executable(aproksymacja main.cpp funkcje.cpp funkcje.h metodaSimpsonaOrazWielomianCzebyszewa.cpp metodaSimpsonaOrazWielomianCzebyszewa.h iloscPunktowOrazWskazniki.h daneDoWykresu.cpp daneDoWykresu.h wspolczynniki.cpp wspolczynniki.h)