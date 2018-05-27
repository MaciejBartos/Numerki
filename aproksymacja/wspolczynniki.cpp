#include <iostream>
#include "metodaSimpsonaOrazWielomianCzebyszewa.h"
#include "wspolczynniki.h"

std::vector<double> wspolczynnikiAproksymacja(double a, double b, double dokladnosc, int stopienWielomianu,
                                              wskaznik wskFunckja1, wskaznik wskFunckja2){
    std::vector<double> wspolczynniki;
    double zmienna1;
    double zmienna2;
    for (int i = 0; i <= stopienWielomianu; ++i) {
        zmienna1 = wzorSimpsona(a, b, dokladnosc, wskFunckja1, wskFunckja2, i);
        zmienna2 = wzorSimpsona(a, b, dokladnosc, wskFunckja2, wskFunckja2, i);
        if (zmienna1 < 0.0001) zmienna1 = 0;
        if (zmienna2 < 0.0001) zmienna2 = 0;
        if (zmienna2 == 0){
            wspolczynniki.push_back(0);
        }
        else{
            wspolczynniki.push_back(zmienna1/zmienna2);
        }
    }
    return wspolczynniki;
}