#ifndef APROKSYMACJA_DANEDOWYKRESU_H
#define APROKSYMACJA_DANEDOWYKRESU_H


#include <vector>
#include "iloscPunktowOrazWskazniki.h"

void daneDoWykresuAproksymowana(double *tabX, double *tabY, double poczatekPrzedzialu, double wzrostX, wskaznik funkcja,
                                int k);
void daneDoWykresuAproksymacja(double *tabX, double *tabY, double poczatekPrzedzialu, double wzrostX,
                               std::vector<double> wspolczynniki);
void zapisDoPlikuAproksymacja(double *tabX, double *tabY);
void zapisDoPlikuAproksymowana(double *tabX, double *tabY);
double wartoscFunkcjiAproksymacja(double x, std::vector<double> wspolczynniki);

#endif //APROKSYMACJA_DANEDOWYKRESU_H
