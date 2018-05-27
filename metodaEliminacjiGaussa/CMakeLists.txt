cmake_minimum_required(VERSION 3.9)
project(metodaEliminacjiGaussa)

set(CMAKE_CXX_STANDARD 11)

add_executable(metodaEliminacjiGaussa main.cpp metodaGaussa.cpp ukladRownan.cpp operacjeNaMacierzy.cpp metodaGaussa.h operacjeNaMacierzy.h warunkiNaRodzajMacierzy.cpp warunkiNaRodzajMacierzy.h ukladRownan.h)