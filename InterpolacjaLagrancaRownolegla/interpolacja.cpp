
#include <cmath>
#include "zmiennaGlobalnaOrazWskaznikNaFunkcje.cpp"
#include "zapisOrazOdczyt.h"

void interpolacja(double *tabX, double *tabY, int n, double wzrostWartosciX, double poczatekPrzedzialu) {
    double iloczynWyrazow, sumaIloczynow;
    double wartoscX = poczatekPrzedzialu;
    double *tabInterpolacja = new double[iloscPunktow];
    double *tabWartosciXInterpolacja = new double[iloscPunktow];

    for (int i = 0; i < iloscPunktow; ++i) {
        tabWartosciXInterpolacja[i] = wartoscX;
        sumaIloczynow = 0;
        for (int j = 0; j < n; ++j) {
            iloczynWyrazow = 1;
            for (int k = 0; k < n; ++k) {
                if (k != j) {
                    iloczynWyrazow *= (wartoscX - tabX[k]) / (tabX[j] - tabX[k]);
                }
            }
            sumaIloczynow += tabY[j] * iloczynWyrazow;
        }
        tabInterpolacja[i] = sumaIloczynow;
        wartoscX += wzrostWartosciX;
    }
    zapisDoPlikuInterpolacja(tabWartosciXInterpolacja, tabInterpolacja);
}

void wyznaczWezly(double *tabX, double *tabY, int n, double poczatekPrzedzialu, double koniecPrzedzialu, funkcja wsk) {
    double coIleWezel = (fabs(poczatekPrzedzialu) + fabs(koniecPrzedzialu)) / (n+1);
    double poczatekWezly = poczatekPrzedzialu;
    for (int i = 0; i < n; ++i) {
        poczatekWezly += coIleWezel;
        tabX[i] = poczatekWezly;
        tabY[i] = wsk(poczatekWezly);

    }

}

void daneDoWykresuFunkcji(double *tabX, double *tabY, double poczatekPrzedzialu, double wzrostX, funkcja wsk) {
    double wartoscX = poczatekPrzedzialu;
    for (int i = 0; i < iloscPunktow; ++i) {
        tabX[i] = wartoscX;
        tabY[i] = wsk(wartoscX);
        wartoscX += wzrostX;
    }
}

