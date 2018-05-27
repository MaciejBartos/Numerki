#include <cmath>
#include "metodaGaussaOrazWzorSimpsona.h"


double wzorSimpsona(double a, double b, double dokladnosc, wskaznik wskFunkcja) {
    double skok;
    int podzielPrzedzial = 2;
    skok = (b - a) / (double) podzielPrzedzial;

    double calkowanie = 0;

    calkowanie = (skok / 6) * (wskFunkcja(a, a) + wskFunkcja(b, b));

    double calkowanieDokladnosc = calkowanie;
    double polozenie;

    int wspolczynnikiWzoruSimpsona[2] = {4, 2};
    do {
        calkowanie = calkowanieDokladnosc;
        podzielPrzedzial *= 2;
        polozenie = a;

        skok = (b - a) / (double) podzielPrzedzial;
        calkowanieDokladnosc = wskFunkcja(a, a) + wskFunkcja(b, b);
        for (int i = 0; i < podzielPrzedzial - 1; ++i) {
            polozenie += skok;
            calkowanieDokladnosc += wspolczynnikiWzoruSimpsona[i % 2] * wskFunkcja(polozenie, polozenie);
        }
        calkowanieDokladnosc *= skok / 3;
    } while ((fabs(calkowanie - calkowanieDokladnosc)) > dokladnosc);

    return calkowanie;
}

double granica(double eps, wskaznik wskFunkcja) {
    double granica = 0, calka, punktStartowy = 0, skok = 0.5;
    do {
        calka = wzorSimpsona(punktStartowy, punktStartowy + skok, eps, wskFunkcja); //przedzial (0,1)
        granica += calka;

        calka = wzorSimpsona(-punktStartowy - skok, -punktStartowy, eps, wskFunkcja); // przedzial (-1,0)
        granica += calka;

        punktStartowy += skok;
        skok *= 0.5;
    } while (fabs(calka) > eps);
    return granica;
}

double metodaGaussa(int n, wskaznik wskFunkcja) {
    double calka = 0;
    double pierwiastek;
    double waga = (M_PI / n);

    for (int i = 1; i < n + 1; i++) {
        pierwiastek = cos(((2.0 * i - 1.0) * M_PI) / (2.0 * n));
        calka += waga * wskFunkcja(pierwiastek, 0);
    }

    return calka;
}
