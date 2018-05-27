#ifndef APROKSYMACJA_WSPOLCZYNNIKI_H
#define APROKSYMACJA_WSPOLCZYNNIKI_H

#include <vector>
#include "iloscPunktowOrazWskazniki.h"

std::vector<double> wspolczynnikiAproksymacja(double a, double b, double dokladnosc, int stopienWielomianu,
                                              wskaznik wskFunckja1, wskaznik wskFunckja2);

#endif //APROKSYMACJA_WSPOLCZYNNIKI_H
