

#ifndef INTERPOLACJALAGRANCAROWNOLEGLA_INTERPOLACJA_H
#define INTERPOLACJALAGRANCAROWNOLEGLA_INTERPOLACJA_H

#include "zmiennaGlobalnaOrazWskaznikNaFunkcje.cpp"

void interpolacja(double *tabX, double *tabY, int n, double wzrostWartosciX, double poczatekPrzedzialu);
void wyznaczWezly(double *tabX, double *tabY, int n, double poczatekPrzedzialu, double koniecPrzedzialu, funkcja wsk);
void daneDoWykresuFunkcji(double *tabX, double *tabY, double poczatekPrzedzialu, double wzrostX, funkcja wsk);

#endif //INTERPOLACJALAGRANCAROWNOLEGLA_INTERPOLACJA_H
