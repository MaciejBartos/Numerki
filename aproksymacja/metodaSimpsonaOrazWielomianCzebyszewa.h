#ifndef APROKSYMACJA_METODASIMPSONAORAZWIELOMIANCZEBYSZEWA_H
#define APROKSYMACJA_METODASIMPSONAORAZWIELOMIANCZEBYSZEWA_H

#include "iloscPunktowOrazWskazniki.h"

double wzorSimpsona(double a, double b, double dokladnosc, wskaznik wskFunkcja1, wskaznik wskFunkcja2, int k);
double wielomianCzebyszewa(double x, int k);

#endif //APROKSYMACJA_METODASIMPSONAORAZWIELOMIANCZEBYSZEWA_H
