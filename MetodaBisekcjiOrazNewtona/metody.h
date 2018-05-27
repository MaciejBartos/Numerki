#ifndef METODYBISEKCJIORAZNEWTONA_METODYORAZSCHEMATHORNERA_H
#define METODYBISEKCJIORAZNEWTONA_METODYORAZSCHEMATHORNERA_H

#include <vector>
#include "funkcje.h"



double metodaNewtona(double a, double b, double eps, funkcja fun, funkcja funP1, int &iloscIteracji,
                     int wymaganaIloscIteracji,
                     double &dokladnosc);

double metodaBisekcji(double a, double b, double eps, funkcja fun, int &iloscIteracji, int wymaganaIloscIteracji,
                      double &dokladnosc);

#endif //METODYBISEKCJIORAZNEWTONA_METODYORAZSCHEMATHORNERA_H
