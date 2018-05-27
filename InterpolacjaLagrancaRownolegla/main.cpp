#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "zapisOrazOdczyt.h"
#include "schematHorneraOrazFunkcje.h"
#include "interpolacja.h"

int main() {
    std::cout << "Podaj przedzial interpolacji" << std::endl;
    double poczatekPrzedzialu, koniecPrzedzialu;
    std::cin >> poczatekPrzedzialu;
    std::cin >> koniecPrzedzialu;

    std::cout << "Podaj ilosc wezlow: " << std::endl;
    int iloscWezlow;
    std::cin >> iloscWezlow;

    double wzrostWartosciX = (fabs(poczatekPrzedzialu) + fabs(koniecPrzedzialu)) / iloscPunktow;

    double *tabXWezly = new double[iloscWezlow];
    double *tabYWezly = new double[iloscWezlow];


    std::cout << "1 - wczytaj wezly z pliku,\n2 - przejdz do wyboru funkcji\n";
    int opcja;
    std::cin >> opcja;
    if (opcja == 1) {
        odczytZPlikuWezly(tabXWezly, tabYWezly, iloscWezlow);
    }
    else if (opcja == 2) {
        std::cout << "wybierz funckje: \n";
        std::cout << "1 - 3x^3 + 3x^2 - 7x + 1\n";
        std::cout << "2 - |x|\n";
        std::cout << "3 - sin (x)\n";
        std::cout << "4 - cos (|x|)\n";
        std::cin >> opcja;

        funkcja wskaznijNaFunckje;


        switch (opcja) {
            case 1:
                wskaznijNaFunckje = wielomian;
                break;
            case 2:
                wskaznijNaFunckje = fabs;
                break;
            case 3:
                wskaznijNaFunckje = sin;
                break;
            case 4:
                wskaznijNaFunckje = zlozenie;
                break;
            default:
                std::cout << "zly numer!";
                return -1;

        }

        wyznaczWezly(tabXWezly, tabYWezly, iloscWezlow, poczatekPrzedzialu, koniecPrzedzialu, wskaznijNaFunckje);
        zapisDoPlikuWezly(tabXWezly, tabYWezly, iloscWezlow);
        double *tabXFunkcja = new double[iloscPunktow];
        double *tabYFunkcja = new double[iloscPunktow];

        daneDoWykresuFunkcji(tabXFunkcja, tabYFunkcja, poczatekPrzedzialu, wzrostWartosciX, wskaznijNaFunckje);
        zapisDoPlikuInterpolowana(tabXFunkcja, tabYFunkcja);
    }
    else {
        std::cout << "zly numer!";
        return -1;
    }

    interpolacja(tabXWezly, tabYWezly, iloscWezlow, wzrostWartosciX, poczatekPrzedzialu);

    return 0;
}