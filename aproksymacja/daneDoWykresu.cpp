#include <iostream>
#include <fstream>
#include <vector>
#include "iloscPunktowOrazWskazniki.h"
#include "metodaSimpsonaOrazWielomianCzebyszewa.h"
#include "daneDoWykresu.h"

double wartoscFunkcjiAproksymacja(double x, std::vector<double> wspolczynniki){
    double wartosc = 0;
    for (int i = 0; i < wspolczynniki.size(); ++i) {
        wartosc += wspolczynniki[i]* wielomianCzebyszewa(x, i);

//        std::cout << wielomianCzebyszewa(x, i) << std::endl;
    }
    return wartosc;
}

void daneDoWykresuAproksymowana(double *tabX, double *tabY, double poczatekPrzedzialu, double wzrostX, wskaznik funkcja,
                                int k) {
    double wartoscX = poczatekPrzedzialu;
    for (int i = 0; i < iloscPunktow; ++i) {
        tabX[i] = wartoscX;
        tabY[i] = funkcja(wartoscX, k);
        wartoscX += wzrostX;
    }
}

void daneDoWykresuAproksymacja(double *tabX, double *tabY, double poczatekPrzedzialu, double wzrostX, std::vector<double> wspolczynniki){
    double wartoscX = poczatekPrzedzialu;
    for (int i = 0; i < iloscPunktow; ++i) {
        tabX[i] = wartoscX;
        tabY[i] = wartoscFunkcjiAproksymacja(wartoscX, wspolczynniki);
        wartoscX += wzrostX;
    }
}

void zapisDoPlikuAproksymacja(double *tabX, double *tabY) {
    std::fstream plik;
    plik.open("wartosciAproksymacja.txt", std::ios_base::out| std::ios_base::trunc);
    if (plik.good()) {
        for (int i = 0; i < iloscPunktow; ++i) {
            plik << std::endl;
            plik << tabX[i] << " " << tabY[i];
        }
    } else {
        std::cout << "Problem z plikiem!";
    }
    plik.close();
}

void zapisDoPlikuAproksymowana(double *tabX, double *tabY) {
    std::fstream plik;
    plik.open("wartosciAproksymowana.txt", std::ios_base::out| std::ios_base::trunc);
    if (plik.good()) {
        for (int i = 0; i < iloscPunktow; ++i) {
            plik << std::endl;
            plik << tabX[i] << " " << tabY[i];
        }
    } else {
        std::cout << "Problem z plikiem!";
    }
    plik.close();
}
