#include <vector>
#include <iostream>
#include "funkcje.h"
#include "metody.h"

double metodaBisekcji(double a, double b, double eps, funkcja fun, int &iloscIteracji, int wymaganaIloscIteracji,
                      double &dokladnosc) {
    double var = 0;

    if (fun(a) * fun(b) > 0) {
        std::cout << "zly przedzial";
        return 0;
    }

    while ((abs(a - b) > eps) && (iloscIteracji < wymaganaIloscIteracji)) {
        iloscIteracji++;

        var = (a + b) / 2;
        if (fun(var) == 0) {
            return var;
        }
        if (fun(a) * fun(var) < 0) {
            b = var;
        } else if (fun(b) * fun(var)) {
            a = var;
        }
        dokladnosc = abs(a - b);
    }
    return var;
}

double metodaNewtona(double a, double b, double eps, funkcja fun, funkcja funP1, int &iloscIteracji,
                     int wymaganaIloscIteracji, double &dokladnosc) {
    double start, x;

    if (fun(a) * fun(b) >= 0) {
        std::cout << "zly przedzial!";
        return 0;
    }

    start = (a + b) / 2;
    x = start - (fun(start) / funP1(start));

    while ((abs(x - start) > eps) && (iloscIteracji < wymaganaIloscIteracji)) {
        iloscIteracji++;
        start = x;
        x = start - (fun(start) / funP1(start));
        dokladnosc = abs(x - start);
    }
    return x;

}