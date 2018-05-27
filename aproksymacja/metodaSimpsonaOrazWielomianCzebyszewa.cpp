
#include <cmath>
#include "metodaSimpsonaOrazWielomianCzebyszewa.h"

double wzorSimpsona(double a, double b, double dokladnosc, wskaznik wskFunkcja1, wskaznik wskFunkcja2, int k) {
    double skok;
    int podzielPrzedzial = 2;
    skok = (b - a) / (double) podzielPrzedzial;

    double calkowanie = 0;

    calkowanie = (skok / 6) * (wskFunkcja1(a, k)*wskFunkcja2(a, k) + wskFunkcja1(b, k)*wskFunkcja2(b, k));

    double calkowanieDokladnosc = calkowanie;
    double polozenie;

    int wspolczynnikiWzoruSimpsona[2] = {4, 2};
    do {
        calkowanie = calkowanieDokladnosc;
        podzielPrzedzial *= 2;
        polozenie = a;

        skok = (b - a) / (double) podzielPrzedzial;
        calkowanieDokladnosc = wskFunkcja1(a, k)*wskFunkcja2(a, k) + wskFunkcja1(b, k)*wskFunkcja2(b, k);
        for (int i = 0; i < podzielPrzedzial - 1; ++i) {
            polozenie += skok;
            calkowanieDokladnosc += wspolczynnikiWzoruSimpsona[i % 2] * wskFunkcja1(polozenie, k)*wskFunkcja2(polozenie, k);
        }
        calkowanieDokladnosc *= skok / 3;
    } while ((fabs(calkowanie - calkowanieDokladnosc)) > dokladnosc);

    return calkowanie;
}

double wielomianCzebyszewa(double x, int k){
    double wartosc;
    double a = 1, b = x;
    if (k == 0){
        wartosc = a;
    }
    else{
        wartosc = b;
    }
    for (int i = 1; i < k; ++i) {
        wartosc = 2*x*b - a;
        a = b;
        b = wartosc;
    }
    return wartosc;
}