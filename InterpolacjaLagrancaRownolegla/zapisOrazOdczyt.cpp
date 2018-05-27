#include <iostream>
#include <fstream>

#include "zmiennaGlobalnaOrazWskaznikNaFunkcje.cpp"

void odczytZPlikuWezly(double *tabX, double *tabY, int n) {
    std::fstream plik;
    plik.open("wartosciXiYWezly.txt");
    if (plik.good()) {
        for (int i = 0; i < n; ++i) {
            plik >> tabX[i] >> tabY[i];
        }
    } else {
        std::cout << "Problem z plikiem!";
    }
    plik.close();
}

void zapisDoPlikuWezly(double *tabX, double *tabY, int n){
    std::fstream plik;
    plik.open("wartosciXiYWezly.txt");
    if (plik.good()) {
        for (int i = 0; i < n; ++i) {
            plik << std::endl;
            plik << tabX[i] << " " << tabY[i];
        }
    } else {
        std::cout << "Problem z plikiem!";
    }
    plik.close();
}

void zapisDoPlikuInterpolacja(double *tabX, double *tabY) {
    std::fstream plik;
    plik.open("wartosciXiInterpolacji.txt");
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

void zapisDoPlikuInterpolowana(double *tabX, double *tabY) {
    std::fstream plik;
    plik.open("wartosciXiInterpolowana.txt");
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



